#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
namespace AiSD
{
    class Logger
    {
        protected:
            std::string src;
            std::ofstream file;

        public:

            Logger(std::string LogFileName);
            void Log(std::string txt);
            ~Logger();
    };
}



#endif // LOGGER_HPP
