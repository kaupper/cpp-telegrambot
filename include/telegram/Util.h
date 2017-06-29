#ifndef UTIL_H
#define UTIL_H

#include <string>

#include "jsonserializer/json.h"
#include "jsonserializer/Generated.h"
#include "curlsession/Commons.h"


namespace telegram
{
    namespace util
    {
        enum class ParseMode {
            NORMAL = 0,
            MARKDOWN = 1,
            HTML = 2
        };

        template <typename T> const bool isMarkup =
                    std::is_same<T, telegram::structures::InlineKeyboardMarkup>::value ||
                    std::is_same<T, telegram::structures::ReplyKeyboardMarkup>::value ||
                    std::is_same<T, telegram::structures::ReplyKeyboardHide>::value ||
                    std::is_same<T, telegram::structures::ForceReply>::value;


        const std::vector<curlsession::Header> GetDefaultHeader();
    }
}

#endif // UTIL_H