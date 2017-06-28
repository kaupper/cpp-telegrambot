#include "TelegramBot.h"

using namespace telegram;
using namespace telegram::request;
using namespace telegram::structures;
using namespace jsonserializer;

const std::vector<curl::Header> TelegramBot::defaultHeader = {{"Content-Type", "application/json"}};

void TelegramBot::Setup(std::string token, std::string configPath,
                        std::string filePath)
{
    Logger::info <<
                 R"( ____  ____  __    ____  ___  ____   __   _  _  ____   __  ____)" <<
                 std::endl;
    Logger::info <<
                 R"((_  _)(  __)(  )  (  __)/ __)(  _ \ / _\ ( \/ )(  _ \ /  \(_  _))" <<
                 std::endl;
    Logger::info <<
                 R"(  )(   ) _) / (_/\ ) _)( (_ \ )   //    \/ \/ \ ) _ ((  O ) )()" <<
                 std::endl;
    Logger::info <<
                 R"( (__) (____)\____/(____)\___/(__\_)\_/\_/\_)(_/(____/ \__/ (__))" <<
                 std::endl;
    Logger::info << R"( ____  _  _    __ _   __   _  _  ____  ____  ____  ____)" <<
                 std::endl;
    Logger::info << R"((  _ \( \/ )  (  / ) / _\ / )( \(  _ \(  _ \(  __)(  _ \)" <<
                 std::endl;
    Logger::info << R"( ) _ ( )  /    )  ( /    \) \/ ( ) __/ ) __/ ) _)  )   /)" <<
                 std::endl;
    Logger::info << R"((____/(__/    (__\_)\_/\_/\____/(__)  (__)  (____)(__\_))" <<
                 std::endl;
    Logger::info << std::endl;
    
    // add trailing slashes if there are not any
    if (configPath[configPath.size() - 1] != '/') {
        configPath += '/';
    }
    
    if (filePath[filePath.size() - 1] != '/') {
        filePath += '/';
    }
    
    (*this)["token"] = token;
    curl::RequestParams requestParams(GetApiUrl("getMe"), curl::Method::POST);
    requestParams.SetHeaders(GetDefaultHeader());
    curl::Response response = session.DoRequest(requestParams);
    
    try {
        json j = json::parse(response.content);
        std::string botName = to_string(j["result"]["username"]);
        Logger::debug << "botName: " << botName << std::endl;
        (*this)["botName"] = botName;
    } catch (const parse_error &ex) {
        throw TelegramException("Failed to get name for token " + token, response);
    }
    
    // TODO!
    // PersistingService::SetFileName(configPath + botName + ".data");
    /*
    try {
        PersistingService::Load();
        Logger::info << "Loaded data file for bot \"" << botName << "\"" << std::endl;
    } catch (const SerializableException &loadEx) {
        Logger::warn << "Failed to load data file for bot \"" << botName << "\"" << std::endl;
        Logger::warn << "Reason: " << loadEx.what() << std::endl;
    
        try {
            PersistingService::Save();
            Logger::info << "Created new data file" << std::endl;
        } catch (const jsonserializer::SerializableException &saveEx) {
            std::string error = "Failed to create new data file\n";
            error += std::string("Reason: ") + saveEx.what();
            throw TelegramException(error);
        }
    }
    */
    // we need to set these strings here to not override it with the load above
    (*this)["filePath"] = filePath;
    (*this)["token"] = token;
    (*this)["background"] = false;
    // PersistingService::Save();
}

void TelegramBot::GetUpdates()
{
    std::map<std::string, std::string> params = {};
    
    if (!(*this)["offset"].is_null()) {
        params = {
            {"offset", to_string((*this)["offset"])}
        };
    }
    
    curl::RequestParams requestParams(GetApiUrl("getUpdates"), curl::Method::POST);
    requestParams.SetHeaders(GetDefaultHeader());
    requestParams.SetParams(params);
    requestParams.FollowRedirects(false);
    curl::Response response = session.DoRequest(requestParams);
    
    if (!CheckResponse(response, "GetUpdates")) {
        return;
    }
    
    auto j = json::parse(response.content);
    std::vector<Update> updates = Converter::FromJSON<std::vector<Update>>
                                  (j["result"]);
                                  
    for (auto &u : updates) {
        User user;
        
        if (u.message != nullptr) {
            user = u.message->GetFromValue();
        } else if (u.editedMessage != nullptr) {
            user = u.editedMessage->GetFromValue();
        } else if (u.inlineQuery != nullptr) {
            user = u.inlineQuery->GetFromValue();
        } else if (u.chosenInlineResult != nullptr) {
            user = u.chosenInlineResult->GetFromValue();
        } else if (u.callbackQuery != nullptr) {
            user = u.callbackQuery->GetFromValue();
        }
        
        std::string senderId = std::to_string(user.GetIdValue());
        queue.Push(senderId, u);
        
        if (processingThreads.find(senderId) == processingThreads.end()) {
            processingThreads[senderId] = new std::thread(TelegramBot::Process, this,
                    senderId);
        }
        
        auto &offset = (*this)["offset"];
        
        if (offset.is_null() || u.GetUpdateIdValue() >= offset.get<int>()) {
            offset = u.GetUpdateIdValue() + 1;
        }
    }
    
    // Save();
}

void TelegramBot::Process(TelegramBot *bot, std::string chatId)
{
    while ((*bot)["running"].get<bool>()) {
        if (!bot->queue.Available(chatId)) {
            std::this_thread::yield();
            continue;
        }
        
        auto update = bot->queue.Pop(chatId);
        Logger::debug << "processing update..." << std::endl;
        // indicates if the current update has already been
        // successfully processed by a command set
        bool found = false;
        
        for (auto &gc : bot->generalCallbacks) {
            gc->Call(update);
        }
        
        if (bot->defaultCommandSet.Process(update)) {
            Logger::debug << "found match in default commandset" << std::endl;
            found = true;
        }
        
        for (auto &cs : bot->commandSets) {
            // if the update has not been successfully processed
            // do so
            if (!found) {
                if (cs->Process(update)) {
                    Logger::debug << "found match in commandsets" << std::endl;
                    // if it was successful set the found flag
                    found = true;
                }
            } else {
                // reset lastCommands of other commandSets
                cs->ResetLastCommand();
            }
        }
        
        if (!found) {
            Logger::debug << "no match found" << std::endl;
        }
    }
}

TelegramBot::~TelegramBot()
{
    for (auto e : commandSets) {
        delete e;
    }
    
    for (auto e : generalCallbacks) {
        delete e;
    }
    
    for (auto &e : dataStore) {
        delete e.second;
    }
    
    startMutex.lock();
    startMutex.unlock();
    (*this)["running"] = false;
    
    for (auto &t : processingThreads) {
        t.second->join();
        delete t.second;
    }
    
    if ((*this)["background"].get<bool>()) {
        daemon.join();
    }
}


void TelegramBot::Start(bool inBackground)
{
    if (inBackground) {
        startMutex.lock();
        (*this)["background"] = true;
        daemon = std::thread([this] { this->Start(false); });
        return;
    }
    
    startMutex.try_lock();
    (*this)["running"] = true;
    startMutex.unlock();
    Logger::info << "Bot started" << std::endl;
    auto delay = std::chrono::milliseconds(500);
    
    while ((*this)["running"].get<bool>()) {
        GetUpdates();
        std::this_thread::sleep_for(delay);
    }
}

bool TelegramBot::CheckResponse(curl::Response &response,
                                const std::string &methodName)
{
    json j;
    
    try {
        j = json::parse(response.content);
    } catch (const parse_error &ex) {
        std::string error = "Response body is no valid JSON";
        
        if (methodName != "") {
            error += ". " + methodName + " failed";
        }
        
        Logger::warn << error << std::endl;
        return false;
    }
    
    bool ok = j["ok"].get<bool>();
    
    if (!ok) {
        std::string description = to_string(j["description"]);
        
        if (methodName != "") {
            Logger::warn << "Call to " << methodName << " failed" << std::endl;
        } else {
            Logger::warn << "HTTP Request failed" << std::endl;
        }
        
        Logger::warn << "Reason: " << description << std::endl;
        Logger::warn << "Code: " << to_string(j["error_code"]) << std::endl;
        Logger::warn << "Result: " << std::string(response.content.begin(),
                     response.content.end()) << std::endl;
    }
    
    return ok;
}

void TelegramBot::DownloadFile(const std::string &fileId)
{
    std::string url = "https://api.telegram.org/file/bot" +
                      to_string((*this)["token"]) + "/";
    auto file = GetFile({ fileId });
    auto response = session.DoRequest({ url + file.GetFilePathValue() });
    std::string statusLine = response.GetHeader("statusLine");
    statusLine = statusLine.substr(statusLine.find(" ") + 1);
    int statusCode = std::stoi(statusLine.substr(0, statusLine.find(" ")));
    
    if (statusCode == 200) {
        std::string extension = file.GetFilePathValue();
        extension = extension.substr(extension.find("."));
        std::string fileName = file.GetFileIdValue() + extension;
        std::string path = to_string((*this)["filePath"]);
        std::ofstream fsFile(path + fileName);
        
        if (!fsFile.is_open()) {
            throw TelegramException("Failed to create file!");
        }
        
        for (auto &c : response.content) {
            fsFile.put(c);
        }
        
        fsFile.close();
        Logger::info << "Successfully wrote file " << path << fileName << std::endl;
    } else {
        throw TelegramException("Failed to download file!", response);
    }
}
