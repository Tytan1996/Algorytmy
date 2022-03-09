#include "DynamicArray.h"

using namespace AiSD;

DynamicArray::DynamicArray(T rozmiar)
{
    capacity=rozmiar;
    size=0;
    tablica[capacity];
}

DynamicArray::~DynamicArray()
{
    //dtor
}
void DynamicArray::Print(){
    if(IsEmpty()==false){
        for(size_t i=0;i<size;++i){
            cout<<"element tablicy ["<<i<<"] ="<<tablica[i]<<endl;
        }
    }else{
        cout<<"tablica jest pusta"<<endl;
    }

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
    if(IsFull()==false){
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
    if(IsFull()==false){
        size++;
        size_t rozmiarTablicy=size-1;
        for(size_t i=rozmiarTablicy;i>=0;--i){
            tablica[i]=tablica[i-1];
            if(i==0)
                break;
        }
        tablica[0]=t;
    }
}

