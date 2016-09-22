#include "TelegramBot.h"
#include "params/SendFileParams.h"

using namespace telegram;
using namespace telegram::structures;
using namespace jsonserializer;
using namespace jsonserializer::structures;

static auto getResponse(const curl::Response &response, const std::string &method)
{
    auto responseJSON = Serializable::Deserialize(std::string(response.content.begin(), response.content.end()));
    
    if(responseJSON == nullptr) {
        throw TelegramException("Failed to deserialize " + method + " response!", response);
    }
    
    return (*responseJSON)["result"];
}

curl::Response TelegramBot::DoMethod(const Serializable &json, const std::string &method, bool multipart, const std::string &fileKey)
{
    curl::RequestParams requestParams(GetApiUrl(method), curl::Method::POST);
    if(!multipart) {
        if(fileKey != "") {
            Logger::debug << "used cached file_id for file: " << json[fileKey].asString() << std::endl;
        }
        requestParams.SetParams(json);
    } else {
        Logger::debug << "upload file: " << json[fileKey].asString() << std::endl;
        requestParams.SetParams(json, {{ fileKey, json[fileKey].asString() }});
    }
    requestParams.SetHeaders(GetDefaultHeader());
    curl::Response response = session.DoRequest(requestParams);
    
    if(!CheckResponse(response, method)) {
        throw TelegramException("Call to " + method + " failed!", response);
    }
    
    return response;
}

void TelegramBot::CacheFile(const std::string &typeString, const std::string &path, const std::string &id)
{
    auto &cache = (*this)["cache"][typeString][path];
    
    struct stat buffer;   
    if(stat(path.c_str(), &buffer) != 0) {
        // file does not exist
        throw TelegramException("File \"" + path + "\" does not exist!");
    }
    
    cache["mtime"] = std::to_string(buffer.st_mtime);
    cache["id"] = id;
}

bool TelegramBot::IsCached(const std::string &typeString, const std::string &path)
{
    auto &cache = (*this)["cache"][typeString][path];
    
    if(cache.isNull()) {
        return false;
    }
    
    // invalidate cache if file does not exist
    struct stat buffer;   
    if(stat(path.c_str(), &buffer) != 0) {
        (*this)["cache"][typeString].removeMember(path);
        return false;
    }

    // invalidate cache if file's last modified date is different
    // than that one find in cache
    if(std::stol(cache["mtime"].asString()) != (long) buffer.st_mtime) {
        (*this)["cache"][typeString].removeMember(path);
        return false;
    }
    
    return true;
}

std::string TelegramBot::GetCached(const std::string &typeString, const std::string &path)
{
    return (*this)["cache"][typeString][path]["id"].asString();
}

Message TelegramBot::SendFile(const params::SendFileParams &params, const std::string &method, const std::function<std::string(Message)> &idExtractor)
{    
    std::string typeString = params.GetFileTypeString();
    Serializable newParams = params;
    std::string path = params[typeString].asString();
    bool needUpload = true;
    
    if(IsCached(typeString, path)) {
        needUpload = false;
        newParams[typeString] = GetCached(typeString, path);
    } else {
        struct stat buffer;   
        if(stat(path.c_str(), &buffer) != 0) {
            // file does not exist
            throw TelegramException("File \"" + path + "\" does not exist!");
        }
    }
    
    auto response = DoMethod((const Serializable &) newParams, method, needUpload, typeString);
    auto message = Converter::FromJSON<Message>(getResponse(response, method));
    
    std::string id = idExtractor(message);
    CacheFile(typeString, path, id);
    
    return message;
}


//
// actual methods
//

Message TelegramBot::SendMessage(const params::SendMessageParams &params)
{
    auto response = DoMethod((const Serializable &) params, "SendMessage");
    return Converter::FromJSON<Message>(getResponse(response, "SendMessage"));
}
 
Message TelegramBot::ForwardMessage(const params::ForwardMessageParams &params)
{
    auto response = DoMethod((const Serializable &) params, "ForwardMessage");
    return Converter::FromJSON<Message>(getResponse(response, "ForwardMessage"));
}
 
Message TelegramBot::SendPhoto(const params::SendPhotoParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetPhotoValue()[0].GetFileIdValue(); };
    return SendFile((const params::SendFileParams &)params, "SendPhoto", idExtractor);
}

Message TelegramBot::SendAudio(const params::SendAudioParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetAudio()->GetFileIdValue(); };
    return SendFile((const params::SendFileParams &) params, "SendAudio", idExtractor);
}
 
Message TelegramBot::SendDocument(const params::SendDocumentParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetDocument()->GetFileIdValue(); };
    return SendFile((const params::SendFileParams &)params, "SendDocument", idExtractor);
}
 
Message TelegramBot::SendSticker(const params::SendStickerParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetSticker()->GetFileIdValue(); };
    return SendFile((const params::SendFileParams &)params, "SendSticker", idExtractor);
}

Message TelegramBot::SendVideo(const params::SendVideoParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetVideo()->GetFileIdValue(); };
    return SendFile((const params::SendFileParams &)params, "SendVideo", idExtractor);
}

Message TelegramBot::SendVoice(const params::SendVoiceParams &params)
{
    auto idExtractor = [](Message message)->std::string { return message.GetVoice()->GetFileIdValue(); };
    return SendFile((const params::SendFileParams &)params, "SendVoice", idExtractor);
}

Message TelegramBot::SendLocation(const params::SendLocationParams &params)
{
    auto response = DoMethod((const Serializable &) params, "SendLocation");
    return Converter::FromJSON<Message>(getResponse(response, "SendLocation"));
}

Message TelegramBot::SendVenue(const params::SendVenueParams &params)
{
    auto response = DoMethod((const Serializable &) params, "SendVenue");
    return Converter::FromJSON<Message>(getResponse(response, "SendVenue"));
}

Message TelegramBot::SendContact(const params::SendContactParams &params)
{
    auto response = DoMethod((const Serializable &) params, "SendContact");
    return Converter::FromJSON<Message>(getResponse(response, "SendContact"));
}

bool TelegramBot::SendChatAction(const params::SendChatActionParams &params)
{
    auto response = DoMethod((const Serializable &) params, "SendChatAction");
    return getResponse(response, "SendContact").asBool();
}



// TODO: implement
UserProfilePhotos TelegramBot::GetUserProfilePhotos(const params::GetUserProfilePhotosParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "GetUserProfilePhotos");
    return Converter::FromJSON<UserProfilePhotos>(getResponse(response, "GetUserProfilePhotos"));
}

File TelegramBot::GetFile(const params::GetFileParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "GetFile");
    return Converter::FromJSON<File>(getResponse(response, "GetFile"));
}

bool TelegramBot::KickChatMember(const params::KickChatMemberParams &params) 
{
    auto response = DoMethod((const Serializable &) params, "KickChatMember");
    return getResponse(response, "KickChatMember").asBool();
}

bool TelegramBot::LeaveChat(const params::LeaveChatParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "LeaveChat");
    return getResponse(response, "LeaveChat").asBool();
}

bool TelegramBot::UnbanChatMember(const params::UnbanChatMemberParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "UnbanChatMember");
    return getResponse(response, "UnbanChatMember").asBool();
}

Chat TelegramBot::GetChat(const params::GetChatParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "GetChat");
    return Converter::FromJSON<Chat>(getResponse(response, "GetChat"));
}

std::vector<ChatMember> TelegramBot::GetChatAdministrators(const params::GetChatAdministratorsParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "GetChatAdministrators");
    return Converter::FromJSON<std::vector<ChatMember>>(getResponse(response, "GetChatAdministrators"));
}

int TelegramBot::GetChatMembersCount(const params::GetChatMembersCountParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "GetChatMembersCount");
    return getResponse(response, "GetChatMembersCount").asInt();
}

ChatMember TelegramBot::GetChatMember(const params::GetChatMemberParams &params) 
{
    auto response = DoMethod((const Serializable &) params, "GetChatMember");
    return Converter::FromJSON<ChatMember>(getResponse(response, "GetChatMember"));
}

bool TelegramBot::AnswerCallbackQuery(const params::AnswerCallbackQueryParams &params) 
{ 
    auto response = DoMethod((const Serializable &) params, "AnswerCallbackQuery");
    return getResponse(response, "AnswerCallbackQuery").asBool();
}