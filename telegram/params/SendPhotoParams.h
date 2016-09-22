#ifndef SEND_PHOTO_PARAMS_H_
#define SEND_PHOTO_PARAMS_H_

#include <fstream>
#include <sstream>

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class SendPhotoParams : public jsonserializer::Serializable
    {
        bool upload;
        
    public:
        SendPhotoParams(const telegram::structures::Chat &chat, const std::string &string, bool upload = false);
        
        bool NeedUpload() const { return upload; }
        
        SendPhotoParams & SetCaption(const std::string &caption);
        SendPhotoParams & SetDisableNotification(bool disable);
        SendPhotoParams & SetReplyToMessageId(int reply);
        
        template <typename T, typename = typename std::enable_if<telegram::isMarkup<T>>::type>
        SendMessageParams & SetReplyMarkup(const T &markup)            
        {
            (*this)["reply_markup"] = jsonserializer::structures::Converter::ToJSON(markup);
            return *this;
        }
    };
}

#endif // SEND_PHOTO_PARAMS_H_
