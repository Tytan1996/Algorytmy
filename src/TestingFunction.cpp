#ifndef TESTINGFUNCTION_CPP
#define TESTINGFUNCTION_CPP

#include "TestingFunction.hpp"

string LogFileName="Log.txt";

void AiSD::Log(string src,string in)
{
    std::ofstream file(src,std::ios_base::app);
    file<<in<<'\n';
    file.close();
}

float AiSD::BridgeFunction(DynamicArray& arr,int NO,T t,size_t i)
{
    /*Myslalem nad tym dlugo i to chyba najbardziej optymalna metoda wywolania funckji*/
    #define ARGV (DynamicArray& a,T t1,size_t i1)
    function<size_t ARGV> f ;
    string name="";

    //przypisanie funckji
    switch(NO)
    {
        case 0:
            f=[]ARGV{a.Print();return 0;};
            name="print";
            break;
        case 1:
            f=[]ARGV{a.Save();return 0;};
            name="save";
            break;
        case 2:
            f=[]ARGV{return a.IsEmpty()?0:1;};
            name="is empty";
            break;
        case 3:
            f=[]ARGV{return a.IsFull()?0:1;};
            name="is full";
            break;
        case 4:
            f=[]ARGV{return a.Space();};
            name="space";
            break;
        case 5:
            f=[]ARGV{a.PushBack(t1);return 0;};
            name="push back";
            break;
        case 6:
            f=[]ARGV{a.PopBack();return 0;};
            name="pop back";
            break;
        case 7:
            f=[]ARGV{a.PushFront(t1);return 0;};
            name="push front";
            break;
        case 8:
            f=[]ARGV{a.PopFront();return 0;};
            name="pop front";
            break;
        case 9:
            f=[]ARGV{a.Insert(t1,i1);return 0;};
            name="insert";
            break;
        case 10:
            f=[]ARGV{a.Erase(i1);return 0;};
            name="erase";
            break;
    }

    //podstawowe informacjedo logow
    std::stringstream ss;
    ss<<"Operation "<<name<<" for arguments "<<t<<" & "<<i<<endl;
    for(size_t i=0;i<arr.size;++i){
        ss<<arr.tablica[i]<<":";
    }ss<<endl;
    Log(LogFileName,ss.str());
    ss.clear();

    //odliczanie czasu i wykonywanie funkcji
    std::chrono::_V2::system_clock::time_point startTime=std::chrono::high_resolution_clock::now();
    size_t v=f(arr,t,i);
    std::chrono::_V2::system_clock::time_point endTime=std::chrono::high_resolution_clock::now();
    std::chrono::__enable_if_is_duration<std::chrono::duration<long long int, std::ratio<1, 1000000>>> time=std::chrono::duration_cast<std::chrono::microseconds>(startTime-endTime);

    //informacja o sukcesie
    ss<<"Success. Took "<<time.count()<<" microseconds"<<endl;
    Log(LogFileName,ss.str());
}
void AiSD::DistortionsSimulation(DynamicArray& arr,int t)
{
    #define pointA -100
    #define pointB 1000
    #define NOFunctions 11

    for(int i=0;i<t;i++)
    {
        int a=rand()%NOFunctions;
        T b=rand()%(pointB-pointA)+pointA;
        size_t c=rand()%(pointB-pointA)+pointA;
        BridgeFunction(arr,a,b,c);
    }
}
#endif // TESTINGFUNCTION_CPP
