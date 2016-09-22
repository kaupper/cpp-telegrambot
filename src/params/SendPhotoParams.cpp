#include "params/SendPhotoParams.h"

using namespace telegram::params;

SendPhotoParams::SendPhotoParams(const telegram::structures::Chat &chat, const std::string &string, bool upload) : upload(upload)
{
    (*this)["chat_id"] = chat.GetIdValue();
    (*this)["photo"] = string;
}
        
SendPhotoParams & SendPhotoParams::SetCaption(const std::string &caption)
{
    (*this)["caption"] = caption;
    return *this;
}

SendPhotoParams & SendPhotoParams::SetDisableNotification(bool disable)
{
    (*this)["disable_notification"] = (disable ? "true" : "false");
    return *this;
}

SendPhotoParams & SendPhotoParams::SetReplyToMessageId(int reply)
{
    (*this)["reply_to_message_id"] = reply;
    return *this;
}