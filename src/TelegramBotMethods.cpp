#include "TelegramBot.h"

using namespace telegram;
using namespace jsonserializer::structures;

structures::Message TelegramBot::SendMessage(params::SendMessageParams &params)
{
    curl::RequestParams requestParams(GetApiUrl("sendMessage"), curl::Method::POST);
    requestParams.SetParams((jsonserializer::Serializable &) params);
    requestParams.SetHeaders(GetDefaultHeader());
    curl::Response response = session.DoRequest(requestParams);
    
    if(!CheckResponse(response, "SendMessage")) {
        throw TelegramException("Call to SendMessage failed!", response);
    }
    
    auto responseJSON = Serializable::Deserialize(std::string(response.content.begin(), response.content.end()));
    if(responseJSON == nullptr) {
        throw TelegramException("Failed to deserialize SendMessage response!", response);
    }
    
    return Converter::FromJSON<structures::Message>((*responseJSON)["result"]);
}

structures::Message TelegramBot::SendMessage(params::SendMessageParams &&params)
{
    return SendMessage(params);
}
