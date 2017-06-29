#ifndef COMMAND_SET_H_
#define COMMAND_SET_H_

#include "Command.h"

namespace telegram
{
    class TelegramBot;
    class CommandSet
    {
            friend class TelegramBot;
            friend class Command;
        private:
            Command *lastCommand;
            std::vector<Command *> commands;

            CallReason GetReason(const telegram::structures::Update &) const;

        protected:
            TelegramBot *bot;

            template <typename T, typename = typename std::enable_if<std::is_base_of<Command, T>::value>::type>
            T & RegisterCommand(TelegramBot *bot, const std::string &name)
            {
                commands.push_back(new T(bot, name, this));
                T *newCommand = (T *) commands.at(commands.size() - 1);
                newCommand->Setup();
                return (T &) * newCommand;
            }

        public:
            CommandSet(TelegramBot *bot) : lastCommand(nullptr), bot(bot) { }
            virtual ~CommandSet();

            virtual void Setup() { }

            bool Process(telegram::structures::Update &update);
            void ResetLastCommand()
            {
                lastCommand = nullptr;
            }
    };
}

#endif // COMMAND_SET_H_