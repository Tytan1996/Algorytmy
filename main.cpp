#include <iostream>
#include "DynamicArray.h"
#include "TestingFunction.hpp"


using namespace AiSD;

int main()
{
    ClearLogTxt();

    DynamicArray dynamicArray(20000);

    std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl;
    std::cout<<"Please wait. Testing is in progress..."<<std::endl;
    for(int i=0;i<20;i++)
    {
        //TYMCZASOWE WYCISZANIE KONSOLI
        std::streambuf *old = std::cout.rdbuf();
        std::cout<<char(219);
        std::cout.rdbuf(0);
        DistortionsSimulation(dynamicArray,1000);
        std::cout.rdbuf(old);
    }std::cout<<std::endl<<std::endl;
    OverflowTable(dynamicArray);
    dynamicArray.Clear();
    std::cout<<std::endl;
    Presentation(dynamicArray);

    return 0;
}
