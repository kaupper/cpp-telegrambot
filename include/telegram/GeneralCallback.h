#ifndef GENERAL_CALLBACK_H_
#define GENERAL_CALLBACK_H_

#include "jsonserializer/RequestConverter.h"


namespace telegram
{
    class GeneralCallback
    {
        protected:
            TelegramBot &bot;
            
        public:
            GeneralCallback(TelegramBot &bot) : bot(bot) { }
            virtual void Call(telegram::structures::Update &update) = 0;
    };
}

#endif // GENERAL_CALLBACK_H_
