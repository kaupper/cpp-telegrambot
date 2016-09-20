#ifndef HIDE_COMMAND_H_
#define HIDE_COMMAND_H_

#include "telegram/Command.h"
#include "telegram/params/SendMessageParams.h"

class HideCommand : public telegram::Command
{
public:
    HideCommand(telegram::TelegramBot &bot, std::string name, telegram::CommandSet *cs) : telegram::Command(bot, name, cs) { }
    
    virtual bool OnDirect(jsonserializer::structures::Update &update)
    {
        telegram::params::SendMessageParams params(update.message->GetChatValue(), "Hide the keyboard");
        params.SetReplyMarkup(jsonserializer::structures::ReplyKeyboardHide(true));
        bot.SendMessage(params);
        return false;
    }
};

#endif // HIDE_COMMAND_H_