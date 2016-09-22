#ifndef SEND_DOCUMENT_PARAMS_H_
#define SEND_DOCUMENT_PARAMS_H_

#include "telegram/params/SendFileParams.h"

namespace telegram::params
{
    class SendDocumentParams : public SendFileParams
    {
    public:
        SendDocumentParams(const telegram::structures::Chat &chat, const std::string &path) 
            : SendFileParams(chat, path, "document") { }
            
        SendDocumentParams & SetCaption(const std::string &);
    };  
}

#endif // SEND_DOCUMENT_PARAMS_H_
