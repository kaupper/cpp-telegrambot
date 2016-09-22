#ifndef GET_CHAT_MEMBERS_COUNT_PARAMS_H_
#define GET_CHAT_MEMBERS_COUNT_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class GetChatMembersCountParams : public jsonserializer::Serializable
    {
    public:
        GetChatMembersCountParams(const telegram::structures::Chat &chat);
    };
}

#endif // GET_CHAT_MEMBERS_COUNT_PARAMS_H_
