#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>

namespace prim
{
    class Logger
    {
    public:
        static void logInfo(std::string str);
        static void logWarning(std::string str);
        static void logError(std::string str);
    };
}

#endif // __LOGGER_HPP__