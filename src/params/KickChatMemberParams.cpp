#include "params/KickChatMemberParams.h"

using namespace telegram::params;

KickChatMemberParams::KickChatMemberParams(const telegram::structures::Chat &chat, const telegram::structures::User &user) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
    (*this)["user_id"] = std::to_string(user.GetIdValue());
}