#ifndef TELEGRAM_BOT_H_
#define TELEGRAM_BOT_H_

#include <fstream>
#include <thread>
#include <map>
#include <vector>
#include <sys/stat.h>

#include "jsonserializer/Generated.h"

// #include "jsonserializer/PersistingService.h"
#include "curlsession/CurlSession.h"

#include "TelegramException.h"
#include "Logger.h"
#include "UpdateQueue.h"
#include "CommandSet.h"
#include "GeneralCallback.h"
#include "JSONPersister.h"
#include "Util.h"
#include "DataStore.h"


namespace telegram
{
    class TelegramBot : public util::JSONPersister, public util::DataStore
    {
        private:
            curlsession::CurlSession session;

            std::mutex startMutex;
            std::thread daemon;
            std::map<std::string, std::thread *> processingThreads;

            UpdateQueue queue;

            CommandSet defaultCommandSet;
            std::vector<CommandSet *> commandSets;
            std::vector<GeneralCallback *> generalCallbacks;

            // update processing function
            static void Process(TelegramBot *bot, std::string);


            std::string GetApiUrl(const std::string &method);

            void GetUpdates();
            bool CheckResponse(const curlsession::Response &response,
                               const std::string &methodName);

        public:
            // public constructor used by users
            TelegramBot(const std::string &token,
                        const std::string &configPath = "./",
                        const std::string &filePath = "./");
            ~TelegramBot();


            template <typename T, typename = typename std::enable_if<std::is_base_of<CommandSet, T>::value>::type>
            T & RegisterCommandSet();

            template <typename T, typename = typename std::enable_if<std::is_base_of<Command, T>::value>::type>
            T & RegisterCommand(const std::string &name);

            void RegisterCommand(const std::string &name, Command::FunctionType directFunction);

            template <typename T, typename = typename std::enable_if<std::is_base_of<GeneralCallback, T>::value>::type>
            T & RegisterGeneralCallback();

            void Start(bool inBackground = false);
            void Wait();


        public:
            void DownloadFile(const std::string &);

            // Bot API methods
            structures::Message SendMessage(const request::SendMessageParams &params);
            structures::Message ForwardMessage(const request::ForwardMessageParams &params);
            structures::Message SendPhoto(const request::SendPhotoParams &params);
            structures::Message SendAudio(const request::SendAudioParams &params);
            structures::Message SendDocument(const request::SendDocumentParams &params);
            structures::Message SendSticker(const request::SendStickerParams &params);
            structures::Message SendVideo(const request::SendVideoParams &params);
            structures::Message SendVoice(const request::SendVoiceParams &params);
            structures::Message SendLocation(const request::SendLocationParams &params);
            structures::Message SendVenue(const request::SendVenueParams &params);
            structures::Message SendContact(const request::SendContactParams &params);
            bool SendChatAction(const request::SendChatActionParams &params);
            structures::UserProfilePhotos GetUserProfilePhotos(
                        const request::GetUserProfilePhotosParams &params);
            structures::File GetFile(const request::GetFileParams &params);
            bool KickChatMember(const request::KickChatMemberParams &params);
            bool LeaveChat(const request::LeaveChatParams &params);
            bool UnbanChatMember(const request::UnbanChatMemberParams &params);
            telegram::structures::Chat GetChat(const request::GetChatParams &params);
            std::vector<structures::ChatMember> GetChatAdministrators(
                        const request::GetChatAdministratorsParams &params);
            int GetChatMembersCount(const request::GetChatMembersCountParams &params);
            structures::ChatMember GetChatMember(const request::GetChatMemberParams &params);
            bool AnswerCallbackQuery(const request::AnswerCallbackQueryParams &params);
            structures::Message EditMessageText(const request::EditMessageTextParams &params);
            structures::Message EditMessageCaption(const request::EditMessageCaptionParams &params);
            structures::Message EditMessageReplyMarkup(const request::EditMessageReplyMarkupParams &params);

            // methods for inline messages
            bool EditInlineMessageText(const request::EditMessageTextParams &params);
            bool EditInlineMessageCaption(const request::EditMessageCaptionParams &params);
            bool EditInlineMessageReplyMarkup(const request::EditMessageReplyMarkupParams &params);
            bool AnswerInlineQuery(const request::AnswerInlineQueryParams &params);

        private:
            // utility methods
            curlsession::Response DoMethod(const json &json, const std::string &method,
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

#include "TelegramBot_impl.h"

#endif // TELEGRAM_BOT_H_
