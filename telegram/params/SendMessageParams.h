#ifndef SEND_MESSAGE_PARAMS_H_
#define SEND_MESSAGE_PARAMS_H_

#include "utils/json/Serializable.h"
#include "telegram/TelegramBot.h"
#include "telegram/structures/StructConverter.h"

namespace telegram::params
{
    class SendMessageParams : public Serializable
    {
    public:
        SendMessageParams(telegram::structures::Chat chat, std::string text);
        
        SendMessageParams & SetParseMode(telegram::ParseMode mode);
        SendMessageParams & SetDisableWebPagePreview(bool disable);
        SendMessageParams & SetDisableNotification(bool disable);
        SendMessageParams & SetReplyToMessageId(int reply);
        
        template <typename T, typename = typename std::enable_if<telegram::structures::isMarkup<T>>::type>
        SendMessageParams & SetReplyMarkup(T markup)            
        {
            (*this)["reply_markup"] = telegram::structures::Converter::ToJSON(markup);
            return *this;
        }
    };
}

#endif // SEND_MESSAGE_PARAMS_H_