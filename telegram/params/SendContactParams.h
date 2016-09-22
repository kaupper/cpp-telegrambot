#ifndef SEND_CONTACT_PARAMS_H_
#define SEND_CONTACT_PARAMS_H_

#include "telegram/params/SendParams.h"

namespace telegram::params
{
    class SendContactParams : public SendParams
    {
    public:
        SendContactParams(const telegram::structures::Chat &chat, const std::string &phoneNumber, const std::string &firstName);
        
        SendContactParams & SetLastName(const std::string &lastName);
    };  
}

#endif // SEND_CONTACT_PARAMS_H_
