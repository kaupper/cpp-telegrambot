#ifndef SEND_MESSAGE_PARAMS_H_
#define SEND_MESSAGE_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class SendMessageParams : public jsonserializer::Serializable
    {
    public:
        SendMessageParams(const telegram::structures::Chat &chat, std::string text);
        
        SendMessageParams & SetParseMode(telegram::ParseMode mode);
        SendMessageParams & SetDisableWebPagePreview(bool disable);
        SendMessageParams & SetDisableNotification(bool disable);
        SendMessageParams & SetReplyToMessageId(int reply);
        
        template <typename T, typename = typename std::enable_if<telegram::isMarkup<T>>::type>
        SendMessageParams & SetReplyMarkup(const T &markup)            
        {
            (*this)["reply_markup"] = jsonserializer::structures::Converter::ToJSON(markup);
            return *this;
        }
    };
}

#endif // SEND_MESSAGE_PARAMS_H_
