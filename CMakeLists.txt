cmake_minimum_required(VERSION 3.6)
project (telegrambot)
 
function(add_external name repo)
    set(DOWNLOAD_PATH ${name}-download)
    set(EXTERNAL_NAME ${name})
    set(EXTERNAL_GIT_REPOSITORY ${repo})
    configure_file(cmake/CMakeLists.txt.in ${DOWNLOAD_PATH}/CMakeLists.txt)
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
                    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/${DOWNLOAD_PATH}")
    execute_process(COMMAND "${CMAKE_COMMAND}" --build .
                    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/${DOWNLOAD_PATH}")
endfunction(add_external)

add_external("jsonserializer" "http://github.com/skaupper/cpp-jsonserializer.git")
add_external("curlsession" "http://github.com/skaupper/cpp-curlsession.git")

set(JSON_CONFIGURATION_FILES request.json telegram.json)
set(JSON_OUTPUT_DIR generated/)
add_subdirectory(${PROJECT_BINARY_DIR}/jsonserializer ${PROJECT_BINARY_DIR}/jsonserializer/build)
add_subdirectory(${PROJECT_BINARY_DIR}/curlsession ${PROJECT_BINARY_DIR}/curlsession/build)

set(SOURCES
${JSON_SOURCES}
${PROJECT_SOURCE_DIR}/src/Command.cpp
${PROJECT_SOURCE_DIR}/src/CommandSet.cpp
${PROJECT_SOURCE_DIR}/src/Logger.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBot.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBotUtilities.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBotMethods.cpp
${PROJECT_SOURCE_DIR}/src/UpdateQueue.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/telegram ${PROJECT_SOURCE_DIR} ${JSON_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC "curlsession" "pthread")
target_include_directories (${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
