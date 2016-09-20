#include "Command.h"
#include "CommandSet.h"

using namespace telegram;

bool Command::operator()(jsonserializer::structures::Update &update, CallReason reason, CallType type)
{
    if(reason == CallReason::MESSAGE) {
        switch(type) {
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

const std::vector<Command *> & Command::GetParentCommands() const
{ 
    return parent->commands; 
}