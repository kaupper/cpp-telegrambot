#ifndef JSON_WRAPPER_H
#define JSON_WRAPPER_H

#include <mutex>
#include <string>

#include "jsonserializer/json.h"


namespace telegram
{
    namespace util
    {
        inline std::string ToString(const json &j)
        {
            if (j.type() == json::value_t::string) {
                return j.get<std::string>();
            } else {
                return j.dump();
            }
        }

        class JSONWrapper : public json
        {
                std::mutex jsonMutex;

                json &GetRef(json &value)
                {
                    return value;
                }

                template <typename T, typename... U>
                json &GetRef(json &value, T &&selector, U &&... selectors)
                {
                    return GetRef(value[selector], selectors...);
                }

            public:
                template <typename T, typename... U>
                json Get(T &&selector, U &&... selectors)
                {
                    jsonMutex.lock();
                    auto &tmp = GetRef(*(static_cast<json *>(this)), selector, selectors...);
                    jsonMutex.unlock();
                    return tmp;
                }

                template <typename T, typename R, typename... U>
                void Set(T &&value, R &&selector, U &&... selectors)
                {
                    jsonMutex.lock();
                    auto &tmp = GetRef(*(static_cast<json *>(this)), selector, selectors...);
                    tmp = value;
                    jsonMutex.unlock();
                }

                template <typename T, typename... U>
                std::string GetString(T &&selector, U &&... selectors)
                {
                    return ToString(Get(selector, selectors...));
                }
        };
    }
}

#endif // JSON_WRAPPER_H