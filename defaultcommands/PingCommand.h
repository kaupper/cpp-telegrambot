#ifndef PING_COMMAND_H_
#define PING_COMMAND_H_

#include "telegram/Command.h"


class PingCommand : public telegram::Command
{
    public:
        PingCommand(telegram::TelegramBot &bot, std::string name,
                    telegram::CommandSet *cs) : telegram::Command(bot, name, cs) { }
                    
        virtual bool OnDirect(telegram::structures::Update &update)
        {
            bot.SendMessage({update.GetMessageValue().GetChatValue().GetIdValue(), "pong"});
            return false;
        }
};

#endif // PING_COMMAND_H_
