#ifndef TESTINGFUNCTION_CPP
#define TESTINGFUNCTION_CPP

#include "TestingFunction.hpp"

const std::string LogFileName="Log.txt";


//FUNKCJE DOT MIERZENIA CZASU

//#define chronotime std::chrono::_V2::system_clock::time_point
auto AiSD::_setNow()
{
    return std::chrono::high_resolution_clock::now();
}
string AiSD::_timeTook(auto a,auto b)
{
    std::stringstream ss;
    auto time=std::chrono::duration_cast<std::chrono::microseconds>(b-a);
    ss<<time.count();
    return ss.str();
}

void AiSD::Log(std::string src,std::string in)
{
    std::ofstream file(src,std::ios_base::app);
    file<<in<<'\n';
    file.close();
}

//OTRZYMANIE FUNKCJI PRZEZ JEJ NUMER

std::string nameV="";
function<size_t (AiSD::DynamicArray& a,T t1,size_t i1)> AiSD::FunctionByNO(int NO)
//mozna to zrobic lepiej dla std::variant https://en.cppreference.com/w/cpp/utility/variant
//oraz https://en.cppreference.com/w/cpp/keyword/union
{
    std::function<size_t (AiSD::DynamicArray& a,T t1,size_t i1)> f ;
    //przypisanie funckji
    switch(NO)
    {
        case 0:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Print();return 0;};
            nameV="print";
            break;
        case 1:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Save();return 0;};
            nameV="save";
            break;
        case 2:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.IsEmpty()?0:1;};
            nameV="is empty";
            break;
        case 3:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.IsFull()?0:1;};
            nameV="is full";
            break;
        case 4:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.Space();};
            nameV="space";
            break;
        case 5:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PushBack(t1);return 0;};
            nameV="push back";
            break;
        case 6:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PopBack();return 0;};
            nameV="pop back";
            break;
        case 7:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PushFront(t1);return 0;};
            nameV="push front";
            break;
        case 8:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PopFront();return 0;};
            nameV="pop front";
            break;
        case 9:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Insert(t1,i1);return 0;};
            nameV="insert";
            break;
        case 10:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Erase(i1);return 0;};
            nameV="erase";
            break;
    }
    return [](AiSD::DynamicArray& a,T t1,size_t i1){return 0;};
}



size_t AiSD::BridgeFunction(DynamicArray& arr,int NO,T t,size_t i)
{
    function<size_t (AiSD::DynamicArray& a,T t1,size_t i1)> f = FunctionByNO(NO);

    //podstawowe informacjedo logow
    std::stringstream ss;
    ss<<"Operation "<<nameV<<" for arguments "<<t<<" & "<<i<<endl<<"Array content: ";
    for(size_t i=0;i<arr.size;++i){
        ss<<arr.tablica[i]<<":";
    }
    Log(LogFileName,ss.str());
    ss.str("");//kasowanie dotychczasowej zawartosci

    //odliczanie czasu i wykonywanie funkcji
    auto startTime=_setNow();
    size_t v=f(arr,t,i);
    auto endTime=_setNow();
    std::string time=_timeTook(startTime,endTime);

    //informacja o sukcesie
    ss<<"Success. Took "<<time<<" microseconds; returned "<<v;
    Log(LogFileName,ss.str());
    return v;
}

const int NOFunctions= 11;
//PIERWSZA FUNKCJA TESTUJACA

std::random_device rd;

void AiSD::DistortionsSimulation(DynamicArray& arr,int t)
{
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis1(-100, 1000);
    std::uniform_int_distribution<> dis2(0, 10);


    for(int i=0;i<t;i++)
    {
        int a=dis1(gen);
        T b=dis2(gen);
        size_t c=dis2(gen);
        BridgeFunction(arr,a,b,c);
    }
}
//DRUGA FUNKCJA TESTUJACA

void AiSD::OverflowTable(DynamicArray& arr)
{
    //tutaj dobra niespodzielka okazala sie kolejnosc funkcji, tzn. 1- to push_back 2- pop_back. Dodawanie a nastepnie kasowanie, nastepnie push_front i pop_front i tak dalej...
    T arg1=0;
    size_t arg2=0;

    for(int NOI=5;NOI<NOFunctions-1;NOI++)
    {
        function<size_t (AiSD::DynamicArray& a,T t1,size_t i1)> f = FunctionByNO(NOI);

        if(NOI==5||NOI==7||NOI==9){arg1=-1;arg2=-1;}; //MAKSYMALNA WARTOSC T
        auto startTime=_setNow();
        for(size_t i=0;i<arr.capacity;++i)
            f(arr,arg1,arg2);
        auto endTime=_setNow();

        //TESTOWANIE PRZEKROCZENIA TABLICY!!!
        for(int i=0;i<10;i++)
            f(arr,0,0);

        std::string time=_timeTook(startTime,endTime);
        std::cout<<nameV<<" "<<arr.capacity<<" times took "<<time<<" microseconds"<<endl;
    }
}

void AiSD::Presentation(DynamicArray& arr)
{


}

#endif // TESTINGFUNCTION_CPP
