#ifndef COMMAND_EXCEPTION_H_
#define COMMAND_EXCEPTION_H_

#include <string>
#include <exception>
#include <stdexcept>

namespace telegram
{
    class CommandException : public std::runtime_error
    {   
    public:
        CommandException(std::string message) : std::runtime_error(message) {}
    };
}

#endif // COMMAND_EXCEPTION_H_