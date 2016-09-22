#ifndef KICK_CHAT_MEMBER_PARAMS_H_
#define KICK_CHAT_MEMBER_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class KickChatMemberParams : public jsonserializer::Serializable
    {
    public:
        KickChatMemberParams(const telegram::structures::Chat &chat, const telegram::structures::User &user);
    };
}

#endif // KICK_CHAT_MEMBER_PARAMS_H_
