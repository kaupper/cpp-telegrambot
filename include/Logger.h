#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

enum class LogLevel
{
    NOTHING = 0,
    ERROR   = 1,
    WARN    = 2,
    INFO    = 4,
    DEBUG   = 8
};

class Logger : public std::ostream
{
private:
    class LoggerStreamBuf: public std::stringbuf
    {
        std::ostream &output;
        std::string prefix;
        Logger *logger;
        
    public:
        LoggerStreamBuf() : output(std::cout), prefix(""), logger(nullptr) {}
        
        void SetParentLogger(Logger *logger) { this->logger = logger; }
        void SetPrefix(std::string newPrefix) { prefix = newPrefix; }
        
        virtual int sync ()
        {
            if(Logger::IsSet(logger->level)) {
                if(useColors) {
                    switch(logger->level) {
                        case LogLevel::ERROR:
                            output << RED;
                            break;
                        case LogLevel::WARN:
                            output << YEL;
                            break;
                        case LogLevel::INFO:
                            output << GRN;
                            break;
                        case LogLevel::DEBUG:
                            output << BLU;
                            break;
                        case LogLevel::NOTHING:
                        default:
                            break;
                    }
                }
                output << "[" << prefix << "] " << str();
                if(useColors) {
                    output << NRM;
                }
                output << std::flush;
                str("");
            }
            return 0;
        }
    };

    struct StaticConstructor
    {
        StaticConstructor();
    };
    static StaticConstructor _;
    
    static bool useColors;
    static std::mutex loggerMutex;
    static int logLevel;
    
    LogLevel level;
    LoggerStreamBuf buffer;
    
    
    void SetInternalLevel(LogLevel level);
    
    Logger() : Logger(LogLevel::NOTHING) { }
    Logger(LogLevel level) : std::ostream(&buffer) { SetInternalLevel(level); buffer.SetParentLogger(this); }

public:
    static void SetLevel(LogLevel level) { logLevel |= (int) level; }
    static void UnsetLevel(LogLevel level) { logLevel &= ~((int) level); }
    static bool IsSet(LogLevel level) { return (logLevel & ((int) level)) != (int) LogLevel::NOTHING; }
    static void UseColors(bool colors) { useColors = colors; }
    static bool UseColors() { return useColors; }
    
    static Logger error;
    static Logger warn;
    static Logger info;
    static Logger debug;
};

#endif // LOGGER_H_