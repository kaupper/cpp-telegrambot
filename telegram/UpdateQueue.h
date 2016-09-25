#ifndef UPDATE_QUEUE_H_
#define UPDATE_QUEUE_H_

#include <mutex>
#include <string>
#include <map>

#include "structures.h"

namespace telegram
{
    class UpdateQueue
    {
    private:
        std::map<std::string, std::vector<telegram::structures::Update>> queue;
        std::mutex queueMutex;
        
    public:
        bool Available(std::string senderId);
        telegram::structures::Update Pop(std::string senderId);
        void Push(std::string senderId, telegram::structures::Update &update);
    };
}

#endif // UPDATE_QUEUE_H_
