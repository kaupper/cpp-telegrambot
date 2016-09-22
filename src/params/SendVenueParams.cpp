#include "params/SendVenueParams.h"

using namespace telegram::params;

SendVenueParams::SendVenueParams(const telegram::structures::Chat &chat, float longitude, float latitude, 
                                 const std::string &title, const std::string &address) : SendLocationParams(chat, longitude, latitude) 
{   
    (*this)["title"] = title;
    (*this)["address"] = address;
}

SendVenueParams & SendVenueParams::SetFoursquareId(const std::string &foursquareId)
{
    (*this)["foursquare_id"] = foursquareId;
    return *this;
}