#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <string>
#include <map>
#include <mutex>

#include "Storage.h"


namespace telegram
{
    namespace util
    {
        class DataStore
        {
                std::map<std::string, Storage *> dataStore;
                std::mutex storeMutex;

            public:
                ~DataStore();

                Storage *GetStorage(const std::string &name);

                template<typename T, typename... U>
                Storage *CreateStorage(const std::string &name, const U &&... storageInitializers);
        };
    }
}

#endif // DATA_STORE_H
