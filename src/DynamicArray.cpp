#include "DynamicArray.h"

using namespace AiSD;


DynamicArray::DynamicArray(){
    capacity=100;
    size=0;
    tablica=new T[capacity]();
}
DynamicArray::DynamicArray(size_t rozmiar) {
    capacity=rozmiar;
    size=0;
    tablica= new T[capacity]();

}
DynamicArray::DynamicArray(size_t rozmiar, size_t N, const T& t) {
    capacity=rozmiar;
    size=N;
    tablica= new T[capacity]();
    for(size_t i=0; i<N; ++i) {
        tablica[i]=t;
    }

}
DynamicArray::DynamicArray(const DynamicArray &dynamicArray1){
    capacity=dynamicArray1.capacity;
    size=dynamicArray1.size;
    tablica=new T[capacity]();
    for(size_t i=0;i<capacity;++i){
        tablica[i]=dynamicArray1.tablica[i];
    }
}
DynamicArray::DynamicArray(DynamicArray&& dynamicArray) {
    capacity=std::move(dynamicArray.capacity);
    size=std::move(dynamicArray.size);
    tablica = new T[capacity]();
    for(size_t i=0;i<capacity;++i){
        tablica[i]=std::move(dynamicArray.tablica[i]);
    }
}
DynamicArray & DynamicArray::operator =(DynamicArray other) {
    capacity=other.capacity;
    size=other.size;
    tablica = new T[capacity]();
    for(size_t i=0;i<size;++i){
        tablica[i]=other.tablica[i];
    }
    return *this;
}
DynamicArray& DynamicArray::operator=(DynamicArray& other) {
    capacity=std::move(other.capacity);
    size=std::move(other.size);
    tablica=new T[capacity]();
    for(size_t i=0;i<size;++i){
        tablica[i]=std::move(other.tablica[i]);
    }
    return *this;
}
DynamicArray::~DynamicArray()
{
    delete [] tablica;
    capacity=0;
    size=0;
}
void DynamicArray::Print(){
    if(IsEmpty()==false){
        for(size_t i=0;i<size;++i){
            std::cout<<"element tablicy ["<<i<<"] = "<<tablica[i]<<std::endl;

        }
    } else {
        std::cout<<"tablica jest pusta"<<std::endl;
    }
}

void DynamicArray::Save() {
    std::ofstream plik(nazwaPliku, std::ios::out);
    //plik<<"ilosc wolnego miejsca: "<<Space()<<endl;
    if(IsEmpty()==true) {
        plik<<"tablica jest pusta"<<std::endl;
        return;
    }
    for(size_t i=0; i<size; ++i) {
        // plik<<"element tablicy ["<<i<<"] = "<<tablica[i]<<endl;
        plik<<tablica[i]<<std::endl;
    }
    plik.close();

}
bool DynamicArray::IsEmpty() {

    if(size==0)
        return true;
    else
        return false;
}
bool DynamicArray::IsFull() {

    if(size==capacity)
        return true;
    else
        return false;
}
size_t DynamicArray::Space() {
    return capacity-size;
}
void DynamicArray::PushBack(T t) {
    if(IsFull()==false) {
        tablica[size]=t;
        ++size;
    }
}
void DynamicArray::PopBack() {
    if(IsEmpty()==false) {
        --size;
        tablica[size]=NULL;
    }
}
void DynamicArray::PushFront(T t) {
    if(IsFull()==false) {
        size++;
        size_t rozmiarTablicy=size-1;
        for(size_t i=rozmiarTablicy; i>=0; --i) {
            tablica[i]=tablica[i-1];
            if(i==0)
                break;
        }
        tablica[0]=t;
    }
}
void DynamicArray::PopFront() {
    if(IsEmpty()==false) {
        --size;
        for(size_t i=0; i<size; ++i) {
            tablica[i]=tablica[i+1];
        }
        tablica[size]=NULL;
    }
}

void DynamicArray::Insert(T t, size_t i){
    if(IsFull()==true){
        return;
    }else if(i<0 || i>size){
        return;
    }
    if(i==0){
        PushFront(t);
    } else if(i==size) {
        PushBack(t);
    } else {
        ++size;
        for(size_t j=size; j>=i; --j) {
            tablica[j+1]=tablica[j];
        }
        tablica[i]=t;
    }
}

void DynamicArray::Erase(size_t i){
    if(IsEmpty()==true){
        return;
    }else if(i<0 || i>size){
        return;
    }
    if(i==0){
        PopFront();
    } else if(i==(size-1)) {
        PopBack();
    } else {
        for(size_t j=i; j<size; ++j) {
            tablica[j]=tablica[j+1];
        }
        tablica[size]=NULL;
        --size;
    }
}
T DynamicArray::wczytajLiczbeCalkowita() {
    std::string wejscie = "";
    T liczba = 0;
    while (true) {
        getline(std::cin, wejscie);
        std::stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    return liczba;
}
void DynamicArray::Clear() {
    for(size_t i=0; i<size; ++i) {
        tablica[i]=NULL;
    }
    size=0;
}
size_t DynamicArray::Search(const T& t) {
    for(size_t i=0; i<size; ++i) {
        if(tablica[i]==t) {
            return i;
        }
    }
    return size;
}
bool DynamicArray::EraseFirst(const T& t) {
    for(size_t i=0; i<size; ++i) {
        if(tablica[i]==t) {
            Erase(i);
            return true;
        }
    }
    return false;
}
size_t DynamicArray::EraseAll(const T& t) {
    size_t iloscUsunietychElementow=0;
    for(size_t i=0;i<size;++i){
        if(tablica[i]==t){
            Erase(i);
            ++iloscUsunietychElementow;
        }
    }
    return iloscUsunietychElementow;
}
size_t DynamicArray::Erase(size_t from, size_t to) {
    size_t iloscUsunietychElementow=0;
    if(IsEmpty()==true)
        return 0;
    if(-from>0 && int(from)<0) {
        std::cout<<"wpisano rozmiar mniejszczy od 0!"<<std::endl;
        return 0;
    } else if(to>size) {
        std::cout<<"wpisanio zbyt duzy indeks!"<<std::endl;
        return 0;
    } else if(to<=from) {
        std::cout<<"priewsza liczba jest mniejsza lub rowna od drugiej!"<<std::endl;
    } else {
        if((to-from)==1) {
            Erase(from);
            return 1;
        } else if(to==size && from==0) {
            Clear();
        } else if(from==0) {
            for(size_t i=0; i<from; ++i) {
                PopFront();
                ++iloscUsunietychElementow;
            }
            return iloscUsunietychElementow;
        } else if(to==size) {
            for(size_t i=from; i>to; --i) {
                PopBack();
                ++iloscUsunietychElementow;
            }
            return iloscUsunietychElementow;
        } else {
            for(size_t i=from; i<to; ++i) {
                Erase(from);
                ++iloscUsunietychElementow;
            }
            return iloscUsunietychElementow;
        }
    }
    return iloscUsunietychElementow;
}
T &DynamicArray::operator [](size_t i) {
    return tablica[i];
}
void DynamicArray::Read() {
    std::fstream plik(nazwaPliku, std::ios::in);
    size_t iloscDanychWczytanych=0;
    std::string liniaZPliku="";
    while(getline(plik, liniaZPliku)) {
        tablica[iloscDanychWczytanych]=atoi(liniaZPliku.c_str());
        ++iloscDanychWczytanych;
    }
    size=iloscDanychWczytanych;
    plik.close();
}
void DynamicArray::PowiekszanieTablicy() {
    if(capacity>=1310720000/6400){ /*dla capacity>=1310720000 jest blad gdy ta wartosc jest powiekszona o 2.
            ale wartosc zostala zmiejszczona o 32 by szybciej operacje wykonaly sie.
            1310720000 wartosc zostala wykryta przez program testujacy dodac do komendarza std::cout.rdbuf(0);
            i wyswietlac wartosc capacity i zobaczyc kiedy program wywoluje blad.
            Dla pewnosci wartosc zostala zmiejszczona o 32 by bardziej program dzialaj i nie wywowalj pamiecy.
            */
        return;
    }
    size_t powiekszonaWartosc=capacity*2;
    T *tablica2 =new T[powiekszonaWartosc];
    for(size_t i=0;i<capacity;++i){
        tablica2[i]=tablica[i];
    }
    tablica=tablica2;
    capacity=powiekszonaWartosc;
    //capacity=capacity*size_t(2);


}
T& DynamicArray::at(size_t i) {
    return tablica[i];
}
void DynamicArray::Insert(T t, size_t iloscElementow, size_t i) {
    if(i>size) {
        std::cout<<"i jest za duzy, i musi byc do "<<size<<"!"<<std::endl;
        return;
    }
    for(size_t j=0; j<iloscElementow; ++j) {
        Insert(t,i);
    }
}
