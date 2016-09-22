#ifndef SEND_PARAMS_H_
#define SEND_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class SendParams : public jsonserializer::Serializable
    {
    public:
        SendParams(const telegram::structures::Chat &chat);
        
        SendParams & SetDisableNotification(bool disable);
        SendParams & SetReplyToMessageId(int reply);
        
        template <typename T, typename = typename std::enable_if<telegram::isMarkup<T>>::type>
        SendParams & SetReplyMarkup(const T &markup)            
        {
            (*this)["reply_markup"] = jsonserializer::structures::Converter::ToJSON(markup);
            return *this;
        }
    };
}

#endif // SEND_PARAMS_H_
