#ifndef TELEGRAM_BOT_H_
#define TELEGRAM_BOT_H_

#include <fstream>
#include <thread>
#include <map>
#include <vector>
#include <sys/stat.h>

#include "jsonserializer/StructConverter.h"
#include "jsonserializer/RequestConverter.h"

// #include "jsonserializer/PersistingService.h"
#include "curlsession/CurlSession.h"

#include "TelegramException.h"
#include "Logger.h"
#include "Storage.h"
#include "UpdateQueue.h"
#include "CommandSet.h"
#include "GeneralCallback.h"


namespace telegram
{
    enum class ParseMode {
        NORMAL = 0,
        MARKDOWN = 1,
        HTML = 2
    };
    
    template <typename T> const bool isMarkup =
        std::is_same<T, telegram::structures::InlineKeyboardMarkup>::value ||
        std::is_same<T, telegram::structures::ReplyKeyboardMarkup>::value ||
        std::is_same<T, telegram::structures::ReplyKeyboardHide>::value ||
        std::is_same<T, telegram::structures::ForceReply>::value;
        
    class TelegramBot : public json // : public jsonserializer::PersistingService
    {
        private:
            template <typename T>
            auto &operator[](T &&key)
            {
                return json::operator[](key);
            }
            
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
            
            static const std::vector<curl::Header> defaultHeader;
            static void Process(TelegramBot *bot, std::string);
            
            std::string GetApiUrl(const std::string &method)
            {
                return "https://api.telegram.org/bot" + at("token").get<std::string>() + "/" +
                       method ;
            }
            std::vector<curl::Header> GetDefaultHeader()
            {
                return defaultHeader;
            }
            
            void Setup(std::string token, std::string configPath, std::string filePath);
            void GetUpdates();
            bool CheckResponse(curl::Response &response, const std::string &methodName);
            
            
            json &_GetSynchronized(json &value)
            {
                return value;
            }
            
            template <typename T, typename... U>
            json &_GetSynchronized(json &value, T &&selector, U &&... selectors)
            {
                jsonMutex.lock();
                auto &v = value[selector];
                jsonMutex.unlock();
                return _GetSynchronized(v, selectors...);
            }
            
            
        public:
            template <typename T, typename... U>
            json &Get(T &&selector, U &&... selectors)
            {
                return _GetSynchronized(*(static_cast<json *>(this)), selector, selectors...);
            }
            
            // public constructor used by users
            TelegramBot(const std::string &token, const std::string &configPath = "./",
                        const std::string &filePath = "./")
                : defaultCommandSet(*this)
            {
                Setup(token, configPath, filePath);
            }
            
            virtual ~TelegramBot();
            
            std::map<std::string, Storage *> &GetDataStore()
            {
                return dataStore;
            }
            
            template <typename T, typename = typename std::enable_if<std::is_base_of<CommandSet, T>::value>::type>
            T & RegisterCommandSet()
            {
                commandSets.push_back(new T(*this));
                T *tmp = (T *) commandSets.back();
                tmp->Setup();
                return (T &) * tmp;
            }
            
            template <typename T, typename = typename std::enable_if<std::is_base_of<Command, T>::value>::type>
            T & RegisterCommand(const std::string &name)
            {
                return defaultCommandSet.RegisterCommand<T>(*this, name);
            }
            
            template <typename T, typename = typename std::enable_if<std::is_base_of<GeneralCallback, T>::value>::type>
            T & RegisterGeneralCallback()
            {
                generalCallbacks.push_back(new T(*this));
                return (T &) * (generalCallbacks.back());
            }
            
            void Start(bool inBackground = false);
            void Wait()
            {
                daemon.join();
            }
            
            
            
            void DownloadFile(const std::string &);
            
            // Bot API methods
            telegram::structures::Message SendMessage(const request::SendMessageParams
                    &params);
            telegram::structures::Message ForwardMessage(const request::ForwardMessageParams
                    &params);
            telegram::structures::Message SendPhoto(const request::SendPhotoParams &params);
            telegram::structures::Message SendAudio(const request::SendAudioParams &params);
            telegram::structures::Message SendDocument(const request::SendDocumentParams
                    &params);
            telegram::structures::Message SendSticker(const request::SendStickerParams
                    &params);
            telegram::structures::Message SendVideo(const request::SendVideoParams &params);
            telegram::structures::Message SendVoice(const request::SendVoiceParams &params);
            telegram::structures::Message SendLocation(const request::SendLocationParams
                    &params);
            telegram::structures::Message SendVenue(const request::SendVenueParams &params);
            telegram::structures::Message SendContact(const request::SendContactParams
                    &params);
            bool SendChatAction(const request::SendChatActionParams &params);
            telegram::structures::UserProfilePhotos GetUserProfilePhotos(
                const request::GetUserProfilePhotosParams &params);
            telegram::structures::File GetFile(const request::GetFileParams &params);
            bool KickChatMember(const request::KickChatMemberParams &params);
            bool LeaveChat(const request::LeaveChatParams &params);
            bool UnbanChatMember(const request::UnbanChatMemberParams &params);
            telegram::structures::Chat GetChat(const request::GetChatParams &params);
            std::vector<telegram::structures::ChatMember> GetChatAdministrators(
                const request::GetChatAdministratorsParams &params);
            int GetChatMembersCount(const request::GetChatMembersCountParams &params);
            telegram::structures::ChatMember GetChatMember(const
                    request::GetChatMemberParams &params);
            bool AnswerCallbackQuery(const request::AnswerCallbackQueryParams &params);
            telegram::structures::Message EditMessageText(const
                    request::EditMessageTextParams &params);
            telegram::structures::Message EditMessageCaption(const
                    request::EditMessageCaptionParams &params);
            telegram::structures::Message EditMessageReplyMarkup(const
                    request::EditMessageReplyMarkupParams &params);
                    
            // methods for inline messages
            bool EditInlineMessageText(const request::EditMessageTextParams &params);
            bool EditInlineMessageCaption(const request::EditMessageCaptionParams &params);
            bool EditInlineMessageReplyMarkup(const request::EditMessageReplyMarkupParams
                                              &params);
            bool AnswerInlineQuery(const request::AnswerInlineQueryParams &params);
            
        private:
            // utility methods
            curl::Response DoMethod(const json &json, const std::string &method,
                                    bool multipart = false, const std::string &fileKey = "");
            telegram::structures::Message SendFile(const json &params,
                                                   const std::string &method,
                                                   const std::function<std::string(telegram::structures::Message)> &idExtractor);
                                                   
            void CacheFile(const std::string &typeString, const std::string &path,
                           const std::string &id);
            bool IsCached(const std::string &typeString, const std::string &path);
            std::string GetCached(const std::string &typeString, const std::string &path);
    };
}

inline std::string to_string(const json &j)
{
    switch (j.type()) {
        case json::value_t::null:
            return "null";
            
        case json::value_t::boolean:
            return std::to_string(j.get<bool>());
            
        case json::value_t::number_integer:
            return std::to_string(j.get<long>());
            
        case json::value_t::number_float:
            return std::to_string(j.get<double>());
            
        case json::value_t::string:
            return j.get<std::string>();
            
        case json::value_t::object:
        case json::value_t::array:
        default:
            telegram::Logger::error << "Object, array or something else" << std::endl;;
    }
}

#endif // TELEGRAM_BOT_H_
