#ifndef GET_CHAT_PARAMS_H_
#define GET_CHAT_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class GetChatParams : public jsonserializer::Serializable
    {
    public:
        GetChatParams(const telegram::structures::Chat &chat);
    };
}

#endif // GET_CHAT_PARAMS_H_
