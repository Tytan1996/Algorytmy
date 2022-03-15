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
    cout<<"Please wait. Testing is in progress..."<<endl;
    for(int i=0;i<20;i++)
    {
        streambuf *old = cout.rdbuf();
        cout<<char(219);
        cout.rdbuf(0);
        DistortionsSimulation(dynamicArray,1000);
        cout.rdbuf(old);
    }cout<<endl<<endl;
    OverflowTable(dynamicArray);
    cout<<endl;
    Presentation(dynamicArray);

    return 0;
}
