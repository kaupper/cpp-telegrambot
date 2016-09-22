#include "params/SendVoiceParams.h"

using namespace telegram::params;

SendVoiceParams & SendVoiceParams::SetDuration(int duration)
{
    (*this)["duration"] = duration;
    return *this;
}

SendVoiceParams & SendVoiceParams::SetCaption(const std::string &caption)
{
    (*this)["caption"] = caption;
    return *this;
}