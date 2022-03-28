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

#endif // LOGGER_CPP
