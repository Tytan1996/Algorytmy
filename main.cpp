#include <iostream>
#include "DynamicArray.h"




int main() {
    AiSD::DynamicArray dynamicArray(5);
    dynamicArray.Read();
    dynamicArray.Print();
    dynamicArray.Clear();
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
    dynamicArray.Save();
    std::cout<<dynamicArray.Search(103)<<std::endl;
    if(dynamicArray.EraseFirst(103)==true) {
        std::cout<<"usunieto"<<std::endl;
    }
    dynamicArray.Print();
    dynamicArray[0]=1000;
    std::cout<<dynamicArray[0]<<std::endl;
    dynamicArray.Erase(1,2);
    dynamicArray.PowiekszanieTablicy();
    dynamicArray.Print();
    dynamicArray.Save();
    dynamicArray.at(4)=123;
    dynamicArray.Print();
    dynamicArray.Insert(100,3,3);
    dynamicArray.Print();

    return 0;
}
