#ifndef COMMAND_H_
#define COMMAND_H_

#include "jsonserializer/Generated.h"

#include "CommandException.h"


namespace telegram
{
    enum class CallType {
        NOTHING = 0,
        DIRECT = 1,
        INDIRECT = 2,
        QUIT = 4
    };

    enum class CallReason {
        NOTHING = 0,
        MESSAGE = 1,
        EDITED_MESSAGE = 2,
        INLINE_QUERY = 4,
        INLINE_RESULT = 8,
        CALLBACK_QUERY = 16
                         // ...
    };

    class TelegramBot;
    class Command
    {
        private:
            std::string name;

        protected:
            TelegramBot *bot;

        public:
            Command(TelegramBot *bot, const std::string &name);
            virtual ~Command();

            std::string GetName() const;

            bool operator()(const telegram::structures::Update &, CallReason, CallType);

            virtual void Setup();

            virtual bool OnDirect(const telegram::structures::Update &);
            virtual bool OnIndirect(const telegram::structures::Update &);
            virtual bool OnQuit(const telegram::structures::Update &);
    };
}

#endif // COMMAND_H_
