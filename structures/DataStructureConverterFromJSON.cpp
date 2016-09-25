#include <string>
#include <vector>
#include "DataStructures.h"
#include "templates/FromJSONTemplates.cpp"

using namespace telegram::structures; 
    
namespace jsonserializer::structures
{
    template <> Update Converter::FromJSON(const Serializable &json)
    {
        Update obj;
        REQ(json, "update_id", obj.updateId);
        OPT(json, "message", obj.message);
        OPT(json, "edited_message", obj.editedMessage);
        OPT(json, "inline_query", obj.inlineQuery);
        OPT(json, "chosen_inline_result", obj.chosenInlineResult);
        OPT(json, "callback_query", obj.callbackQuery);
        return std::move(obj);
    }

    template <> User Converter::FromJSON(const Serializable &json)
    {
        User obj;
        REQ(json, "id", obj.id);
        REQ(json, "first_name", obj.firstName);
        OPT(json, "last_name", obj.lastName);
        OPT(json, "username", obj.userName);
        return std::move(obj);
    }

    template <> Chat Converter::FromJSON(const Serializable &json)
    {
        Chat obj;
        REQ(json, "id", obj.id);
        REQ(json, "type", obj.type);
        OPT(json, "title", obj.title);
        OPT(json, "username", obj.userName);
        OPT(json, "first_name", obj.firstName);
        OPT(json, "last_name", obj.lastName);
        return std::move(obj);
    }

    template <> Message Converter::FromJSON(const Serializable &json)
    {
        Message obj;
        REQ(json, "message_id", obj.messageId);
        OPT(json, "from", obj.from);
        REQ(json, "date", obj.date);
        REQ(json, "chat", obj.chat);
        OPT(json, "forward_from", obj.forwardFrom);
        OPT(json, "forward_from_chat", obj.forwardFromChat);
        OPT(json, "forward_date", obj.forwardDate);
        OPT(json, "reply_to_message", obj.replyToMessage);
        OPT(json, "edit_date", obj.editDate);
        OPT(json, "text", obj.text);
        OPT(json, "entities", obj.entities);
        OPT(json, "audio", obj.audio);
        OPT(json, "document", obj.document);
        OPT(json, "photo", obj.photo);
        OPT(json, "sticker", obj.sticker);
        OPT(json, "video", obj.video);
        OPT(json, "voice", obj.voice);
        OPT(json, "caption", obj.caption);
        OPT(json, "contact", obj.contact);
        OPT(json, "location", obj.location);
        OPT(json, "venue", obj.venue);
        OPT(json, "new_chat_member", obj.newChatMember);
        OPT(json, "left_chat_member", obj.leftChatMember);
        OPT(json, "new_chat_title", obj.newChatTitle);
        OPT(json, "new_chat_photo", obj.newChatPhoto);
        OPT(json, "delete_chat_photo", obj.deleteChatPhoto);
        OPT(json, "group_chat_created", obj.groupChatCreated);
        OPT(json, "supegroup_chat_created", obj.superGroupChatCreated);
        OPT(json, "channel_chat_created", obj.channelChatCreated);
        OPT(json, "migrate_to_chat_id", obj.migrateToChatId);
        OPT(json, "migrate_from_chat_id", obj.migrateFromChatId);
        OPT(json, "pinned_message", obj.pinnedMessage);
        return std::move(obj);
    }

    template <> MessageEntity Converter::FromJSON(const Serializable &json)
    {
        MessageEntity obj;
        REQ(json, "type", obj.type);
        REQ(json, "offset", obj.offset);
        REQ(json, "length", obj.length);
        OPT(json, "url", obj.url);
        OPT(json, "user", obj.user);
        return std::move(obj);
    }

    template <> PhotoSize Converter::FromJSON(const Serializable &json)
    {
        PhotoSize obj;
        REQ(json, "file_id", obj.fileId);
        REQ(json, "width", obj.width);
        REQ(json, "height", obj.height);
        OPT(json, "file_size", obj.fileSize);
        return std::move(obj);
    }

    template <> Audio Converter::FromJSON(const Serializable &json)
    {
        Audio obj;
        REQ(json, "file_id", obj.fileId);
        REQ(json, "duration", obj.duration);
        OPT(json, "performer", obj.performer);
        OPT(json, "title", obj.title);
        OPT(json, "mime_type", obj.mimeType);
        OPT(json, "file_size", obj.fileSize);
        return std::move(obj);
    }

    template <> Document Converter::FromJSON(const Serializable &json)
    {
        Document obj;
        REQ(json, "file_id", obj.fileId);
        OPT(json, "thumb", obj.thumb);
        OPT(json, "file_name", obj.fileName);
        OPT(json, "mime_type", obj.mimeType);
        OPT(json, "file_size", obj.fileSize);
        return std::move(obj);
    }

    template <> Sticker Converter::FromJSON(const Serializable &json)
    {
        Sticker obj;
        REQ(json, "file_id", obj.fileId);
        REQ(json, "width", obj.width);
        REQ(json, "height", obj.height);
        OPT(json, "thumb", obj.thumb);
        OPT(json, "emoji", obj.emoji);
        OPT(json, "file_size", obj.fileSize);
        return std::move(obj);
    }

    template <> Video Converter::FromJSON(const Serializable &json)
    {
        Video obj;
        REQ(json, "file_id", obj.fileId);
        REQ(json, "width", obj.width);
        REQ(json, "height", obj.height);
        REQ(json, "duration", obj.duration);
        OPT(json, "thumb", obj.thumb);
        OPT(json, "mime_type", obj.mimeType);
        OPT(json, "file_size", obj.fileSize);
        return std::move(obj);
    }

    template <> Voice Converter::FromJSON(const Serializable &json)
    {
        Voice obj;
        REQ(json, "file_id", obj.fileId);
        REQ(json, "duration", obj.duration);
        OPT(json, "mime_type", obj.mimeType);
        OPT(json, "file_size", obj.fileSize);
        return std::move(obj);
    }

    template <> Contact Converter::FromJSON(const Serializable &json)
    {
        Contact obj;
        REQ(json, "phone_number", obj.phoneNumber);
        REQ(json, "first_name", obj.firstName);
        OPT(json, "last_name", obj.lastName);
        OPT(json, "user_id", obj.userId);
        return std::move(obj);
    }

    template <> Location Converter::FromJSON(const Serializable &json)
    {
        Location obj;
        REQ(json, "longitude", obj.longitude);
        REQ(json, "latitude", obj.latitude);
        return std::move(obj);
    }

    template <> Venue Converter::FromJSON(const Serializable &json)
    {
        Venue obj;
        REQ(json, "location", obj.location);
        REQ(json, "title", obj.title);
        REQ(json, "address", obj.address);
        OPT(json, "foursquare_id", obj.foursquareId);
        return std::move(obj);
    }

    template <> UserProfilePhotos Converter::FromJSON(const Serializable &json)
    {
        UserProfilePhotos obj;
        REQ(json, "total_count", obj.totalCount);
        REQ(json, "photos", obj.photos);
        return std::move(obj);
    }

    template <> File Converter::FromJSON(const Serializable &json)
    {
        File obj;
        REQ(json, "file_id", obj.fileId);
        OPT(json, "file_size", obj.fileSize);
        OPT(json, "file_path", obj.filePath);
        return std::move(obj);
    }

    template <> ReplyKeyboardMarkup Converter::FromJSON(const Serializable &json)
    {
        ReplyKeyboardMarkup obj;
        REQ(json, "keyboard", obj.keyboard);
        OPT(json, "resize_keyboard", obj.resizeKeyboard);
        OPT(json, "one_time_keyboard", obj.oneTimeKeyboard);
        OPT(json, "selective", obj.selective);
        return std::move(obj);
    }

    template <> KeyboardButton Converter::FromJSON(const Serializable &json)
    {
        KeyboardButton obj;
        REQ(json, "text", obj.text);
        OPT(json, "request_contact", obj.requestContact);
        OPT(json, "request_location", obj.requestLocation);
        return std::move(obj);
    }

    template <> ReplyKeyboardHide Converter::FromJSON(const Serializable &json)
    {
        ReplyKeyboardHide obj;
        REQ(json, "hide_keyboard", obj.hideKeyboard);
        OPT(json, "selective", obj.selective);
        return std::move(obj);
    }

    template <> InlineKeyboardMarkup Converter::FromJSON(const Serializable &json)
    {
        InlineKeyboardMarkup obj;
        REQ(json, "inline_keyboard", obj.inlineKeyboard);
        return std::move(obj);
    }

    template <> InlineKeyboardButton Converter::FromJSON(const Serializable &json)
    {
        InlineKeyboardButton obj;
        REQ(json, "text", obj.text);
        OPT(json, "url", obj.url);
        OPT(json, "callback_data", obj.callbackData);
        OPT(json, "switch_inline_query", obj.switchInlineQuery);
        return std::move(obj);
    }

    template <> CallbackQuery Converter::FromJSON(const Serializable &json)
    {
        CallbackQuery obj;
        REQ(json, "id", obj.id);
        REQ(json, "from", obj.from);
        OPT(json, "message", obj.message);
        OPT(json, "inline_message_id", obj.inlineMessageId);
        REQ(json, "data", obj.data);
        return std::move(obj);
    }

    template <> ForceReply Converter::FromJSON(const Serializable &json)
    {
        ForceReply obj;
        REQ(json, "force_reply", obj.forceReply);
        OPT(json, "selective", obj.selective);
        return std::move(obj);
    }

    template <> ChatMember Converter::FromJSON(const Serializable &json)
    {
        ChatMember obj;
        REQ(json, "user", obj.user);
        REQ(json, "status", obj.status);
        return std::move(obj);
    }

    template <> InlineQuery Converter::FromJSON(const Serializable &json)
    {
        InlineQuery obj;
        REQ(json, "id", obj.id);
        REQ(json, "from", obj.from);
        OPT(json, "location", obj.location);
        REQ(json, "query", obj.query);
        REQ(json, "offset", obj.offset);
        return std::move(obj);
    }

    template <> ChosenInlineResult Converter::FromJSON(const Serializable &json)
    {
        ChosenInlineResult obj;
        REQ(json, "result_id", obj.resultId);
        REQ(json, "from", obj.from);
        OPT(json, "location", obj.location);
        OPT(json, "inline_message_id", obj.inlineMessageId);
        REQ(json, "query", obj.query);
        return std::move(obj);
    }
}
