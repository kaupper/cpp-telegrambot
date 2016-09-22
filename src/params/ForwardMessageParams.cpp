#include "params/ForwardMessageParams.h"

using namespace telegram::params;

ForwardMessageParams::ForwardMessageParams(const telegram::structures::Chat &toChat, const telegram::structures::Chat &fromChat, int messageId)
{
    (*this)["chat_id"] = toChat.GetIdValue();
    (*this)["from_chat_id"] = fromChat.GetIdValue();
    (*this)["message_id"] = messageId;
}

ForwardMessageParams & ForwardMessageParams::SetDisableNotification(bool disable)
{
    (*this)["disable_notification"] = (disable ? "true" : "false");
    return *this;
}