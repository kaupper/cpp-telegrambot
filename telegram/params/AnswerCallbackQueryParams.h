#ifndef ANSWER_CALLBACK_QUERY_PARAMS_H_
#define ANSWER_CALLBACK_QUERY_PARAMS_H_

#include "jsonserializer/Serializable.h"
#include "jsonserializer/StructConverter.h"

#include "telegram/TelegramBot.h"

namespace telegram::params
{
    class AnswerCallbackQueryParams : public jsonserializer::Serializable
    {
    public:
        AnswerCallbackQueryParams(const std::string &callbackQueryId);
            
        AnswerCallbackQueryParams & SetText(const std::string &);
        AnswerCallbackQueryParams & SetShowAlert(bool);
    };  
}

#endif // ANSWER_CALLBACK_QUERY_PARAMS_H_
