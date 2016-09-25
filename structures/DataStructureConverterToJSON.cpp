#include <string>
#include <vector>
#include "DataStructures.h"
#include "templates/ToJSONTemplates.cpp"

using namespace telegram::structures; 
    
namespace jsonserializer::structures
{
    template <> Serializable Converter::ToJSON(const Update &obj)
    {
        Serializable s;
        REQ(s, "update_id", obj.updateId);
        OPT(s, "message", obj.message);
        OPT(s, "edited_message", obj.editedMessage);
        OPT(s, "inline_query", obj.inlineQuery);
        OPT(s, "chosen_inline_result", obj.chosenInlineResult);
        OPT(s, "callback_query", obj.callbackQuery);
        return s;
    }

    template <> Serializable Converter::ToJSON(const User &obj)
    {
        Serializable s;
        REQ(s, "id", obj.id);
        REQ(s, "first_name", obj.firstName);
        OPT(s, "last_name", obj.lastName);
        OPT(s, "username", obj.userName);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Chat &obj)
    {
        Serializable s;
        REQ(s, "id", obj.id);
        REQ(s, "type", obj.type);
        OPT(s, "title", obj.title);
        OPT(s, "username", obj.userName);
        OPT(s, "first_name", obj.firstName);
        OPT(s, "last_name", obj.lastName);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Message &obj)
    {
        Serializable s;
        REQ(s, "message_id", obj.messageId);
        OPT(s, "from", obj.from);
        REQ(s, "date", obj.date);
        REQ(s, "chat", obj.chat);
        OPT(s, "forward_from", obj.forwardFrom);
        OPT(s, "forward_from_chat", obj.forwardFromChat);
        OPT(s, "forward_date", obj.forwardDate);
        OPT(s, "reply_to_message", obj.replyToMessage);
        OPT(s, "edit_date", obj.editDate);
        OPT(s, "text", obj.text);
        OPT(s, "entities", obj.entities);
        OPT(s, "audio", obj.audio);
        OPT(s, "document", obj.document);
        OPT(s, "photo", obj.photo);
        OPT(s, "sticker", obj.sticker);
        OPT(s, "video", obj.video);
        OPT(s, "voice", obj.voice);
        OPT(s, "caption", obj.caption);
        OPT(s, "contact", obj.contact);
        OPT(s, "location", obj.location);
        OPT(s, "venue", obj.venue);
        OPT(s, "new_chat_member", obj.newChatMember);
        OPT(s, "left_chat_member", obj.leftChatMember);
        OPT(s, "new_chat_title", obj.newChatTitle);
        OPT(s, "new_chat_photo", obj.newChatPhoto);
        OPT(s, "delete_chat_photo", obj.deleteChatPhoto);
        OPT(s, "group_chat_created", obj.groupChatCreated);
        OPT(s, "supegroup_chat_created", obj.superGroupChatCreated);
        OPT(s, "channel_chat_created", obj.channelChatCreated);
        OPT(s, "migrate_to_chat_id", obj.migrateToChatId);
        OPT(s, "migrate_from_chat_id", obj.migrateFromChatId);
        OPT(s, "pinned_message", obj.pinnedMessage);
        return s;
    }

    template <> Serializable Converter::ToJSON(const MessageEntity &obj)
    {
        Serializable s;
        REQ(s, "type", obj.type);
        REQ(s, "offset", obj.offset);
        REQ(s, "length", obj.length);
        OPT(s, "url", obj.url);
        OPT(s, "user", obj.user);
        return s;
    }

    template <> Serializable Converter::ToJSON(const PhotoSize &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        REQ(s, "width", obj.width);
        REQ(s, "height", obj.height);
        OPT(s, "file_size", obj.fileSize);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Audio &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        REQ(s, "duration", obj.duration);
        OPT(s, "performer", obj.performer);
        OPT(s, "title", obj.title);
        OPT(s, "mime_type", obj.mimeType);
        OPT(s, "file_size", obj.fileSize);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Document &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        OPT(s, "thumb", obj.thumb);
        OPT(s, "file_name", obj.fileName);
        OPT(s, "mime_type", obj.mimeType);
        OPT(s, "file_size", obj.fileSize);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Sticker &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        REQ(s, "width", obj.width);
        REQ(s, "height", obj.height);
        OPT(s, "thumb", obj.thumb);
        OPT(s, "emoji", obj.emoji);
        OPT(s, "file_size", obj.fileSize);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Video &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        REQ(s, "width", obj.width);
        REQ(s, "height", obj.height);
        REQ(s, "duration", obj.duration);
        OPT(s, "thumb", obj.thumb);
        OPT(s, "mime_type", obj.mimeType);
        OPT(s, "file_size", obj.fileSize);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Voice &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        REQ(s, "duration", obj.duration);
        OPT(s, "mime_type", obj.mimeType);
        OPT(s, "file_size", obj.fileSize);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Contact &obj)
    {
        Serializable s;
        REQ(s, "phone_number", obj.phoneNumber);
        REQ(s, "first_name", obj.firstName);
        OPT(s, "last_name", obj.lastName);
        OPT(s, "user_id", obj.userId);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Location &obj)
    {
        Serializable s;
        REQ(s, "longitude", obj.longitude);
        REQ(s, "latitude", obj.latitude);
        return s;
    }

    template <> Serializable Converter::ToJSON(const Venue &obj)
    {
        Serializable s;
        REQ(s, "location", obj.location);
        REQ(s, "title", obj.title);
        REQ(s, "address", obj.address);
        OPT(s, "foursquare_id", obj.foursquareId);
        return s;
    }

    template <> Serializable Converter::ToJSON(const UserProfilePhotos &obj)
    {
        Serializable s;
        REQ(s, "total_count", obj.totalCount);
        REQ(s, "photos", obj.photos);
        return s;
    }

    template <> Serializable Converter::ToJSON(const File &obj)
    {
        Serializable s;
        REQ(s, "file_id", obj.fileId);
        OPT(s, "file_size", obj.fileSize);
        OPT(s, "file_path", obj.filePath);
        return s;
    }

    template <> Serializable Converter::ToJSON(const ReplyKeyboardMarkup &obj)
    {
        Serializable s;
        REQ(s, "keyboard", obj.keyboard);
        OPT(s, "resize_keyboard", obj.resizeKeyboard);
        OPT(s, "one_time_keyboard", obj.oneTimeKeyboard);
        OPT(s, "selective", obj.selective);
        return s;
    }

    template <> Serializable Converter::ToJSON(const KeyboardButton &obj)
    {
        Serializable s;
        REQ(s, "text", obj.text);
        OPT(s, "request_contact", obj.requestContact);
        OPT(s, "request_location", obj.requestLocation);
        return s;
    }

    template <> Serializable Converter::ToJSON(const ReplyKeyboardHide &obj)
    {
        Serializable s;
        REQ(s, "hide_keyboard", obj.hideKeyboard);
        OPT(s, "selective", obj.selective);
        return s;
    }

    template <> Serializable Converter::ToJSON(const InlineKeyboardMarkup &obj)
    {
        Serializable s;
        REQ(s, "inline_keyboard", obj.inlineKeyboard);
        return s;
    }

    template <> Serializable Converter::ToJSON(const InlineKeyboardButton &obj)
    {
        Serializable s;
        REQ(s, "text", obj.text);
        OPT(s, "url", obj.url);
        OPT(s, "callback_data", obj.callbackData);
        OPT(s, "switch_inline_query", obj.switchInlineQuery);
        return s;
    }

    template <> Serializable Converter::ToJSON(const CallbackQuery &obj)
    {
        Serializable s;
        REQ(s, "id", obj.id);
        REQ(s, "from", obj.from);
        OPT(s, "message", obj.message);
        OPT(s, "inline_message_id", obj.inlineMessageId);
        REQ(s, "data", obj.data);
        return s;
    }

    template <> Serializable Converter::ToJSON(const ForceReply &obj)
    {
        Serializable s;
        REQ(s, "force_reply", obj.forceReply);
        OPT(s, "selective", obj.selective);
        return s;
    }

    template <> Serializable Converter::ToJSON(const ChatMember &obj)
    {
        Serializable s;
        REQ(s, "user", obj.user);
        REQ(s, "status", obj.status);
        return s;
    }

    template <> Serializable Converter::ToJSON(const InlineQuery &obj)
    {
        Serializable s;
        REQ(s, "id", obj.id);
        REQ(s, "from", obj.from);
        OPT(s, "location", obj.location);
        REQ(s, "query", obj.query);
        REQ(s, "offset", obj.offset);
        return s;
    }

    template <> Serializable Converter::ToJSON(const ChosenInlineResult &obj)
    {
        Serializable s;
        REQ(s, "result_id", obj.resultId);
        REQ(s, "from", obj.from);
        OPT(s, "location", obj.location);
        OPT(s, "inline_message_id", obj.inlineMessageId);
        REQ(s, "query", obj.query);
        return s;
    }
}
