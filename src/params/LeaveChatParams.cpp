#include "params/LeaveChatParams.h"

using namespace telegram::params;

LeaveChatParams::LeaveChatParams(const telegram::structures::Chat &chat) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
}