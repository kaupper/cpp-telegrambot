#include "Util.h"

using namespace telegram::util;


const std::vector<curlsession::Header> GetDefaultHeader()
{
    static const std::vector<curlsession::Header> header {{"Content-Type", "application/json"}};
    return header;
}