#ifndef UNBAN_CHAT_MEMBER_PARAMS_H_
#define UNBAN_CHAT_MEMBER_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class UnbanChatMemberParams : public jsonserializer::Serializable
    {
    public:
        UnbanChatMemberParams(const telegram::structures::Chat &chat, const telegram::structures::User &user);
    };
}

#endif // UNBAN_CHAT_MEMBER_PARAMS_H_
