#ifndef SEND_AUDIO_PARAMS_H_
#define SEND_AUDIO_PARAMS_H_

#include "telegram/params/SendFileParams.h"

namespace telegram::params
{
    class SendAudioParams : public SendFileParams
    {
    public:
        SendAudioParams(const telegram::structures::Chat &chat, const std::string &path) 
            : SendFileParams(chat, path, "audio") { }
            
        SendAudioParams & SetCaption(const std::string &);
        SendAudioParams & SetDuration(int);
        SendAudioParams & SetPerformer(const std::string &);
        SendAudioParams & SetTitle(const std::string &);
    };  
}

#endif // SEND_AUDIO_PARAMS_H_
