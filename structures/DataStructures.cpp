#include <string>
#include <vector>
#include "DataStructures.h"

using namespace telegram::structures;

template <typename T> T * deepCopyPointer(T * pointer) {
    if (pointer == nullptr) {
        return nullptr;
    }
    return new T(*pointer);
}

static Update & copy(Update &lhs, const Update &rhs)
{
    lhs.updateId = deepCopyPointer(rhs.updateId);
    lhs.message = deepCopyPointer(rhs.message);
    lhs.editedMessage = deepCopyPointer(rhs.editedMessage);
    lhs.inlineQuery = deepCopyPointer(rhs.inlineQuery);
    lhs.chosenInlineResult = deepCopyPointer(rhs.chosenInlineResult);
    lhs.callbackQuery = deepCopyPointer(rhs.callbackQuery);
    return lhs;
}

static User & copy(User &lhs, const User &rhs)
{
    lhs.id = deepCopyPointer(rhs.id);
    lhs.firstName = deepCopyPointer(rhs.firstName);
    lhs.lastName = deepCopyPointer(rhs.lastName);
    lhs.userName = deepCopyPointer(rhs.userName);
    return lhs;
}

static Chat & copy(Chat &lhs, const Chat &rhs)
{
    lhs.id = deepCopyPointer(rhs.id);
    lhs.type = deepCopyPointer(rhs.type);
    lhs.title = deepCopyPointer(rhs.title);
    lhs.userName = deepCopyPointer(rhs.userName);
    lhs.firstName = deepCopyPointer(rhs.firstName);
    lhs.lastName = deepCopyPointer(rhs.lastName);
    return lhs;
}

static Message & copy(Message &lhs, const Message &rhs)
{
    lhs.messageId = deepCopyPointer(rhs.messageId);
    lhs.from = deepCopyPointer(rhs.from);
    lhs.date = deepCopyPointer(rhs.date);
    lhs.chat = deepCopyPointer(rhs.chat);
    lhs.forwardFrom = deepCopyPointer(rhs.forwardFrom);
    lhs.forwardFromChat = deepCopyPointer(rhs.forwardFromChat);
    lhs.forwardDate = deepCopyPointer(rhs.forwardDate);
    lhs.replyToMessage = deepCopyPointer(rhs.replyToMessage);
    lhs.editDate = deepCopyPointer(rhs.editDate);
    lhs.text = deepCopyPointer(rhs.text);
    lhs.entities = deepCopyPointer(rhs.entities);
    lhs.audio = deepCopyPointer(rhs.audio);
    lhs.document = deepCopyPointer(rhs.document);
    lhs.photo = deepCopyPointer(rhs.photo);
    lhs.sticker = deepCopyPointer(rhs.sticker);
    lhs.video = deepCopyPointer(rhs.video);
    lhs.voice = deepCopyPointer(rhs.voice);
    lhs.caption = deepCopyPointer(rhs.caption);
    lhs.contact = deepCopyPointer(rhs.contact);
    lhs.location = deepCopyPointer(rhs.location);
    lhs.venue = deepCopyPointer(rhs.venue);
    lhs.newChatMember = deepCopyPointer(rhs.newChatMember);
    lhs.leftChatMember = deepCopyPointer(rhs.leftChatMember);
    lhs.newChatTitle = deepCopyPointer(rhs.newChatTitle);
    lhs.newChatPhoto = deepCopyPointer(rhs.newChatPhoto);
    lhs.deleteChatPhoto = deepCopyPointer(rhs.deleteChatPhoto);
    lhs.groupChatCreated = deepCopyPointer(rhs.groupChatCreated);
    lhs.superGroupChatCreated = deepCopyPointer(rhs.superGroupChatCreated);
    lhs.channelChatCreated = deepCopyPointer(rhs.channelChatCreated);
    lhs.migrateToChatId = deepCopyPointer(rhs.migrateToChatId);
    lhs.migrateFromChatId = deepCopyPointer(rhs.migrateFromChatId);
    lhs.pinnedMessage = deepCopyPointer(rhs.pinnedMessage);
    return lhs;
}

static MessageEntity & copy(MessageEntity &lhs, const MessageEntity &rhs)
{
    lhs.type = deepCopyPointer(rhs.type);
    lhs.offset = deepCopyPointer(rhs.offset);
    lhs.length = deepCopyPointer(rhs.length);
    lhs.url = deepCopyPointer(rhs.url);
    lhs.user = deepCopyPointer(rhs.user);
    return lhs;
}

static PhotoSize & copy(PhotoSize &lhs, const PhotoSize &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.width = deepCopyPointer(rhs.width);
    lhs.height = deepCopyPointer(rhs.height);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    return lhs;
}

static Audio & copy(Audio &lhs, const Audio &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.duration = deepCopyPointer(rhs.duration);
    lhs.performer = deepCopyPointer(rhs.performer);
    lhs.title = deepCopyPointer(rhs.title);
    lhs.mimeType = deepCopyPointer(rhs.mimeType);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    return lhs;
}

static Document & copy(Document &lhs, const Document &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.thumb = deepCopyPointer(rhs.thumb);
    lhs.fileName = deepCopyPointer(rhs.fileName);
    lhs.mimeType = deepCopyPointer(rhs.mimeType);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    return lhs;
}

static Sticker & copy(Sticker &lhs, const Sticker &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.width = deepCopyPointer(rhs.width);
    lhs.height = deepCopyPointer(rhs.height);
    lhs.thumb = deepCopyPointer(rhs.thumb);
    lhs.emoji = deepCopyPointer(rhs.emoji);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    return lhs;
}

static Video & copy(Video &lhs, const Video &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.width = deepCopyPointer(rhs.width);
    lhs.height = deepCopyPointer(rhs.height);
    lhs.duration = deepCopyPointer(rhs.duration);
    lhs.thumb = deepCopyPointer(rhs.thumb);
    lhs.mimeType = deepCopyPointer(rhs.mimeType);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    return lhs;
}

static Voice & copy(Voice &lhs, const Voice &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.duration = deepCopyPointer(rhs.duration);
    lhs.mimeType = deepCopyPointer(rhs.mimeType);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    return lhs;
}

static Contact & copy(Contact &lhs, const Contact &rhs)
{
    lhs.phoneNumber = deepCopyPointer(rhs.phoneNumber);
    lhs.firstName = deepCopyPointer(rhs.firstName);
    lhs.lastName = deepCopyPointer(rhs.lastName);
    lhs.userId = deepCopyPointer(rhs.userId);
    return lhs;
}

static Location & copy(Location &lhs, const Location &rhs)
{
    lhs.longitude = deepCopyPointer(rhs.longitude);
    lhs.latitude = deepCopyPointer(rhs.latitude);
    return lhs;
}

static Venue & copy(Venue &lhs, const Venue &rhs)
{
    lhs.location = deepCopyPointer(rhs.location);
    lhs.title = deepCopyPointer(rhs.title);
    lhs.address = deepCopyPointer(rhs.address);
    lhs.foursquareId = deepCopyPointer(rhs.foursquareId);
    return lhs;
}

static UserProfilePhotos & copy(UserProfilePhotos &lhs, const UserProfilePhotos &rhs)
{
    lhs.totalCount = deepCopyPointer(rhs.totalCount);
    lhs.photos = deepCopyPointer(rhs.photos);
    return lhs;
}

static File & copy(File &lhs, const File &rhs)
{
    lhs.fileId = deepCopyPointer(rhs.fileId);
    lhs.fileSize = deepCopyPointer(rhs.fileSize);
    lhs.filePath = deepCopyPointer(rhs.filePath);
    return lhs;
}

static ReplyKeyboardMarkup & copy(ReplyKeyboardMarkup &lhs, const ReplyKeyboardMarkup &rhs)
{
    lhs.keyboard = deepCopyPointer(rhs.keyboard);
    lhs.resizeKeyboard = deepCopyPointer(rhs.resizeKeyboard);
    lhs.oneTimeKeyboard = deepCopyPointer(rhs.oneTimeKeyboard);
    lhs.selective = deepCopyPointer(rhs.selective);
    return lhs;
}

static KeyboardButton & copy(KeyboardButton &lhs, const KeyboardButton &rhs)
{
    lhs.text = deepCopyPointer(rhs.text);
    lhs.requestContact = deepCopyPointer(rhs.requestContact);
    lhs.requestLocation = deepCopyPointer(rhs.requestLocation);
    return lhs;
}

static ReplyKeyboardHide & copy(ReplyKeyboardHide &lhs, const ReplyKeyboardHide &rhs)
{
    lhs.hideKeyboard = deepCopyPointer(rhs.hideKeyboard);
    lhs.selective = deepCopyPointer(rhs.selective);
    return lhs;
}

static InlineKeyboardMarkup & copy(InlineKeyboardMarkup &lhs, const InlineKeyboardMarkup &rhs)
{
    lhs.inlineKeyboard = deepCopyPointer(rhs.inlineKeyboard);
    return lhs;
}

static InlineKeyboardButton & copy(InlineKeyboardButton &lhs, const InlineKeyboardButton &rhs)
{
    lhs.text = deepCopyPointer(rhs.text);
    lhs.url = deepCopyPointer(rhs.url);
    lhs.callbackData = deepCopyPointer(rhs.callbackData);
    lhs.switchInlineQuery = deepCopyPointer(rhs.switchInlineQuery);
    return lhs;
}

static CallbackQuery & copy(CallbackQuery &lhs, const CallbackQuery &rhs)
{
    lhs.id = deepCopyPointer(rhs.id);
    lhs.from = deepCopyPointer(rhs.from);
    lhs.message = deepCopyPointer(rhs.message);
    lhs.inlineMessageId = deepCopyPointer(rhs.inlineMessageId);
    lhs.data = deepCopyPointer(rhs.data);
    return lhs;
}

static ForceReply & copy(ForceReply &lhs, const ForceReply &rhs)
{
    lhs.forceReply = deepCopyPointer(rhs.forceReply);
    lhs.selective = deepCopyPointer(rhs.selective);
    return lhs;
}

static ChatMember & copy(ChatMember &lhs, const ChatMember &rhs)
{
    lhs.user = deepCopyPointer(rhs.user);
    lhs.status = deepCopyPointer(rhs.status);
    return lhs;
}

static InlineQuery & copy(InlineQuery &lhs, const InlineQuery &rhs)
{
    lhs.id = deepCopyPointer(rhs.id);
    lhs.from = deepCopyPointer(rhs.from);
    lhs.location = deepCopyPointer(rhs.location);
    lhs.query = deepCopyPointer(rhs.query);
    lhs.offset = deepCopyPointer(rhs.offset);
    return lhs;
}

static ChosenInlineResult & copy(ChosenInlineResult &lhs, const ChosenInlineResult &rhs)
{
    lhs.resultId = deepCopyPointer(rhs.resultId);
    lhs.from = deepCopyPointer(rhs.from);
    lhs.location = deepCopyPointer(rhs.location);
    lhs.inlineMessageId = deepCopyPointer(rhs.inlineMessageId);
    lhs.query = deepCopyPointer(rhs.query);
    return lhs;
}

static Update & move(Update &lhs, Update &rhs)
{
    std::swap(lhs.updateId, rhs.updateId);
    std::swap(lhs.message, rhs.message);
    std::swap(lhs.editedMessage, rhs.editedMessage);
    std::swap(lhs.inlineQuery, rhs.inlineQuery);
    std::swap(lhs.chosenInlineResult, rhs.chosenInlineResult);
    std::swap(lhs.callbackQuery, rhs.callbackQuery);
    return lhs;
}

static User & move(User &lhs, User &rhs)
{
    std::swap(lhs.id, rhs.id);
    std::swap(lhs.firstName, rhs.firstName);
    std::swap(lhs.lastName, rhs.lastName);
    std::swap(lhs.userName, rhs.userName);
    return lhs;
}

static Chat & move(Chat &lhs, Chat &rhs)
{
    std::swap(lhs.id, rhs.id);
    std::swap(lhs.type, rhs.type);
    std::swap(lhs.title, rhs.title);
    std::swap(lhs.userName, rhs.userName);
    std::swap(lhs.firstName, rhs.firstName);
    std::swap(lhs.lastName, rhs.lastName);
    return lhs;
}

static Message & move(Message &lhs, Message &rhs)
{
    std::swap(lhs.messageId, rhs.messageId);
    std::swap(lhs.from, rhs.from);
    std::swap(lhs.date, rhs.date);
    std::swap(lhs.chat, rhs.chat);
    std::swap(lhs.forwardFrom, rhs.forwardFrom);
    std::swap(lhs.forwardFromChat, rhs.forwardFromChat);
    std::swap(lhs.forwardDate, rhs.forwardDate);
    std::swap(lhs.replyToMessage, rhs.replyToMessage);
    std::swap(lhs.editDate, rhs.editDate);
    std::swap(lhs.text, rhs.text);
    std::swap(lhs.entities, rhs.entities);
    std::swap(lhs.audio, rhs.audio);
    std::swap(lhs.document, rhs.document);
    std::swap(lhs.photo, rhs.photo);
    std::swap(lhs.sticker, rhs.sticker);
    std::swap(lhs.video, rhs.video);
    std::swap(lhs.voice, rhs.voice);
    std::swap(lhs.caption, rhs.caption);
    std::swap(lhs.contact, rhs.contact);
    std::swap(lhs.location, rhs.location);
    std::swap(lhs.venue, rhs.venue);
    std::swap(lhs.newChatMember, rhs.newChatMember);
    std::swap(lhs.leftChatMember, rhs.leftChatMember);
    std::swap(lhs.newChatTitle, rhs.newChatTitle);
    std::swap(lhs.newChatPhoto, rhs.newChatPhoto);
    std::swap(lhs.deleteChatPhoto, rhs.deleteChatPhoto);
    std::swap(lhs.groupChatCreated, rhs.groupChatCreated);
    std::swap(lhs.superGroupChatCreated, rhs.superGroupChatCreated);
    std::swap(lhs.channelChatCreated, rhs.channelChatCreated);
    std::swap(lhs.migrateToChatId, rhs.migrateToChatId);
    std::swap(lhs.migrateFromChatId, rhs.migrateFromChatId);
    std::swap(lhs.pinnedMessage, rhs.pinnedMessage);
    return lhs;
}

static MessageEntity & move(MessageEntity &lhs, MessageEntity &rhs)
{
    std::swap(lhs.type, rhs.type);
    std::swap(lhs.offset, rhs.offset);
    std::swap(lhs.length, rhs.length);
    std::swap(lhs.url, rhs.url);
    std::swap(lhs.user, rhs.user);
    return lhs;
}

static PhotoSize & move(PhotoSize &lhs, PhotoSize &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.width, rhs.width);
    std::swap(lhs.height, rhs.height);
    std::swap(lhs.fileSize, rhs.fileSize);
    return lhs;
}

static Audio & move(Audio &lhs, Audio &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.duration, rhs.duration);
    std::swap(lhs.performer, rhs.performer);
    std::swap(lhs.title, rhs.title);
    std::swap(lhs.mimeType, rhs.mimeType);
    std::swap(lhs.fileSize, rhs.fileSize);
    return lhs;
}

static Document & move(Document &lhs, Document &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.thumb, rhs.thumb);
    std::swap(lhs.fileName, rhs.fileName);
    std::swap(lhs.mimeType, rhs.mimeType);
    std::swap(lhs.fileSize, rhs.fileSize);
    return lhs;
}

static Sticker & move(Sticker &lhs, Sticker &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.width, rhs.width);
    std::swap(lhs.height, rhs.height);
    std::swap(lhs.thumb, rhs.thumb);
    std::swap(lhs.emoji, rhs.emoji);
    std::swap(lhs.fileSize, rhs.fileSize);
    return lhs;
}

static Video & move(Video &lhs, Video &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.width, rhs.width);
    std::swap(lhs.height, rhs.height);
    std::swap(lhs.duration, rhs.duration);
    std::swap(lhs.thumb, rhs.thumb);
    std::swap(lhs.mimeType, rhs.mimeType);
    std::swap(lhs.fileSize, rhs.fileSize);
    return lhs;
}

static Voice & move(Voice &lhs, Voice &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.duration, rhs.duration);
    std::swap(lhs.mimeType, rhs.mimeType);
    std::swap(lhs.fileSize, rhs.fileSize);
    return lhs;
}

static Contact & move(Contact &lhs, Contact &rhs)
{
    std::swap(lhs.phoneNumber, rhs.phoneNumber);
    std::swap(lhs.firstName, rhs.firstName);
    std::swap(lhs.lastName, rhs.lastName);
    std::swap(lhs.userId, rhs.userId);
    return lhs;
}

static Location & move(Location &lhs, Location &rhs)
{
    std::swap(lhs.longitude, rhs.longitude);
    std::swap(lhs.latitude, rhs.latitude);
    return lhs;
}

static Venue & move(Venue &lhs, Venue &rhs)
{
    std::swap(lhs.location, rhs.location);
    std::swap(lhs.title, rhs.title);
    std::swap(lhs.address, rhs.address);
    std::swap(lhs.foursquareId, rhs.foursquareId);
    return lhs;
}

static UserProfilePhotos & move(UserProfilePhotos &lhs, UserProfilePhotos &rhs)
{
    std::swap(lhs.totalCount, rhs.totalCount);
    std::swap(lhs.photos, rhs.photos);
    return lhs;
}

static File & move(File &lhs, File &rhs)
{
    std::swap(lhs.fileId, rhs.fileId);
    std::swap(lhs.fileSize, rhs.fileSize);
    std::swap(lhs.filePath, rhs.filePath);
    return lhs;
}

static ReplyKeyboardMarkup & move(ReplyKeyboardMarkup &lhs, ReplyKeyboardMarkup &rhs)
{
    std::swap(lhs.keyboard, rhs.keyboard);
    std::swap(lhs.resizeKeyboard, rhs.resizeKeyboard);
    std::swap(lhs.oneTimeKeyboard, rhs.oneTimeKeyboard);
    std::swap(lhs.selective, rhs.selective);
    return lhs;
}

static KeyboardButton & move(KeyboardButton &lhs, KeyboardButton &rhs)
{
    std::swap(lhs.text, rhs.text);
    std::swap(lhs.requestContact, rhs.requestContact);
    std::swap(lhs.requestLocation, rhs.requestLocation);
    return lhs;
}

static ReplyKeyboardHide & move(ReplyKeyboardHide &lhs, ReplyKeyboardHide &rhs)
{
    std::swap(lhs.hideKeyboard, rhs.hideKeyboard);
    std::swap(lhs.selective, rhs.selective);
    return lhs;
}

static InlineKeyboardMarkup & move(InlineKeyboardMarkup &lhs, InlineKeyboardMarkup &rhs)
{
    std::swap(lhs.inlineKeyboard, rhs.inlineKeyboard);
    return lhs;
}

static InlineKeyboardButton & move(InlineKeyboardButton &lhs, InlineKeyboardButton &rhs)
{
    std::swap(lhs.text, rhs.text);
    std::swap(lhs.url, rhs.url);
    std::swap(lhs.callbackData, rhs.callbackData);
    std::swap(lhs.switchInlineQuery, rhs.switchInlineQuery);
    return lhs;
}

static CallbackQuery & move(CallbackQuery &lhs, CallbackQuery &rhs)
{
    std::swap(lhs.id, rhs.id);
    std::swap(lhs.from, rhs.from);
    std::swap(lhs.message, rhs.message);
    std::swap(lhs.inlineMessageId, rhs.inlineMessageId);
    std::swap(lhs.data, rhs.data);
    return lhs;
}

static ForceReply & move(ForceReply &lhs, ForceReply &rhs)
{
    std::swap(lhs.forceReply, rhs.forceReply);
    std::swap(lhs.selective, rhs.selective);
    return lhs;
}

static ChatMember & move(ChatMember &lhs, ChatMember &rhs)
{
    std::swap(lhs.user, rhs.user);
    std::swap(lhs.status, rhs.status);
    return lhs;
}

static InlineQuery & move(InlineQuery &lhs, InlineQuery &rhs)
{
    std::swap(lhs.id, rhs.id);
    std::swap(lhs.from, rhs.from);
    std::swap(lhs.location, rhs.location);
    std::swap(lhs.query, rhs.query);
    std::swap(lhs.offset, rhs.offset);
    return lhs;
}

static ChosenInlineResult & move(ChosenInlineResult &lhs, ChosenInlineResult &rhs)
{
    std::swap(lhs.resultId, rhs.resultId);
    std::swap(lhs.from, rhs.from);
    std::swap(lhs.location, rhs.location);
    std::swap(lhs.inlineMessageId, rhs.inlineMessageId);
    std::swap(lhs.query, rhs.query);
    return lhs;
}

Update::Update()
{
    updateId = nullptr;
    message = nullptr;
    editedMessage = nullptr;
    inlineQuery = nullptr;
    chosenInlineResult = nullptr;
    callbackQuery = nullptr;
}

Update::~Update()
{
    delete updateId; updateId = nullptr;
    if(map.find("updateId") != map.end()) {
        delete (int *) map["updateId"];
    }
    delete message; message = nullptr;
    if(map.find("message") != map.end()) {
        delete (Message *) map["message"];
    }
    delete editedMessage; editedMessage = nullptr;
    if(map.find("editedMessage") != map.end()) {
        delete (Message *) map["editedMessage"];
    }
    delete inlineQuery; inlineQuery = nullptr;
    if(map.find("inlineQuery") != map.end()) {
        delete (InlineQuery *) map["inlineQuery"];
    }
    delete chosenInlineResult; chosenInlineResult = nullptr;
    if(map.find("chosenInlineResult") != map.end()) {
        delete (ChosenInlineResult *) map["chosenInlineResult"];
    }
    delete callbackQuery; callbackQuery = nullptr;
    if(map.find("callbackQuery") != map.end()) {
        delete (CallbackQuery *) map["callbackQuery"];
    }
}

Update::Update(const Update &src)
{
    copy(*this, src);
}

Update & Update::operator=(const Update &src)
{
    return copy(*this, src);
}

Update::Update(Update &&src) : Update()
{
    move(*this, src);
}

Update & Update::operator=(Update &&src)
{
    return move(*this, src);
}

Update::Update(const int &updateId) : Update()
{
    this->updateId = new int(updateId);
}

Update::Update(const int &updateId, const Message &message, const Message &editedMessage, const InlineQuery &inlineQuery, const ChosenInlineResult &chosenInlineResult, const CallbackQuery &callbackQuery) : Update(updateId)
{
    this->updateId = new int(updateId);
    this->message = new Message(message);
    this->editedMessage = new Message(editedMessage);
    this->inlineQuery = new InlineQuery(inlineQuery);
    this->chosenInlineResult = new ChosenInlineResult(chosenInlineResult);
    this->callbackQuery = new CallbackQuery(callbackQuery);
}

int * Update::GetUpdateId()
{
    if(updateId == nullptr) {
        if(map.find("updateId") == map.end()) {
            map.emplace("updateId", (void *) new int);
        }
        return (int *) map["updateId"];
    }
    return updateId;
}

Message * Update::GetMessage()
{
    if(message == nullptr) {
        if(map.find("message") == map.end()) {
            map.emplace("message", (void *) new Message);
        }
        return (Message *) map["message"];
    }
    return message;
}

Message * Update::GetEditedMessage()
{
    if(editedMessage == nullptr) {
        if(map.find("editedMessage") == map.end()) {
            map.emplace("editedMessage", (void *) new Message);
        }
        return (Message *) map["editedMessage"];
    }
    return editedMessage;
}

InlineQuery * Update::GetInlineQuery()
{
    if(inlineQuery == nullptr) {
        if(map.find("inlineQuery") == map.end()) {
            map.emplace("inlineQuery", (void *) new InlineQuery);
        }
        return (InlineQuery *) map["inlineQuery"];
    }
    return inlineQuery;
}

ChosenInlineResult * Update::GetChosenInlineResult()
{
    if(chosenInlineResult == nullptr) {
        if(map.find("chosenInlineResult") == map.end()) {
            map.emplace("chosenInlineResult", (void *) new ChosenInlineResult);
        }
        return (ChosenInlineResult *) map["chosenInlineResult"];
    }
    return chosenInlineResult;
}

CallbackQuery * Update::GetCallbackQuery()
{
    if(callbackQuery == nullptr) {
        if(map.find("callbackQuery") == map.end()) {
            map.emplace("callbackQuery", (void *) new CallbackQuery);
        }
        return (CallbackQuery *) map["callbackQuery"];
    }
    return callbackQuery;
}

int & Update::GetUpdateIdValue() const
{
    return *updateId;
}

Message & Update::GetMessageValue() const
{
    return *message;
}

Message & Update::GetEditedMessageValue() const
{
    return *editedMessage;
}

InlineQuery & Update::GetInlineQueryValue() const
{
    return *inlineQuery;
}

ChosenInlineResult & Update::GetChosenInlineResultValue() const
{
    return *chosenInlineResult;
}

CallbackQuery & Update::GetCallbackQueryValue() const
{
    return *callbackQuery;
}

void Update::SetUpdateId(const int &updateId)
{
    if(this->updateId != nullptr) {
        delete this->updateId;
    }
    this->updateId = new int(updateId);
}

void Update::SetMessage(const Message &message)
{
    if(this->message != nullptr) {
        delete this->message;
    }
    this->message = new Message(message);
}

void Update::SetEditedMessage(const Message &editedMessage)
{
    if(this->editedMessage != nullptr) {
        delete this->editedMessage;
    }
    this->editedMessage = new Message(editedMessage);
}

void Update::SetInlineQuery(const InlineQuery &inlineQuery)
{
    if(this->inlineQuery != nullptr) {
        delete this->inlineQuery;
    }
    this->inlineQuery = new InlineQuery(inlineQuery);
}

void Update::SetChosenInlineResult(const ChosenInlineResult &chosenInlineResult)
{
    if(this->chosenInlineResult != nullptr) {
        delete this->chosenInlineResult;
    }
    this->chosenInlineResult = new ChosenInlineResult(chosenInlineResult);
}

void Update::SetCallbackQuery(const CallbackQuery &callbackQuery)
{
    if(this->callbackQuery != nullptr) {
        delete this->callbackQuery;
    }
    this->callbackQuery = new CallbackQuery(callbackQuery);
}

User::User()
{
    id = nullptr;
    firstName = nullptr;
    lastName = nullptr;
    userName = nullptr;
}

User::~User()
{
    delete id; id = nullptr;
    if(map.find("id") != map.end()) {
        delete (int *) map["id"];
    }
    delete firstName; firstName = nullptr;
    if(map.find("firstName") != map.end()) {
        delete (std::string *) map["firstName"];
    }
    delete lastName; lastName = nullptr;
    if(map.find("lastName") != map.end()) {
        delete (std::string *) map["lastName"];
    }
    delete userName; userName = nullptr;
    if(map.find("userName") != map.end()) {
        delete (std::string *) map["userName"];
    }
}

User::User(const User &src)
{
    copy(*this, src);
}

User & User::operator=(const User &src)
{
    return copy(*this, src);
}

User::User(User &&src) : User()
{
    move(*this, src);
}

User & User::operator=(User &&src)
{
    return move(*this, src);
}

User::User(const int &id, const std::string &firstName) : User()
{
    this->id = new int(id);
    this->firstName = new std::string(firstName);
}

User::User(const int &id, const std::string &firstName, const std::string &lastName, const std::string &userName) : User(id, firstName)
{
    this->id = new int(id);
    this->firstName = new std::string(firstName);
    this->lastName = new std::string(lastName);
    this->userName = new std::string(userName);
}

int * User::GetId()
{
    if(id == nullptr) {
        if(map.find("id") == map.end()) {
            map.emplace("id", (void *) new int);
        }
        return (int *) map["id"];
    }
    return id;
}

std::string * User::GetFirstName()
{
    if(firstName == nullptr) {
        if(map.find("firstName") == map.end()) {
            map.emplace("firstName", (void *) new std::string);
        }
        return (std::string *) map["firstName"];
    }
    return firstName;
}

std::string * User::GetLastName()
{
    if(lastName == nullptr) {
        if(map.find("lastName") == map.end()) {
            map.emplace("lastName", (void *) new std::string);
        }
        return (std::string *) map["lastName"];
    }
    return lastName;
}

std::string * User::GetUserName()
{
    if(userName == nullptr) {
        if(map.find("userName") == map.end()) {
            map.emplace("userName", (void *) new std::string);
        }
        return (std::string *) map["userName"];
    }
    return userName;
}

int & User::GetIdValue() const
{
    return *id;
}

std::string & User::GetFirstNameValue() const
{
    return *firstName;
}

std::string & User::GetLastNameValue() const
{
    return *lastName;
}

std::string & User::GetUserNameValue() const
{
    return *userName;
}

void User::SetId(const int &id)
{
    if(this->id != nullptr) {
        delete this->id;
    }
    this->id = new int(id);
}

void User::SetFirstName(const std::string &firstName)
{
    if(this->firstName != nullptr) {
        delete this->firstName;
    }
    this->firstName = new std::string(firstName);
}

void User::SetLastName(const std::string &lastName)
{
    if(this->lastName != nullptr) {
        delete this->lastName;
    }
    this->lastName = new std::string(lastName);
}

void User::SetUserName(const std::string &userName)
{
    if(this->userName != nullptr) {
        delete this->userName;
    }
    this->userName = new std::string(userName);
}

Chat::Chat()
{
    id = nullptr;
    type = nullptr;
    title = nullptr;
    userName = nullptr;
    firstName = nullptr;
    lastName = nullptr;
}

Chat::~Chat()
{
    delete id; id = nullptr;
    if(map.find("id") != map.end()) {
        delete (long *) map["id"];
    }
    delete type; type = nullptr;
    if(map.find("type") != map.end()) {
        delete (std::string *) map["type"];
    }
    delete title; title = nullptr;
    if(map.find("title") != map.end()) {
        delete (std::string *) map["title"];
    }
    delete userName; userName = nullptr;
    if(map.find("userName") != map.end()) {
        delete (std::string *) map["userName"];
    }
    delete firstName; firstName = nullptr;
    if(map.find("firstName") != map.end()) {
        delete (std::string *) map["firstName"];
    }
    delete lastName; lastName = nullptr;
    if(map.find("lastName") != map.end()) {
        delete (std::string *) map["lastName"];
    }
}

Chat::Chat(const Chat &src)
{
    copy(*this, src);
}

Chat & Chat::operator=(const Chat &src)
{
    return copy(*this, src);
}

Chat::Chat(Chat &&src) : Chat()
{
    move(*this, src);
}

Chat & Chat::operator=(Chat &&src)
{
    return move(*this, src);
}

Chat::Chat(const long &id, const std::string &type) : Chat()
{
    this->id = new long(id);
    this->type = new std::string(type);
}

Chat::Chat(const long &id, const std::string &type, const std::string &title, const std::string &userName, const std::string &firstName, const std::string &lastName) : Chat(id, type)
{
    this->id = new long(id);
    this->type = new std::string(type);
    this->title = new std::string(title);
    this->userName = new std::string(userName);
    this->firstName = new std::string(firstName);
    this->lastName = new std::string(lastName);
}

long * Chat::GetId()
{
    if(id == nullptr) {
        if(map.find("id") == map.end()) {
            map.emplace("id", (void *) new long);
        }
        return (long *) map["id"];
    }
    return id;
}

std::string * Chat::GetType()
{
    if(type == nullptr) {
        if(map.find("type") == map.end()) {
            map.emplace("type", (void *) new std::string);
        }
        return (std::string *) map["type"];
    }
    return type;
}

std::string * Chat::GetTitle()
{
    if(title == nullptr) {
        if(map.find("title") == map.end()) {
            map.emplace("title", (void *) new std::string);
        }
        return (std::string *) map["title"];
    }
    return title;
}

std::string * Chat::GetUserName()
{
    if(userName == nullptr) {
        if(map.find("userName") == map.end()) {
            map.emplace("userName", (void *) new std::string);
        }
        return (std::string *) map["userName"];
    }
    return userName;
}

std::string * Chat::GetFirstName()
{
    if(firstName == nullptr) {
        if(map.find("firstName") == map.end()) {
            map.emplace("firstName", (void *) new std::string);
        }
        return (std::string *) map["firstName"];
    }
    return firstName;
}

std::string * Chat::GetLastName()
{
    if(lastName == nullptr) {
        if(map.find("lastName") == map.end()) {
            map.emplace("lastName", (void *) new std::string);
        }
        return (std::string *) map["lastName"];
    }
    return lastName;
}

long & Chat::GetIdValue() const
{
    return *id;
}

std::string & Chat::GetTypeValue() const
{
    return *type;
}

std::string & Chat::GetTitleValue() const
{
    return *title;
}

std::string & Chat::GetUserNameValue() const
{
    return *userName;
}

std::string & Chat::GetFirstNameValue() const
{
    return *firstName;
}

std::string & Chat::GetLastNameValue() const
{
    return *lastName;
}

void Chat::SetId(const long &id)
{
    if(this->id != nullptr) {
        delete this->id;
    }
    this->id = new long(id);
}

void Chat::SetType(const std::string &type)
{
    if(this->type != nullptr) {
        delete this->type;
    }
    this->type = new std::string(type);
}

void Chat::SetTitle(const std::string &title)
{
    if(this->title != nullptr) {
        delete this->title;
    }
    this->title = new std::string(title);
}

void Chat::SetUserName(const std::string &userName)
{
    if(this->userName != nullptr) {
        delete this->userName;
    }
    this->userName = new std::string(userName);
}

void Chat::SetFirstName(const std::string &firstName)
{
    if(this->firstName != nullptr) {
        delete this->firstName;
    }
    this->firstName = new std::string(firstName);
}

void Chat::SetLastName(const std::string &lastName)
{
    if(this->lastName != nullptr) {
        delete this->lastName;
    }
    this->lastName = new std::string(lastName);
}

Message::Message()
{
    messageId = nullptr;
    from = nullptr;
    date = nullptr;
    chat = nullptr;
    forwardFrom = nullptr;
    forwardFromChat = nullptr;
    forwardDate = nullptr;
    replyToMessage = nullptr;
    editDate = nullptr;
    text = nullptr;
    entities = nullptr;
    audio = nullptr;
    document = nullptr;
    photo = nullptr;
    sticker = nullptr;
    video = nullptr;
    voice = nullptr;
    caption = nullptr;
    contact = nullptr;
    location = nullptr;
    venue = nullptr;
    newChatMember = nullptr;
    leftChatMember = nullptr;
    newChatTitle = nullptr;
    newChatPhoto = nullptr;
    deleteChatPhoto = nullptr;
    groupChatCreated = nullptr;
    superGroupChatCreated = nullptr;
    channelChatCreated = nullptr;
    migrateToChatId = nullptr;
    migrateFromChatId = nullptr;
    pinnedMessage = nullptr;
}

Message::~Message()
{
    delete messageId; messageId = nullptr;
    if(map.find("messageId") != map.end()) {
        delete (int *) map["messageId"];
    }
    delete from; from = nullptr;
    if(map.find("from") != map.end()) {
        delete (User *) map["from"];
    }
    delete date; date = nullptr;
    if(map.find("date") != map.end()) {
        delete (int *) map["date"];
    }
    delete chat; chat = nullptr;
    if(map.find("chat") != map.end()) {
        delete (Chat *) map["chat"];
    }
    delete forwardFrom; forwardFrom = nullptr;
    if(map.find("forwardFrom") != map.end()) {
        delete (User *) map["forwardFrom"];
    }
    delete forwardFromChat; forwardFromChat = nullptr;
    if(map.find("forwardFromChat") != map.end()) {
        delete (Chat *) map["forwardFromChat"];
    }
    delete forwardDate; forwardDate = nullptr;
    if(map.find("forwardDate") != map.end()) {
        delete (int *) map["forwardDate"];
    }
    delete replyToMessage; replyToMessage = nullptr;
    if(map.find("replyToMessage") != map.end()) {
        delete (Message *) map["replyToMessage"];
    }
    delete editDate; editDate = nullptr;
    if(map.find("editDate") != map.end()) {
        delete (int *) map["editDate"];
    }
    delete text; text = nullptr;
    if(map.find("text") != map.end()) {
        delete (std::string *) map["text"];
    }
    delete entities; entities = nullptr;
    if(map.find("entities") != map.end()) {
        delete (std::vector<MessageEntity> *) map["entities"];
    }
    delete audio; audio = nullptr;
    if(map.find("audio") != map.end()) {
        delete (Audio *) map["audio"];
    }
    delete document; document = nullptr;
    if(map.find("document") != map.end()) {
        delete (Document *) map["document"];
    }
    delete photo; photo = nullptr;
    if(map.find("photo") != map.end()) {
        delete (std::vector<PhotoSize> *) map["photo"];
    }
    delete sticker; sticker = nullptr;
    if(map.find("sticker") != map.end()) {
        delete (Sticker *) map["sticker"];
    }
    delete video; video = nullptr;
    if(map.find("video") != map.end()) {
        delete (Video *) map["video"];
    }
    delete voice; voice = nullptr;
    if(map.find("voice") != map.end()) {
        delete (Voice *) map["voice"];
    }
    delete caption; caption = nullptr;
    if(map.find("caption") != map.end()) {
        delete (std::string *) map["caption"];
    }
    delete contact; contact = nullptr;
    if(map.find("contact") != map.end()) {
        delete (Contact *) map["contact"];
    }
    delete location; location = nullptr;
    if(map.find("location") != map.end()) {
        delete (Location *) map["location"];
    }
    delete venue; venue = nullptr;
    if(map.find("venue") != map.end()) {
        delete (Venue *) map["venue"];
    }
    delete newChatMember; newChatMember = nullptr;
    if(map.find("newChatMember") != map.end()) {
        delete (User *) map["newChatMember"];
    }
    delete leftChatMember; leftChatMember = nullptr;
    if(map.find("leftChatMember") != map.end()) {
        delete (User *) map["leftChatMember"];
    }
    delete newChatTitle; newChatTitle = nullptr;
    if(map.find("newChatTitle") != map.end()) {
        delete (std::string *) map["newChatTitle"];
    }
    delete newChatPhoto; newChatPhoto = nullptr;
    if(map.find("newChatPhoto") != map.end()) {
        delete (std::vector<PhotoSize> *) map["newChatPhoto"];
    }
    delete deleteChatPhoto; deleteChatPhoto = nullptr;
    if(map.find("deleteChatPhoto") != map.end()) {
        delete (bool *) map["deleteChatPhoto"];
    }
    delete groupChatCreated; groupChatCreated = nullptr;
    if(map.find("groupChatCreated") != map.end()) {
        delete (bool *) map["groupChatCreated"];
    }
    delete superGroupChatCreated; superGroupChatCreated = nullptr;
    if(map.find("superGroupChatCreated") != map.end()) {
        delete (bool *) map["superGroupChatCreated"];
    }
    delete channelChatCreated; channelChatCreated = nullptr;
    if(map.find("channelChatCreated") != map.end()) {
        delete (bool *) map["channelChatCreated"];
    }
    delete migrateToChatId; migrateToChatId = nullptr;
    if(map.find("migrateToChatId") != map.end()) {
        delete (long *) map["migrateToChatId"];
    }
    delete migrateFromChatId; migrateFromChatId = nullptr;
    if(map.find("migrateFromChatId") != map.end()) {
        delete (long *) map["migrateFromChatId"];
    }
    delete pinnedMessage; pinnedMessage = nullptr;
    if(map.find("pinnedMessage") != map.end()) {
        delete (Message *) map["pinnedMessage"];
    }
}

Message::Message(const Message &src)
{
    copy(*this, src);
}

Message & Message::operator=(const Message &src)
{
    return copy(*this, src);
}

Message::Message(Message &&src) : Message()
{
    move(*this, src);
}

Message & Message::operator=(Message &&src)
{
    return move(*this, src);
}

Message::Message(const int &messageId, const int &date, const Chat &chat) : Message()
{
    this->messageId = new int(messageId);
    this->date = new int(date);
    this->chat = new Chat(chat);
}

Message::Message(const int &messageId, const User &from, const int &date, const Chat &chat, const User &forwardFrom, const Chat &forwardFromChat, const int &forwardDate, const Message &replyToMessage, const int &editDate, const std::string &text, const std::vector<MessageEntity> &entities, const Audio &audio, const Document &document, const std::vector<PhotoSize> &photo, const Sticker &sticker, const Video &video, const Voice &voice, const std::string &caption, const Contact &contact, const Location &location, const Venue &venue, const User &newChatMember, const User &leftChatMember, const std::string &newChatTitle, const std::vector<PhotoSize> &newChatPhoto, const bool &deleteChatPhoto, const bool &groupChatCreated, const bool &superGroupChatCreated, const bool &channelChatCreated, const long &migrateToChatId, const long &migrateFromChatId, const Message &pinnedMessage) : Message(messageId, date, chat)
{
    this->messageId = new int(messageId);
    this->from = new User(from);
    this->date = new int(date);
    this->chat = new Chat(chat);
    this->forwardFrom = new User(forwardFrom);
    this->forwardFromChat = new Chat(forwardFromChat);
    this->forwardDate = new int(forwardDate);
    this->replyToMessage = new Message(replyToMessage);
    this->editDate = new int(editDate);
    this->text = new std::string(text);
    this->entities = new std::vector<MessageEntity>(entities);
    this->audio = new Audio(audio);
    this->document = new Document(document);
    this->photo = new std::vector<PhotoSize>(photo);
    this->sticker = new Sticker(sticker);
    this->video = new Video(video);
    this->voice = new Voice(voice);
    this->caption = new std::string(caption);
    this->contact = new Contact(contact);
    this->location = new Location(location);
    this->venue = new Venue(venue);
    this->newChatMember = new User(newChatMember);
    this->leftChatMember = new User(leftChatMember);
    this->newChatTitle = new std::string(newChatTitle);
    this->newChatPhoto = new std::vector<PhotoSize>(newChatPhoto);
    this->deleteChatPhoto = new bool(deleteChatPhoto);
    this->groupChatCreated = new bool(groupChatCreated);
    this->superGroupChatCreated = new bool(superGroupChatCreated);
    this->channelChatCreated = new bool(channelChatCreated);
    this->migrateToChatId = new long(migrateToChatId);
    this->migrateFromChatId = new long(migrateFromChatId);
    this->pinnedMessage = new Message(pinnedMessage);
}

int * Message::GetMessageId()
{
    if(messageId == nullptr) {
        if(map.find("messageId") == map.end()) {
            map.emplace("messageId", (void *) new int);
        }
        return (int *) map["messageId"];
    }
    return messageId;
}

User * Message::GetFrom()
{
    if(from == nullptr) {
        if(map.find("from") == map.end()) {
            map.emplace("from", (void *) new User);
        }
        return (User *) map["from"];
    }
    return from;
}

int * Message::GetDate()
{
    if(date == nullptr) {
        if(map.find("date") == map.end()) {
            map.emplace("date", (void *) new int);
        }
        return (int *) map["date"];
    }
    return date;
}

Chat * Message::GetChat()
{
    if(chat == nullptr) {
        if(map.find("chat") == map.end()) {
            map.emplace("chat", (void *) new Chat);
        }
        return (Chat *) map["chat"];
    }
    return chat;
}

User * Message::GetForwardFrom()
{
    if(forwardFrom == nullptr) {
        if(map.find("forwardFrom") == map.end()) {
            map.emplace("forwardFrom", (void *) new User);
        }
        return (User *) map["forwardFrom"];
    }
    return forwardFrom;
}

Chat * Message::GetForwardFromChat()
{
    if(forwardFromChat == nullptr) {
        if(map.find("forwardFromChat") == map.end()) {
            map.emplace("forwardFromChat", (void *) new Chat);
        }
        return (Chat *) map["forwardFromChat"];
    }
    return forwardFromChat;
}

int * Message::GetForwardDate()
{
    if(forwardDate == nullptr) {
        if(map.find("forwardDate") == map.end()) {
            map.emplace("forwardDate", (void *) new int);
        }
        return (int *) map["forwardDate"];
    }
    return forwardDate;
}

Message * Message::GetReplyToMessage()
{
    if(replyToMessage == nullptr) {
        if(map.find("replyToMessage") == map.end()) {
            map.emplace("replyToMessage", (void *) new Message);
        }
        return (Message *) map["replyToMessage"];
    }
    return replyToMessage;
}

int * Message::GetEditDate()
{
    if(editDate == nullptr) {
        if(map.find("editDate") == map.end()) {
            map.emplace("editDate", (void *) new int);
        }
        return (int *) map["editDate"];
    }
    return editDate;
}

std::string * Message::GetText()
{
    if(text == nullptr) {
        if(map.find("text") == map.end()) {
            map.emplace("text", (void *) new std::string);
        }
        return (std::string *) map["text"];
    }
    return text;
}

std::vector<MessageEntity> * Message::GetEntities()
{
    if(entities == nullptr) {
        if(map.find("entities") == map.end()) {
            map.emplace("entities", (void *) new std::vector<MessageEntity>);
        }
        return (std::vector<MessageEntity> *) map["entities"];
    }
    return entities;
}

Audio * Message::GetAudio()
{
    if(audio == nullptr) {
        if(map.find("audio") == map.end()) {
            map.emplace("audio", (void *) new Audio);
        }
        return (Audio *) map["audio"];
    }
    return audio;
}

Document * Message::GetDocument()
{
    if(document == nullptr) {
        if(map.find("document") == map.end()) {
            map.emplace("document", (void *) new Document);
        }
        return (Document *) map["document"];
    }
    return document;
}

std::vector<PhotoSize> * Message::GetPhoto()
{
    if(photo == nullptr) {
        if(map.find("photo") == map.end()) {
            map.emplace("photo", (void *) new std::vector<PhotoSize>);
        }
        return (std::vector<PhotoSize> *) map["photo"];
    }
    return photo;
}

Sticker * Message::GetSticker()
{
    if(sticker == nullptr) {
        if(map.find("sticker") == map.end()) {
            map.emplace("sticker", (void *) new Sticker);
        }
        return (Sticker *) map["sticker"];
    }
    return sticker;
}

Video * Message::GetVideo()
{
    if(video == nullptr) {
        if(map.find("video") == map.end()) {
            map.emplace("video", (void *) new Video);
        }
        return (Video *) map["video"];
    }
    return video;
}

Voice * Message::GetVoice()
{
    if(voice == nullptr) {
        if(map.find("voice") == map.end()) {
            map.emplace("voice", (void *) new Voice);
        }
        return (Voice *) map["voice"];
    }
    return voice;
}

std::string * Message::GetCaption()
{
    if(caption == nullptr) {
        if(map.find("caption") == map.end()) {
            map.emplace("caption", (void *) new std::string);
        }
        return (std::string *) map["caption"];
    }
    return caption;
}

Contact * Message::GetContact()
{
    if(contact == nullptr) {
        if(map.find("contact") == map.end()) {
            map.emplace("contact", (void *) new Contact);
        }
        return (Contact *) map["contact"];
    }
    return contact;
}

Location * Message::GetLocation()
{
    if(location == nullptr) {
        if(map.find("location") == map.end()) {
            map.emplace("location", (void *) new Location);
        }
        return (Location *) map["location"];
    }
    return location;
}

Venue * Message::GetVenue()
{
    if(venue == nullptr) {
        if(map.find("venue") == map.end()) {
            map.emplace("venue", (void *) new Venue);
        }
        return (Venue *) map["venue"];
    }
    return venue;
}

User * Message::GetNewChatMember()
{
    if(newChatMember == nullptr) {
        if(map.find("newChatMember") == map.end()) {
            map.emplace("newChatMember", (void *) new User);
        }
        return (User *) map["newChatMember"];
    }
    return newChatMember;
}

User * Message::GetLeftChatMember()
{
    if(leftChatMember == nullptr) {
        if(map.find("leftChatMember") == map.end()) {
            map.emplace("leftChatMember", (void *) new User);
        }
        return (User *) map["leftChatMember"];
    }
    return leftChatMember;
}

std::string * Message::GetNewChatTitle()
{
    if(newChatTitle == nullptr) {
        if(map.find("newChatTitle") == map.end()) {
            map.emplace("newChatTitle", (void *) new std::string);
        }
        return (std::string *) map["newChatTitle"];
    }
    return newChatTitle;
}

std::vector<PhotoSize> * Message::GetNewChatPhoto()
{
    if(newChatPhoto == nullptr) {
        if(map.find("newChatPhoto") == map.end()) {
            map.emplace("newChatPhoto", (void *) new std::vector<PhotoSize>);
        }
        return (std::vector<PhotoSize> *) map["newChatPhoto"];
    }
    return newChatPhoto;
}

bool * Message::GetDeleteChatPhoto()
{
    if(deleteChatPhoto == nullptr) {
        if(map.find("deleteChatPhoto") == map.end()) {
            map.emplace("deleteChatPhoto", (void *) new bool);
        }
        return (bool *) map["deleteChatPhoto"];
    }
    return deleteChatPhoto;
}

bool * Message::GetGroupChatCreated()
{
    if(groupChatCreated == nullptr) {
        if(map.find("groupChatCreated") == map.end()) {
            map.emplace("groupChatCreated", (void *) new bool);
        }
        return (bool *) map["groupChatCreated"];
    }
    return groupChatCreated;
}

bool * Message::GetSuperGroupChatCreated()
{
    if(superGroupChatCreated == nullptr) {
        if(map.find("superGroupChatCreated") == map.end()) {
            map.emplace("superGroupChatCreated", (void *) new bool);
        }
        return (bool *) map["superGroupChatCreated"];
    }
    return superGroupChatCreated;
}

bool * Message::GetChannelChatCreated()
{
    if(channelChatCreated == nullptr) {
        if(map.find("channelChatCreated") == map.end()) {
            map.emplace("channelChatCreated", (void *) new bool);
        }
        return (bool *) map["channelChatCreated"];
    }
    return channelChatCreated;
}

long * Message::GetMigrateToChatId()
{
    if(migrateToChatId == nullptr) {
        if(map.find("migrateToChatId") == map.end()) {
            map.emplace("migrateToChatId", (void *) new long);
        }
        return (long *) map["migrateToChatId"];
    }
    return migrateToChatId;
}

long * Message::GetMigrateFromChatId()
{
    if(migrateFromChatId == nullptr) {
        if(map.find("migrateFromChatId") == map.end()) {
            map.emplace("migrateFromChatId", (void *) new long);
        }
        return (long *) map["migrateFromChatId"];
    }
    return migrateFromChatId;
}

Message * Message::GetPinnedMessage()
{
    if(pinnedMessage == nullptr) {
        if(map.find("pinnedMessage") == map.end()) {
            map.emplace("pinnedMessage", (void *) new Message);
        }
        return (Message *) map["pinnedMessage"];
    }
    return pinnedMessage;
}

int & Message::GetMessageIdValue() const
{
    return *messageId;
}

User & Message::GetFromValue() const
{
    return *from;
}

int & Message::GetDateValue() const
{
    return *date;
}

Chat & Message::GetChatValue() const
{
    return *chat;
}

User & Message::GetForwardFromValue() const
{
    return *forwardFrom;
}

Chat & Message::GetForwardFromChatValue() const
{
    return *forwardFromChat;
}

int & Message::GetForwardDateValue() const
{
    return *forwardDate;
}

Message & Message::GetReplyToMessageValue() const
{
    return *replyToMessage;
}

int & Message::GetEditDateValue() const
{
    return *editDate;
}

std::string & Message::GetTextValue() const
{
    return *text;
}

std::vector<MessageEntity> & Message::GetEntitiesValue() const
{
    return *entities;
}

Audio & Message::GetAudioValue() const
{
    return *audio;
}

Document & Message::GetDocumentValue() const
{
    return *document;
}

std::vector<PhotoSize> & Message::GetPhotoValue() const
{
    return *photo;
}

Sticker & Message::GetStickerValue() const
{
    return *sticker;
}

Video & Message::GetVideoValue() const
{
    return *video;
}

Voice & Message::GetVoiceValue() const
{
    return *voice;
}

std::string & Message::GetCaptionValue() const
{
    return *caption;
}

Contact & Message::GetContactValue() const
{
    return *contact;
}

Location & Message::GetLocationValue() const
{
    return *location;
}

Venue & Message::GetVenueValue() const
{
    return *venue;
}

User & Message::GetNewChatMemberValue() const
{
    return *newChatMember;
}

User & Message::GetLeftChatMemberValue() const
{
    return *leftChatMember;
}

std::string & Message::GetNewChatTitleValue() const
{
    return *newChatTitle;
}

std::vector<PhotoSize> & Message::GetNewChatPhotoValue() const
{
    return *newChatPhoto;
}

bool & Message::GetDeleteChatPhotoValue() const
{
    return *deleteChatPhoto;
}

bool & Message::GetGroupChatCreatedValue() const
{
    return *groupChatCreated;
}

bool & Message::GetSuperGroupChatCreatedValue() const
{
    return *superGroupChatCreated;
}

bool & Message::GetChannelChatCreatedValue() const
{
    return *channelChatCreated;
}

long & Message::GetMigrateToChatIdValue() const
{
    return *migrateToChatId;
}

long & Message::GetMigrateFromChatIdValue() const
{
    return *migrateFromChatId;
}

Message & Message::GetPinnedMessageValue() const
{
    return *pinnedMessage;
}

void Message::SetMessageId(const int &messageId)
{
    if(this->messageId != nullptr) {
        delete this->messageId;
    }
    this->messageId = new int(messageId);
}

void Message::SetFrom(const User &from)
{
    if(this->from != nullptr) {
        delete this->from;
    }
    this->from = new User(from);
}

void Message::SetDate(const int &date)
{
    if(this->date != nullptr) {
        delete this->date;
    }
    this->date = new int(date);
}

void Message::SetChat(const Chat &chat)
{
    if(this->chat != nullptr) {
        delete this->chat;
    }
    this->chat = new Chat(chat);
}

void Message::SetForwardFrom(const User &forwardFrom)
{
    if(this->forwardFrom != nullptr) {
        delete this->forwardFrom;
    }
    this->forwardFrom = new User(forwardFrom);
}

void Message::SetForwardFromChat(const Chat &forwardFromChat)
{
    if(this->forwardFromChat != nullptr) {
        delete this->forwardFromChat;
    }
    this->forwardFromChat = new Chat(forwardFromChat);
}

void Message::SetForwardDate(const int &forwardDate)
{
    if(this->forwardDate != nullptr) {
        delete this->forwardDate;
    }
    this->forwardDate = new int(forwardDate);
}

void Message::SetReplyToMessage(const Message &replyToMessage)
{
    if(this->replyToMessage != nullptr) {
        delete this->replyToMessage;
    }
    this->replyToMessage = new Message(replyToMessage);
}

void Message::SetEditDate(const int &editDate)
{
    if(this->editDate != nullptr) {
        delete this->editDate;
    }
    this->editDate = new int(editDate);
}

void Message::SetText(const std::string &text)
{
    if(this->text != nullptr) {
        delete this->text;
    }
    this->text = new std::string(text);
}

void Message::SetEntities(const std::vector<MessageEntity> &entities)
{
    if(this->entities != nullptr) {
        delete this->entities;
    }
    this->entities = new std::vector<MessageEntity>(entities);
}

void Message::SetAudio(const Audio &audio)
{
    if(this->audio != nullptr) {
        delete this->audio;
    }
    this->audio = new Audio(audio);
}

void Message::SetDocument(const Document &document)
{
    if(this->document != nullptr) {
        delete this->document;
    }
    this->document = new Document(document);
}

void Message::SetPhoto(const std::vector<PhotoSize> &photo)
{
    if(this->photo != nullptr) {
        delete this->photo;
    }
    this->photo = new std::vector<PhotoSize>(photo);
}

void Message::SetSticker(const Sticker &sticker)
{
    if(this->sticker != nullptr) {
        delete this->sticker;
    }
    this->sticker = new Sticker(sticker);
}

void Message::SetVideo(const Video &video)
{
    if(this->video != nullptr) {
        delete this->video;
    }
    this->video = new Video(video);
}

void Message::SetVoice(const Voice &voice)
{
    if(this->voice != nullptr) {
        delete this->voice;
    }
    this->voice = new Voice(voice);
}

void Message::SetCaption(const std::string &caption)
{
    if(this->caption != nullptr) {
        delete this->caption;
    }
    this->caption = new std::string(caption);
}

void Message::SetContact(const Contact &contact)
{
    if(this->contact != nullptr) {
        delete this->contact;
    }
    this->contact = new Contact(contact);
}

void Message::SetLocation(const Location &location)
{
    if(this->location != nullptr) {
        delete this->location;
    }
    this->location = new Location(location);
}

void Message::SetVenue(const Venue &venue)
{
    if(this->venue != nullptr) {
        delete this->venue;
    }
    this->venue = new Venue(venue);
}

void Message::SetNewChatMember(const User &newChatMember)
{
    if(this->newChatMember != nullptr) {
        delete this->newChatMember;
    }
    this->newChatMember = new User(newChatMember);
}

void Message::SetLeftChatMember(const User &leftChatMember)
{
    if(this->leftChatMember != nullptr) {
        delete this->leftChatMember;
    }
    this->leftChatMember = new User(leftChatMember);
}

void Message::SetNewChatTitle(const std::string &newChatTitle)
{
    if(this->newChatTitle != nullptr) {
        delete this->newChatTitle;
    }
    this->newChatTitle = new std::string(newChatTitle);
}

void Message::SetNewChatPhoto(const std::vector<PhotoSize> &newChatPhoto)
{
    if(this->newChatPhoto != nullptr) {
        delete this->newChatPhoto;
    }
    this->newChatPhoto = new std::vector<PhotoSize>(newChatPhoto);
}

void Message::SetDeleteChatPhoto(const bool &deleteChatPhoto)
{
    if(this->deleteChatPhoto != nullptr) {
        delete this->deleteChatPhoto;
    }
    this->deleteChatPhoto = new bool(deleteChatPhoto);
}

void Message::SetGroupChatCreated(const bool &groupChatCreated)
{
    if(this->groupChatCreated != nullptr) {
        delete this->groupChatCreated;
    }
    this->groupChatCreated = new bool(groupChatCreated);
}

void Message::SetSuperGroupChatCreated(const bool &superGroupChatCreated)
{
    if(this->superGroupChatCreated != nullptr) {
        delete this->superGroupChatCreated;
    }
    this->superGroupChatCreated = new bool(superGroupChatCreated);
}

void Message::SetChannelChatCreated(const bool &channelChatCreated)
{
    if(this->channelChatCreated != nullptr) {
        delete this->channelChatCreated;
    }
    this->channelChatCreated = new bool(channelChatCreated);
}

void Message::SetMigrateToChatId(const long &migrateToChatId)
{
    if(this->migrateToChatId != nullptr) {
        delete this->migrateToChatId;
    }
    this->migrateToChatId = new long(migrateToChatId);
}

void Message::SetMigrateFromChatId(const long &migrateFromChatId)
{
    if(this->migrateFromChatId != nullptr) {
        delete this->migrateFromChatId;
    }
    this->migrateFromChatId = new long(migrateFromChatId);
}

void Message::SetPinnedMessage(const Message &pinnedMessage)
{
    if(this->pinnedMessage != nullptr) {
        delete this->pinnedMessage;
    }
    this->pinnedMessage = new Message(pinnedMessage);
}

MessageEntity::MessageEntity()
{
    type = nullptr;
    offset = nullptr;
    length = nullptr;
    url = nullptr;
    user = nullptr;
}

MessageEntity::~MessageEntity()
{
    delete type; type = nullptr;
    if(map.find("type") != map.end()) {
        delete (std::string *) map["type"];
    }
    delete offset; offset = nullptr;
    if(map.find("offset") != map.end()) {
        delete (int *) map["offset"];
    }
    delete length; length = nullptr;
    if(map.find("length") != map.end()) {
        delete (int *) map["length"];
    }
    delete url; url = nullptr;
    if(map.find("url") != map.end()) {
        delete (std::string *) map["url"];
    }
    delete user; user = nullptr;
    if(map.find("user") != map.end()) {
        delete (User *) map["user"];
    }
}

MessageEntity::MessageEntity(const MessageEntity &src)
{
    copy(*this, src);
}

MessageEntity & MessageEntity::operator=(const MessageEntity &src)
{
    return copy(*this, src);
}

MessageEntity::MessageEntity(MessageEntity &&src) : MessageEntity()
{
    move(*this, src);
}

MessageEntity & MessageEntity::operator=(MessageEntity &&src)
{
    return move(*this, src);
}

MessageEntity::MessageEntity(const std::string &type, const int &offset, const int &length) : MessageEntity()
{
    this->type = new std::string(type);
    this->offset = new int(offset);
    this->length = new int(length);
}

MessageEntity::MessageEntity(const std::string &type, const int &offset, const int &length, const std::string &url, const User &user) : MessageEntity(type, offset, length)
{
    this->type = new std::string(type);
    this->offset = new int(offset);
    this->length = new int(length);
    this->url = new std::string(url);
    this->user = new User(user);
}

std::string * MessageEntity::GetType()
{
    if(type == nullptr) {
        if(map.find("type") == map.end()) {
            map.emplace("type", (void *) new std::string);
        }
        return (std::string *) map["type"];
    }
    return type;
}

int * MessageEntity::GetOffset()
{
    if(offset == nullptr) {
        if(map.find("offset") == map.end()) {
            map.emplace("offset", (void *) new int);
        }
        return (int *) map["offset"];
    }
    return offset;
}

int * MessageEntity::GetLength()
{
    if(length == nullptr) {
        if(map.find("length") == map.end()) {
            map.emplace("length", (void *) new int);
        }
        return (int *) map["length"];
    }
    return length;
}

std::string * MessageEntity::GetUrl()
{
    if(url == nullptr) {
        if(map.find("url") == map.end()) {
            map.emplace("url", (void *) new std::string);
        }
        return (std::string *) map["url"];
    }
    return url;
}

User * MessageEntity::GetUser()
{
    if(user == nullptr) {
        if(map.find("user") == map.end()) {
            map.emplace("user", (void *) new User);
        }
        return (User *) map["user"];
    }
    return user;
}

std::string & MessageEntity::GetTypeValue() const
{
    return *type;
}

int & MessageEntity::GetOffsetValue() const
{
    return *offset;
}

int & MessageEntity::GetLengthValue() const
{
    return *length;
}

std::string & MessageEntity::GetUrlValue() const
{
    return *url;
}

User & MessageEntity::GetUserValue() const
{
    return *user;
}

void MessageEntity::SetType(const std::string &type)
{
    if(this->type != nullptr) {
        delete this->type;
    }
    this->type = new std::string(type);
}

void MessageEntity::SetOffset(const int &offset)
{
    if(this->offset != nullptr) {
        delete this->offset;
    }
    this->offset = new int(offset);
}

void MessageEntity::SetLength(const int &length)
{
    if(this->length != nullptr) {
        delete this->length;
    }
    this->length = new int(length);
}

void MessageEntity::SetUrl(const std::string &url)
{
    if(this->url != nullptr) {
        delete this->url;
    }
    this->url = new std::string(url);
}

void MessageEntity::SetUser(const User &user)
{
    if(this->user != nullptr) {
        delete this->user;
    }
    this->user = new User(user);
}

PhotoSize::PhotoSize()
{
    fileId = nullptr;
    width = nullptr;
    height = nullptr;
    fileSize = nullptr;
}

PhotoSize::~PhotoSize()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete width; width = nullptr;
    if(map.find("width") != map.end()) {
        delete (int *) map["width"];
    }
    delete height; height = nullptr;
    if(map.find("height") != map.end()) {
        delete (int *) map["height"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
}

PhotoSize::PhotoSize(const PhotoSize &src)
{
    copy(*this, src);
}

PhotoSize & PhotoSize::operator=(const PhotoSize &src)
{
    return copy(*this, src);
}

PhotoSize::PhotoSize(PhotoSize &&src) : PhotoSize()
{
    move(*this, src);
}

PhotoSize & PhotoSize::operator=(PhotoSize &&src)
{
    return move(*this, src);
}

PhotoSize::PhotoSize(const std::string &fileId, const int &width, const int &height) : PhotoSize()
{
    this->fileId = new std::string(fileId);
    this->width = new int(width);
    this->height = new int(height);
}

PhotoSize::PhotoSize(const std::string &fileId, const int &width, const int &height, const int &fileSize) : PhotoSize(fileId, width, height)
{
    this->fileId = new std::string(fileId);
    this->width = new int(width);
    this->height = new int(height);
    this->fileSize = new int(fileSize);
}

std::string * PhotoSize::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

int * PhotoSize::GetWidth()
{
    if(width == nullptr) {
        if(map.find("width") == map.end()) {
            map.emplace("width", (void *) new int);
        }
        return (int *) map["width"];
    }
    return width;
}

int * PhotoSize::GetHeight()
{
    if(height == nullptr) {
        if(map.find("height") == map.end()) {
            map.emplace("height", (void *) new int);
        }
        return (int *) map["height"];
    }
    return height;
}

int * PhotoSize::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string & PhotoSize::GetFileIdValue() const
{
    return *fileId;
}

int & PhotoSize::GetWidthValue() const
{
    return *width;
}

int & PhotoSize::GetHeightValue() const
{
    return *height;
}

int & PhotoSize::GetFileSizeValue() const
{
    return *fileSize;
}

void PhotoSize::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void PhotoSize::SetWidth(const int &width)
{
    if(this->width != nullptr) {
        delete this->width;
    }
    this->width = new int(width);
}

void PhotoSize::SetHeight(const int &height)
{
    if(this->height != nullptr) {
        delete this->height;
    }
    this->height = new int(height);
}

void PhotoSize::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

Audio::Audio()
{
    fileId = nullptr;
    duration = nullptr;
    performer = nullptr;
    title = nullptr;
    mimeType = nullptr;
    fileSize = nullptr;
}

Audio::~Audio()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete duration; duration = nullptr;
    if(map.find("duration") != map.end()) {
        delete (int *) map["duration"];
    }
    delete performer; performer = nullptr;
    if(map.find("performer") != map.end()) {
        delete (std::string *) map["performer"];
    }
    delete title; title = nullptr;
    if(map.find("title") != map.end()) {
        delete (std::string *) map["title"];
    }
    delete mimeType; mimeType = nullptr;
    if(map.find("mimeType") != map.end()) {
        delete (std::string *) map["mimeType"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
}

Audio::Audio(const Audio &src)
{
    copy(*this, src);
}

Audio & Audio::operator=(const Audio &src)
{
    return copy(*this, src);
}

Audio::Audio(Audio &&src) : Audio()
{
    move(*this, src);
}

Audio & Audio::operator=(Audio &&src)
{
    return move(*this, src);
}

Audio::Audio(const std::string &fileId, const int &duration) : Audio()
{
    this->fileId = new std::string(fileId);
    this->duration = new int(duration);
}

Audio::Audio(const std::string &fileId, const int &duration, const std::string &performer, const std::string &title, const std::string &mimeType, const int &fileSize) : Audio(fileId, duration)
{
    this->fileId = new std::string(fileId);
    this->duration = new int(duration);
    this->performer = new std::string(performer);
    this->title = new std::string(title);
    this->mimeType = new std::string(mimeType);
    this->fileSize = new int(fileSize);
}

std::string * Audio::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

int * Audio::GetDuration()
{
    if(duration == nullptr) {
        if(map.find("duration") == map.end()) {
            map.emplace("duration", (void *) new int);
        }
        return (int *) map["duration"];
    }
    return duration;
}

std::string * Audio::GetPerformer()
{
    if(performer == nullptr) {
        if(map.find("performer") == map.end()) {
            map.emplace("performer", (void *) new std::string);
        }
        return (std::string *) map["performer"];
    }
    return performer;
}

std::string * Audio::GetTitle()
{
    if(title == nullptr) {
        if(map.find("title") == map.end()) {
            map.emplace("title", (void *) new std::string);
        }
        return (std::string *) map["title"];
    }
    return title;
}

std::string * Audio::GetMimeType()
{
    if(mimeType == nullptr) {
        if(map.find("mimeType") == map.end()) {
            map.emplace("mimeType", (void *) new std::string);
        }
        return (std::string *) map["mimeType"];
    }
    return mimeType;
}

int * Audio::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string & Audio::GetFileIdValue() const
{
    return *fileId;
}

int & Audio::GetDurationValue() const
{
    return *duration;
}

std::string & Audio::GetPerformerValue() const
{
    return *performer;
}

std::string & Audio::GetTitleValue() const
{
    return *title;
}

std::string & Audio::GetMimeTypeValue() const
{
    return *mimeType;
}

int & Audio::GetFileSizeValue() const
{
    return *fileSize;
}

void Audio::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void Audio::SetDuration(const int &duration)
{
    if(this->duration != nullptr) {
        delete this->duration;
    }
    this->duration = new int(duration);
}

void Audio::SetPerformer(const std::string &performer)
{
    if(this->performer != nullptr) {
        delete this->performer;
    }
    this->performer = new std::string(performer);
}

void Audio::SetTitle(const std::string &title)
{
    if(this->title != nullptr) {
        delete this->title;
    }
    this->title = new std::string(title);
}

void Audio::SetMimeType(const std::string &mimeType)
{
    if(this->mimeType != nullptr) {
        delete this->mimeType;
    }
    this->mimeType = new std::string(mimeType);
}

void Audio::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

Document::Document()
{
    fileId = nullptr;
    thumb = nullptr;
    fileName = nullptr;
    mimeType = nullptr;
    fileSize = nullptr;
}

Document::~Document()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete thumb; thumb = nullptr;
    if(map.find("thumb") != map.end()) {
        delete (PhotoSize *) map["thumb"];
    }
    delete fileName; fileName = nullptr;
    if(map.find("fileName") != map.end()) {
        delete (std::string *) map["fileName"];
    }
    delete mimeType; mimeType = nullptr;
    if(map.find("mimeType") != map.end()) {
        delete (std::string *) map["mimeType"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
}

Document::Document(const Document &src)
{
    copy(*this, src);
}

Document & Document::operator=(const Document &src)
{
    return copy(*this, src);
}

Document::Document(Document &&src) : Document()
{
    move(*this, src);
}

Document & Document::operator=(Document &&src)
{
    return move(*this, src);
}

Document::Document(const std::string &fileId) : Document()
{
    this->fileId = new std::string(fileId);
}

Document::Document(const std::string &fileId, const PhotoSize &thumb, const std::string &fileName, const std::string &mimeType, const int &fileSize) : Document(fileId)
{
    this->fileId = new std::string(fileId);
    this->thumb = new PhotoSize(thumb);
    this->fileName = new std::string(fileName);
    this->mimeType = new std::string(mimeType);
    this->fileSize = new int(fileSize);
}

std::string * Document::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

PhotoSize * Document::GetThumb()
{
    if(thumb == nullptr) {
        if(map.find("thumb") == map.end()) {
            map.emplace("thumb", (void *) new PhotoSize);
        }
        return (PhotoSize *) map["thumb"];
    }
    return thumb;
}

std::string * Document::GetFileName()
{
    if(fileName == nullptr) {
        if(map.find("fileName") == map.end()) {
            map.emplace("fileName", (void *) new std::string);
        }
        return (std::string *) map["fileName"];
    }
    return fileName;
}

std::string * Document::GetMimeType()
{
    if(mimeType == nullptr) {
        if(map.find("mimeType") == map.end()) {
            map.emplace("mimeType", (void *) new std::string);
        }
        return (std::string *) map["mimeType"];
    }
    return mimeType;
}

int * Document::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string & Document::GetFileIdValue() const
{
    return *fileId;
}

PhotoSize & Document::GetThumbValue() const
{
    return *thumb;
}

std::string & Document::GetFileNameValue() const
{
    return *fileName;
}

std::string & Document::GetMimeTypeValue() const
{
    return *mimeType;
}

int & Document::GetFileSizeValue() const
{
    return *fileSize;
}

void Document::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void Document::SetThumb(const PhotoSize &thumb)
{
    if(this->thumb != nullptr) {
        delete this->thumb;
    }
    this->thumb = new PhotoSize(thumb);
}

void Document::SetFileName(const std::string &fileName)
{
    if(this->fileName != nullptr) {
        delete this->fileName;
    }
    this->fileName = new std::string(fileName);
}

void Document::SetMimeType(const std::string &mimeType)
{
    if(this->mimeType != nullptr) {
        delete this->mimeType;
    }
    this->mimeType = new std::string(mimeType);
}

void Document::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

Sticker::Sticker()
{
    fileId = nullptr;
    width = nullptr;
    height = nullptr;
    thumb = nullptr;
    emoji = nullptr;
    fileSize = nullptr;
}

Sticker::~Sticker()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete width; width = nullptr;
    if(map.find("width") != map.end()) {
        delete (int *) map["width"];
    }
    delete height; height = nullptr;
    if(map.find("height") != map.end()) {
        delete (int *) map["height"];
    }
    delete thumb; thumb = nullptr;
    if(map.find("thumb") != map.end()) {
        delete (PhotoSize *) map["thumb"];
    }
    delete emoji; emoji = nullptr;
    if(map.find("emoji") != map.end()) {
        delete (std::string *) map["emoji"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
}

Sticker::Sticker(const Sticker &src)
{
    copy(*this, src);
}

Sticker & Sticker::operator=(const Sticker &src)
{
    return copy(*this, src);
}

Sticker::Sticker(Sticker &&src) : Sticker()
{
    move(*this, src);
}

Sticker & Sticker::operator=(Sticker &&src)
{
    return move(*this, src);
}

Sticker::Sticker(const std::string &fileId, const int &width, const int &height) : Sticker()
{
    this->fileId = new std::string(fileId);
    this->width = new int(width);
    this->height = new int(height);
}

Sticker::Sticker(const std::string &fileId, const int &width, const int &height, const PhotoSize &thumb, const std::string &emoji, const int &fileSize) : Sticker(fileId, width, height)
{
    this->fileId = new std::string(fileId);
    this->width = new int(width);
    this->height = new int(height);
    this->thumb = new PhotoSize(thumb);
    this->emoji = new std::string(emoji);
    this->fileSize = new int(fileSize);
}

std::string * Sticker::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

int * Sticker::GetWidth()
{
    if(width == nullptr) {
        if(map.find("width") == map.end()) {
            map.emplace("width", (void *) new int);
        }
        return (int *) map["width"];
    }
    return width;
}

int * Sticker::GetHeight()
{
    if(height == nullptr) {
        if(map.find("height") == map.end()) {
            map.emplace("height", (void *) new int);
        }
        return (int *) map["height"];
    }
    return height;
}

PhotoSize * Sticker::GetThumb()
{
    if(thumb == nullptr) {
        if(map.find("thumb") == map.end()) {
            map.emplace("thumb", (void *) new PhotoSize);
        }
        return (PhotoSize *) map["thumb"];
    }
    return thumb;
}

std::string * Sticker::GetEmoji()
{
    if(emoji == nullptr) {
        if(map.find("emoji") == map.end()) {
            map.emplace("emoji", (void *) new std::string);
        }
        return (std::string *) map["emoji"];
    }
    return emoji;
}

int * Sticker::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string & Sticker::GetFileIdValue() const
{
    return *fileId;
}

int & Sticker::GetWidthValue() const
{
    return *width;
}

int & Sticker::GetHeightValue() const
{
    return *height;
}

PhotoSize & Sticker::GetThumbValue() const
{
    return *thumb;
}

std::string & Sticker::GetEmojiValue() const
{
    return *emoji;
}

int & Sticker::GetFileSizeValue() const
{
    return *fileSize;
}

void Sticker::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void Sticker::SetWidth(const int &width)
{
    if(this->width != nullptr) {
        delete this->width;
    }
    this->width = new int(width);
}

void Sticker::SetHeight(const int &height)
{
    if(this->height != nullptr) {
        delete this->height;
    }
    this->height = new int(height);
}

void Sticker::SetThumb(const PhotoSize &thumb)
{
    if(this->thumb != nullptr) {
        delete this->thumb;
    }
    this->thumb = new PhotoSize(thumb);
}

void Sticker::SetEmoji(const std::string &emoji)
{
    if(this->emoji != nullptr) {
        delete this->emoji;
    }
    this->emoji = new std::string(emoji);
}

void Sticker::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

Video::Video()
{
    fileId = nullptr;
    width = nullptr;
    height = nullptr;
    duration = nullptr;
    thumb = nullptr;
    mimeType = nullptr;
    fileSize = nullptr;
}

Video::~Video()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete width; width = nullptr;
    if(map.find("width") != map.end()) {
        delete (int *) map["width"];
    }
    delete height; height = nullptr;
    if(map.find("height") != map.end()) {
        delete (int *) map["height"];
    }
    delete duration; duration = nullptr;
    if(map.find("duration") != map.end()) {
        delete (int *) map["duration"];
    }
    delete thumb; thumb = nullptr;
    if(map.find("thumb") != map.end()) {
        delete (PhotoSize *) map["thumb"];
    }
    delete mimeType; mimeType = nullptr;
    if(map.find("mimeType") != map.end()) {
        delete (std::string *) map["mimeType"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
}

Video::Video(const Video &src)
{
    copy(*this, src);
}

Video & Video::operator=(const Video &src)
{
    return copy(*this, src);
}

Video::Video(Video &&src) : Video()
{
    move(*this, src);
}

Video & Video::operator=(Video &&src)
{
    return move(*this, src);
}

Video::Video(const std::string &fileId, const int &width, const int &height, const int &duration) : Video()
{
    this->fileId = new std::string(fileId);
    this->width = new int(width);
    this->height = new int(height);
    this->duration = new int(duration);
}

Video::Video(const std::string &fileId, const int &width, const int &height, const int &duration, const PhotoSize &thumb, const std::string &mimeType, const int &fileSize) : Video(fileId, width, height, duration)
{
    this->fileId = new std::string(fileId);
    this->width = new int(width);
    this->height = new int(height);
    this->duration = new int(duration);
    this->thumb = new PhotoSize(thumb);
    this->mimeType = new std::string(mimeType);
    this->fileSize = new int(fileSize);
}

std::string * Video::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

int * Video::GetWidth()
{
    if(width == nullptr) {
        if(map.find("width") == map.end()) {
            map.emplace("width", (void *) new int);
        }
        return (int *) map["width"];
    }
    return width;
}

int * Video::GetHeight()
{
    if(height == nullptr) {
        if(map.find("height") == map.end()) {
            map.emplace("height", (void *) new int);
        }
        return (int *) map["height"];
    }
    return height;
}

int * Video::GetDuration()
{
    if(duration == nullptr) {
        if(map.find("duration") == map.end()) {
            map.emplace("duration", (void *) new int);
        }
        return (int *) map["duration"];
    }
    return duration;
}

PhotoSize * Video::GetThumb()
{
    if(thumb == nullptr) {
        if(map.find("thumb") == map.end()) {
            map.emplace("thumb", (void *) new PhotoSize);
        }
        return (PhotoSize *) map["thumb"];
    }
    return thumb;
}

std::string * Video::GetMimeType()
{
    if(mimeType == nullptr) {
        if(map.find("mimeType") == map.end()) {
            map.emplace("mimeType", (void *) new std::string);
        }
        return (std::string *) map["mimeType"];
    }
    return mimeType;
}

int * Video::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string & Video::GetFileIdValue() const
{
    return *fileId;
}

int & Video::GetWidthValue() const
{
    return *width;
}

int & Video::GetHeightValue() const
{
    return *height;
}

int & Video::GetDurationValue() const
{
    return *duration;
}

PhotoSize & Video::GetThumbValue() const
{
    return *thumb;
}

std::string & Video::GetMimeTypeValue() const
{
    return *mimeType;
}

int & Video::GetFileSizeValue() const
{
    return *fileSize;
}

void Video::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void Video::SetWidth(const int &width)
{
    if(this->width != nullptr) {
        delete this->width;
    }
    this->width = new int(width);
}

void Video::SetHeight(const int &height)
{
    if(this->height != nullptr) {
        delete this->height;
    }
    this->height = new int(height);
}

void Video::SetDuration(const int &duration)
{
    if(this->duration != nullptr) {
        delete this->duration;
    }
    this->duration = new int(duration);
}

void Video::SetThumb(const PhotoSize &thumb)
{
    if(this->thumb != nullptr) {
        delete this->thumb;
    }
    this->thumb = new PhotoSize(thumb);
}

void Video::SetMimeType(const std::string &mimeType)
{
    if(this->mimeType != nullptr) {
        delete this->mimeType;
    }
    this->mimeType = new std::string(mimeType);
}

void Video::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

Voice::Voice()
{
    fileId = nullptr;
    duration = nullptr;
    mimeType = nullptr;
    fileSize = nullptr;
}

Voice::~Voice()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete duration; duration = nullptr;
    if(map.find("duration") != map.end()) {
        delete (int *) map["duration"];
    }
    delete mimeType; mimeType = nullptr;
    if(map.find("mimeType") != map.end()) {
        delete (std::string *) map["mimeType"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
}

Voice::Voice(const Voice &src)
{
    copy(*this, src);
}

Voice & Voice::operator=(const Voice &src)
{
    return copy(*this, src);
}

Voice::Voice(Voice &&src) : Voice()
{
    move(*this, src);
}

Voice & Voice::operator=(Voice &&src)
{
    return move(*this, src);
}

Voice::Voice(const std::string &fileId, const int &duration) : Voice()
{
    this->fileId = new std::string(fileId);
    this->duration = new int(duration);
}

Voice::Voice(const std::string &fileId, const int &duration, const std::string &mimeType, const int &fileSize) : Voice(fileId, duration)
{
    this->fileId = new std::string(fileId);
    this->duration = new int(duration);
    this->mimeType = new std::string(mimeType);
    this->fileSize = new int(fileSize);
}

std::string * Voice::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

int * Voice::GetDuration()
{
    if(duration == nullptr) {
        if(map.find("duration") == map.end()) {
            map.emplace("duration", (void *) new int);
        }
        return (int *) map["duration"];
    }
    return duration;
}

std::string * Voice::GetMimeType()
{
    if(mimeType == nullptr) {
        if(map.find("mimeType") == map.end()) {
            map.emplace("mimeType", (void *) new std::string);
        }
        return (std::string *) map["mimeType"];
    }
    return mimeType;
}

int * Voice::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string & Voice::GetFileIdValue() const
{
    return *fileId;
}

int & Voice::GetDurationValue() const
{
    return *duration;
}

std::string & Voice::GetMimeTypeValue() const
{
    return *mimeType;
}

int & Voice::GetFileSizeValue() const
{
    return *fileSize;
}

void Voice::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void Voice::SetDuration(const int &duration)
{
    if(this->duration != nullptr) {
        delete this->duration;
    }
    this->duration = new int(duration);
}

void Voice::SetMimeType(const std::string &mimeType)
{
    if(this->mimeType != nullptr) {
        delete this->mimeType;
    }
    this->mimeType = new std::string(mimeType);
}

void Voice::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

Contact::Contact()
{
    phoneNumber = nullptr;
    firstName = nullptr;
    lastName = nullptr;
    userId = nullptr;
}

Contact::~Contact()
{
    delete phoneNumber; phoneNumber = nullptr;
    if(map.find("phoneNumber") != map.end()) {
        delete (std::string *) map["phoneNumber"];
    }
    delete firstName; firstName = nullptr;
    if(map.find("firstName") != map.end()) {
        delete (std::string *) map["firstName"];
    }
    delete lastName; lastName = nullptr;
    if(map.find("lastName") != map.end()) {
        delete (std::string *) map["lastName"];
    }
    delete userId; userId = nullptr;
    if(map.find("userId") != map.end()) {
        delete (int *) map["userId"];
    }
}

Contact::Contact(const Contact &src)
{
    copy(*this, src);
}

Contact & Contact::operator=(const Contact &src)
{
    return copy(*this, src);
}

Contact::Contact(Contact &&src) : Contact()
{
    move(*this, src);
}

Contact & Contact::operator=(Contact &&src)
{
    return move(*this, src);
}

Contact::Contact(const std::string &phoneNumber, const std::string &firstName) : Contact()
{
    this->phoneNumber = new std::string(phoneNumber);
    this->firstName = new std::string(firstName);
}

Contact::Contact(const std::string &phoneNumber, const std::string &firstName, const std::string &lastName, const int &userId) : Contact(phoneNumber, firstName)
{
    this->phoneNumber = new std::string(phoneNumber);
    this->firstName = new std::string(firstName);
    this->lastName = new std::string(lastName);
    this->userId = new int(userId);
}

std::string * Contact::GetPhoneNumber()
{
    if(phoneNumber == nullptr) {
        if(map.find("phoneNumber") == map.end()) {
            map.emplace("phoneNumber", (void *) new std::string);
        }
        return (std::string *) map["phoneNumber"];
    }
    return phoneNumber;
}

std::string * Contact::GetFirstName()
{
    if(firstName == nullptr) {
        if(map.find("firstName") == map.end()) {
            map.emplace("firstName", (void *) new std::string);
        }
        return (std::string *) map["firstName"];
    }
    return firstName;
}

std::string * Contact::GetLastName()
{
    if(lastName == nullptr) {
        if(map.find("lastName") == map.end()) {
            map.emplace("lastName", (void *) new std::string);
        }
        return (std::string *) map["lastName"];
    }
    return lastName;
}

int * Contact::GetUserId()
{
    if(userId == nullptr) {
        if(map.find("userId") == map.end()) {
            map.emplace("userId", (void *) new int);
        }
        return (int *) map["userId"];
    }
    return userId;
}

std::string & Contact::GetPhoneNumberValue() const
{
    return *phoneNumber;
}

std::string & Contact::GetFirstNameValue() const
{
    return *firstName;
}

std::string & Contact::GetLastNameValue() const
{
    return *lastName;
}

int & Contact::GetUserIdValue() const
{
    return *userId;
}

void Contact::SetPhoneNumber(const std::string &phoneNumber)
{
    if(this->phoneNumber != nullptr) {
        delete this->phoneNumber;
    }
    this->phoneNumber = new std::string(phoneNumber);
}

void Contact::SetFirstName(const std::string &firstName)
{
    if(this->firstName != nullptr) {
        delete this->firstName;
    }
    this->firstName = new std::string(firstName);
}

void Contact::SetLastName(const std::string &lastName)
{
    if(this->lastName != nullptr) {
        delete this->lastName;
    }
    this->lastName = new std::string(lastName);
}

void Contact::SetUserId(const int &userId)
{
    if(this->userId != nullptr) {
        delete this->userId;
    }
    this->userId = new int(userId);
}

Location::Location()
{
    longitude = nullptr;
    latitude = nullptr;
}

Location::~Location()
{
    delete longitude; longitude = nullptr;
    if(map.find("longitude") != map.end()) {
        delete (float *) map["longitude"];
    }
    delete latitude; latitude = nullptr;
    if(map.find("latitude") != map.end()) {
        delete (float *) map["latitude"];
    }
}

Location::Location(const Location &src)
{
    copy(*this, src);
}

Location & Location::operator=(const Location &src)
{
    return copy(*this, src);
}

Location::Location(Location &&src) : Location()
{
    move(*this, src);
}

Location & Location::operator=(Location &&src)
{
    return move(*this, src);
}

Location::Location(const float &longitude, const float &latitude) : Location()
{
    this->longitude = new float(longitude);
    this->latitude = new float(latitude);
}

float * Location::GetLongitude()
{
    if(longitude == nullptr) {
        if(map.find("longitude") == map.end()) {
            map.emplace("longitude", (void *) new float);
        }
        return (float *) map["longitude"];
    }
    return longitude;
}

float * Location::GetLatitude()
{
    if(latitude == nullptr) {
        if(map.find("latitude") == map.end()) {
            map.emplace("latitude", (void *) new float);
        }
        return (float *) map["latitude"];
    }
    return latitude;
}

float & Location::GetLongitudeValue() const
{
    return *longitude;
}

float & Location::GetLatitudeValue() const
{
    return *latitude;
}

void Location::SetLongitude(const float &longitude)
{
    if(this->longitude != nullptr) {
        delete this->longitude;
    }
    this->longitude = new float(longitude);
}

void Location::SetLatitude(const float &latitude)
{
    if(this->latitude != nullptr) {
        delete this->latitude;
    }
    this->latitude = new float(latitude);
}

Venue::Venue()
{
    location = nullptr;
    title = nullptr;
    address = nullptr;
    foursquareId = nullptr;
}

Venue::~Venue()
{
    delete location; location = nullptr;
    if(map.find("location") != map.end()) {
        delete (Location *) map["location"];
    }
    delete title; title = nullptr;
    if(map.find("title") != map.end()) {
        delete (std::string *) map["title"];
    }
    delete address; address = nullptr;
    if(map.find("address") != map.end()) {
        delete (std::string *) map["address"];
    }
    delete foursquareId; foursquareId = nullptr;
    if(map.find("foursquareId") != map.end()) {
        delete (std::string *) map["foursquareId"];
    }
}

Venue::Venue(const Venue &src)
{
    copy(*this, src);
}

Venue & Venue::operator=(const Venue &src)
{
    return copy(*this, src);
}

Venue::Venue(Venue &&src) : Venue()
{
    move(*this, src);
}

Venue & Venue::operator=(Venue &&src)
{
    return move(*this, src);
}

Venue::Venue(const Location &location, const std::string &title, const std::string &address) : Venue()
{
    this->location = new Location(location);
    this->title = new std::string(title);
    this->address = new std::string(address);
}

Venue::Venue(const Location &location, const std::string &title, const std::string &address, const std::string &foursquareId) : Venue(location, title, address)
{
    this->location = new Location(location);
    this->title = new std::string(title);
    this->address = new std::string(address);
    this->foursquareId = new std::string(foursquareId);
}

Location * Venue::GetLocation()
{
    if(location == nullptr) {
        if(map.find("location") == map.end()) {
            map.emplace("location", (void *) new Location);
        }
        return (Location *) map["location"];
    }
    return location;
}

std::string * Venue::GetTitle()
{
    if(title == nullptr) {
        if(map.find("title") == map.end()) {
            map.emplace("title", (void *) new std::string);
        }
        return (std::string *) map["title"];
    }
    return title;
}

std::string * Venue::GetAddress()
{
    if(address == nullptr) {
        if(map.find("address") == map.end()) {
            map.emplace("address", (void *) new std::string);
        }
        return (std::string *) map["address"];
    }
    return address;
}

std::string * Venue::GetFoursquareId()
{
    if(foursquareId == nullptr) {
        if(map.find("foursquareId") == map.end()) {
            map.emplace("foursquareId", (void *) new std::string);
        }
        return (std::string *) map["foursquareId"];
    }
    return foursquareId;
}

Location & Venue::GetLocationValue() const
{
    return *location;
}

std::string & Venue::GetTitleValue() const
{
    return *title;
}

std::string & Venue::GetAddressValue() const
{
    return *address;
}

std::string & Venue::GetFoursquareIdValue() const
{
    return *foursquareId;
}

void Venue::SetLocation(const Location &location)
{
    if(this->location != nullptr) {
        delete this->location;
    }
    this->location = new Location(location);
}

void Venue::SetTitle(const std::string &title)
{
    if(this->title != nullptr) {
        delete this->title;
    }
    this->title = new std::string(title);
}

void Venue::SetAddress(const std::string &address)
{
    if(this->address != nullptr) {
        delete this->address;
    }
    this->address = new std::string(address);
}

void Venue::SetFoursquareId(const std::string &foursquareId)
{
    if(this->foursquareId != nullptr) {
        delete this->foursquareId;
    }
    this->foursquareId = new std::string(foursquareId);
}

UserProfilePhotos::UserProfilePhotos()
{
    totalCount = nullptr;
    photos = nullptr;
}

UserProfilePhotos::~UserProfilePhotos()
{
    delete totalCount; totalCount = nullptr;
    if(map.find("totalCount") != map.end()) {
        delete (int *) map["totalCount"];
    }
    delete photos; photos = nullptr;
    if(map.find("photos") != map.end()) {
        delete (std::vector<std::vector<PhotoSize>> *) map["photos"];
    }
}

UserProfilePhotos::UserProfilePhotos(const UserProfilePhotos &src)
{
    copy(*this, src);
}

UserProfilePhotos & UserProfilePhotos::operator=(const UserProfilePhotos &src)
{
    return copy(*this, src);
}

UserProfilePhotos::UserProfilePhotos(UserProfilePhotos &&src) : UserProfilePhotos()
{
    move(*this, src);
}

UserProfilePhotos & UserProfilePhotos::operator=(UserProfilePhotos &&src)
{
    return move(*this, src);
}

UserProfilePhotos::UserProfilePhotos(const int &totalCount, const std::vector<std::vector<PhotoSize>> &photos) : UserProfilePhotos()
{
    this->totalCount = new int(totalCount);
    this->photos = new std::vector<std::vector<PhotoSize>>(photos);
}

int * UserProfilePhotos::GetTotalCount()
{
    if(totalCount == nullptr) {
        if(map.find("totalCount") == map.end()) {
            map.emplace("totalCount", (void *) new int);
        }
        return (int *) map["totalCount"];
    }
    return totalCount;
}

std::vector<std::vector<PhotoSize>> * UserProfilePhotos::GetPhotos()
{
    if(photos == nullptr) {
        if(map.find("photos") == map.end()) {
            map.emplace("photos", (void *) new std::vector<std::vector<PhotoSize>>);
        }
        return (std::vector<std::vector<PhotoSize>> *) map["photos"];
    }
    return photos;
}

int & UserProfilePhotos::GetTotalCountValue() const
{
    return *totalCount;
}

std::vector<std::vector<PhotoSize>> & UserProfilePhotos::GetPhotosValue() const
{
    return *photos;
}

void UserProfilePhotos::SetTotalCount(const int &totalCount)
{
    if(this->totalCount != nullptr) {
        delete this->totalCount;
    }
    this->totalCount = new int(totalCount);
}

void UserProfilePhotos::SetPhotos(const std::vector<std::vector<PhotoSize>> &photos)
{
    if(this->photos != nullptr) {
        delete this->photos;
    }
    this->photos = new std::vector<std::vector<PhotoSize>>(photos);
}

File::File()
{
    fileId = nullptr;
    fileSize = nullptr;
    filePath = nullptr;
}

File::~File()
{
    delete fileId; fileId = nullptr;
    if(map.find("fileId") != map.end()) {
        delete (std::string *) map["fileId"];
    }
    delete fileSize; fileSize = nullptr;
    if(map.find("fileSize") != map.end()) {
        delete (int *) map["fileSize"];
    }
    delete filePath; filePath = nullptr;
    if(map.find("filePath") != map.end()) {
        delete (std::string *) map["filePath"];
    }
}

File::File(const File &src)
{
    copy(*this, src);
}

File & File::operator=(const File &src)
{
    return copy(*this, src);
}

File::File(File &&src) : File()
{
    move(*this, src);
}

File & File::operator=(File &&src)
{
    return move(*this, src);
}

File::File(const std::string &fileId) : File()
{
    this->fileId = new std::string(fileId);
}

File::File(const std::string &fileId, const int &fileSize, const std::string &filePath) : File(fileId)
{
    this->fileId = new std::string(fileId);
    this->fileSize = new int(fileSize);
    this->filePath = new std::string(filePath);
}

std::string * File::GetFileId()
{
    if(fileId == nullptr) {
        if(map.find("fileId") == map.end()) {
            map.emplace("fileId", (void *) new std::string);
        }
        return (std::string *) map["fileId"];
    }
    return fileId;
}

int * File::GetFileSize()
{
    if(fileSize == nullptr) {
        if(map.find("fileSize") == map.end()) {
            map.emplace("fileSize", (void *) new int);
        }
        return (int *) map["fileSize"];
    }
    return fileSize;
}

std::string * File::GetFilePath()
{
    if(filePath == nullptr) {
        if(map.find("filePath") == map.end()) {
            map.emplace("filePath", (void *) new std::string);
        }
        return (std::string *) map["filePath"];
    }
    return filePath;
}

std::string & File::GetFileIdValue() const
{
    return *fileId;
}

int & File::GetFileSizeValue() const
{
    return *fileSize;
}

std::string & File::GetFilePathValue() const
{
    return *filePath;
}

void File::SetFileId(const std::string &fileId)
{
    if(this->fileId != nullptr) {
        delete this->fileId;
    }
    this->fileId = new std::string(fileId);
}

void File::SetFileSize(const int &fileSize)
{
    if(this->fileSize != nullptr) {
        delete this->fileSize;
    }
    this->fileSize = new int(fileSize);
}

void File::SetFilePath(const std::string &filePath)
{
    if(this->filePath != nullptr) {
        delete this->filePath;
    }
    this->filePath = new std::string(filePath);
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup()
{
    keyboard = nullptr;
    resizeKeyboard = nullptr;
    oneTimeKeyboard = nullptr;
    selective = nullptr;
}

ReplyKeyboardMarkup::~ReplyKeyboardMarkup()
{
    delete keyboard; keyboard = nullptr;
    if(map.find("keyboard") != map.end()) {
        delete (std::vector<std::vector<KeyboardButton>> *) map["keyboard"];
    }
    delete resizeKeyboard; resizeKeyboard = nullptr;
    if(map.find("resizeKeyboard") != map.end()) {
        delete (bool *) map["resizeKeyboard"];
    }
    delete oneTimeKeyboard; oneTimeKeyboard = nullptr;
    if(map.find("oneTimeKeyboard") != map.end()) {
        delete (bool *) map["oneTimeKeyboard"];
    }
    delete selective; selective = nullptr;
    if(map.find("selective") != map.end()) {
        delete (bool *) map["selective"];
    }
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(const ReplyKeyboardMarkup &src)
{
    copy(*this, src);
}

ReplyKeyboardMarkup & ReplyKeyboardMarkup::operator=(const ReplyKeyboardMarkup &src)
{
    return copy(*this, src);
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(ReplyKeyboardMarkup &&src) : ReplyKeyboardMarkup()
{
    move(*this, src);
}

ReplyKeyboardMarkup & ReplyKeyboardMarkup::operator=(ReplyKeyboardMarkup &&src)
{
    return move(*this, src);
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton>> &keyboard) : ReplyKeyboardMarkup()
{
    this->keyboard = new std::vector<std::vector<KeyboardButton>>(keyboard);
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton>> &keyboard, const bool &resizeKeyboard, const bool &oneTimeKeyboard, const bool &selective) : ReplyKeyboardMarkup(keyboard)
{
    this->keyboard = new std::vector<std::vector<KeyboardButton>>(keyboard);
    this->resizeKeyboard = new bool(resizeKeyboard);
    this->oneTimeKeyboard = new bool(oneTimeKeyboard);
    this->selective = new bool(selective);
}

std::vector<std::vector<KeyboardButton>> * ReplyKeyboardMarkup::GetKeyboard()
{
    if(keyboard == nullptr) {
        if(map.find("keyboard") == map.end()) {
            map.emplace("keyboard", (void *) new std::vector<std::vector<KeyboardButton>>);
        }
        return (std::vector<std::vector<KeyboardButton>> *) map["keyboard"];
    }
    return keyboard;
}

bool * ReplyKeyboardMarkup::GetResizeKeyboard()
{
    if(resizeKeyboard == nullptr) {
        if(map.find("resizeKeyboard") == map.end()) {
            map.emplace("resizeKeyboard", (void *) new bool);
        }
        return (bool *) map["resizeKeyboard"];
    }
    return resizeKeyboard;
}

bool * ReplyKeyboardMarkup::GetOneTimeKeyboard()
{
    if(oneTimeKeyboard == nullptr) {
        if(map.find("oneTimeKeyboard") == map.end()) {
            map.emplace("oneTimeKeyboard", (void *) new bool);
        }
        return (bool *) map["oneTimeKeyboard"];
    }
    return oneTimeKeyboard;
}

bool * ReplyKeyboardMarkup::GetSelective()
{
    if(selective == nullptr) {
        if(map.find("selective") == map.end()) {
            map.emplace("selective", (void *) new bool);
        }
        return (bool *) map["selective"];
    }
    return selective;
}

std::vector<std::vector<KeyboardButton>> & ReplyKeyboardMarkup::GetKeyboardValue() const
{
    return *keyboard;
}

bool & ReplyKeyboardMarkup::GetResizeKeyboardValue() const
{
    return *resizeKeyboard;
}

bool & ReplyKeyboardMarkup::GetOneTimeKeyboardValue() const
{
    return *oneTimeKeyboard;
}

bool & ReplyKeyboardMarkup::GetSelectiveValue() const
{
    return *selective;
}

void ReplyKeyboardMarkup::SetKeyboard(const std::vector<std::vector<KeyboardButton>> &keyboard)
{
    if(this->keyboard != nullptr) {
        delete this->keyboard;
    }
    this->keyboard = new std::vector<std::vector<KeyboardButton>>(keyboard);
}

void ReplyKeyboardMarkup::SetResizeKeyboard(const bool &resizeKeyboard)
{
    if(this->resizeKeyboard != nullptr) {
        delete this->resizeKeyboard;
    }
    this->resizeKeyboard = new bool(resizeKeyboard);
}

void ReplyKeyboardMarkup::SetOneTimeKeyboard(const bool &oneTimeKeyboard)
{
    if(this->oneTimeKeyboard != nullptr) {
        delete this->oneTimeKeyboard;
    }
    this->oneTimeKeyboard = new bool(oneTimeKeyboard);
}

void ReplyKeyboardMarkup::SetSelective(const bool &selective)
{
    if(this->selective != nullptr) {
        delete this->selective;
    }
    this->selective = new bool(selective);
}

KeyboardButton::KeyboardButton()
{
    text = nullptr;
    requestContact = nullptr;
    requestLocation = nullptr;
}

KeyboardButton::~KeyboardButton()
{
    delete text; text = nullptr;
    if(map.find("text") != map.end()) {
        delete (std::string *) map["text"];
    }
    delete requestContact; requestContact = nullptr;
    if(map.find("requestContact") != map.end()) {
        delete (bool *) map["requestContact"];
    }
    delete requestLocation; requestLocation = nullptr;
    if(map.find("requestLocation") != map.end()) {
        delete (bool *) map["requestLocation"];
    }
}

KeyboardButton::KeyboardButton(const KeyboardButton &src)
{
    copy(*this, src);
}

KeyboardButton & KeyboardButton::operator=(const KeyboardButton &src)
{
    return copy(*this, src);
}

KeyboardButton::KeyboardButton(KeyboardButton &&src) : KeyboardButton()
{
    move(*this, src);
}

KeyboardButton & KeyboardButton::operator=(KeyboardButton &&src)
{
    return move(*this, src);
}

KeyboardButton::KeyboardButton(const std::string &text) : KeyboardButton()
{
    this->text = new std::string(text);
}

KeyboardButton::KeyboardButton(const std::string &text, const bool &requestContact, const bool &requestLocation) : KeyboardButton(text)
{
    this->text = new std::string(text);
    this->requestContact = new bool(requestContact);
    this->requestLocation = new bool(requestLocation);
}

std::string * KeyboardButton::GetText()
{
    if(text == nullptr) {
        if(map.find("text") == map.end()) {
            map.emplace("text", (void *) new std::string);
        }
        return (std::string *) map["text"];
    }
    return text;
}

bool * KeyboardButton::GetRequestContact()
{
    if(requestContact == nullptr) {
        if(map.find("requestContact") == map.end()) {
            map.emplace("requestContact", (void *) new bool);
        }
        return (bool *) map["requestContact"];
    }
    return requestContact;
}

bool * KeyboardButton::GetRequestLocation()
{
    if(requestLocation == nullptr) {
        if(map.find("requestLocation") == map.end()) {
            map.emplace("requestLocation", (void *) new bool);
        }
        return (bool *) map["requestLocation"];
    }
    return requestLocation;
}

std::string & KeyboardButton::GetTextValue() const
{
    return *text;
}

bool & KeyboardButton::GetRequestContactValue() const
{
    return *requestContact;
}

bool & KeyboardButton::GetRequestLocationValue() const
{
    return *requestLocation;
}

void KeyboardButton::SetText(const std::string &text)
{
    if(this->text != nullptr) {
        delete this->text;
    }
    this->text = new std::string(text);
}

void KeyboardButton::SetRequestContact(const bool &requestContact)
{
    if(this->requestContact != nullptr) {
        delete this->requestContact;
    }
    this->requestContact = new bool(requestContact);
}

void KeyboardButton::SetRequestLocation(const bool &requestLocation)
{
    if(this->requestLocation != nullptr) {
        delete this->requestLocation;
    }
    this->requestLocation = new bool(requestLocation);
}

ReplyKeyboardHide::ReplyKeyboardHide()
{
    hideKeyboard = nullptr;
    selective = nullptr;
}

ReplyKeyboardHide::~ReplyKeyboardHide()
{
    delete hideKeyboard; hideKeyboard = nullptr;
    if(map.find("hideKeyboard") != map.end()) {
        delete (bool *) map["hideKeyboard"];
    }
    delete selective; selective = nullptr;
    if(map.find("selective") != map.end()) {
        delete (bool *) map["selective"];
    }
}

ReplyKeyboardHide::ReplyKeyboardHide(const ReplyKeyboardHide &src)
{
    copy(*this, src);
}

ReplyKeyboardHide & ReplyKeyboardHide::operator=(const ReplyKeyboardHide &src)
{
    return copy(*this, src);
}

ReplyKeyboardHide::ReplyKeyboardHide(ReplyKeyboardHide &&src) : ReplyKeyboardHide()
{
    move(*this, src);
}

ReplyKeyboardHide & ReplyKeyboardHide::operator=(ReplyKeyboardHide &&src)
{
    return move(*this, src);
}

ReplyKeyboardHide::ReplyKeyboardHide(const bool &hideKeyboard) : ReplyKeyboardHide()
{
    this->hideKeyboard = new bool(hideKeyboard);
}

ReplyKeyboardHide::ReplyKeyboardHide(const bool &hideKeyboard, const bool &selective) : ReplyKeyboardHide(hideKeyboard)
{
    this->hideKeyboard = new bool(hideKeyboard);
    this->selective = new bool(selective);
}

bool * ReplyKeyboardHide::GetHideKeyboard()
{
    if(hideKeyboard == nullptr) {
        if(map.find("hideKeyboard") == map.end()) {
            map.emplace("hideKeyboard", (void *) new bool);
        }
        return (bool *) map["hideKeyboard"];
    }
    return hideKeyboard;
}

bool * ReplyKeyboardHide::GetSelective()
{
    if(selective == nullptr) {
        if(map.find("selective") == map.end()) {
            map.emplace("selective", (void *) new bool);
        }
        return (bool *) map["selective"];
    }
    return selective;
}

bool & ReplyKeyboardHide::GetHideKeyboardValue() const
{
    return *hideKeyboard;
}

bool & ReplyKeyboardHide::GetSelectiveValue() const
{
    return *selective;
}

void ReplyKeyboardHide::SetHideKeyboard(const bool &hideKeyboard)
{
    if(this->hideKeyboard != nullptr) {
        delete this->hideKeyboard;
    }
    this->hideKeyboard = new bool(hideKeyboard);
}

void ReplyKeyboardHide::SetSelective(const bool &selective)
{
    if(this->selective != nullptr) {
        delete this->selective;
    }
    this->selective = new bool(selective);
}

InlineKeyboardMarkup::InlineKeyboardMarkup()
{
    inlineKeyboard = nullptr;
}

InlineKeyboardMarkup::~InlineKeyboardMarkup()
{
    delete inlineKeyboard; inlineKeyboard = nullptr;
    if(map.find("inlineKeyboard") != map.end()) {
        delete (std::vector<std::vector<InlineKeyboardButton>> *) map["inlineKeyboard"];
    }
}

InlineKeyboardMarkup::InlineKeyboardMarkup(const InlineKeyboardMarkup &src)
{
    copy(*this, src);
}

InlineKeyboardMarkup & InlineKeyboardMarkup::operator=(const InlineKeyboardMarkup &src)
{
    return copy(*this, src);
}

InlineKeyboardMarkup::InlineKeyboardMarkup(InlineKeyboardMarkup &&src) : InlineKeyboardMarkup()
{
    move(*this, src);
}

InlineKeyboardMarkup & InlineKeyboardMarkup::operator=(InlineKeyboardMarkup &&src)
{
    return move(*this, src);
}

InlineKeyboardMarkup::InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton>> &inlineKeyboard) : InlineKeyboardMarkup()
{
    this->inlineKeyboard = new std::vector<std::vector<InlineKeyboardButton>>(inlineKeyboard);
}

std::vector<std::vector<InlineKeyboardButton>> * InlineKeyboardMarkup::GetInlineKeyboard()
{
    if(inlineKeyboard == nullptr) {
        if(map.find("inlineKeyboard") == map.end()) {
            map.emplace("inlineKeyboard", (void *) new std::vector<std::vector<InlineKeyboardButton>>);
        }
        return (std::vector<std::vector<InlineKeyboardButton>> *) map["inlineKeyboard"];
    }
    return inlineKeyboard;
}

std::vector<std::vector<InlineKeyboardButton>> & InlineKeyboardMarkup::GetInlineKeyboardValue() const
{
    return *inlineKeyboard;
}

void InlineKeyboardMarkup::SetInlineKeyboard(const std::vector<std::vector<InlineKeyboardButton>> &inlineKeyboard)
{
    if(this->inlineKeyboard != nullptr) {
        delete this->inlineKeyboard;
    }
    this->inlineKeyboard = new std::vector<std::vector<InlineKeyboardButton>>(inlineKeyboard);
}

InlineKeyboardButton::InlineKeyboardButton()
{
    text = nullptr;
    url = nullptr;
    callbackData = nullptr;
    switchInlineQuery = nullptr;
}

InlineKeyboardButton::~InlineKeyboardButton()
{
    delete text; text = nullptr;
    if(map.find("text") != map.end()) {
        delete (std::string *) map["text"];
    }
    delete url; url = nullptr;
    if(map.find("url") != map.end()) {
        delete (std::string *) map["url"];
    }
    delete callbackData; callbackData = nullptr;
    if(map.find("callbackData") != map.end()) {
        delete (std::string *) map["callbackData"];
    }
    delete switchInlineQuery; switchInlineQuery = nullptr;
    if(map.find("switchInlineQuery") != map.end()) {
        delete (std::string *) map["switchInlineQuery"];
    }
}

InlineKeyboardButton::InlineKeyboardButton(const InlineKeyboardButton &src)
{
    copy(*this, src);
}

InlineKeyboardButton & InlineKeyboardButton::operator=(const InlineKeyboardButton &src)
{
    return copy(*this, src);
}

InlineKeyboardButton::InlineKeyboardButton(InlineKeyboardButton &&src) : InlineKeyboardButton()
{
    move(*this, src);
}

InlineKeyboardButton & InlineKeyboardButton::operator=(InlineKeyboardButton &&src)
{
    return move(*this, src);
}

InlineKeyboardButton::InlineKeyboardButton(const std::string &text) : InlineKeyboardButton()
{
    this->text = new std::string(text);
}

InlineKeyboardButton::InlineKeyboardButton(const std::string &text, const std::string &url, const std::string &callbackData, const std::string &switchInlineQuery) : InlineKeyboardButton(text)
{
    this->text = new std::string(text);
    this->url = new std::string(url);
    this->callbackData = new std::string(callbackData);
    this->switchInlineQuery = new std::string(switchInlineQuery);
}

std::string * InlineKeyboardButton::GetText()
{
    if(text == nullptr) {
        if(map.find("text") == map.end()) {
            map.emplace("text", (void *) new std::string);
        }
        return (std::string *) map["text"];
    }
    return text;
}

std::string * InlineKeyboardButton::GetUrl()
{
    if(url == nullptr) {
        if(map.find("url") == map.end()) {
            map.emplace("url", (void *) new std::string);
        }
        return (std::string *) map["url"];
    }
    return url;
}

std::string * InlineKeyboardButton::GetCallbackData()
{
    if(callbackData == nullptr) {
        if(map.find("callbackData") == map.end()) {
            map.emplace("callbackData", (void *) new std::string);
        }
        return (std::string *) map["callbackData"];
    }
    return callbackData;
}

std::string * InlineKeyboardButton::GetSwitchInlineQuery()
{
    if(switchInlineQuery == nullptr) {
        if(map.find("switchInlineQuery") == map.end()) {
            map.emplace("switchInlineQuery", (void *) new std::string);
        }
        return (std::string *) map["switchInlineQuery"];
    }
    return switchInlineQuery;
}

std::string & InlineKeyboardButton::GetTextValue() const
{
    return *text;
}

std::string & InlineKeyboardButton::GetUrlValue() const
{
    return *url;
}

std::string & InlineKeyboardButton::GetCallbackDataValue() const
{
    return *callbackData;
}

std::string & InlineKeyboardButton::GetSwitchInlineQueryValue() const
{
    return *switchInlineQuery;
}

void InlineKeyboardButton::SetText(const std::string &text)
{
    if(this->text != nullptr) {
        delete this->text;
    }
    this->text = new std::string(text);
}

void InlineKeyboardButton::SetUrl(const std::string &url)
{
    if(this->url != nullptr) {
        delete this->url;
    }
    this->url = new std::string(url);
}

void InlineKeyboardButton::SetCallbackData(const std::string &callbackData)
{
    if(this->callbackData != nullptr) {
        delete this->callbackData;
    }
    this->callbackData = new std::string(callbackData);
}

void InlineKeyboardButton::SetSwitchInlineQuery(const std::string &switchInlineQuery)
{
    if(this->switchInlineQuery != nullptr) {
        delete this->switchInlineQuery;
    }
    this->switchInlineQuery = new std::string(switchInlineQuery);
}

CallbackQuery::CallbackQuery()
{
    id = nullptr;
    from = nullptr;
    message = nullptr;
    inlineMessageId = nullptr;
    data = nullptr;
}

CallbackQuery::~CallbackQuery()
{
    delete id; id = nullptr;
    if(map.find("id") != map.end()) {
        delete (std::string *) map["id"];
    }
    delete from; from = nullptr;
    if(map.find("from") != map.end()) {
        delete (User *) map["from"];
    }
    delete message; message = nullptr;
    if(map.find("message") != map.end()) {
        delete (Message *) map["message"];
    }
    delete inlineMessageId; inlineMessageId = nullptr;
    if(map.find("inlineMessageId") != map.end()) {
        delete (std::string *) map["inlineMessageId"];
    }
    delete data; data = nullptr;
    if(map.find("data") != map.end()) {
        delete (std::string *) map["data"];
    }
}

CallbackQuery::CallbackQuery(const CallbackQuery &src)
{
    copy(*this, src);
}

CallbackQuery & CallbackQuery::operator=(const CallbackQuery &src)
{
    return copy(*this, src);
}

CallbackQuery::CallbackQuery(CallbackQuery &&src) : CallbackQuery()
{
    move(*this, src);
}

CallbackQuery & CallbackQuery::operator=(CallbackQuery &&src)
{
    return move(*this, src);
}

CallbackQuery::CallbackQuery(const std::string &id, const User &from, const std::string &data) : CallbackQuery()
{
    this->id = new std::string(id);
    this->from = new User(from);
    this->data = new std::string(data);
}

CallbackQuery::CallbackQuery(const std::string &id, const User &from, const Message &message, const std::string &inlineMessageId, const std::string &data) : CallbackQuery(id, from, data)
{
    this->id = new std::string(id);
    this->from = new User(from);
    this->message = new Message(message);
    this->inlineMessageId = new std::string(inlineMessageId);
    this->data = new std::string(data);
}

std::string * CallbackQuery::GetId()
{
    if(id == nullptr) {
        if(map.find("id") == map.end()) {
            map.emplace("id", (void *) new std::string);
        }
        return (std::string *) map["id"];
    }
    return id;
}

User * CallbackQuery::GetFrom()
{
    if(from == nullptr) {
        if(map.find("from") == map.end()) {
            map.emplace("from", (void *) new User);
        }
        return (User *) map["from"];
    }
    return from;
}

Message * CallbackQuery::GetMessage()
{
    if(message == nullptr) {
        if(map.find("message") == map.end()) {
            map.emplace("message", (void *) new Message);
        }
        return (Message *) map["message"];
    }
    return message;
}

std::string * CallbackQuery::GetInlineMessageId()
{
    if(inlineMessageId == nullptr) {
        if(map.find("inlineMessageId") == map.end()) {
            map.emplace("inlineMessageId", (void *) new std::string);
        }
        return (std::string *) map["inlineMessageId"];
    }
    return inlineMessageId;
}

std::string * CallbackQuery::GetData()
{
    if(data == nullptr) {
        if(map.find("data") == map.end()) {
            map.emplace("data", (void *) new std::string);
        }
        return (std::string *) map["data"];
    }
    return data;
}

std::string & CallbackQuery::GetIdValue() const
{
    return *id;
}

User & CallbackQuery::GetFromValue() const
{
    return *from;
}

Message & CallbackQuery::GetMessageValue() const
{
    return *message;
}

std::string & CallbackQuery::GetInlineMessageIdValue() const
{
    return *inlineMessageId;
}

std::string & CallbackQuery::GetDataValue() const
{
    return *data;
}

void CallbackQuery::SetId(const std::string &id)
{
    if(this->id != nullptr) {
        delete this->id;
    }
    this->id = new std::string(id);
}

void CallbackQuery::SetFrom(const User &from)
{
    if(this->from != nullptr) {
        delete this->from;
    }
    this->from = new User(from);
}

void CallbackQuery::SetMessage(const Message &message)
{
    if(this->message != nullptr) {
        delete this->message;
    }
    this->message = new Message(message);
}

void CallbackQuery::SetInlineMessageId(const std::string &inlineMessageId)
{
    if(this->inlineMessageId != nullptr) {
        delete this->inlineMessageId;
    }
    this->inlineMessageId = new std::string(inlineMessageId);
}

void CallbackQuery::SetData(const std::string &data)
{
    if(this->data != nullptr) {
        delete this->data;
    }
    this->data = new std::string(data);
}

ForceReply::ForceReply()
{
    forceReply = nullptr;
    selective = nullptr;
}

ForceReply::~ForceReply()
{
    delete forceReply; forceReply = nullptr;
    if(map.find("forceReply") != map.end()) {
        delete (bool *) map["forceReply"];
    }
    delete selective; selective = nullptr;
    if(map.find("selective") != map.end()) {
        delete (bool *) map["selective"];
    }
}

ForceReply::ForceReply(const ForceReply &src)
{
    copy(*this, src);
}

ForceReply & ForceReply::operator=(const ForceReply &src)
{
    return copy(*this, src);
}

ForceReply::ForceReply(ForceReply &&src) : ForceReply()
{
    move(*this, src);
}

ForceReply & ForceReply::operator=(ForceReply &&src)
{
    return move(*this, src);
}

ForceReply::ForceReply(const bool &forceReply) : ForceReply()
{
    this->forceReply = new bool(forceReply);
}

ForceReply::ForceReply(const bool &forceReply, const bool &selective) : ForceReply(forceReply)
{
    this->forceReply = new bool(forceReply);
    this->selective = new bool(selective);
}

bool * ForceReply::GetForceReply()
{
    if(forceReply == nullptr) {
        if(map.find("forceReply") == map.end()) {
            map.emplace("forceReply", (void *) new bool);
        }
        return (bool *) map["forceReply"];
    }
    return forceReply;
}

bool * ForceReply::GetSelective()
{
    if(selective == nullptr) {
        if(map.find("selective") == map.end()) {
            map.emplace("selective", (void *) new bool);
        }
        return (bool *) map["selective"];
    }
    return selective;
}

bool & ForceReply::GetForceReplyValue() const
{
    return *forceReply;
}

bool & ForceReply::GetSelectiveValue() const
{
    return *selective;
}

void ForceReply::SetForceReply(const bool &forceReply)
{
    if(this->forceReply != nullptr) {
        delete this->forceReply;
    }
    this->forceReply = new bool(forceReply);
}

void ForceReply::SetSelective(const bool &selective)
{
    if(this->selective != nullptr) {
        delete this->selective;
    }
    this->selective = new bool(selective);
}

ChatMember::ChatMember()
{
    user = nullptr;
    status = nullptr;
}

ChatMember::~ChatMember()
{
    delete user; user = nullptr;
    if(map.find("user") != map.end()) {
        delete (User *) map["user"];
    }
    delete status; status = nullptr;
    if(map.find("status") != map.end()) {
        delete (std::string *) map["status"];
    }
}

ChatMember::ChatMember(const ChatMember &src)
{
    copy(*this, src);
}

ChatMember & ChatMember::operator=(const ChatMember &src)
{
    return copy(*this, src);
}

ChatMember::ChatMember(ChatMember &&src) : ChatMember()
{
    move(*this, src);
}

ChatMember & ChatMember::operator=(ChatMember &&src)
{
    return move(*this, src);
}

ChatMember::ChatMember(const User &user, const std::string &status) : ChatMember()
{
    this->user = new User(user);
    this->status = new std::string(status);
}

User * ChatMember::GetUser()
{
    if(user == nullptr) {
        if(map.find("user") == map.end()) {
            map.emplace("user", (void *) new User);
        }
        return (User *) map["user"];
    }
    return user;
}

std::string * ChatMember::GetStatus()
{
    if(status == nullptr) {
        if(map.find("status") == map.end()) {
            map.emplace("status", (void *) new std::string);
        }
        return (std::string *) map["status"];
    }
    return status;
}

User & ChatMember::GetUserValue() const
{
    return *user;
}

std::string & ChatMember::GetStatusValue() const
{
    return *status;
}

void ChatMember::SetUser(const User &user)
{
    if(this->user != nullptr) {
        delete this->user;
    }
    this->user = new User(user);
}

void ChatMember::SetStatus(const std::string &status)
{
    if(this->status != nullptr) {
        delete this->status;
    }
    this->status = new std::string(status);
}

InlineQuery::InlineQuery()
{
    id = nullptr;
    from = nullptr;
    location = nullptr;
    query = nullptr;
    offset = nullptr;
}

InlineQuery::~InlineQuery()
{
    delete id; id = nullptr;
    if(map.find("id") != map.end()) {
        delete (std::string *) map["id"];
    }
    delete from; from = nullptr;
    if(map.find("from") != map.end()) {
        delete (User *) map["from"];
    }
    delete location; location = nullptr;
    if(map.find("location") != map.end()) {
        delete (Location *) map["location"];
    }
    delete query; query = nullptr;
    if(map.find("query") != map.end()) {
        delete (std::string *) map["query"];
    }
    delete offset; offset = nullptr;
    if(map.find("offset") != map.end()) {
        delete (std::string *) map["offset"];
    }
}

InlineQuery::InlineQuery(const InlineQuery &src)
{
    copy(*this, src);
}

InlineQuery & InlineQuery::operator=(const InlineQuery &src)
{
    return copy(*this, src);
}

InlineQuery::InlineQuery(InlineQuery &&src) : InlineQuery()
{
    move(*this, src);
}

InlineQuery & InlineQuery::operator=(InlineQuery &&src)
{
    return move(*this, src);
}

InlineQuery::InlineQuery(const std::string &id, const User &from, const std::string &query, const std::string &offset) : InlineQuery()
{
    this->id = new std::string(id);
    this->from = new User(from);
    this->query = new std::string(query);
    this->offset = new std::string(offset);
}

InlineQuery::InlineQuery(const std::string &id, const User &from, const Location &location, const std::string &query, const std::string &offset) : InlineQuery(id, from, query, offset)
{
    this->id = new std::string(id);
    this->from = new User(from);
    this->location = new Location(location);
    this->query = new std::string(query);
    this->offset = new std::string(offset);
}

std::string * InlineQuery::GetId()
{
    if(id == nullptr) {
        if(map.find("id") == map.end()) {
            map.emplace("id", (void *) new std::string);
        }
        return (std::string *) map["id"];
    }
    return id;
}

User * InlineQuery::GetFrom()
{
    if(from == nullptr) {
        if(map.find("from") == map.end()) {
            map.emplace("from", (void *) new User);
        }
        return (User *) map["from"];
    }
    return from;
}

Location * InlineQuery::GetLocation()
{
    if(location == nullptr) {
        if(map.find("location") == map.end()) {
            map.emplace("location", (void *) new Location);
        }
        return (Location *) map["location"];
    }
    return location;
}

std::string * InlineQuery::GetQuery()
{
    if(query == nullptr) {
        if(map.find("query") == map.end()) {
            map.emplace("query", (void *) new std::string);
        }
        return (std::string *) map["query"];
    }
    return query;
}

std::string * InlineQuery::GetOffset()
{
    if(offset == nullptr) {
        if(map.find("offset") == map.end()) {
            map.emplace("offset", (void *) new std::string);
        }
        return (std::string *) map["offset"];
    }
    return offset;
}

std::string & InlineQuery::GetIdValue() const
{
    return *id;
}

User & InlineQuery::GetFromValue() const
{
    return *from;
}

Location & InlineQuery::GetLocationValue() const
{
    return *location;
}

std::string & InlineQuery::GetQueryValue() const
{
    return *query;
}

std::string & InlineQuery::GetOffsetValue() const
{
    return *offset;
}

void InlineQuery::SetId(const std::string &id)
{
    if(this->id != nullptr) {
        delete this->id;
    }
    this->id = new std::string(id);
}

void InlineQuery::SetFrom(const User &from)
{
    if(this->from != nullptr) {
        delete this->from;
    }
    this->from = new User(from);
}

void InlineQuery::SetLocation(const Location &location)
{
    if(this->location != nullptr) {
        delete this->location;
    }
    this->location = new Location(location);
}

void InlineQuery::SetQuery(const std::string &query)
{
    if(this->query != nullptr) {
        delete this->query;
    }
    this->query = new std::string(query);
}

void InlineQuery::SetOffset(const std::string &offset)
{
    if(this->offset != nullptr) {
        delete this->offset;
    }
    this->offset = new std::string(offset);
}

ChosenInlineResult::ChosenInlineResult()
{
    resultId = nullptr;
    from = nullptr;
    location = nullptr;
    inlineMessageId = nullptr;
    query = nullptr;
}

ChosenInlineResult::~ChosenInlineResult()
{
    delete resultId; resultId = nullptr;
    if(map.find("resultId") != map.end()) {
        delete (std::string *) map["resultId"];
    }
    delete from; from = nullptr;
    if(map.find("from") != map.end()) {
        delete (User *) map["from"];
    }
    delete location; location = nullptr;
    if(map.find("location") != map.end()) {
        delete (Location *) map["location"];
    }
    delete inlineMessageId; inlineMessageId = nullptr;
    if(map.find("inlineMessageId") != map.end()) {
        delete (std::string *) map["inlineMessageId"];
    }
    delete query; query = nullptr;
    if(map.find("query") != map.end()) {
        delete (std::string *) map["query"];
    }
}

ChosenInlineResult::ChosenInlineResult(const ChosenInlineResult &src)
{
    copy(*this, src);
}

ChosenInlineResult & ChosenInlineResult::operator=(const ChosenInlineResult &src)
{
    return copy(*this, src);
}

ChosenInlineResult::ChosenInlineResult(ChosenInlineResult &&src) : ChosenInlineResult()
{
    move(*this, src);
}

ChosenInlineResult & ChosenInlineResult::operator=(ChosenInlineResult &&src)
{
    return move(*this, src);
}

ChosenInlineResult::ChosenInlineResult(const std::string &resultId, const User &from, const std::string &query) : ChosenInlineResult()
{
    this->resultId = new std::string(resultId);
    this->from = new User(from);
    this->query = new std::string(query);
}

ChosenInlineResult::ChosenInlineResult(const std::string &resultId, const User &from, const Location &location, const std::string &inlineMessageId, const std::string &query) : ChosenInlineResult(resultId, from, query)
{
    this->resultId = new std::string(resultId);
    this->from = new User(from);
    this->location = new Location(location);
    this->inlineMessageId = new std::string(inlineMessageId);
    this->query = new std::string(query);
}

std::string * ChosenInlineResult::GetResultId()
{
    if(resultId == nullptr) {
        if(map.find("resultId") == map.end()) {
            map.emplace("resultId", (void *) new std::string);
        }
        return (std::string *) map["resultId"];
    }
    return resultId;
}

User * ChosenInlineResult::GetFrom()
{
    if(from == nullptr) {
        if(map.find("from") == map.end()) {
            map.emplace("from", (void *) new User);
        }
        return (User *) map["from"];
    }
    return from;
}

Location * ChosenInlineResult::GetLocation()
{
    if(location == nullptr) {
        if(map.find("location") == map.end()) {
            map.emplace("location", (void *) new Location);
        }
        return (Location *) map["location"];
    }
    return location;
}

std::string * ChosenInlineResult::GetInlineMessageId()
{
    if(inlineMessageId == nullptr) {
        if(map.find("inlineMessageId") == map.end()) {
            map.emplace("inlineMessageId", (void *) new std::string);
        }
        return (std::string *) map["inlineMessageId"];
    }
    return inlineMessageId;
}

std::string * ChosenInlineResult::GetQuery()
{
    if(query == nullptr) {
        if(map.find("query") == map.end()) {
            map.emplace("query", (void *) new std::string);
        }
        return (std::string *) map["query"];
    }
    return query;
}

std::string & ChosenInlineResult::GetResultIdValue() const
{
    return *resultId;
}

User & ChosenInlineResult::GetFromValue() const
{
    return *from;
}

Location & ChosenInlineResult::GetLocationValue() const
{
    return *location;
}

std::string & ChosenInlineResult::GetInlineMessageIdValue() const
{
    return *inlineMessageId;
}

std::string & ChosenInlineResult::GetQueryValue() const
{
    return *query;
}

void ChosenInlineResult::SetResultId(const std::string &resultId)
{
    if(this->resultId != nullptr) {
        delete this->resultId;
    }
    this->resultId = new std::string(resultId);
}

void ChosenInlineResult::SetFrom(const User &from)
{
    if(this->from != nullptr) {
        delete this->from;
    }
    this->from = new User(from);
}

void ChosenInlineResult::SetLocation(const Location &location)
{
    if(this->location != nullptr) {
        delete this->location;
    }
    this->location = new Location(location);
}

void ChosenInlineResult::SetInlineMessageId(const std::string &inlineMessageId)
{
    if(this->inlineMessageId != nullptr) {
        delete this->inlineMessageId;
    }
    this->inlineMessageId = new std::string(inlineMessageId);
}

void ChosenInlineResult::SetQuery(const std::string &query)
{
    if(this->query != nullptr) {
        delete this->query;
    }
    this->query = new std::string(query);
}

