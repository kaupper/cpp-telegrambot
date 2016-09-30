#include "TelegramBotUtilities.h"

using namespace telegram;
using namespace telegram::params;
using namespace telegram::structures;


InlineKeyboardButton TelegramBotUtilities::IBData(const std::string &text, const std::string &callbackData)
{
    InlineKeyboardButton button(text);
    button.SetCallbackData(callbackData);
    return button;
}

InlineKeyboardButton TelegramBotUtilities::IBUrl(const std::string &text, const std::string &url)
{
    InlineKeyboardButton button(text);
    button.SetUrl(url);
    return button;
}

InlineKeyboardButton TelegramBotUtilities::IBQuery(const std::string &text, const std::string &switchInlineQuery)
{
    InlineKeyboardButton button(text);
    button.SetSwitchInlineQuery(switchInlineQuery);
    return button;
}


InlineQueryResult TelegramBotUtilities::IQRArticle(const std::string &id, const std::string &title, const structures::InputMessageContent &content)
{
    InlineQueryResultArticle article(title, content);
    InlineQueryResult result("article", id);
    result.SetArticle(article);
    return result;
}


InputMessageContent TelegramBotUtilities::IMCText(const std::string &text)
{
    InputTextMessageContent content(text);
    InputMessageContent resultContent;
    resultContent.SetText(content);
    return resultContent;
}

EditMessageTextParams TelegramBotUtilities::EMTParams(const std::string &text, const std::string &chatId, int messageId)
{
    EditMessageTextParams params(text);
    params.SetChatId(chatId);
    params.SetMessageId(messageId);
    return params;
}

EditMessageTextParams TelegramBotUtilities::EMTParamsInline(const std::string &text, const std::string &inlineMessageId)
{
    EditMessageTextParams params(text);
    params.SetInlineMessageId(inlineMessageId);
    return params;
}