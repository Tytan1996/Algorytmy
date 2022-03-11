#include <iostream>
#include "DynamicArray.h"



using namespace std;
using namespace AiSD;

int main() {
    DynamicArray dynamicArray(5);
    dynamicArray.Read();
    dynamicArray.Print();
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
    cout<<dynamicArray.Search(103)<<endl;
    if(dynamicArray.EraseFirst(103)==true) {
        cout<<"usunieto"<<endl;
    }
    dynamicArray.Print();
    dynamicArray[0]=1000;
    cout<<dynamicArray[0]<<endl;
    return 0;
}
