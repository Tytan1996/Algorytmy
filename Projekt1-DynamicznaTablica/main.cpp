//Algorytmy Dynamiczna Tablica
//Maciej Pestka 170088
//Damian Szopinski 185394

#include <iostream>
//#include "DynamicArray.h"
#include "TestingFunction.hpp"

int main()
{

    std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl<<std::endl;
    std::cout<<"Sprawdzanie czasu operacji na tablicy (najwieksze mozliwe argumenty funkcji)"<<std::endl;
    {
        AiSD::OverflowTable testing(20000);
        testing.test();
    }
    {
        AiSD::DistortionsSimulation testing(100,1000);
        testing.doMultipleTimes(20);
    }
    {
        AiSD::Presentation testing(5);
        testing.test();
    }

    return 0;
}
