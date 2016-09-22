#ifndef SEND_LOCATION_PARAMS_H_
#define SEND_LOCATION_PARAMS_H_

#include "telegram/params/SendParams.h"

namespace telegram::params
{
    class SendLocationParams : public SendParams
    {
    public:
        SendLocationParams(const telegram::structures::Chat &chat, float longitude, float latitude);
    };  
}

#endif // SEND_LOCATION_PARAMS_H_
