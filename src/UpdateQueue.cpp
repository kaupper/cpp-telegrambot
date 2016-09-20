#include "UpdateQueue.h"

using namespace telegram;

bool UpdateQueue::Available(std::string senderId) 
{
    queueMutex.lock();
    unsigned long availables = queue[senderId].size();
    queueMutex.unlock();
    return availables > 0; 
}

jsonserializer::structures::Update UpdateQueue::Pop(std::string senderId)
{
    queueMutex.lock();
    jsonserializer::structures::Update update = queue[senderId].back();
    queue[senderId].pop_back();
    queueMutex.unlock();
    return update;
}

void UpdateQueue::Push(std::string senderId, jsonserializer::structures::Update &update)
{
    queueMutex.lock();
    queue[senderId].push_back(update);
    queueMutex.unlock();
}