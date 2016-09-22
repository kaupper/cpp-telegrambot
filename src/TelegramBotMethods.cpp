#include "TelegramBot.h"
#include "params/SendPhotoParams.h"

using namespace telegram;
using namespace telegram::structures;
using namespace jsonserializer;
using namespace jsonserializer::structures;

static Message getMessageResponse(const curl::Response &response, const std::string &method)
{
    auto responseJSON = Serializable::Deserialize(std::string(response.content.begin(), response.content.end()));
    
    if(responseJSON == nullptr) {
        throw TelegramException("Failed to deserialize " + method + " response!", response);
    }
    
    return Converter::FromJSON<Message>((*responseJSON)["result"]);
}

curl::Response TelegramBot::DoMethod(const Serializable &json, const std::string &method)
{
    return DoMethod(json, method, false);
}

curl::Response TelegramBot::DoMethod(const Serializable &json, const std::string &method, bool multipart, const std::string &fileKey)
{
    curl::RequestParams requestParams(GetApiUrl(method), curl::Method::POST);
    if(!multipart) {
        Logger::debug << "used cached file_id for file: " << json[fileKey].asString() << std::endl;
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

Message TelegramBot::SendMessage(const params::SendMessageParams &params)
{
    auto response = DoMethod((const Serializable &) params, "SendMessage");
    return getMessageResponse(response, "SendMessage");
}
 
Message TelegramBot::ForwardMessage(const params::ForwardMessageParams &params)
{
    auto response = DoMethod((const Serializable &) params, "ForwardMessage");
    return getMessageResponse(response, "ForwardMessage");
}
 
Message TelegramBot::SendPhoto(const params::SendPhotoParams &params)
{
    params::SendPhotoParams newParams = params;
    bool needUpload = true;
    if(params.NeedUpload()) {
        if(!(*this)["cache"]["photos"][params["photo"].asString()].isNull()) {
            newParams["photo"] = (*this)["cache"]["photos"][params["photo"].asString()].asString();
            needUpload = false;
        }
    }
    
    auto response = DoMethod((const Serializable &) newParams, "SendPhoto", needUpload, "photo");
    auto message = getMessageResponse(response, "SendPhoto");
    
    // TODO: cache photo!!
    (*this)["cache"]["photos"][params["photo"].asString()] = message.GetPhotoValue()[0].GetFileIdValue();
    
    return message;
}
