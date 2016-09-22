#ifndef GET_USER_PROFILE_PHOTOS_PARAMS_H_
#define GET_USER_PROFILE_PHOTOS_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class GetUserProfilePhotosParams : public jsonserializer::Serializable
    {
    public:
        GetUserProfilePhotosParams(const telegram::structures::User &user);
        
        GetUserProfilePhotosParams & SetOffset(int);
        GetUserProfilePhotosParams & SetLimit(int);
    };
}

#endif // GET_USER_PROFILE_PHOTOS_PARAMS_H_
