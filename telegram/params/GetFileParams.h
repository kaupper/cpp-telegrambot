#ifndef GET_FILE_PARAMS_H_
#define GET_FILE_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class GetFileParams : public jsonserializer::Serializable
    {
    public:
        GetFileParams(const std::string &fileId);
    };
}

#endif // GET_FILE_PARAMS_H_
