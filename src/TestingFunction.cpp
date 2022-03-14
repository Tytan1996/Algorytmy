#ifndef TESTINGFUNCTION_CPP
#define TESTINGFUNCTION_CPP

#include "TestingFunction.hpp"

string LogFileName="Log.txt";


//FUNKCJE DOT MIERZENIA CZASU

#define chronotime std::chrono::_V2::system_clock::time_point
chronotime _setNow()
{
    return std::chrono::high_resolution_clock::now();
}
string _timeTook(chronotime a,chronotime b)
{
    std::stringstream ss;
    std::chrono::__enable_if_is_duration<std::chrono::duration<long long int, std::ratio<1, 1000000>>> time=std::chrono::duration_cast<std::chrono::microseconds>(b-a);
    ss<<time.count();
    return ss.str();
}



void AiSD::Log(string src,string in)
{
    std::ofstream file(src,std::ios_base::app);
    file<<in<<'\n';
    file.close();
}

//OTRZYMANIE FUNKCJI PRZEZ JEJ NUMER

#define ARGV (AiSD::DynamicArray& a,T t1,size_t i1)
string nameV="";
function<size_t ARGV> FunctionByNO(int NO)
{
    /*Myslalem nad tym dlugo i to chyba najbardziej optymalna metoda wywolania funckji*/

    function<size_t ARGV> f ;
    //przypisanie funckji
    switch(NO)
    {
        case 0:
            f=[]ARGV{a.Print();return 0;};
            nameV="print";
            break;
        case 1:
            f=[]ARGV{a.Save();return 0;};
            nameV="save";
            break;
        case 2:
            f=[]ARGV{return a.IsEmpty()?0:1;};
            nameV="is empty";
            break;
        case 3:
            f=[]ARGV{return a.IsFull()?0:1;};
            nameV="is full";
            break;
        case 4:
            f=[]ARGV{return a.Space();};
            nameV="space";
            break;
        case 5:
            f=[]ARGV{a.PushBack(t1);return 0;};
            nameV="push back";
            break;
        case 6:
            f=[]ARGV{a.PopBack();return 0;};
            nameV="pop back";
            break;
        case 7:
            f=[]ARGV{a.PushFront(t1);return 0;};
            nameV="push front";
            break;
        case 8:
            f=[]ARGV{a.PopFront();return 0;};
            nameV="pop front";
            break;
        case 9:
            f=[]ARGV{a.Insert(t1,i1);return 0;};
            nameV="insert";
            break;
        case 10:
            f=[]ARGV{a.Erase(i1);return 0;};
            nameV="erase";
            break;
    }
    return []ARGV{return 0;};
}



size_t AiSD::BridgeFunction(DynamicArray& arr,int NO,T t,size_t i)
{
    function<size_t ARGV> f = FunctionByNO(NO);

    //podstawowe informacjedo logow
    std::stringstream ss;
    ss<<"Operation "<<nameV<<" for arguments "<<t<<" & "<<i<<endl<<"Array content: ";
    for(size_t i=0;i<arr.size;++i){
        ss<<arr.tablica[i]<<":";
    }
    Log(LogFileName,ss.str());
    ss.str("");//kasowanie dotychczasowej zawartosci

    //odliczanie czasu i wykonywanie funkcji
    chronotime startTime=_setNow();
    size_t v=f(arr,t,i);
    chronotime endTime=_setNow();
    string time=_timeTook(startTime,endTime);

    //informacja o sukcesie
    ss<<"Success. Took "<<time<<" microseconds; returned "<<v;
    Log(LogFileName,ss.str());
    return v;
}

#define NOFunctions 11
//PIERWSZA FUNKCJA TESTUJACA

void AiSD::DistortionsSimulation(DynamicArray& arr,int t)
{
    #define pointA -100
    #define pointB 1000
    for(int i=0;i<t;i++)
    {
        int a=rand()%NOFunctions;
        T b=rand()%(pointB-pointA)+pointA;
        size_t c=rand()%(pointB-pointA)+pointA;
        BridgeFunction(arr,a,b,c);
    }
}
//DRUGA FUNKCJA TESTUJACA

void AiSD::OverflowTable(DynamicArray& arr)
{
    //tutaj dobra niespodzielka okazala sie kolejnosc funkcji, tzn. 1- to push_back 2- pop_back. Dodawanie a nastepnie kasowanie, nastepnie push_front i pop_front i tak dalej...
    for(int NOI=5;NOI<NOFunctions;NOI++)
    {
        function<size_t ARGV> f = FunctionByNO(NOI);
        chronotime startTime=_setNow();
        for(size_t i=0;i<arr.capacity;++i)
                f(arr,i-1,i-1);
        chronotime endTime=_setNow();
        //TESTOWANIE PRZEKROCZENIA TABLICY!!!
        for(int i=0;i<10;i++)
            f(arr,0,0);

        string time=_timeTook(startTime,endTime);
        std::cout<<nameV<<" "<<arr.capacity<<" times took "<<time<<" microseconds"<<endl;
    }
}

#endif // TESTINGFUNCTION_CPP
