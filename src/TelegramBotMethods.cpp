#include "TelegramBot.h"

using namespace telegram;
using namespace telegram::structures;
using namespace telegram::request;
using namespace telegram::util;
using namespace jsonserializer;
using curlsession::Method;
using curlsession::Request;
using curlsession::RequestBuilder;
using curlsession::Response;


static json getResponse(const Response &response,
                        const std::string &method)
{
    json responseJSON;

    try {
        responseJSON = json::parse(response.content);
    } catch (const nlohmann::detail::parse_error &ex) {
        throw TelegramException("Failed to deserialize " + method + " response!", response);
    }

    return responseJSON["result"];
}

Response TelegramBot::DoMethod(const json &j, const std::string &method,
                               bool multipart, const std::string &fileKey)
{
    RequestBuilder requestBuilder(GetApiUrl(method), Method::POST);

    if (!multipart) {
        if (fileKey != "") {
            Logger::debug << "used cached file_id for file: " << ToString(j[fileKey]) << std::endl;
        }

        requestBuilder.SetJSONParams(j);
    } else {
        Logger::debug << "upload file: " << ToString(j[fileKey]) << std::endl;
        requestBuilder.SetMultipartParams(j, {{ fileKey, ToString(j[fileKey]) }});
    }

    requestBuilder.SetHeaders(GetDefaultHeader());
    Response response = session.DoRequest(requestBuilder.GetRequest());

    if (!CheckResponse(response, method)) {
        throw TelegramException("Call to " + method + " failed!", response);
    }

    return response;
}

void TelegramBot::CacheFile(const std::string &typeString,
                            const std::string &path, const std::string &id)
{
    auto cache = Get("cache", typeString, path);
    struct stat buffer;

    if (stat(path.c_str(), &buffer) != 0) {
        // file does not exist
        throw TelegramException("File \"" + path + "\" does not exist!");
    }

    cache["mtime"] = static_cast<long>(buffer.st_mtime);
    cache["id"] = id;
    Set(cache, "cache", typeString, path);
}

bool TelegramBot::IsCached(const std::string &typeString,
                           const std::string &path)
{
    auto cache = Get("cache", typeString, path);

    if (cache.is_null()) {
        return false;
    }

    // invalidate cache if file does not exist
    struct stat buffer;

    if (stat(path.c_str(), &buffer) != 0) {
        auto tmp = Get("cache", typeString);
        tmp.erase(tmp.find(path));
        Set(tmp, "cache", typeString);
        return false;
    }

    // invalidate cache if file's last modified date is different
    // than that one find in cache
    if (cache["mtime"].get<long>() != (long) buffer.st_mtime) {
        auto tmp = Get("cache", typeString);
        tmp.erase(tmp.find(path));
        Set(tmp, "cache", typeString);
        return false;
    }

    return true;
}

std::string TelegramBot::GetCached(const std::string &typeString,
                                   const std::string &path)
{
    return GetString("cache", typeString, path, "id");
}

Message TelegramBot::SendFile(const json &params, const std::string &method,
                              const std::function<std::string(Message)> &idExtractor)
{
    std::string typeString = "";

    if (params.find("photo") != params.end()) {
        typeString = "photo";
    } else if (params.find("audio") != params.end()) {
        typeString = "audio";
    } else if (params.find("document") != params.end()) {
        typeString = "document";
    } else if (params.find("sticker") != params.end()) {
        typeString = "sticker";
    } else if (params.find("video") != params.end()) {
        typeString = "video";
    } else if (params.find("voice") != params.end()) {
        typeString = "voice";
    }

    json newParams = params;
    std::string path = ToString(params[typeString]);
    bool needUpload = true;

    if (IsCached(typeString, path)) {
        needUpload = false;
        newParams[typeString] = GetCached(typeString, path);
    } else {
        struct stat buffer;

        if (stat(path.c_str(), &buffer) != 0) {
            // file does not exist
            throw TelegramException("File \"" + path + "\" does not exist!");
        }
    }

    auto response = DoMethod(newParams, method, needUpload, typeString);
    auto message = Converter::FromJSON<Message>(getResponse(response, method));
    std::string id = idExtractor(message);
    CacheFile(typeString, path, id);
    return message;
}


//
// actual methods
//

Message TelegramBot::SendMessage(const request::SendMessageParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "SendMessage");
    return Converter::FromJSON<Message>(getResponse(response, "SendMessage"));
}

Message TelegramBot::ForwardMessage(const request::ForwardMessageParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "ForwardMessage");
    return Converter::FromJSON<Message>(getResponse(response, "ForwardMessage"));
}

Message TelegramBot::SendPhoto(const request::SendPhotoParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetPhotoValue()[0].GetFileIdValue(); };
    return SendFile(Converter::ToJSON(params), "SendPhoto", idExtractor);
}

Message TelegramBot::SendAudio(const request::SendAudioParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetAudio()->GetFileIdValue(); };
    return SendFile(Converter::ToJSON(params), "SendAudio", idExtractor);
}

Message TelegramBot::SendDocument(const request::SendDocumentParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetDocument()->GetFileIdValue(); };
    return SendFile(Converter::ToJSON(params), "SendDocument", idExtractor);
}

Message TelegramBot::SendSticker(const request::SendStickerParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetSticker()->GetFileIdValue(); };
    return SendFile(Converter::ToJSON(params), "SendSticker", idExtractor);
}

Message TelegramBot::SendVideo(const request::SendVideoParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetVideo()->GetFileIdValue(); };
    return SendFile(Converter::ToJSON(params), "SendVideo", idExtractor);
}

Message TelegramBot::SendVoice(const request::SendVoiceParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetVoice()->GetFileIdValue(); };
    return SendFile(Converter::ToJSON(params), "SendVoice", idExtractor);
}

Message TelegramBot::SendLocation(const request::SendLocationParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "SendLocation");
    return Converter::FromJSON<Message>(getResponse(response, "SendLocation"));
}

Message TelegramBot::SendVenue(const request::SendVenueParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "SendVenue");
    return Converter::FromJSON<Message>(getResponse(response, "SendVenue"));
}

Message TelegramBot::SendContact(const request::SendContactParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "SendContact");
    return Converter::FromJSON<Message>(getResponse(response, "SendContact"));
}

bool TelegramBot::SendChatAction(const request::SendChatActionParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "SendChatAction");
    return getResponse(response, "SendContact").get<bool>();
}



// TODO: implement
UserProfilePhotos TelegramBot::GetUserProfilePhotos(const request::GetUserProfilePhotosParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "GetUserProfilePhotos");
    return Converter::FromJSON<UserProfilePhotos>(getResponse(response, "GetUserProfilePhotos"));
}

File TelegramBot::GetFile(const request::GetFileParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "GetFile");
    return Converter::FromJSON<File>(getResponse(response, "GetFile"));
}

bool TelegramBot::KickChatMember(const request::KickChatMemberParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "KickChatMember");
    return getResponse(response, "KickChatMember").get<bool>();
}

bool TelegramBot::LeaveChat(const request::LeaveChatParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "LeaveChat");
    return getResponse(response, "LeaveChat").get<bool>();
}

bool TelegramBot::UnbanChatMember(const request::UnbanChatMemberParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "UnbanChatMember");
    return getResponse(response, "UnbanChatMember").get<bool>();
}

Chat TelegramBot::GetChat(const request::GetChatParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "GetChat");
    return Converter::FromJSON<Chat>(getResponse(response, "GetChat"));
}

std::vector<ChatMember> TelegramBot::GetChatAdministrators(const request::GetChatAdministratorsParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "GetChatAdministrators");
    return Converter::FromJSON<std::vector<ChatMember>>(getResponse(response, "GetChatAdministrators"));
}

int TelegramBot::GetChatMembersCount(const request::GetChatMembersCountParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "GetChatMembersCount");
    return getResponse(response, "GetChatMembersCount").get<int>();
}

ChatMember TelegramBot::GetChatMember(const request::GetChatMemberParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "GetChatMember");
    return Converter::FromJSON<ChatMember>(getResponse(response, "GetChatMember"));
}

bool TelegramBot::AnswerCallbackQuery(const request::AnswerCallbackQueryParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "AnswerCallbackQuery");
    return getResponse(response, "AnswerCallbackQuery").get<bool>();
}

Message TelegramBot::EditMessageText(const request::EditMessageTextParams &params)
{
    if (params.HasInlineMessageId()) {
        throw TelegramException("Inline message id set. This is not allowed for normal message modifications!");
    }

    auto response = DoMethod(Converter::ToJSON(params), "EditMessageText");
    return Converter::FromJSON<Message>(getResponse(response, "EditMessageText"));
}

Message TelegramBot::EditMessageCaption(const request::EditMessageCaptionParams &params)
{
    if (params.HasInlineMessageId()) {
        throw TelegramException("Inline message id set. This is not allowed for normal message modifications!");
    }

    auto response = DoMethod(Converter::ToJSON(params), "EditMessageCaption");
    return Converter::FromJSON<Message>(getResponse(response, "EditMessageCaption"));
}

Message TelegramBot::EditMessageReplyMarkup(const
        request::EditMessageReplyMarkupParams &params)
{
    if (params.HasInlineMessageId()) {
        throw TelegramException("Inline message id set. This is not allowed for normal message modifications!");
    }

    auto response = DoMethod(Converter::ToJSON(params), "EditMessageReplyMarkup");
    return Converter::FromJSON<Message>(getResponse(response, "EditMessageReplyMarkup"));
}

bool TelegramBot::EditInlineMessageText(const request::EditMessageTextParams &params)
{
    if (params.HasChatId() || params.HasMessageId()) {
        throw TelegramException("Chat id or message id set. This is not allowed for inline message modifications!");
    }

    auto response = DoMethod(Converter::ToJSON(params), "EditMessageText");
    return getResponse(response, "EditInlineMessageText").get<bool>();
}

bool TelegramBot::EditInlineMessageCaption(const request::EditMessageCaptionParams &params)
{
    if (params.HasChatId() || params.HasMessageId()) {
        throw TelegramException("Chat id or message id set. This is not allowed for inline message modifications!");
    }

    auto response = DoMethod(Converter::ToJSON(params), "EditMessageCaption");
    return getResponse(response, "EditInlineMessageCaption").get<bool>();
}

bool TelegramBot::EditInlineMessageReplyMarkup(const request::EditMessageReplyMarkupParams &params)
{
    if (params.HasChatId() || params.HasMessageId()) {
        throw TelegramException("Chat id or message id set. This is not allowed for inline message modifications!");
    }

    auto response = DoMethod(Converter::ToJSON(params), "EditMessageReplyMarkup");
    return getResponse(response, "EditInlineMessageReplyMarkup").get<bool>();
}

bool TelegramBot::AnswerInlineQuery(const request::AnswerInlineQueryParams &params)
{
    auto response = DoMethod(Converter::ToJSON(params), "AnswerInlineQuery");
    return getResponse(response, "AnswerInlineQuery").get<bool>();
}