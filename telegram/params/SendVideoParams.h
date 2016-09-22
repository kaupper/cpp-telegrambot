#ifndef SEND_VIDEO_PARAMS_H_
#define SEND_VIDEO_PARAMS_H_

#include "telegram/params/SendFileParams.h"

namespace telegram::params
{
    class SendVideoParams : public SendFileParams
    {
    public:
        SendVideoParams(const telegram::structures::Chat &chat, const std::string &path) 
            : SendFileParams(chat, path, "video") { }
        
        SendVideoParams & SetCaption(const std::string &);
        SendVideoParams & SetDuration(int);
        SendVideoParams & SetWidth(int);
        SendVideoParams & SetHeight(int);
    };  
}

#endif // SEND_VIDEO_PARAMS_H_
