#include "params/SendPhotoParams.h"

using namespace telegram::params;

SendPhotoParams & SendPhotoParams::SetCaption(const std::string &caption)
{
    (*this)["caption"] = caption;
    return *this;
}