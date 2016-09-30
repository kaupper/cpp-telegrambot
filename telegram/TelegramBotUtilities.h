#ifndef TELEGRAM_BOT_UTILITIES_H_
#define TELEGRAM_BOT_UTILITIES_H_

#include "params.h"
#include "structures.h"

namespace telegram
{
    class TelegramBotUtilities
    {
    private:
        TelegramBotUtilities();
        
    public:
        static structures::InlineKeyboardButton IBData(const std::string &, const std::string &);
        static structures::InlineKeyboardButton IBUrl(const std::string &, const std::string &);
        static structures::InlineKeyboardButton IBQuery(const std::string &, const std::string &);
        
        static structures::InlineQueryResult IQRArticle(const std::string &, const std::string &, const structures::InputMessageContent &);
        static structures::InlineQueryResult IQRPhoto(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRGif(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRMpeg(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRVideo(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRAudio(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRVoice(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRDocument(const std::string &, const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRLocation(const std::string &, float, float, const std::string &);
        static structures::InlineQueryResult IQRVenue(const std::string &, float, float, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRContact(const std::string &, const std::string &, const std::string &);
        
        static structures::InlineQueryResult IQRCPhoto(const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCGif(const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCMpeg(const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCSticker(const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCDocument(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCVideo(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCVoice(const std::string &, const std::string &, const std::string &);
        static structures::InlineQueryResult IQRCAudio(const std::string &, const std::string &, const std::string &);
        
        static structures::InputMessageContent IMCText(const std::string &);    
        static structures::InputMessageContent IMCLocation(float, float);    
        static structures::InputMessageContent IMCVenue(float, float, const std::string &, const std::string &);    
        static structures::InputMessageContent IMCContact(const std::string &, const std::string &);    
        
        static params::EditMessageTextParams EMTParams(const std::string &, const std::string &, int);    
        static params::EditMessageTextParams EMTParamsInline(const std::string &, const std::string &);    
    };
    using Utils = TelegramBotUtilities;
}

#endif // TELEGRAM_BOT_UTILITIES_H_