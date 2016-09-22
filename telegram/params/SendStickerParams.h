#ifndef SEND_STICKER_PARAMS_H_
#define SEND_STICKER_PARAMS_H_

#include "telegram/params/SendFileParams.h"

namespace telegram::params
{
    class SendStickerParams : public SendFileParams
    {
    public:
        SendStickerParams(const telegram::structures::Chat &chat, const std::string &path) 
            : SendFileParams(chat, path, "sticker") { }
    };  
}

#endif // SEND_STICKER_PARAMS_H_
