cmake_minimum_required(VERSION 3.6)
project (telegrambot)
 
set(JSON_SERIALIZER_NAME telegram-jsonserializer)
set(JSON_FILE ${PROJECT_SOURCE_DIR}/DataStructureDefinitions.json)
set(GENERATED_DIRECTORY ${PROJECT_SOURCE_DIR}/generated)
set(GENERATED_HEADER ${PROJECT_SOURCE_DIR}/generated.h)
set(GENERATED_NAMESPACE "telegram::structures")
add_subdirectory(cpp-jsonserializer)

add_subdirectory(cpp-curlsession)

set(SOURCES
${PROJECT_SOURCE_DIR}/src/params/SendParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendFileParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendMessageParams.cpp
${PROJECT_SOURCE_DIR}/src/params/ForwardMessageParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendPhotoParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendAudioParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendDocumentParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendVideoParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendVoiceParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendLocationParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendVenueParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendContactParams.cpp
${PROJECT_SOURCE_DIR}/src/params/SendChatActionParams.cpp
${PROJECT_SOURCE_DIR}/src/params/GetUserProfilePhotosParams.cpp
${PROJECT_SOURCE_DIR}/src/params/GetFileParams.cpp
${PROJECT_SOURCE_DIR}/src/params/KickChatMemberParams.cpp
${PROJECT_SOURCE_DIR}/src/params/LeaveChatParams.cpp
${PROJECT_SOURCE_DIR}/src/params/UnbanChatMemberParams.cpp
${PROJECT_SOURCE_DIR}/src/params/GetChatParams.cpp
${PROJECT_SOURCE_DIR}/src/params/GetChatAdministratorsParams.cpp
${PROJECT_SOURCE_DIR}/src/params/GetChatMembersCountParams.cpp
${PROJECT_SOURCE_DIR}/src/params/GetChatMemberParams.cpp
${PROJECT_SOURCE_DIR}/src/params/AnswerCallbackQueryParams.cpp
${PROJECT_SOURCE_DIR}/src/Command.cpp
${PROJECT_SOURCE_DIR}/src/CommandSet.cpp
${PROJECT_SOURCE_DIR}/src/Logger.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBot.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBotMethods.cpp
${PROJECT_SOURCE_DIR}/src/UpdateQueue.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/telegram ${PROJECT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC "curlsession" ${JSON_SERIALIZER_NAME} "pthread")
target_include_directories (${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
