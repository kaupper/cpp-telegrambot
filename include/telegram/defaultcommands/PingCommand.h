#ifndef PING_COMMAND_H_
#define PING_COMMAND_H_

#include "telegram/Command.h"


class PingCommand : public telegram::Command
{
    public:
        PingCommand(telegram::TelegramBot *bot, const std::string &name) : telegram::Command(bot, name) { }

        bool OnDirect(const telegram::structures::Update &update) override
        {
            bot->SendMessage({update.GetMessageValue().GetChatValue().GetIdValue(), "pong"});
            return false;
        }
};

#endif // PING_COMMAND_H_
