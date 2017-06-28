#ifndef EXIT_COMMAND_H_
#define EXIT_COMMAND_H_

#include "telegram/Command.h"

class ExitCommand : public telegram::Command
{
    public:
        ExitCommand(telegram::TelegramBot &bot, std::string name,
                    telegram::CommandSet *cs) : telegram::Command(bot, name, cs) { }
                    
        virtual bool OnDirect(telegram::structures::Update &update)
        {
            (void) update;
            bot.Get("running") = false;
            return false;
        }
};

#endif // EXIT_COMMAND_H_