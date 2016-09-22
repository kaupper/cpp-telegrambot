#include "params/GetChatMemberParams.h"

using namespace telegram::params;

GetChatMemberParams::GetChatMemberParams(const telegram::structures::Chat &chat, const telegram::structures::User &user) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
    (*this)["user_id"] = std::to_string(user.GetIdValue());
}