#include "DynamicArray.h"

using namespace AiSD;

DynamicArray::DynamicArray(T rozmiar)
{
    capacity=rozmiar;
    tablica[capacity];
}

DynamicArray::~DynamicArray()
{
    //dtor
}
bool DynamicArray::IsEmpty(){

    if(size==0)
        return true;
    else
        return false;
}
bool DynamicArray::IsFull(){

    if(size==capacity)
        return true;
    else
        return false;
}
size_t DynamicArray::Space(){
    return capacity-size;
}
void DynamicArray::PushBack(T t){
    if(IsFull()==true){
        tablica[size]=t;
        ++size;
    }
}
void DynamicArray::PopBack(){
    if(IsEmpty()==true){
        tablica[size]=NULL;
        --size;
    }
}
void DynamicArray::PushFront(T t){
    if(IsFull()==true){
        size_t rozmarTablicy==size;
        size++;
        for(size_t i=0; i<rozmarTablicy;++i){
            tablica[i+1]=tablica[i];
        }
        tablica[0]=t;
    }
}

