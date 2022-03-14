#include <iostream>
#include "DynamicArray.h"
#include "TestingFunction.hpp"


using namespace std;
using namespace AiSD;

int main()
{
    srand(time(NULL));
    DynamicArray dynamicArray(10000);
    //862:966:631:-10:203:126:491:328:806
    dynamicArray.PushBack(862);
    dynamicArray.PushBack(966);
    dynamicArray.PushBack(631);
    dynamicArray.PushBack(-10);
    dynamicArray.PushBack(203);
    dynamicArray.PushBack(126);
    dynamicArray.PushBack(491);
    dynamicArray.PushBack(328);
    dynamicArray.PushBack(806);
    cout<<dynamicArray.IsEmpty()<<endl;



    //cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<endl;
    //DistortionsSimulation(dynamicArray,1000);
    //OverflowTable(dynamicArray);





    //dynamicArray.PushBack(850);
    //dynamicArray.PushBack(NULL);
    //dynamicArray.PushBack(-1);
    //dynamicArray.Erase(NULL);
    //dynamicArray.Insert(NULL,NULL);
    //dynamicArray.Print();

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
