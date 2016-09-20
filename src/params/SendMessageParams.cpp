#include "params/SendMessageParams.h"

using namespace telegram::params;

SendMessageParams::SendMessageParams(telegram::structures::Chat chat, std::string text) : jsonserializer::Serializable() 
{   
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
    (*this)["text"] = text;
}

SendMessageParams & SendMessageParams::SetParseMode(telegram::ParseMode mode) 
{
    switch(mode) {
        case telegram::ParseMode::MARKDOWN:
            (*this)["parse_mode"] = "Markdown";
            break;
            
        case telegram::ParseMode::HTML:
            (*this)["parse_mode"] = "HTML";
            break;
            
        case telegram::ParseMode::NORMAL:
            break;
    }
    return *this;
}

SendMessageParams & SendMessageParams::SetDisableWebPagePreview(bool disable)
{
    (*this)["disable_web_page_preview"] = (disable ? "true" : "false");
    return *this;
}

SendMessageParams & SendMessageParams::SetDisableNotification(bool disable)
{
    (*this)["disable_notification"] = (disable ? "true" : "false");
    return *this;
}

SendMessageParams & SendMessageParams::SetReplyToMessageId(int reply)
{
    (*this)["reply_to_message_id"] = reply;
    return *this;
}