#ifndef TELEGRAM_EXCEPTION_H_
#define TELEGRAM_EXCEPTION_H_

#include <string>
#include <exception>
#include <stdexcept>

#include "curlsession/CurlSession.h"

namespace telegram
{
    class TelegramException : public std::runtime_error
    {
        curl::Response response;
        
    public:
        TelegramException(std::string message) : TelegramException(message, curl::Response()) {}
        TelegramException(std::string message, curl::Response response) : std::runtime_error(message), response(response) {}
        
        const curl::Response & GetResponse() const { return response; }
    };
}

#endif // TELEGRAM_EXCEPTION_H_
