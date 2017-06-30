#ifndef JSON_PERSISTER_H
#define JSON_PERSISTER_H

#include <fstream>

#include "JSONWrapper.h"


namespace telegram
{
    namespace util
    {
        class JSONPersister : public JSONWrapper
        {
                std::string fileName;

            public:
                JSONPersister();
                JSONPersister(const std::string fileName);

                void SetFileName(const std::string &fileName);
                std::string GetFileName() const;

                void Load();
                void Save();
        };
    }
}

#endif