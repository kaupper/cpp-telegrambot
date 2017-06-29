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
            curlsession::Response response;
            
        public:
            TelegramException(const std::string &message)
                : TelegramException(message, curlsession::Response()) {}
            TelegramException(const std::string &message,
                              const curlsession::Response &response)
                : std::runtime_error(message), response(response) {}
                
            curlsession::Response GetResponse() const
            {
                return response;
            }
    };
}

#endif // TELEGRAM_EXCEPTION_H_
