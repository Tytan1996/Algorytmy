#include <iostream>
#include "DynamicArray.h"
#include "TestingFunction.hpp"


using namespace std;
using namespace AiSD;

int main()
{
    srand(time(NULL));
    DynamicArray dynamicArray(5);

    //DistortionsSimulation(dynamicArray,1000);

    dynamicArray.PushBack(850);
    dynamicArray.PushBack(74);
    dynamicArray.Insert(207,391);

    /*dynamicArray.Print();
    dynamicArray.PushBack(1);
    dynamicArray.PushFront(100);
    dynamicArray.PushFront(101);
    dynamicArray.PushFront(102);
    dynamicArray.PushBack(103);
    dynamicArray.Print();
    dynamicArray.PopFront();
    dynamicArray.Print();
    dynamicArray.Insert(321,4);
    dynamicArray.Print();
    dynamicArray.Erase(2);
    dynamicArray.Print();
    dynamicArray.Save();*/

    return 0;
}
