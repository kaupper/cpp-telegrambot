#include "params/SendVideoParams.h"

using namespace telegram::params;

SendVideoParams & SendVideoParams::SetCaption(const std::string &caption)
{
    (*this)["caption"] = caption;
    return *this;
}

SendVideoParams & SendVideoParams::SetDuration(int duration)
{
    (*this)["duration"] = duration;
    return *this;
}

SendVideoParams & SendVideoParams::SetWidth(int width)
{
    (*this)["width"] = width;
    return *this;
}

SendVideoParams & SendVideoParams::SetHeight(int height)
{
    (*this)["height"] = height;
    return *this;
}