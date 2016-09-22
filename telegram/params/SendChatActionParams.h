#ifndef SEND_CHAT_ACTION_PARAMS_H_
#define SEND_CHAT_ACTION_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    enum class ChatAction
    {
        TYPING,
        UPLOAD_PHOTO,
        RECORD_VIDEO,
        UPLOAD_VIDEO,
        RECORD_AUDIO,
        UPLOAD_AUDIO,
        UPLOAD_DOCUMENT,
        FIND_LOCATION
    };
    
    class SendChatActionParams : public jsonserializer::Serializable
    {
    public:
        SendChatActionParams(const telegram::structures::Chat &chat, const ChatAction &);
    };
}

#endif // SEND_CHAT_ACTION_PARAMS_H_
