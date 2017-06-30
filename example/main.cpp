#include "telegram/TelegramBot.h"

using namespace telegram;
using namespace telegram::structures;
using namespace telegram::request;


class ExitCommand : public telegram::Command
{
    public:
        using Command::Command;
        
        bool OnDirect(const Update &) override
        {
            bot->Set(false, "running");
            return false;
        }
};

class HideCommand : public telegram::Command
{
    public:
        using Command::Command;
        
        bool OnDirect(const Update &update) override
        {
            SendMessageParams params(update.GetMessage()->GetChatValue().GetIdValue(),
                                     "Hide the keyboard");
            ReplyMarkup replyMarkup;
            replyMarkup.SetReplyKeyboardHide({true});
            params.SetReplyMarkup(replyMarkup);
            bot->SendMessage(params);
            return false;
        }
};

class TestCommandSet : public telegram::CommandSet
{
    public:
        TestCommandSet(telegram::TelegramBot *bot) : telegram::CommandSet(bot)
        {
            RegisterCommand<ExitCommand>(bot, "/exit");
            RegisterCommand<HideCommand>(bot, "/hide");
        }
};


void ping(TelegramBot *bot, const Update &update)
{
    bot->SendMessage({update.GetMessageValue().GetChatValue().GetIdValue(), "pong"});
}

void store(TelegramBot *bot, const Update &update)
{
    bot->Set("test", "store", "field");
    bot->Set(123, "store", "field2");
}

void sendFile(TelegramBot *bot, const Update &update)
{
    bot->SendDocument({update.GetMessageValue().GetChatValue().GetIdValue(), "./Makefile"});
}

int main()
{
    telegram::TelegramBot bot("90987199:AAF9qXVq0fhy1sL4uY0NEyJEGm8PqzxU_Wc");
    bot.RegisterCommandSet<TestCommandSet>();
    bot.RegisterCommand("/ping", ping);
    bot.RegisterCommand("/store", store);
    bot.RegisterCommand("/file", sendFile);
    bot.Start();
    return 0;
}