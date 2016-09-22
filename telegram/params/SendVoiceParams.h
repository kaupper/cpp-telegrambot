#ifndef SEND_VOICE_PARAMS_H_
#define SEND_VOICE_PARAMS_H_

#include "telegram/params/SendFileParams.h"

namespace telegram::params
{
    class SendVoiceParams : public SendFileParams
    {
    public:
        SendVoiceParams(const telegram::structures::Chat &chat, const std::string &path) 
            : SendFileParams(chat, path, "voice") { }
            
        SendVoiceParams & SetCaption(const std::string &);
        SendVoiceParams & SetDuration(int);
    };  
}

#endif // SEND_VOICE_PARAMS_H_
