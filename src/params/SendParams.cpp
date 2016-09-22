#include "params/SendParams.h"

using namespace telegram::params;

SendParams::SendParams(const telegram::structures::Chat &chat) : jsonserializer::Serializable() 
{   
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
}

SendParams & SendParams::SetDisableNotification(bool disable)
{
    (*this)["disable_notification"] = (disable ? "true" : "false");
    return *this;
}

SendParams & SendParams::SetReplyToMessageId(int reply)
{
    (*this)["reply_to_message_id"] = reply;
    return *this;
}