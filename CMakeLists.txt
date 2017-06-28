cmake_minimum_required(VERSION 3.6)
project (telegrambot)
 
function(add_external_func name repo)
    set(EXTERNAL_DOWNLOAD_PATH ${name}-download)
    set(EXTERNAL_NAME ${name})
    set(EXTERNAL_GIT_REPOSITORY ${repo})
    configure_file(${PROJECT_SOURCE_DIR}/cmake/CMakeLists.txt.in ${EXTERNAL_DOWNLOAD_PATH}/CMakeLists.txt)
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
                    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/${EXTERNAL_DOWNLOAD_PATH}")
    execute_process(COMMAND "${CMAKE_COMMAND}" --build .
                    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/${EXTERNAL_DOWNLOAD_PATH}")
endfunction(add_external_func)

macro(add_external name repo)
    add_external_func(${name} ${repo})
    add_subdirectory(${PROJECT_BINARY_DIR}/${name} ${PROJECT_BINARY_DIR}/${name}/build)
endmacro(add_external)

set(JSON_CONFIGURATION_FILES ${PROJECT_SOURCE_DIR}/request.json ${PROJECT_SOURCE_DIR}/telegram.json)
add_external("jsonserializer" "https://github.com/skaupper/cpp-jsonserializer.git")
add_external("curlsession" "https://github.com/skaupper/cpp-curlsession.git")

set(SOURCES
${PROJECT_SOURCE_DIR}/src/Command.cpp
${PROJECT_SOURCE_DIR}/src/CommandSet.cpp
${PROJECT_SOURCE_DIR}/src/Logger.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBot.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBotUtilities.cpp
${PROJECT_SOURCE_DIR}/src/TelegramBotMethods.cpp
${PROJECT_SOURCE_DIR}/src/UpdateQueue.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC "curlsession" "pthread" "jsonserializer")
target_include_directories (${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories (${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/telegram)
