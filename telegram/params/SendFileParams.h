#ifndef SEND_FILE_PARAMS_H_
#define SEND_FILE_PARAMS_H_

#include <fstream>
#include <sstream>

#include "telegram/params/SendParams.h"

namespace telegram::params
{
    class SendFileParams : public SendParams
    {
    private:
        std::string fileTypeString;
        
    public:
        SendFileParams(const telegram::structures::Chat &chat, const std::string &path, const std::string &fileTypeString);
        
        const std::string & GetFileTypeString() const { return fileTypeString; }
    };  
}

#endif // SEND_FILE_PARAMS_H_
