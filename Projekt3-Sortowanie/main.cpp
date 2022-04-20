#include <iostream>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include "Sort.h"
#include <vector>
#include <SortFunction.h>
#include <Sort.h>

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

    int rozmiar=400000000;
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
    cout<<"przed: "<<endl;
    //for(int i=0; i<rozmiar; ++i) {
      // cout<<records[i].key<<' ';

    //}
    cout<<AiSD::ShellSort(records)<<endl;
    cout<<endl<<"Po (ShellSort): "<<endl;
    //for(int i=0; i<rozmiar; ++i) {
      // cout<<records[i].key<<' ';
    //}
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
    cout<<endl<<"przed: "<<endl;
    //for(int i=0; i<rozmiar; ++i) {
      // cout<<records[i].key<<' ';

    //}
    cout<<AiSD::QuickSort(records)<<endl;;
    cout<<endl<<"Po (QuickSort): "<<endl;
    //for(int i=0; i<50; ++i) {
      // cout<<records[i].key<<' ';

    //}
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
    cout<<endl<<"przed: "<<endl;
   // for(int i=0; i<50; ++i) {
      // cout<<records[i].key<<' ';

    //}
    cout<<AiSD::InsertionSort(records)<<endl;;
    cout<<endl<<"Po (InsertionSort): "<<endl;
    //for(int i=0; i<50; ++i) {
    //   cout<<records[i].key<<' ';

    //}
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
    cout<<endl<<"przed: "<<endl;
    //for(int i=0; i<50; ++i) {
     //  cout<<records[i].key<<' ';

    //}
    cout<<AiSD::MergeSort(records)<<endl;;
    cout<<endl<<"Po (MergeSort): "<<endl;
    //for(int i=0; i<50; ++i) {
      // cout<<records[i].key<<' ';

    //}
    return 0;
}
