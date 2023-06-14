#include "logger.hpp"
#include <iostream>

namespace prim
{
    void Logger::logInfo(std::string str)
    {
        std::cout << "[INFO] " << str << std::endl;
    }
    
    void Logger::logWarning(std::string str)
    {
        std::cout << "[WARNING] " << str << std::endl;
    }
    
    void Logger::logError(std::string str)
    {
        std::cerr << "[ERROR] " << str << std::endl;
    }
}