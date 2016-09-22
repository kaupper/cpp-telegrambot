#include "params/SendLocationParams.h"

using namespace telegram::params;

SendLocationParams::SendLocationParams(const telegram::structures::Chat &chat, float longitude, float latitude) : SendParams(chat) 
{   
    (*this)["longitude"] = longitude;
    (*this)["latitude"] = latitude;
}