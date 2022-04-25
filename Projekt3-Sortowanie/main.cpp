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



/*
class TAKA{
    size_t status {13}

public:
    operator() ()
    {
        return 2*status++;1
    };

};


TAKA nijaka;*/
int main() {
    /*
    struct Record{
        int key;
        char ID[5];
    };*/





    vector<Record> records ;





    //records.resize(50);

    //auto moja = nijaka();



    //td::generate(records.begin(),records.end(), [](){return 1;} );

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis1(0, std::numeric_limits<int>::max());
    int rozmiar=4000;
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
    cout<<"czas InsertionSort: "<<AiSD::InsertionSort(records)<<std::endl;
    return 0;
}
