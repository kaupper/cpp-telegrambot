#ifndef TEST_COMMAND_H_
#define TEST_COMMAND_H_

#include "telegram/Command.h"
#include "skyforge/SkyforgeRequests.h"
#include "telegram/params/SendMessageParams.h"

class TestCommand : public telegram::Command
{
public:
    TestCommand(telegram::TelegramBot &bot, std::string name, telegram::CommandSet *cs) : telegram::Command(bot, name, cs) { }
    
    virtual bool OnDirect(telegram::structures::Update &update)
    {
        (void) update;
        skyforge::SkyforgeRequests sf;
        sf.Authenticate("s.kaupper@gmx.at", "kaupperbasti1996");
        /*
        bot.GetDataStore()["seas"] = new telegram::IntStorage(1234);
        telegram::Storage *tmp = bot.GetDataStore()["seas"];
        int i = -1;
        if(tmp->GetType() == "int") {
            i = ((telegram::IntStorage *) tmp)->GetInt();
        }
        bot.SendMessage({update.GetMessage()->GetChatValue(), "create data in data store with value " + std::to_string(i)});
        */
        return false;
    }
};

#endif // TEST_COMMAND_H_