#include "Util.h"


const std::vector<curlsession::Header> telegram::util::GetDefaultHeader()
{
    static const std::vector<curlsession::Header> header {{"Content-Type", "application/json"}};
    return header;
}