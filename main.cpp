#include <iostream>
#include "DynamicArray.h"
#include "TestingFunction.hpp"

/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */


using namespace AiSD;

int main()
{
    ClearLogTxt();

    DynamicArray dynamicArray(20000);

    std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl;
    std::cout<<"Please wait. Testing is in progress..."<<std::endl;
    for(int i=0;i<20;i++)
    {
        std::streambuf *old = std::cout.rdbuf();
        std::cout<<char(219);
        std::cout.rdbuf(0);
        DistortionsSimulation(dynamicArray,1000);
        std::cout.rdbuf(old);
    }std::cout<<std::endl<<std::endl;
    OverflowTable(dynamicArray);
    std::cout<<std::endl;
    Presentation(dynamicArray);

    return 0;
}
