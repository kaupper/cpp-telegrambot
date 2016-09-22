#ifndef FORWARD_MESSAGE_PARAMS_H_
#define FORWARD_MESSAGE_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class ForwardMessageParams : public jsonserializer::Serializable
    {
    public:
        ForwardMessageParams(const telegram::structures::Chat &toChat, const telegram::structures::Chat &fromChat, int messageId);
        ForwardMessageParams(const telegram::structures::Chat &toChat, const telegram::structures::Chat &fromChat, const telegram::structures::Message &message) :
            ForwardMessageParams(toChat, fromChat, message.GetMessageIdValue()) { }
        
        ForwardMessageParams & SetDisableNotification(bool disable);
    };
}

#endif // FORWARD_MESSAGE_PARAMS_H_
