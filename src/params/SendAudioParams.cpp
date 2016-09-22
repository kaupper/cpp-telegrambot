#include "params/SendAudioParams.h"

using namespace telegram::params;

SendAudioParams & SendAudioParams::SetDuration(int duration)
{
    (*this)["duration"] = duration;
    return *this;
}

SendAudioParams & SendAudioParams::SetPerformer(const std::string &performer)
{
    (*this)["performer"] = performer;
    return *this;
}

SendAudioParams & SendAudioParams::SetTitle(const std::string &title)
{
    (*this)["title"] = title;
    return *this;
}

SendAudioParams & SendAudioParams::SetCaption(const std::string &caption)
{
    (*this)["caption"] = caption;
    return *this;
}