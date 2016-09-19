#ifndef TELEGRAM_BOT_H_
#define TELEGRAM_BOT_H_

#include <thread>
#include <map>
#include <vector>

#include "UpdateQueue.h"
#include "CommandSet.h"
#include "structures/StructConverter.h"
#include "TelegramException.h"
#include "utils/Logger.h"
#include "utils/Storage.h"
#include "utils/curl/CurlSession.h"
#include "utils/json/PersistingService.h"

namespace telegram
{
    enum class ParseMode
    {
        NORMAL = 0,
        MARKDOWN = 1,
        HTML = 2
    };
    
    namespace params
    {
        class SendMessageParams;
    }
    
    class TelegramBot : public PersistingService
    {
    private:
        template <typename T>
        auto & operator[](T &&key) { return Json::Value::operator[](key); }
    
        std::map<std::string, Storage *> dataStore;
    
        curl::CurlSession session;
        std::thread daemon;
        
        UpdateQueue queue;
        std::map<std::string, std::thread *> processingThreads;
        
        static void Process(TelegramBot *bot, std::string);
        
        CommandSet defaultCommandSet;
        std::vector<CommandSet *> commandSets;
        
        std::string GetApiUrl(const std::string &method) { return "https://api.telegram.org/bot" + (*this)["token"].asString() + "/" + method ; }
        std::map<std::string, std::string> &GetDefaultHeader() { static std::map<std::string, std::string> defaultHeader = {{"Content-Type", "application/json"}}; return defaultHeader; }
        
        void Setup(const std::string &token, const std::string &path);
        void GetUpdates();

        bool CheckResponse(curl::Response &response, const std::string &methodName);
        
        
        std::mutex jsonMutex;
        
        Json::Value & _GetSynchronized(Json::Value &value) { return value; }
        
        template <typename T, typename... U>
        Json::Value & _GetSynchronized(Json::Value &value, T &&selector, U &&... selectors)
        {
            jsonMutex.lock();
            auto &v = value[selector];
            jsonMutex.unlock();
            return _GetSynchronized(v, selectors...);
        }
        
        
    public:  
        template <typename T, typename... U>
        Json::Value & Get(T &&selector, U &&... selectors) 
        {
            return _GetSynchronized(*((Json::Value *)this), selector, selectors...);
        }  
        
        // public constructor used by users
        TelegramBot(std::string token, std::string path = "./") : PersistingService(),
            defaultCommandSet(*this) { Setup(token, path); }
            
        
        virtual ~TelegramBot();
        
        std::map<std::string, Storage *> & GetDataStore() { return dataStore; }
        
        template <typename T, typename = typename std::enable_if<std::is_base_of<CommandSet, T>::value>::type> 
        T &RegisterCommandSet() 
        {
            commandSets.push_back(new T(*this));
            T * tmp = (T *) commandSets.back();
            tmp->Setup();
            return (T &) *tmp;
        }
        
        template <typename T, typename = typename std::enable_if<std::is_base_of<Command, T>::value>::type> 
        T &RegisterCommand(std::string name) 
        {            
            return defaultCommandSet.RegisterCommand<T>(*this, name);
        }
        
        void SendMessage(params::SendMessageParams &params);
        void SendMessage(params::SendMessageParams &&params);
        
        void Start(bool inBackground = false);
        void Wait() { daemon.join(); }
    };
}

#endif // TELEGRAM_BOT_H_
