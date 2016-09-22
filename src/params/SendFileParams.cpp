#include "params/SendFileParams.h"

using namespace telegram::params;

SendFileParams::SendFileParams(const telegram::structures::Chat &chat, const std::string &path, const std::string &fileTypeString)
    : SendParams(chat)
{
    this->fileTypeString = fileTypeString;
    (*this)[fileTypeString] = path;
}