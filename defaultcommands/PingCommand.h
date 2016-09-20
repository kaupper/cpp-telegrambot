#ifndef PING_COMMAND_H_
#define PING_COMMAND_H_

#include "telegram/Command.h"
#include "telegram/params/SendMessageParams.h"

class PingCommand : public telegram::Command
{
public:
    PingCommand(telegram::TelegramBot &bot, std::string name, telegram::CommandSet *cs) : telegram::Command(bot, name, cs) { }
    
    virtual bool OnDirect(jsonserializer::structures::Update &update)
    {
        bot.SendMessage({update.GetMessage()->GetChatValue(), "pong"});
        return false;
    }
};

#endif // PING_COMMAND_H_