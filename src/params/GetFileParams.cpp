#include "params/GetFileParams.h"

using namespace telegram::params;

GetFileParams::GetFileParams(const std::string &fileId) : jsonserializer::Serializable()
{
    (*this)["file_id"] = fileId;
}