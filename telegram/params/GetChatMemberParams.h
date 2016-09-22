#ifndef GET_CHAT_MEMBER_PARAMS_H_
#define GET_CHAT_MEMBER_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class GetChatMemberParams : public jsonserializer::Serializable
    {
    public:
        GetChatMemberParams(const telegram::structures::Chat &chat, const telegram::structures::User &user);
    };
}

#endif // GET_CHAT_MEMBER_PARAMS_H_
