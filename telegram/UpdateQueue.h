#ifndef UPDATE_QUEUE_H_
#define UPDATE_QUEUE_H_

#include "structures/StructConverter.h"

namespace telegram
{
    class UpdateQueue
    {
    private:
        std::map<std::string, std::vector<structures::Update>> queue;
        std::mutex queueMutex;
        
    public:
        bool Available(std::string senderId);
        structures::Update Pop(std::string senderId);
        void Push(std::string senderId, structures::Update &update);
    };
}

#endif // UPDATE_QUEUE_H_