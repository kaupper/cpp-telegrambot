#include "TelegramBot.h"

using namespace telegram;
using namespace jsonserializer::structures;

structures::Message TelegramBot::SendMessage(params::SendMessageParams &params)
{
    curl::RequestParams requestParams(GetApiUrl("sendMessage"), curl::Method::POST);
    requestParams.SetParams(params);
    requestParams.SetHeaders(GetDefaultHeader());
    curl::Response response = session.DoRequest(requestParams);
    
    CheckResponse(response, "SendMessage"); 
    
    auto responseJSON = Serializable::Deserialize(std::string(response.begin(), response.end()));
    if(responseJSON == nullptr) {
        throw TelegramException("Failed to deserialize SendMessage response!", response);
    }
    
    return Converter::FromJSON<structures::Message>(*responseJSON);
}

structures::Message TelegramBot::SendMessage(params::SendMessageParams &&params)
{
    return SendMessage(params);
}
