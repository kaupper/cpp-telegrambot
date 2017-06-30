#include "TelegramBot.h"

using namespace telegram;
using namespace telegram::request;
using namespace telegram::structures;
using namespace telegram::util;
using namespace curlsession;
using namespace jsonserializer;


std::string TelegramBot::GetApiUrl(const std::string &method)
{
    return "https://api.telegram.org/bot" + GetString("token") + "/" + method;
}

void TelegramBot::RegisterCommand(const std::string &name, Command::FunctionType directFunction)
{
    defaultCommandSet.RegisterCommand(this, name, directFunction);
}


TelegramBot::TelegramBot(const std::string &token,
                         const std::string &configPath,
                         const std::string &filePath)
    : defaultCommandSet(this)
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
    std::string cfgPath = configPath;
    std::string fPath = filePath;
    
    if (cfgPath.empty()) {
        cfgPath = "./";
    }
    
    if (fPath.empty()) {
        fPath = "./";
    }
    
    // add trailing slashes if there are not any
    if (cfgPath.back() != '/') {
        cfgPath += '/';
    }
    
    if (fPath.back() != '/') {
        fPath += '/';
    }
    
    Set(token, "token");
    Request request = RequestBuilder(GetApiUrl("getMe"), Method::POST)
                      .SetHeaders(GetDefaultHeader())
                      .GetRequest();
    Response response = session.DoRequest(request);
    std::string botName;
    
    try {
        json j = json::parse(response.content);
        botName = ToString(j["result"]["username"]);
        Set(botName, "botName");
        Logger::debug << "botName: " << botName << std::endl;
    } catch (const parse_error &ex) {
        throw TelegramException("Failed to get name for token " + token, response);
    }
    
    JSONPersister::SetFileName(configPath + botName + ".data");
    
    try {
        Load();
        Logger::info << "Loaded data file for bot \"" << botName << "\"" << std::endl;
    } catch (const std::runtime_error &loadEx) {
        Logger::warn << "Failed to load data file for bot \"" << botName << "\"" << std::endl;
        Logger::warn << "Reason: " << loadEx.what() << std::endl;
        
        try {
            Save();
            Logger::info << "Created new data file" << std::endl;
        } catch (const std::runtime_error &saveEx) {
            std::string error = "Failed to create new data file\n";
            error += std::string("Reason: ") + saveEx.what();
            throw TelegramException(error);
        }
    }
    
    // we need to set these strings here to not override it with the load above
    Set(filePath, "filePath");
    Set(token, "token");
    Set(false, "background");
    Save();
}

void TelegramBot::GetUpdates()
{
    json params;
    
    if (!Get("offset").is_null()) {
        params = {
            {"offset", std::stoi(GetString("offset"))}
        };
    }
    
    Request request = RequestBuilder(GetApiUrl("getUpdates"), Method::POST)
                      .SetHeaders(GetDefaultHeader())
                      .SetJSONParams(params)
                      .GetRequest();
    Response response = session.DoRequest(request);
    
    if (!CheckResponse(response, "GetUpdates")) {
        return;
    }
    
    auto j = json::parse(response.content);
    std::vector<Update> updates = Converter::FromJSON<std::vector<Update>>(j["result"]);
    
    for (auto &u : updates) {
        User user;
        
        if (u.HasMessage()) {
            user = u.GetMessage()->GetFromValue();
        } else if (u.HasEditedMessage()) {
            user = u.GetEditedMessage()->GetFromValue();
        } else if (u.HasInlineQuery()) {
            user = u.GetInlineQuery()->GetFromValue();
        } else if (u.HasChosenInlineResult()) {
            user = u.GetChosenInlineResult()->GetFromValue();
        } else if (u.HasCallbackQuery()) {
            user = u.GetCallbackQuery()->GetFromValue();
        }
        
        std::string senderId = std::to_string(user.GetIdValue());
        queue.Push(senderId, u);
        
        if (processingThreads.find(senderId) == processingThreads.end()) {
            processingThreads[senderId] = new std::thread(TelegramBot::Process, this, senderId);
        }
        
        auto offset = Get("offset");
        
        if (offset.is_null() || u.GetUpdateIdValue() >= offset.get<int>()) {
            Set(u.GetUpdateIdValue() + 1, "offset");
        }
    }
    
    Save();
}

void TelegramBot::Process(TelegramBot *bot, std::string chatId)
{
    while (bot->Get("running").get<bool>()) {
        if (!bot->queue.Available(chatId)) {
            std::this_thread::yield();
            continue;
        }
        
        auto update = bot->queue.Pop(chatId);
        Logger::debug << "processing update..." << std::endl;
        // indicates if the current update has already been
        // successfully processed by a command set
        bool found = false;
        
        for (auto gc : bot->generalCallbacks) {
            gc->Call(update);
        }
        
        if (bot->defaultCommandSet.Process(update)) {
            Logger::debug << "found match in default commandset" << std::endl;
            found = true;
        }
        
        for (auto cs : bot->commandSets) {
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
    
    startMutex.lock();
    startMutex.unlock();
    Set(false, "running");
    
    for (auto &t : processingThreads) {
        t.second->join();
        delete t.second;
    }
    
    if (Get("background").get<bool>()) {
        daemon.join();
    }
}


void TelegramBot::Start(bool inBackground)
{
    if (inBackground) {
        startMutex.lock();
        Set(true, "background");
        daemon = std::thread([this] { this->Start(false); });
        return;
    }
    
    startMutex.try_lock();
    Set(true, "running");
    startMutex.unlock();
    Logger::info << "Bot started" << std::endl;
    auto delay = std::chrono::milliseconds(500);
    
    while (Get("running").get<bool>()) {
        GetUpdates();
        std::this_thread::sleep_for(delay);
    }
    
    // get updates once more to mark previous ones as read
    GetUpdates();
}

bool TelegramBot::CheckResponse(const Response &response, const std::string &methodName)
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
        Logger::debug << response.content << std::endl;
        return false;
    }
    
    bool ok = j["ok"].get<bool>();
    
    if (!ok) {
        std::string description = ToString(j["description"]);
        
        if (methodName != "") {
            Logger::warn << "Call to " << methodName << " failed" << std::endl;
        } else {
            Logger::warn << "HTTP Request failed" << std::endl;
        }
        
        Logger::warn << "Reason: " << description << std::endl;
        Logger::warn << "Code: " << ToString(j["error_code"]) << std::endl;
        Logger::warn << "Result: " << response.content << std::endl;
    }
    
    return ok;
}

void TelegramBot::DownloadFile(const std::string &fileId)
{
    std::string url = "https://api.telegram.org/file/bot" + GetString("token") + "/";
    auto file = GetFile({ fileId });
    auto response = session.DoRequest(RequestBuilder(url + file.GetFilePathValue()).GetRequest());
    
    if (response.code == 200) {
        std::string extension = file.GetFilePathValue();
        extension = extension.substr(extension.find("."));
        std::string fileName = file.GetFileIdValue() + extension;
        std::string path = GetString("filePath");
        std::ofstream fsFile(path + fileName);
        
        if (!fsFile.is_open()) {
            throw TelegramException("Failed to create file!");
        }
        
        fsFile << response.content;
        fsFile.close();
        Logger::info << "Successfully wrote file " << path << fileName << std::endl;
    } else {
        throw TelegramException("Failed to download file!", response);
    }
}

void TelegramBot::Wait()
{
    daemon.join();
}