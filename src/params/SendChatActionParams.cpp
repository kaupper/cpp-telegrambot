#include "params/SendChatActionParams.h"

using namespace telegram::params;

SendChatActionParams::SendChatActionParams(const telegram::structures::Chat &chat, const ChatAction &action) : jsonserializer::Serializable()
{
    (*this)["chat_id"] = std::to_string(chat.GetIdValue());
    
    std::string actionString = "";
    switch(action) {
        case ChatAction::TYPING:
            actionString = "typing";
            break;
        case ChatAction::UPLOAD_PHOTO:
            actionString = "upload_photo";
            break;
        case ChatAction::RECORD_VIDEO:
            actionString = "record_video";
            break;
        case ChatAction::UPLOAD_VIDEO:
            actionString = "upload_video";
            break;
        case ChatAction::RECORD_AUDIO:
            actionString = "record_audio";
            break;
        case ChatAction::UPLOAD_AUDIO:
            actionString = "upload_audio";
            break;
        case ChatAction::UPLOAD_DOCUMENT:
            actionString = "upload_document";
            break;
        case ChatAction::FIND_LOCATION:
            actionString = "find_location";
            break;
    }
    (*this)["action"] = actionString;
}