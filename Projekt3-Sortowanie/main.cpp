#include <iostream>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include "Sort.h"
#include <vector>
#include <SortFunction.h>
#include <Sort.h>
#include <random>

using namespace std;

int main() {


    vector<Record> records ;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis1(0, std::numeric_limits<int>::max());
    int rozmiar=400000;
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= dis1(gen);
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    cout<<"czas ShellSort: "<<AiSD::ShellSort(records)<<endl;

    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    cout<<"czas QuickSort: "<<AiSD::QuickSort(records)<<std::endl;
    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    cout<<"czas MergeSort: "<<AiSD::MergeSort(records)<<std::endl;
    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    cout<<"czas MergeSort2 (szybca wersja): "<<AiSD::MergeSort2(records)<<std::endl;
    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    cout<<"czas InsertionSort: "<<AiSD::InsertionSort(records)<<std::endl;
    rozmiar=200;
    map<std::string, size_t> mapa;
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= dis1(gen);
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    mapa=AiSD::Diag_ShellSort(records);
    typedef std::map<std::string, size_t>::iterator MapIterator;
    for(MapIterator it=mapa.begin(); it!=mapa.end(); ++it)
    {
        std::cout<<it->first<<": "<<it->second<<std::endl;
    }
    mapa.clear();
    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    mapa=AiSD::Diag_QuickSort(records);
    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }
    mapa=AiSD::Diag_MergeSort(records);
    for(MapIterator it=mapa.begin(); it!=mapa.end(); ++it)
    {
        std::cout<<it->first<<": "<<it->second<<std::endl;
    }
    mapa.clear();
    records.clear();
    for(int i=0; i<rozmiar; ++i) {
        Record nowy;
        srand (time(NULL));
        nowy.key= rand() % (4*(i+1))+i;
        nowy.ID[0]=char(i);
        nowy.ID[1]=char(i);
        nowy.ID[2]=char(i);
        nowy.ID[3]=char(i);
        nowy.ID[4]=char(i);
        records.push_back(nowy);
    }

    mapa=AiSD::Diag_InsertionSort(records);
    for(MapIterator it=mapa.begin(); it!=mapa.end(); ++it)
    {
        std::cout<<it->first<<": "<<it->second<<std::endl;
    }
    mapa.clear();
    return 0;
}
