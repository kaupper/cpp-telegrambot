#include "params/GetUserProfilePhotosParams.h"

using namespace telegram::params;

GetUserProfilePhotosParams::GetUserProfilePhotosParams(const structures::User &user) : jsonserializer::Serializable()
{
    (*this)["user_id"] = std::to_string(user.GetIdValue());
}

GetUserProfilePhotosParams & GetUserProfilePhotosParams::SetOffset(int offset)
{
    (*this)["offset"] = std::to_string(offset);
    return *this;
}

GetUserProfilePhotosParams & GetUserProfilePhotosParams::SetLimit(int limit)
{
    (*this)["limit"] = std::to_string(limit);
    return *this;
}