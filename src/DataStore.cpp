#include "DataStore.h"

using namespace telegram::util;


DataStore::~DataStore()
{
    storeMutex.lock();

    for (auto &pair : dataStore) {
        delete pair.second;
    }

    storeMutex.unlock();
}

Storage *DataStore::GetStorage(const std::string &name)
{
    storeMutex.lock();
    Storage *tmp = nullptr;

    if (dataStore.find(name) != dataStore.end()) {
        tmp = dataStore[name];
    }

    storeMutex.unlock();
    return tmp;
}

template<typename T, typename... U>
Storage *DataStore::CreateStorage(const std::string &name, const U &&... storageInitializers)
{
    storeMutex.lock();
    auto tmp = (dataStore[name] = new T(storageInitializers...));
    storeMutex.unlock();
    return tmp;
}