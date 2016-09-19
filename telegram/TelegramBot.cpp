#include "TelegramBot.h"
#include "params/SendMessageParams.h"

using namespace telegram;
using namespace telegram::params;
using namespace telegram::structures;

void TelegramBot::Setup(const std::string &token, const std::string &path)
{   
	Logger::info << R"( ____  ____  __    ____  ___  ____   __   _  _  ____   __  ____)" << std::endl;
	Logger::info << R"((_  _)(  __)(  )  (  __)/ __)(  _ \ / _\ ( \/ )(  _ \ /  \(_  _))" << std::endl;
	Logger::info << R"(  )(   ) _) / (_/\ ) _)( (_ \ )   //    \/ \/ \ ) _ ((  O ) )()" << std::endl;
	Logger::info << R"( (__) (____)\____/(____)\___/(__\_)\_/\_/\_)(_/(____/ \__/ (__))" << std::endl;
	Logger::info << R"( ____  _  _    __ _   __   _  _  ____  ____  ____  ____)" << std::endl;        
	Logger::info << R"((  _ \( \/ )  (  / ) / _\ / )( \(  _ \(  _ \(  __)(  _ \)" << std::endl;
	Logger::info << R"( ) _ ( )  /    )  ( /    \) \/ ( ) __/ ) __/ ) _)  )   /)" << std::endl;
	Logger::info << R"((____/(__/    (__\_)\_/\_/\____/(__)  (__)  (____)(__\_))" << std::endl;
	Logger::info << std::endl;

 
    (*this)["token"] = token;
    
    curl::RequestParams requestParams(GetApiUrl("getme"), curl::Method::POST);
    requestParams.SetHeaders(GetDefaultHeader());
    
    curl::Response response = session.DoRequest(requestParams);
    
    auto json = Serializable::Deserialize(std::string(response.content.begin(), response.content.end()));
    std::string botName = (*json)["result"]["username"].asString();
    
    Logger::debug << "botName: " << botName << std::endl;
    
    (*this)["botName"] = botName;
    PersistingService::SetFileName(path + botName + ".data");
    
    try {
        PersistingService::Load();
        Logger::info << "Loaded data file for bot \"" << botName << "\"" << std::endl;
    } catch (const PersistingException &loadEx) {
        Logger::warn << "Failed to load data file for bot \"" << botName << "\"" << std::endl;
        Logger::warn << "Reason: " << loadEx.what() << std::endl;
        
        try {
            PersistingService::Save();
            Logger::info << "Created new data file" << std::endl;
        } catch (const PersistingException &saveEx) {
            std::string error = "Failed to create new data file\n";
            error += std::string("Reason: ") + saveEx.what();
            throw TelegramException(error);
        }
    }
}

void TelegramBot::GetUpdates() 
{
    std::map<std::string, std::string> params = {};
    if(!(*this)["offset"].isNull()) {
        params = {
            {"offset", (*this)["offset"].asString()}
        };   
    }
    
    curl::RequestParams requestParams(GetApiUrl("getUpdates"), curl::Method::POST);
    requestParams.SetHeaders(GetDefaultHeader());
    requestParams.SetParams(params);
    requestParams.FollowRedirects(false);
    curl::Response response = session.DoRequest(requestParams);
    
    if(!CheckResponse(response, "GetUpdates")) {
        return;
    }
    
    auto json = Serializable::Deserialize(std::string(response.content.begin(), response.content.end()));
    std::vector<Update> updates = Converter::FromJSON<std::vector<Update>>((*json)["result"]);
    
    for(auto &u : updates) {
        User user;
        if(u.message != nullptr) {
            user = u.message->GetFromValue();
        } else if(u.editedMessage != nullptr) {
            user = u.editedMessage->GetFromValue();
        } else if(u.inlineQuery != nullptr) {
            user = u.inlineQuery->GetFromValue();
        } else if(u.chosenInlineResult != nullptr) {
            user = u.chosenInlineResult->GetFromValue();
        } else if(u.callbackQuery != nullptr) {
            user = u.callbackQuery->GetFromValue();
        }
        
        std::string senderId = std::to_string(user.GetIdValue());
        queue.Push(senderId, u);
        
        if(processingThreads.find(senderId) == processingThreads.end()) {
            processingThreads[senderId] = new std::thread(TelegramBot::Process, this, senderId);
        }

        if(u.GetUpdateIdValue() >= (*this)["offset"].asInt()) {
            (*this)["offset"] = u.GetUpdateIdValue() + 1;
        }
    }
    Save();
}

void TelegramBot::Process(TelegramBot *bot, std::string senderId) 
{
    while((*bot)["running"].asBool()) {
        if(!bot->queue.Available(senderId)) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            continue;
        }
        auto update = bot->queue.Pop(senderId);
        
        Logger::debug << "processing update..." << std::endl;
            
        // indicates if the current update has already been
        // successfully processed by a command set
        bool found = false;
        
        if(bot->defaultCommandSet.Process(update)) {
            Logger::debug << "found match in default commandset" << std::endl;
            found = true;
        }
        
        for(auto &cs : bot->commandSets) {
            // if the update has not been successfully processed
            // do so
            if(!found) {
                if(cs->Process(update)) {
                    Logger::debug << "found match in commandsets" << std::endl;
                    // if it was successful set the found flag
                    found = true;
                }
            } else {
                // reset lastCommands of other commandSets
                cs->ResetLastCommand();
            }
        }
        
        if(!found) {
            Logger::debug << "no match found" << std::endl;
        }
        
    }
}

TelegramBot::~TelegramBot()
{
    for(unsigned int i = 0; i < commandSets.size(); i++) {
        delete commandSets[i];
    }
    for(auto &e : dataStore) {
        delete e.second;
    }
    for(auto &t : processingThreads) {
        t.second->join();
        delete t.second;
    }
}

void TelegramBot::Start(bool inBackground)
{
    if(inBackground) {
        daemon = std::thread([this] { Start(false); });
        return;
    }
    
    Logger::info << "Bot started" << std::endl;
    
    (*this)["running"] = true;
    
    while ((*this)["running"].asBool()) {
        GetUpdates();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool TelegramBot::CheckResponse(curl::Response &response, const std::string &methodName)
{
    auto json = Serializable::Deserialize(std::string(response.content.begin(), response.content.end()));
    if (json == nullptr) {
        std::string error = "Response body is no valid JSON";
        if(methodName != "") {
            error += ". " + methodName + " failed";
        }
        throw TelegramException(error, response);
    }
    
    bool ok = (*json)["ok"].asBool();
    if(ok) {
        
    } else {
        std::string description = (*json)["description"].asString();
        if(methodName != "") {
            Logger::warn << "Call to " << methodName << " failed" << std::endl;
        } else {
            Logger::warn << "HTTP Request failed" << std::endl;
        }
        Logger::warn << "Reason: " << description << std::endl;
    }
    
    return ok;
}

void TelegramBot::SendMessage(params::SendMessageParams &params)
{
    curl::RequestParams requestParams(GetApiUrl("sendMessage"), curl::Method::POST);
    requestParams.SetParams(params);
    requestParams.SetHeaders(GetDefaultHeader());
    curl::Response response = session.DoRequest(requestParams);
    
    CheckResponse(response, "SendMessage"); 
}

void TelegramBot::SendMessage(params::SendMessageParams &&params)
{
    SendMessage(params);
}
