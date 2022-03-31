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
    class Logger2{
        std::string nazwaPliku;
        std::fstream plik;
        public:
        Logger2(std::string nowaNazwaPliku);
        void zapis(std::string txt);
        ~Logger2();
    };
}



#endif // LOGGER_HPP
