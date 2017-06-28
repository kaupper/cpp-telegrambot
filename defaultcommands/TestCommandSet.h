#ifndef TEST_COMMAND_SET_H_
#define TEST_COMMAND_SET_H_

#include "telegram/CommandSet.h"
#include "PingCommand.h"
#include "HideCommand.h"
#include "ExitCommand.h"

class TestCommandSet : public telegram::CommandSet
{
    public:
        TestCommandSet(telegram::TelegramBot &bot) : telegram::CommandSet(bot)
        {
            RegisterCommand<PingCommand>(bot, "/ping");
            RegisterCommand<ExitCommand>(bot, "/exit");
            RegisterCommand<HideCommand>(bot, "/hide");
        }
};

#endif // TEST_COMMAND_SET_H_