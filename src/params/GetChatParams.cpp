#include "params/GetChatParams.h"

using namespace telegram::params;

GetChatParams::GetChatParams(const telegram::structures::Chat &chat) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
}