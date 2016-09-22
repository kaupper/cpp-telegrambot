#include "params/GetChatAdministratorsParams.h"

using namespace telegram::params;

GetChatAdministratorsParams::GetChatAdministratorsParams(const telegram::structures::Chat &chat) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
}