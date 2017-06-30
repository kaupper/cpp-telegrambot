#ifndef HIDE_COMMAND_H_
#define HIDE_COMMAND_H_

#include "telegram/Command.h"
#include "jsonserializer/RequestConverter.h"


class HideCommand : public telegram::Command
{
    public:
        HideCommand(telegram::TelegramBot *bot, const std::string &name) : telegram::Command(bot, name) { }

        bool OnDirect(const telegram::structures::Update &update) override
        {
            telegram::request::SendMessageParams params(update.GetMessage()->GetChatValue().GetIdValue(), "Hide the keyboard");
            telegram::request::ReplyMarkup replyMarkup;
            replyMarkup.SetReplyKeyboardHide({true});
            params.SetReplyMarkup(replyMarkup);
            bot->SendMessage(params);
            return false;
        }
};

#endif // HIDE_COMMAND_H_
