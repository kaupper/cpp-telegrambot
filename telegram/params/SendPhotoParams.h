#ifndef SEND_PHOTO_PARAMS_H_
#define SEND_PHOTO_PARAMS_H_

#include "telegram/params/SendFileParams.h"

namespace telegram::params
{
    class SendPhotoParams : public SendFileParams
    {
    public:
        SendPhotoParams(const telegram::structures::Chat &chat, const std::string &path) 
            : SendFileParams(chat, path, "photo") { }
            
        SendPhotoParams & SetCaption(const std::string &);
    };  
}

#endif // SEND_PHOTO_PARAMS_H_
