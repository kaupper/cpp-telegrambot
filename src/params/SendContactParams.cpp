#include "params/SendContactParams.h"

using namespace telegram::params;

SendContactParams::SendContactParams(const telegram::structures::Chat &chat, const std::string &phoneNumber, const std::string &firstName)
    : SendParams(chat) 
{   
    (*this)["phone_number"] = phoneNumber;
    (*this)["first_name"] = firstName;
}

SendContactParams & SendContactParams::SetLastName(const std::string &lastName)
{
    (*this)["last_name"] = lastName;
    return *this;
}