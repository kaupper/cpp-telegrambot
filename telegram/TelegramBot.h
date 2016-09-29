#ifndef TELEGRAM_BOT_H_
#define TELEGRAM_BOT_H_

#include <thread>
#include <map>
#include <vector>
#include <sys/stat.h>

#include "jsonserializer/StructConverter.h"
#include "jsonserializer/PersistingService.h"
#include "curlsession/CurlSession.h"

#include "TelegramException.h"
#include "Logger.h"
#include "Storage.h"
#include "UpdateQueue.h"
#include "CommandSet.h"
#include "GeneralCallback.h"

#include "params.h"

namespace telegram
{
    enum class ParseMode
    {
        NORMAL = 0,
        MARKDOWN = 1,
        HTML = 2
    };
   
    template <typename T> const bool isMarkup = std::is_same<T, telegram::structures::InlineKeyboardMarkup>::value ||
                                                std::is_same<T, telegram::structures::ReplyKeyboardMarkup>::value ||
                                                std::is_same<T, telegram::structures::ReplyKeyboardHide>::value ||
                                                std::is_same<T, telegram::structures::ForceReply>::value;
    
    class TelegramBot : public jsonserializer::PersistingService
    {
    private:
        template <typename T>
        auto & operator[](T &&key) { return Json::Value::operator[](key); }
    
        std::map<std::string, Storage *> dataStore;
        curl::CurlSession session;
        std::thread daemon;
        UpdateQueue queue;
        std::map<std::string, std::thread *> processingThreads;
        CommandSet defaultCommandSet;
        std::vector<CommandSet *> commandSets;
        std::vector<GeneralCallback *> generalCallbacks;
        std::mutex jsonMutex;
        std::mutex startMutex;
        
        static const std::map<std::string, std::string> defaultHeader;
        static void Process(TelegramBot *bot, std::string);
        
        std::string GetApiUrl(const std::string &method) { return "https://api.telegram.org/bot" + (*this)["token"].asString() + "/" + method ; }
        std::map<std::string, std::string> GetDefaultHeader() { return defaultHeader; }
        
        void Setup(std::string token, std::string configPath, std::string filePath);
        void GetUpdates();
        bool CheckResponse(curl::Response &response, const std::string &methodName);
        
        
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
            return _GetSynchronized(*((Json::Value *) this), selector, selectors...);
        }  
        
        // public constructor used by users
        TelegramBot(const std::string &token, const std::string &configPath = "./", const std::string &filePath = "./") : PersistingService(),
            defaultCommandSet(*this) { Setup(token, configPath, filePath); }
            
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
        T &RegisterCommand(const std::string &name) 
        {            
            return defaultCommandSet.RegisterCommand<T>(*this, name);
        }
        
        template <typename T, typename = typename std::enable_if<std::is_base_of<GeneralCallback, T>::value>::type> 
        T &RegisterGeneralCallback() 
        {            
            generalCallbacks.push_back(new T(*this));
            return (T &) *(generalCallbacks.back());
        }
        
        void Start(bool inBackground = false);
        void Wait() { daemon.join(); }
        
        
        
        void DownloadFile(const std::string &);
        
        // Bot API methods
        telegram::structures::Message SendMessage(const params::SendMessageParams &params);
        telegram::structures::Message ForwardMessage(const params::ForwardMessageParams &params);
        telegram::structures::Message SendPhoto(const params::SendPhotoParams &params);
        telegram::structures::Message SendAudio(const params::SendAudioParams &params);
        telegram::structures::Message SendDocument(const params::SendDocumentParams &params);
        telegram::structures::Message SendSticker(const params::SendStickerParams &params);
        telegram::structures::Message SendVideo(const params::SendVideoParams &params);
        telegram::structures::Message SendVoice(const params::SendVoiceParams &params);
        telegram::structures::Message SendLocation(const params::SendLocationParams &params);
        telegram::structures::Message SendVenue(const params::SendVenueParams &params);
        telegram::structures::Message SendContact(const params::SendContactParams &params);
        bool SendChatAction(const params::SendChatActionParams &params);
        telegram::structures::UserProfilePhotos GetUserProfilePhotos(const params::GetUserProfilePhotosParams &params);
        telegram::structures::File GetFile(const params::GetFileParams &params);
        bool KickChatMember(const params::KickChatMemberParams &params);
        bool LeaveChat(const params::LeaveChatParams &params);
        bool UnbanChatMember(const params::UnbanChatMemberParams &params);
        telegram::structures::Chat GetChat(const params::GetChatParams &params);
        std::vector<telegram::structures::ChatMember> GetChatAdministrators(const params::GetChatAdministratorsParams &params);
        int GetChatMembersCount(const params::GetChatMembersCountParams &params);
        telegram::structures::ChatMember GetChatMember(const params::GetChatMemberParams &params);
        bool AnswerCallbackQuery(const params::AnswerCallbackQueryParams &params);
        telegram::structures::Message EditMessageText(const params::EditMessageTextParams &params);
        telegram::structures::Message EditMessageCaption(const params::EditMessageCaptionParams &params);
        telegram::structures::Message EditMessageReplyMarkup(const params::EditMessageReplyMarkupParams &params);
        
        // methods for inline messages
        bool EditInlineMessageText(const params::EditMessageTextParams &params);
        bool EditInlineMessageCaption(const params::EditMessageCaptionParams &params);
        bool EditInlineMessageReplyMarkup(const params::EditMessageReplyMarkupParams &params);
        bool AnswerInlineQuery(const params::AnswerInlineQueryParams &params);
        
    private:
        // utility methods
        curl::Response DoMethod(const jsonserializer::Serializable &json, const std::string &method, bool multipart = false, const std::string &fileKey = "");
        telegram::structures::Message SendFile(const Serializable &params, 
                                               const std::string &method, 
                                               const std::function<std::string(telegram::structures::Message)> &idExtractor);
        
        void CacheFile(const std::string &typeString, const std::string &path, const std::string &id);
        bool IsCached(const std::string &typeString, const std::string &path);
        std::string GetCached(const std::string &typeString, const std::string &path);
    };
}

#endif // TELEGRAM_BOT_H_
