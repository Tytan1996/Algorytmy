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
int main(){
    /*
    struct Record{
        int key;
        char ID[5];
    };*/



    vector<Record> records ;

    //records.resize(50);

    //auto moja = nijaka();



    //td::generate(records.begin(),records.end(), [](){return 1;} );


    for(int i=0;i<50;++i){
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
    cout<<AiSD::ShellSort(records)<<endl;
    Sort test;
    std::cout<<"Przed: "<<std::endl;
    for (std::vector<Record> :: iterator itr = records.begin(); itr != records.end(); itr++)
    {
        std::cout<<itr->key<<" ";
    }
    std::cout<<'\n'<<"Po: "<<std::endl<<"Czas :";
    std::cout<<test.ShellSort(records)<<std::endl;
    for (std::vector<Record> :: iterator itr = records.begin(); itr != records.end(); itr++)
    {
        std::cout<<itr->key<<" ";
    }
    return 0;
}
