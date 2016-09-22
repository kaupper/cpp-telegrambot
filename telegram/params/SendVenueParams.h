#ifndef SEND_VENUE_PARAMS_H_
#define SEND_VENUE_PARAMS_H_

#include "telegram/params/SendLocationParams.h"

namespace telegram::params
{
    class SendVenueParams : public SendLocationParams
    {
    public:
        SendVenueParams(const telegram::structures::Chat &chat, float longitude, float latitude, const std::string &title, const std::string &address);
    
        SendVenueParams & SetFoursquareId(const std::string &foursquareId);
    };  
}

#endif // SEND_VENUE_PARAMS_H_
