#ifndef UPDATE_QUEUE_H_
#define UPDATE_QUEUE_H_

#include <mutex>
#include <string>
#include <map>

#include "jsonserializer/RequestConverter.h"


namespace telegram
{
    class UpdateQueue
    {
        private:
            std::map<std::string, std::vector<telegram::structures::Update>> queue;
            std::mutex queueMutex;

        public:
            bool Available(const std::string &senderId);
            telegram::structures::Update Pop(const std::string &senderId);
            void Push(const std::string &senderId, const telegram::structures::Update &update);
    };
}

#endif // UPDATE_QUEUE_H_
