#ifndef JSON_SERIALIZER_DATA_STRUCTURES_TELEGRAM_STRUCTURES_H_
#define JSON_SERIALIZER_DATA_STRUCTURES_TELEGRAM_STRUCTURES_H_

#include <map>
#include <string>
#include <vector>
#include "jsonserializer/StructConverter.h"

namespace telegram::structures
{
    struct Update;
    struct User;
    struct Chat;
    struct Message;
    struct MessageEntity;
    struct PhotoSize;
    struct Audio;
    struct Document;
    struct Sticker;
    struct Video;
    struct Voice;
    struct Contact;
    struct Location;
    struct Venue;
    struct UserProfilePhotos;
    struct File;
    struct ReplyKeyboardMarkup;
    struct KeyboardButton;
    struct ReplyKeyboardHide;
    struct InlineKeyboardMarkup;
    struct InlineKeyboardButton;
    struct CallbackQuery;
    struct ForceReply;
    struct ChatMember;
    struct InlineQuery;
    struct ChosenInlineResult;

    struct Update
    {
        Update();
        virtual ~Update();
        Update(const Update &);
        Update & operator=(const Update &);
        Update(Update &&);
        Update & operator=(Update &&);
        Update(const int &);
        Update(const int &, const Message &, const Message &, const InlineQuery &, const ChosenInlineResult &, const CallbackQuery &);
    
    static const bool __transient = false;
    
        int *updateId;
        Message *message;
        Message *editedMessage;
        InlineQuery *inlineQuery;
        ChosenInlineResult *chosenInlineResult;
        CallbackQuery *callbackQuery;
    
        std::map<std::string, void*> map;

        int * GetUpdateId();
        int & GetUpdateIdValue() const;
        void SetUpdateId(const int &updateId);
        Message * GetMessage();
        Message & GetMessageValue() const;
        void SetMessage(const Message &message);
        Message * GetEditedMessage();
        Message & GetEditedMessageValue() const;
        void SetEditedMessage(const Message &editedMessage);
        InlineQuery * GetInlineQuery();
        InlineQuery & GetInlineQueryValue() const;
        void SetInlineQuery(const InlineQuery &inlineQuery);
        ChosenInlineResult * GetChosenInlineResult();
        ChosenInlineResult & GetChosenInlineResultValue() const;
        void SetChosenInlineResult(const ChosenInlineResult &chosenInlineResult);
        CallbackQuery * GetCallbackQuery();
        CallbackQuery & GetCallbackQueryValue() const;
        void SetCallbackQuery(const CallbackQuery &callbackQuery);
    };

    struct User
    {
        User();
        virtual ~User();
        User(const User &);
        User & operator=(const User &);
        User(User &&);
        User & operator=(User &&);
        User(const int &, const std::string &);
        User(const int &, const std::string &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        int *id;
        std::string *firstName;
        std::string *lastName;
        std::string *userName;
    
        std::map<std::string, void*> map;

        int * GetId();
        int & GetIdValue() const;
        void SetId(const int &id);
        std::string * GetFirstName();
        std::string & GetFirstNameValue() const;
        void SetFirstName(const std::string &firstName);
        std::string * GetLastName();
        std::string & GetLastNameValue() const;
        void SetLastName(const std::string &lastName);
        std::string * GetUserName();
        std::string & GetUserNameValue() const;
        void SetUserName(const std::string &userName);
    };

    struct Chat
    {
        Chat();
        virtual ~Chat();
        Chat(const Chat &);
        Chat & operator=(const Chat &);
        Chat(Chat &&);
        Chat & operator=(Chat &&);
        Chat(const long &, const std::string &);
        Chat(const long &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        long *id;
        std::string *type;
        std::string *title;
        std::string *userName;
        std::string *firstName;
        std::string *lastName;
    
        std::map<std::string, void*> map;

        long * GetId();
        long & GetIdValue() const;
        void SetId(const long &id);
        std::string * GetType();
        std::string & GetTypeValue() const;
        void SetType(const std::string &type);
        std::string * GetTitle();
        std::string & GetTitleValue() const;
        void SetTitle(const std::string &title);
        std::string * GetUserName();
        std::string & GetUserNameValue() const;
        void SetUserName(const std::string &userName);
        std::string * GetFirstName();
        std::string & GetFirstNameValue() const;
        void SetFirstName(const std::string &firstName);
        std::string * GetLastName();
        std::string & GetLastNameValue() const;
        void SetLastName(const std::string &lastName);
    };

    struct Message
    {
        Message();
        virtual ~Message();
        Message(const Message &);
        Message & operator=(const Message &);
        Message(Message &&);
        Message & operator=(Message &&);
        Message(const int &, const int &, const Chat &);
        Message(const int &, const User &, const int &, const Chat &, const User &, const Chat &, const int &, const Message &, const int &, const std::string &, const std::vector<MessageEntity> &, const Audio &, const Document &, const std::vector<PhotoSize> &, const Sticker &, const Video &, const Voice &, const std::string &, const Contact &, const Location &, const Venue &, const User &, const User &, const std::string &, const std::vector<PhotoSize> &, const bool &, const bool &, const bool &, const bool &, const long &, const long &, const Message &);
    
    static const bool __transient = false;
    
        int *messageId;
        User *from;
        int *date;
        Chat *chat;
        User *forwardFrom;
        Chat *forwardFromChat;
        int *forwardDate;
        Message *replyToMessage;
        int *editDate;
        std::string *text;
        std::vector<MessageEntity> *entities;
        Audio *audio;
        Document *document;
        std::vector<PhotoSize> *photo;
        Sticker *sticker;
        Video *video;
        Voice *voice;
        std::string *caption;
        Contact *contact;
        Location *location;
        Venue *venue;
        User *newChatMember;
        User *leftChatMember;
        std::string *newChatTitle;
        std::vector<PhotoSize> *newChatPhoto;
        bool *deleteChatPhoto;
        bool *groupChatCreated;
        bool *superGroupChatCreated;
        bool *channelChatCreated;
        long *migrateToChatId;
        long *migrateFromChatId;
        Message *pinnedMessage;
    
        std::map<std::string, void*> map;

        int * GetMessageId();
        int & GetMessageIdValue() const;
        void SetMessageId(const int &messageId);
        User * GetFrom();
        User & GetFromValue() const;
        void SetFrom(const User &from);
        int * GetDate();
        int & GetDateValue() const;
        void SetDate(const int &date);
        Chat * GetChat();
        Chat & GetChatValue() const;
        void SetChat(const Chat &chat);
        User * GetForwardFrom();
        User & GetForwardFromValue() const;
        void SetForwardFrom(const User &forwardFrom);
        Chat * GetForwardFromChat();
        Chat & GetForwardFromChatValue() const;
        void SetForwardFromChat(const Chat &forwardFromChat);
        int * GetForwardDate();
        int & GetForwardDateValue() const;
        void SetForwardDate(const int &forwardDate);
        Message * GetReplyToMessage();
        Message & GetReplyToMessageValue() const;
        void SetReplyToMessage(const Message &replyToMessage);
        int * GetEditDate();
        int & GetEditDateValue() const;
        void SetEditDate(const int &editDate);
        std::string * GetText();
        std::string & GetTextValue() const;
        void SetText(const std::string &text);
        std::vector<MessageEntity> * GetEntities();
        std::vector<MessageEntity> & GetEntitiesValue() const;
        void SetEntities(const std::vector<MessageEntity> &entities);
        Audio * GetAudio();
        Audio & GetAudioValue() const;
        void SetAudio(const Audio &audio);
        Document * GetDocument();
        Document & GetDocumentValue() const;
        void SetDocument(const Document &document);
        std::vector<PhotoSize> * GetPhoto();
        std::vector<PhotoSize> & GetPhotoValue() const;
        void SetPhoto(const std::vector<PhotoSize> &photo);
        Sticker * GetSticker();
        Sticker & GetStickerValue() const;
        void SetSticker(const Sticker &sticker);
        Video * GetVideo();
        Video & GetVideoValue() const;
        void SetVideo(const Video &video);
        Voice * GetVoice();
        Voice & GetVoiceValue() const;
        void SetVoice(const Voice &voice);
        std::string * GetCaption();
        std::string & GetCaptionValue() const;
        void SetCaption(const std::string &caption);
        Contact * GetContact();
        Contact & GetContactValue() const;
        void SetContact(const Contact &contact);
        Location * GetLocation();
        Location & GetLocationValue() const;
        void SetLocation(const Location &location);
        Venue * GetVenue();
        Venue & GetVenueValue() const;
        void SetVenue(const Venue &venue);
        User * GetNewChatMember();
        User & GetNewChatMemberValue() const;
        void SetNewChatMember(const User &newChatMember);
        User * GetLeftChatMember();
        User & GetLeftChatMemberValue() const;
        void SetLeftChatMember(const User &leftChatMember);
        std::string * GetNewChatTitle();
        std::string & GetNewChatTitleValue() const;
        void SetNewChatTitle(const std::string &newChatTitle);
        std::vector<PhotoSize> * GetNewChatPhoto();
        std::vector<PhotoSize> & GetNewChatPhotoValue() const;
        void SetNewChatPhoto(const std::vector<PhotoSize> &newChatPhoto);
        bool * GetDeleteChatPhoto();
        bool & GetDeleteChatPhotoValue() const;
        void SetDeleteChatPhoto(const bool &deleteChatPhoto);
        bool * GetGroupChatCreated();
        bool & GetGroupChatCreatedValue() const;
        void SetGroupChatCreated(const bool &groupChatCreated);
        bool * GetSuperGroupChatCreated();
        bool & GetSuperGroupChatCreatedValue() const;
        void SetSuperGroupChatCreated(const bool &superGroupChatCreated);
        bool * GetChannelChatCreated();
        bool & GetChannelChatCreatedValue() const;
        void SetChannelChatCreated(const bool &channelChatCreated);
        long * GetMigrateToChatId();
        long & GetMigrateToChatIdValue() const;
        void SetMigrateToChatId(const long &migrateToChatId);
        long * GetMigrateFromChatId();
        long & GetMigrateFromChatIdValue() const;
        void SetMigrateFromChatId(const long &migrateFromChatId);
        Message * GetPinnedMessage();
        Message & GetPinnedMessageValue() const;
        void SetPinnedMessage(const Message &pinnedMessage);
    };

    struct MessageEntity
    {
        MessageEntity();
        virtual ~MessageEntity();
        MessageEntity(const MessageEntity &);
        MessageEntity & operator=(const MessageEntity &);
        MessageEntity(MessageEntity &&);
        MessageEntity & operator=(MessageEntity &&);
        MessageEntity(const std::string &, const int &, const int &);
        MessageEntity(const std::string &, const int &, const int &, const std::string &, const User &);
    
    static const bool __transient = false;
    
        std::string *type;
        int *offset;
        int *length;
        std::string *url;
        User *user;
    
        std::map<std::string, void*> map;

        std::string * GetType();
        std::string & GetTypeValue() const;
        void SetType(const std::string &type);
        int * GetOffset();
        int & GetOffsetValue() const;
        void SetOffset(const int &offset);
        int * GetLength();
        int & GetLengthValue() const;
        void SetLength(const int &length);
        std::string * GetUrl();
        std::string & GetUrlValue() const;
        void SetUrl(const std::string &url);
        User * GetUser();
        User & GetUserValue() const;
        void SetUser(const User &user);
    };

    struct PhotoSize
    {
        PhotoSize();
        virtual ~PhotoSize();
        PhotoSize(const PhotoSize &);
        PhotoSize & operator=(const PhotoSize &);
        PhotoSize(PhotoSize &&);
        PhotoSize & operator=(PhotoSize &&);
        PhotoSize(const std::string &, const int &, const int &);
        PhotoSize(const std::string &, const int &, const int &, const int &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        int *width;
        int *height;
        int *fileSize;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        int * GetWidth();
        int & GetWidthValue() const;
        void SetWidth(const int &width);
        int * GetHeight();
        int & GetHeightValue() const;
        void SetHeight(const int &height);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
    };

    struct Audio
    {
        Audio();
        virtual ~Audio();
        Audio(const Audio &);
        Audio & operator=(const Audio &);
        Audio(Audio &&);
        Audio & operator=(Audio &&);
        Audio(const std::string &, const int &);
        Audio(const std::string &, const int &, const std::string &, const std::string &, const std::string &, const int &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        int *duration;
        std::string *performer;
        std::string *title;
        std::string *mimeType;
        int *fileSize;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        int * GetDuration();
        int & GetDurationValue() const;
        void SetDuration(const int &duration);
        std::string * GetPerformer();
        std::string & GetPerformerValue() const;
        void SetPerformer(const std::string &performer);
        std::string * GetTitle();
        std::string & GetTitleValue() const;
        void SetTitle(const std::string &title);
        std::string * GetMimeType();
        std::string & GetMimeTypeValue() const;
        void SetMimeType(const std::string &mimeType);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
    };

    struct Document
    {
        Document();
        virtual ~Document();
        Document(const Document &);
        Document & operator=(const Document &);
        Document(Document &&);
        Document & operator=(Document &&);
        Document(const std::string &);
        Document(const std::string &, const PhotoSize &, const std::string &, const std::string &, const int &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        PhotoSize *thumb;
        std::string *fileName;
        std::string *mimeType;
        int *fileSize;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        PhotoSize * GetThumb();
        PhotoSize & GetThumbValue() const;
        void SetThumb(const PhotoSize &thumb);
        std::string * GetFileName();
        std::string & GetFileNameValue() const;
        void SetFileName(const std::string &fileName);
        std::string * GetMimeType();
        std::string & GetMimeTypeValue() const;
        void SetMimeType(const std::string &mimeType);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
    };

    struct Sticker
    {
        Sticker();
        virtual ~Sticker();
        Sticker(const Sticker &);
        Sticker & operator=(const Sticker &);
        Sticker(Sticker &&);
        Sticker & operator=(Sticker &&);
        Sticker(const std::string &, const int &, const int &);
        Sticker(const std::string &, const int &, const int &, const PhotoSize &, const std::string &, const int &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        int *width;
        int *height;
        PhotoSize *thumb;
        std::string *emoji;
        int *fileSize;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        int * GetWidth();
        int & GetWidthValue() const;
        void SetWidth(const int &width);
        int * GetHeight();
        int & GetHeightValue() const;
        void SetHeight(const int &height);
        PhotoSize * GetThumb();
        PhotoSize & GetThumbValue() const;
        void SetThumb(const PhotoSize &thumb);
        std::string * GetEmoji();
        std::string & GetEmojiValue() const;
        void SetEmoji(const std::string &emoji);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
    };

    struct Video
    {
        Video();
        virtual ~Video();
        Video(const Video &);
        Video & operator=(const Video &);
        Video(Video &&);
        Video & operator=(Video &&);
        Video(const std::string &, const int &, const int &, const int &);
        Video(const std::string &, const int &, const int &, const int &, const PhotoSize &, const std::string &, const int &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        int *width;
        int *height;
        int *duration;
        PhotoSize *thumb;
        std::string *mimeType;
        int *fileSize;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        int * GetWidth();
        int & GetWidthValue() const;
        void SetWidth(const int &width);
        int * GetHeight();
        int & GetHeightValue() const;
        void SetHeight(const int &height);
        int * GetDuration();
        int & GetDurationValue() const;
        void SetDuration(const int &duration);
        PhotoSize * GetThumb();
        PhotoSize & GetThumbValue() const;
        void SetThumb(const PhotoSize &thumb);
        std::string * GetMimeType();
        std::string & GetMimeTypeValue() const;
        void SetMimeType(const std::string &mimeType);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
    };

    struct Voice
    {
        Voice();
        virtual ~Voice();
        Voice(const Voice &);
        Voice & operator=(const Voice &);
        Voice(Voice &&);
        Voice & operator=(Voice &&);
        Voice(const std::string &, const int &);
        Voice(const std::string &, const int &, const std::string &, const int &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        int *duration;
        std::string *mimeType;
        int *fileSize;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        int * GetDuration();
        int & GetDurationValue() const;
        void SetDuration(const int &duration);
        std::string * GetMimeType();
        std::string & GetMimeTypeValue() const;
        void SetMimeType(const std::string &mimeType);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
    };

    struct Contact
    {
        Contact();
        virtual ~Contact();
        Contact(const Contact &);
        Contact & operator=(const Contact &);
        Contact(Contact &&);
        Contact & operator=(Contact &&);
        Contact(const std::string &, const std::string &);
        Contact(const std::string &, const std::string &, const std::string &, const int &);
    
    static const bool __transient = false;
    
        std::string *phoneNumber;
        std::string *firstName;
        std::string *lastName;
        int *userId;
    
        std::map<std::string, void*> map;

        std::string * GetPhoneNumber();
        std::string & GetPhoneNumberValue() const;
        void SetPhoneNumber(const std::string &phoneNumber);
        std::string * GetFirstName();
        std::string & GetFirstNameValue() const;
        void SetFirstName(const std::string &firstName);
        std::string * GetLastName();
        std::string & GetLastNameValue() const;
        void SetLastName(const std::string &lastName);
        int * GetUserId();
        int & GetUserIdValue() const;
        void SetUserId(const int &userId);
    };

    struct Location
    {
        Location();
        virtual ~Location();
        Location(const Location &);
        Location & operator=(const Location &);
        Location(Location &&);
        Location & operator=(Location &&);
        Location(const float &, const float &);
    
    static const bool __transient = false;
    
        float *longitude;
        float *latitude;
    
        std::map<std::string, void*> map;

        float * GetLongitude();
        float & GetLongitudeValue() const;
        void SetLongitude(const float &longitude);
        float * GetLatitude();
        float & GetLatitudeValue() const;
        void SetLatitude(const float &latitude);
    };

    struct Venue
    {
        Venue();
        virtual ~Venue();
        Venue(const Venue &);
        Venue & operator=(const Venue &);
        Venue(Venue &&);
        Venue & operator=(Venue &&);
        Venue(const Location &, const std::string &, const std::string &);
        Venue(const Location &, const std::string &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        Location *location;
        std::string *title;
        std::string *address;
        std::string *foursquareId;
    
        std::map<std::string, void*> map;

        Location * GetLocation();
        Location & GetLocationValue() const;
        void SetLocation(const Location &location);
        std::string * GetTitle();
        std::string & GetTitleValue() const;
        void SetTitle(const std::string &title);
        std::string * GetAddress();
        std::string & GetAddressValue() const;
        void SetAddress(const std::string &address);
        std::string * GetFoursquareId();
        std::string & GetFoursquareIdValue() const;
        void SetFoursquareId(const std::string &foursquareId);
    };

    struct UserProfilePhotos
    {
        UserProfilePhotos();
        virtual ~UserProfilePhotos();
        UserProfilePhotos(const UserProfilePhotos &);
        UserProfilePhotos & operator=(const UserProfilePhotos &);
        UserProfilePhotos(UserProfilePhotos &&);
        UserProfilePhotos & operator=(UserProfilePhotos &&);
        UserProfilePhotos(const int &, const std::vector<std::vector<PhotoSize>> &);
    
    static const bool __transient = false;
    
        int *totalCount;
        std::vector<std::vector<PhotoSize>> *photos;
    
        std::map<std::string, void*> map;

        int * GetTotalCount();
        int & GetTotalCountValue() const;
        void SetTotalCount(const int &totalCount);
        std::vector<std::vector<PhotoSize>> * GetPhotos();
        std::vector<std::vector<PhotoSize>> & GetPhotosValue() const;
        void SetPhotos(const std::vector<std::vector<PhotoSize>> &photos);
    };

    struct File
    {
        File();
        virtual ~File();
        File(const File &);
        File & operator=(const File &);
        File(File &&);
        File & operator=(File &&);
        File(const std::string &);
        File(const std::string &, const int &, const std::string &);
    
    static const bool __transient = false;
    
        std::string *fileId;
        int *fileSize;
        std::string *filePath;
    
        std::map<std::string, void*> map;

        std::string * GetFileId();
        std::string & GetFileIdValue() const;
        void SetFileId(const std::string &fileId);
        int * GetFileSize();
        int & GetFileSizeValue() const;
        void SetFileSize(const int &fileSize);
        std::string * GetFilePath();
        std::string & GetFilePathValue() const;
        void SetFilePath(const std::string &filePath);
    };

    struct ReplyKeyboardMarkup
    {
        ReplyKeyboardMarkup();
        virtual ~ReplyKeyboardMarkup();
        ReplyKeyboardMarkup(const ReplyKeyboardMarkup &);
        ReplyKeyboardMarkup & operator=(const ReplyKeyboardMarkup &);
        ReplyKeyboardMarkup(ReplyKeyboardMarkup &&);
        ReplyKeyboardMarkup & operator=(ReplyKeyboardMarkup &&);
        ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton>> &);
        ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton>> &, const bool &, const bool &, const bool &);
    
    static const bool __transient = false;
    
        std::vector<std::vector<KeyboardButton>> *keyboard;
        bool *resizeKeyboard;
        bool *oneTimeKeyboard;
        bool *selective;
    
        std::map<std::string, void*> map;

        std::vector<std::vector<KeyboardButton>> * GetKeyboard();
        std::vector<std::vector<KeyboardButton>> & GetKeyboardValue() const;
        void SetKeyboard(const std::vector<std::vector<KeyboardButton>> &keyboard);
        bool * GetResizeKeyboard();
        bool & GetResizeKeyboardValue() const;
        void SetResizeKeyboard(const bool &resizeKeyboard);
        bool * GetOneTimeKeyboard();
        bool & GetOneTimeKeyboardValue() const;
        void SetOneTimeKeyboard(const bool &oneTimeKeyboard);
        bool * GetSelective();
        bool & GetSelectiveValue() const;
        void SetSelective(const bool &selective);
    };

    struct KeyboardButton
    {
        KeyboardButton();
        virtual ~KeyboardButton();
        KeyboardButton(const KeyboardButton &);
        KeyboardButton & operator=(const KeyboardButton &);
        KeyboardButton(KeyboardButton &&);
        KeyboardButton & operator=(KeyboardButton &&);
        KeyboardButton(const std::string &);
        KeyboardButton(const std::string &, const bool &, const bool &);
    
    static const bool __transient = false;
    
        std::string *text;
        bool *requestContact;
        bool *requestLocation;
    
        std::map<std::string, void*> map;

        std::string * GetText();
        std::string & GetTextValue() const;
        void SetText(const std::string &text);
        bool * GetRequestContact();
        bool & GetRequestContactValue() const;
        void SetRequestContact(const bool &requestContact);
        bool * GetRequestLocation();
        bool & GetRequestLocationValue() const;
        void SetRequestLocation(const bool &requestLocation);
    };

    struct ReplyKeyboardHide
    {
        ReplyKeyboardHide();
        virtual ~ReplyKeyboardHide();
        ReplyKeyboardHide(const ReplyKeyboardHide &);
        ReplyKeyboardHide & operator=(const ReplyKeyboardHide &);
        ReplyKeyboardHide(ReplyKeyboardHide &&);
        ReplyKeyboardHide & operator=(ReplyKeyboardHide &&);
        ReplyKeyboardHide(const bool &);
        ReplyKeyboardHide(const bool &, const bool &);
    
    static const bool __transient = false;
    
        bool *hideKeyboard;
        bool *selective;
    
        std::map<std::string, void*> map;

        bool * GetHideKeyboard();
        bool & GetHideKeyboardValue() const;
        void SetHideKeyboard(const bool &hideKeyboard);
        bool * GetSelective();
        bool & GetSelectiveValue() const;
        void SetSelective(const bool &selective);
    };

    struct InlineKeyboardMarkup
    {
        InlineKeyboardMarkup();
        virtual ~InlineKeyboardMarkup();
        InlineKeyboardMarkup(const InlineKeyboardMarkup &);
        InlineKeyboardMarkup & operator=(const InlineKeyboardMarkup &);
        InlineKeyboardMarkup(InlineKeyboardMarkup &&);
        InlineKeyboardMarkup & operator=(InlineKeyboardMarkup &&);
        InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton>> &);
    
    static const bool __transient = false;
    
        std::vector<std::vector<InlineKeyboardButton>> *inlineKeyboard;
    
        std::map<std::string, void*> map;

        std::vector<std::vector<InlineKeyboardButton>> * GetInlineKeyboard();
        std::vector<std::vector<InlineKeyboardButton>> & GetInlineKeyboardValue() const;
        void SetInlineKeyboard(const std::vector<std::vector<InlineKeyboardButton>> &inlineKeyboard);
    };

    struct InlineKeyboardButton
    {
        InlineKeyboardButton();
        virtual ~InlineKeyboardButton();
        InlineKeyboardButton(const InlineKeyboardButton &);
        InlineKeyboardButton & operator=(const InlineKeyboardButton &);
        InlineKeyboardButton(InlineKeyboardButton &&);
        InlineKeyboardButton & operator=(InlineKeyboardButton &&);
        InlineKeyboardButton(const std::string &);
        InlineKeyboardButton(const std::string &, const std::string &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        std::string *text;
        std::string *url;
        std::string *callbackData;
        std::string *switchInlineQuery;
    
        std::map<std::string, void*> map;

        std::string * GetText();
        std::string & GetTextValue() const;
        void SetText(const std::string &text);
        std::string * GetUrl();
        std::string & GetUrlValue() const;
        void SetUrl(const std::string &url);
        std::string * GetCallbackData();
        std::string & GetCallbackDataValue() const;
        void SetCallbackData(const std::string &callbackData);
        std::string * GetSwitchInlineQuery();
        std::string & GetSwitchInlineQueryValue() const;
        void SetSwitchInlineQuery(const std::string &switchInlineQuery);
    };

    struct CallbackQuery
    {
        CallbackQuery();
        virtual ~CallbackQuery();
        CallbackQuery(const CallbackQuery &);
        CallbackQuery & operator=(const CallbackQuery &);
        CallbackQuery(CallbackQuery &&);
        CallbackQuery & operator=(CallbackQuery &&);
        CallbackQuery(const std::string &, const User &, const std::string &);
        CallbackQuery(const std::string &, const User &, const Message &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        std::string *id;
        User *from;
        Message *message;
        std::string *inlineMessageId;
        std::string *data;
    
        std::map<std::string, void*> map;

        std::string * GetId();
        std::string & GetIdValue() const;
        void SetId(const std::string &id);
        User * GetFrom();
        User & GetFromValue() const;
        void SetFrom(const User &from);
        Message * GetMessage();
        Message & GetMessageValue() const;
        void SetMessage(const Message &message);
        std::string * GetInlineMessageId();
        std::string & GetInlineMessageIdValue() const;
        void SetInlineMessageId(const std::string &inlineMessageId);
        std::string * GetData();
        std::string & GetDataValue() const;
        void SetData(const std::string &data);
    };

    struct ForceReply
    {
        ForceReply();
        virtual ~ForceReply();
        ForceReply(const ForceReply &);
        ForceReply & operator=(const ForceReply &);
        ForceReply(ForceReply &&);
        ForceReply & operator=(ForceReply &&);
        ForceReply(const bool &);
        ForceReply(const bool &, const bool &);
    
    static const bool __transient = false;
    
        bool *forceReply;
        bool *selective;
    
        std::map<std::string, void*> map;

        bool * GetForceReply();
        bool & GetForceReplyValue() const;
        void SetForceReply(const bool &forceReply);
        bool * GetSelective();
        bool & GetSelectiveValue() const;
        void SetSelective(const bool &selective);
    };

    struct ChatMember
    {
        ChatMember();
        virtual ~ChatMember();
        ChatMember(const ChatMember &);
        ChatMember & operator=(const ChatMember &);
        ChatMember(ChatMember &&);
        ChatMember & operator=(ChatMember &&);
        ChatMember(const User &, const std::string &);
    
    static const bool __transient = false;
    
        User *user;
        std::string *status;
    
        std::map<std::string, void*> map;

        User * GetUser();
        User & GetUserValue() const;
        void SetUser(const User &user);
        std::string * GetStatus();
        std::string & GetStatusValue() const;
        void SetStatus(const std::string &status);
    };

    struct InlineQuery
    {
        InlineQuery();
        virtual ~InlineQuery();
        InlineQuery(const InlineQuery &);
        InlineQuery & operator=(const InlineQuery &);
        InlineQuery(InlineQuery &&);
        InlineQuery & operator=(InlineQuery &&);
        InlineQuery(const std::string &, const User &, const std::string &, const std::string &);
        InlineQuery(const std::string &, const User &, const Location &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        std::string *id;
        User *from;
        Location *location;
        std::string *query;
        std::string *offset;
    
        std::map<std::string, void*> map;

        std::string * GetId();
        std::string & GetIdValue() const;
        void SetId(const std::string &id);
        User * GetFrom();
        User & GetFromValue() const;
        void SetFrom(const User &from);
        Location * GetLocation();
        Location & GetLocationValue() const;
        void SetLocation(const Location &location);
        std::string * GetQuery();
        std::string & GetQueryValue() const;
        void SetQuery(const std::string &query);
        std::string * GetOffset();
        std::string & GetOffsetValue() const;
        void SetOffset(const std::string &offset);
    };

    struct ChosenInlineResult
    {
        ChosenInlineResult();
        virtual ~ChosenInlineResult();
        ChosenInlineResult(const ChosenInlineResult &);
        ChosenInlineResult & operator=(const ChosenInlineResult &);
        ChosenInlineResult(ChosenInlineResult &&);
        ChosenInlineResult & operator=(ChosenInlineResult &&);
        ChosenInlineResult(const std::string &, const User &, const std::string &);
        ChosenInlineResult(const std::string &, const User &, const Location &, const std::string &, const std::string &);
    
    static const bool __transient = false;
    
        std::string *resultId;
        User *from;
        Location *location;
        std::string *inlineMessageId;
        std::string *query;
    
        std::map<std::string, void*> map;

        std::string * GetResultId();
        std::string & GetResultIdValue() const;
        void SetResultId(const std::string &resultId);
        User * GetFrom();
        User & GetFromValue() const;
        void SetFrom(const User &from);
        Location * GetLocation();
        Location & GetLocationValue() const;
        void SetLocation(const Location &location);
        std::string * GetInlineMessageId();
        std::string & GetInlineMessageIdValue() const;
        void SetInlineMessageId(const std::string &inlineMessageId);
        std::string * GetQuery();
        std::string & GetQueryValue() const;
        void SetQuery(const std::string &query);
    };
}

#endif // JSON_SERIALIZER_DATA_STRUCTURES_TELEGRAM_STRUCTURES_H_
