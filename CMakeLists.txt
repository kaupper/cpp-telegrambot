cmake_minimum_required(VERSION 3.6)
project (telegrambot)
 
set(JSON_SERIALIZER_NAME telegram-jsonserializer)
set(JSON_FILE ${PROJECT_SOURCE_DIR}/DataStructureDefinitions.json)
add_subdirectory(cpp-jsonserializer)

add_subdirectory(cpp-curlsession)

set(SOURCES
${STRUCTURE_SOURCES}
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
