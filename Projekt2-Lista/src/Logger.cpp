#ifndef LOGGER_CPP
#define LOGGER_CPP

#include "Logger.hpp"
AiSD::Logger::Logger(std::string LogFileName)
{
    try{
        src=LogFileName;
        file.open(LogFileName,std::ifstream::trunc);
    }catch (std::ifstream::failure e)
    {
        std::exit(EXIT_FAILURE);
    }
}

AiSD::Logger::~Logger()
{
    file.close();
}

void AiSD::Logger::Log(std::string txt)
{
    file<<txt<<'\n';
}
AiSD::Logger2::Logger2(std::string nowaNazwaPliku){
    try{
        nazwaPliku=nowaNazwaPliku;
        plik.open(nazwaPliku, std::ifstream::trunc);
        plik<<"----STATYSTYKI WYKONYWANA MENU----"<<'\n';
    }catch(std::ifstream::failure e){
        std::exit(EXIT_FAILURE);
    }
}
void AiSD::Logger2::zapis(std::string txt){
    plik<<txt<<'\n';
}
AiSD::Logger2::~Logger2()
{
    plik.close();
}

#endif // LOGGER_CPP
