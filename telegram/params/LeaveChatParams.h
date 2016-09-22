#ifndef LEAVE_CHAT_PARAMS_H_
#define LEAVE_CHAT_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class LeaveChatParams : public jsonserializer::Serializable
    {
    public:
        LeaveChatParams(const telegram::structures::Chat &chat);
    };
}

#endif // LEAVE_CHAT_PARAMS_H_
