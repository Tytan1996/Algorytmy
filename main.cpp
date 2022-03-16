//Algorytmy Dynamiczna Tablica
//Maciej Pestka 170088
//Damian Szopinski 185394

#include <iostream>
#include "DynamicArray.h"
#include "TestingFunction.hpp"

int main()
{
    AiSD::ClearLogTxt();

    {
        AiSD::DynamicArray dynamicArray(20000);
        std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl<<std::endl;
        //dynamicArray.Space();
        std::cout<<"Sprawdzanie czasu operacji na tablicy (najwieksze mozliwe argumenty funkcji)"<<std::endl;
        AiSD::OverflowTable(dynamicArray);
    }
    {
        AiSD::DynamicArray dynamicArray(100);
        std::cout<<std::endl<<"Random operations"<<std::endl<<"Please wait. Testing is in progress..."<<std::endl;
        for(int i=0;i<20;i++)
        {
            //TYMCZASOWE WYCISZANIE KONSOLI
            std::streambuf *old = std::cout.rdbuf();
            std::cout<<char(219);
            std::cout.rdbuf(0);
            AiSD::DistortionsSimulation(dynamicArray,1000);
            std::cout.rdbuf(old);
            //Blad krytyczny scrashuje program
        }std::cout<<std::endl<<"No problems found"<<std::endl;
    }
    {
        AiSD::DynamicArray dynamicArray(5);
        std::cout<<std::endl;
        AiSD::Presentation(dynamicArray);
    }

    return 0;
}
