#include "params/AnswerCallbackQueryParams.h"

using namespace telegram::params;

AnswerCallbackQueryParams::AnswerCallbackQueryParams(const std::string &callbackQueryId) : jsonserializer::Serializable()
{
    (*this)["callback_query_id"] = callbackQueryId;
}

AnswerCallbackQueryParams & AnswerCallbackQueryParams::SetText(const std::string &text)
{
    (*this)["text"] = text;
    return *this;
}

AnswerCallbackQueryParams & AnswerCallbackQueryParams::SetShowAlert(bool showAlert)
{
    (*this)["show_alert"] = (showAlert ? "true" : "false");
    return *this;
}