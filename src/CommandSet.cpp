#include "CommandSet.h"
#include "TelegramBot.h"

using namespace telegram;
using namespace telegram::structures;


CallReason CommandSet::GetReason(const Update &update) const
{
    CallReason reason = CallReason::NOTHING;

    if (update.message != nullptr) {
        reason = CallReason::MESSAGE;
    } else if (update.editedMessage != nullptr) {
        reason = CallReason::EDITED_MESSAGE;
    } else if (update.inlineQuery != nullptr) {
        reason = CallReason::INLINE_QUERY;
    } else if (update.inlineQuery != nullptr) {
        reason = CallReason::INLINE_RESULT;
    } else if (update.inlineQuery != nullptr) {
        reason = CallReason::CALLBACK_QUERY;
    }

    return reason;
}

CommandSet::~CommandSet()
{
    for (auto command : commands) {
        delete command;
    }
}

bool CommandSet::Process(Update &update)
{
    CallReason reason = GetReason(update);
    std::string cmd = *(update.GetMessage()->GetText());

    // check if cmd is a valid command
    // (/<cmd> [args])
    if (cmd != "") {
        if (!cmd.empty() && cmd.front() == '/') {
            cmd = cmd.substr(0, cmd.find(" "));
        } else {
            cmd = "";
        }
    }

    auto atPosition = std::string::npos;
    bool breakLoop = false;

    for (auto command : commands) {
        bool result = false;

        switch (reason) {
            case CallReason::MESSAGE: {
                // an empty name is not allowed!
                if (command->GetName() == "") {
                    Logger::warn << "Commands with empty names are no allowed!" << std::endl;
                    continue;
                }

                // commands like /<cmd>@<botname> must be filtered by us
                if (cmd != "" && (atPosition = cmd.find("@")) != std::string::npos
                        && cmd.substr(atPosition + 1) != bot->Get("botName").get<std::string>()) {
                    Logger::warn << "Command \"" << cmd << "\" addresses another bot!" << std::endl;
                    continue;
                }

                if (atPosition != std::string::npos) {
                    cmd = cmd.substr(0, atPosition);
                    atPosition = std::string::npos;
                }

                // used to store CallType of command being called
                // will be printed in case of an exception together with the commands name
                CallType type = CallType::NOTHING;
                Command *commandCalled = command;
                // default value
                // in case we found the right command
                // we will not need to iterate further
                breakLoop = true;

                try {
                    // if current command name matches with the received command
                    // invoke it with CallType DIRECT
                    if (cmd == command->GetName()) {
                        // if we have a command stored
                        // and its name does not match with the received command
                        // invoke it with CallType QUIT
                        if (lastCommand != nullptr && lastCommand->GetName() != cmd) {
                            commandCalled = lastCommand;
                            lastCommand->operator()(update, reason, (type = CallType::QUIT));
                        }

                        commandCalled = command;
                        // invoke the current command
                        result = command->operator()(update, reason, (type = CallType::DIRECT));

                        // a result of true means that we should store the command
                        // otherwise we will set lastCommand to NULL
                        if (result) {
                            lastCommand = command;
                        } else {
                            lastCommand = nullptr;
                        }
                    }
                    // if the received command is empty or invalid
                    // and the current command matches the stored command
                    // invoke it with CallType INDIRECT
                    else if (cmd == "" && lastCommand != nullptr && command->GetName() == lastCommand->GetName()) {
                        commandCalled = lastCommand;
                        result = lastCommand->operator()(update, reason, (type = CallType::INDIRECT));

                        if (!result) {
                            // signal the command that we are going to drop it
                            lastCommand->operator()(update, reason, (type = CallType::QUIT));
                            lastCommand = nullptr;
                        }
                    }
                    // we did not found the right command
                    // do not break the loop!
                    else {
                        breakLoop = false;
                    }
                } catch (const std::runtime_error &ex) {
                    std::string typeString = "";

                    switch (type) {
                        case CallType::DIRECT:
                            typeString = "direct";
                            break;

                        case CallType::INDIRECT:
                            typeString = "indirect";
                            break;

                        case CallType::QUIT:
                            typeString = "quit";
                            break;

                        case CallType::NOTHING:
                            break;
                    }

                    Logger::error << "Command " << commandCalled->GetName() << " failed on " << typeString << " call!"
                                  << std::endl;
                    Logger::error << "Reason: " << ex.what() << std::endl;
                }

                break;
            }

            case CallReason::EDITED_MESSAGE:
            case CallReason::INLINE_QUERY:
            case CallReason::INLINE_RESULT:
            case CallReason::CALLBACK_QUERY:
            case CallReason::NOTHING:
            default:
                break;
        }

        if (breakLoop) {
            return true;
        }
    }

    // the break loop flag states if we had found a command
    // to process our update
    return breakLoop;
}
