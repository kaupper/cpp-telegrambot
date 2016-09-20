#include "Logger.h"

using namespace telegram;

Logger Logger::error;
Logger Logger::warn;
Logger Logger::info;
Logger Logger::debug;

Logger::StaticConstructor Logger::_;
std::mutex Logger::loggerMutex;
int Logger::logLevel = (int) LogLevel::NOTHING;
bool Logger::useColors;


Logger::StaticConstructor::StaticConstructor()
{
    Logger::error.SetInternalLevel(LogLevel::ERROR);
    Logger::warn.SetInternalLevel(LogLevel::WARN);
    Logger::info.SetInternalLevel(LogLevel::INFO);
    Logger::debug.SetInternalLevel(LogLevel::DEBUG);
    Logger::logLevel = (int) LogLevel::NOTHING;
    Logger::useColors = true;
}
    

void Logger::SetInternalLevel(LogLevel level)
{
    this->level = level;
    std::string prefix;
    switch(level) {
        case LogLevel::ERROR:
            prefix = "ERROR";
            break;
        
        case LogLevel::WARN:
            prefix = "WARN";
            break;
            
        case LogLevel::INFO:
            prefix = "INFO";
            break;
        
        case LogLevel::DEBUG:
            prefix = "DEBUG";
            break;
        
        case LogLevel::NOTHING:
        default:
            prefix = "NOTHING";
            break;
    }
    buffer.SetPrefix(prefix);
}
