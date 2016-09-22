#ifndef GET_CHAT_ADMINISTRATORS_PARAMS_H_
#define GET_CHAT_ADMINISTRATORS_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class GetChatAdministratorsParams : public jsonserializer::Serializable
    {
    public:
        GetChatAdministratorsParams(const telegram::structures::Chat &chat);
    };
}

#endif // GET_CHAT_ADMINISTRATORS_PARAMS_H_
