#include <iostream>
#include "DynamicArray.h"



using namespace std;
using namespace AiSD;

int main()
{
    DynamicArray dynamicArray(5);
    dynamicArray.Print();
    dynamicArray.PushBack(1);
    dynamicArray.PushFront(100);
    dynamicArray.PushFront(101);
    dynamicArray.PushFront(102);
    dynamicArray.PushBack(103);
    dynamicArray.Print();
    return 0;
}
