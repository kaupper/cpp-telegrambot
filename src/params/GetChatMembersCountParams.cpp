#include "params/GetChatMembersCountParams.h"

using namespace telegram::params;

GetChatMembersCountParams::GetChatMembersCountParams(const telegram::structures::Chat &chat) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
}