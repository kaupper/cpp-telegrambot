#ifndef SEND_MESSAGE_PARAMS_H_
#define SEND_MESSAGE_PARAMS_H_

#include "telegram/params/SendParams.h"

namespace telegram::params
{
    class SendMessageParams : public SendParams
    {
    public:
        SendMessageParams(const telegram::structures::Chat &chat, std::string text);
        
        SendMessageParams & SetParseMode(telegram::ParseMode mode);
        SendMessageParams & SetDisableWebPagePreview(bool disable);
    };
}

#endif // SEND_MESSAGE_PARAMS_H_
