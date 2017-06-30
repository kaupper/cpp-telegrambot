#ifndef EXIT_COMMAND_H_
#define EXIT_COMMAND_H_

#include "telegram/Command.h"

class ExitCommand : public telegram::Command
{
    public:
        ExitCommand(telegram::TelegramBot *bot, const std::string &name) : telegram::Command(bot, name) { }

        virtual bool OnDirect(const telegram::structures::Update &update)
        {
            (void) update;
            bot->Set(false, "running");
            return false;
        }
};

#endif // EXIT_COMMAND_H_