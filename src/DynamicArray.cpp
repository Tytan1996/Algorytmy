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
            cout<<"element tablicy ["<<i<<"] = "<<tablica[i]<<endl;
        }
    }else{
        cout<<"tablica jest pusta"<<endl;
    }

}
void DynamicArray::Save(){
    ofstream plik(nazwaPliku, ios::out);
    plik<<"ilosc wolnego miejsca: "<<Space()<<endl;
    if(IsEmpty()==true){
        plik<<"tablica jest piusta"<<endl;
        return;
    }
    for(size_t i=0;i<size;++i){
        plik<<"element tablicy ["<<i<<"] = "<<tablica[i]<<endl;
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
    if(IsEmpty()==false){
        --size;
        tablica[size]=NULL;
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
void DynamicArray::PopFront(){
    if(IsEmpty()==false){
        --size;
        for(size_t i=0;i<size;++i){
            tablica[i]=tablica[i+1];
        }
        tablica[size]=NULL;
    }
}
void DynamicArray::Insert(T t, size_t i){
    if(IsFull()==true)
        return;
    if(i==0){
        PushFront(t);
    }else if(i==size){
        PushBack(t);
    }else{
        ++size;
        for(size_t j=size; j>=i;--j){
            tablica[j+1]=tablica[j];
        }
        tablica[i]=t;
    }
}
void DynamicArray::Erase(size_t i){
    if(IsEmpty()==true)
        return;

    if(i==0){
        PopFront();
    }else if(i==(size-1)){
        PopBack();
    }else{
        for(size_t j=i; j<size; ++j){
            tablica[j]=tablica[j+1];
        }
        tablica[size]=NULL;
        --size;
    }
}
T DynamicArray::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    T liczba = 0;
    while (true)
    {
        getline(cin, wejscie);
        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
void DynamicArray::Clear(){
    for(size_t i=0;i<size;++i){
        tablica[i]=NULL;
    }
    size=0;
}
size_t DynamicArray::Search(const T t){
    for(size_t i=0; i<size; ++i){
        if(tablica[i]==t){
            return i;
        }
    }
    return size;
}
bool DynamicArray::EraseFirst(const T t){
    for(size_t i=0;i<size;++i){
        if(tablica[i]==t){
            Erase(i);
            return true;
        }
    }
    return false;
}
