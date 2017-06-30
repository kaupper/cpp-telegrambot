#include "Command.h"
#include "CommandSet.h"

using namespace telegram;


Command::Command(TelegramBot *bot, const std::string &name)
    : name(name), bot(bot)
{
}

Command::~Command()
{
}

bool Command::operator()(const telegram::structures::Update &update, CallReason reason,
                         CallType type)
{
    if (reason == CallReason::MESSAGE) {
        switch (type) {
            case CallType::DIRECT:
                return OnDirect(update);

            case CallType::INDIRECT:
                return OnIndirect(update);

            case CallType::QUIT:
                return OnQuit(update);

            case CallType::NOTHING:
                return false;
        }
    }

    // implement others!
    return false;
}

std::string Command::GetName() const
{
    return name;
}

void Command::Setup()
{
}

bool Command::OnDirect(const telegram::structures::Update &)
{
    throw CommandException("Method OnDirect is not implemented!");
}

bool Command::OnIndirect(const telegram::structures::Update &)
{
    throw CommandException("Method OnIndirect is not implemented!");
}

bool Command::OnQuit(const telegram::structures::Update &)
{
    throw CommandException("Method OnQuit is not implemented!");
}