#ifndef COMMAND_H_
#define COMMAND_H_

#include "jsonserializer/StructConverter.h"
#include "generated.h"

#include "CommandException.h"

namespace telegram
{
    enum class CallType
    {
        NOTHING = 0,
        DIRECT = 1,
        INDIRECT = 2,
        QUIT = 4
    };
    
    enum class CallReason
    {
        NOTHING = 0,
        MESSAGE = 1,
        EDITED_MESSAGE = 2,
        INLINE_QUERY = 4,
        INLINE_RESULT = 8,
        CALLBACK_QUERY = 16
        // ...
    };
    
    class TelegramBot;
    class CommandSet;
    class Command
    {
    private:
        std::string name;
        CommandSet *parent;
        
    protected:
        TelegramBot &bot;
        
        bool HasParent() { return parent != nullptr; }
        const std::vector<Command *> & GetParentCommands() const;
    
    public:
        Command(TelegramBot &bot, std::string name, CommandSet *parent = nullptr) : name(name), parent(parent), bot(bot) { }
        virtual ~Command() { }
        
        void SetName(std::string n) { name = n; } 
        const std::string & GetName() const { return name; }
        
        bool operator()(telegram::structures::Update &, CallReason, CallType);
        
        virtual void Setup() { }
        
        virtual bool OnDirect(telegram::structures::Update &) { throw CommandException("Method OnDirect is not implemented!"); }
        virtual bool OnIndirect(telegram::structures::Update &) { throw CommandException("Method OnIndirect is not implemented!"); }
        virtual bool OnQuit(telegram::structures::Update &) { throw CommandException("Method OnQuit is not implemented!"); }
    };
}

#endif // COMMAND_H_
