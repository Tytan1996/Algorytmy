#ifndef TESTINGFUNCTION_CPP
#define TESTINGFUNCTION_CPP

#include "TestingFunction.hpp"

const std::string LogFileName="Log.txt";
AiSD::noneV nothing{};


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
auto AiSD::FunctionByNO(int NO)
//mozna to zrobic lepiej dla std::variant https://en.cppreference.com/w/cpp/utility/variant
//oraz https://en.cppreference.com/w/cpp/keyword/union
{
    std::function<variant <bool, size_t,noneV> (AiSD::DynamicArray& a,T t1,size_t i1)> f ;
    //przypisanie funckji
    switch(NO)
    {
        case 0:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){ a.Print();return nothing;};
            nameV="print";
            break;
        case 1:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Save();return nothing;};
            nameV="save";
            break;
        case 2:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.IsEmpty();};
            nameV="is empty";
            break;
        case 3:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.IsFull();};
            nameV="is full";
            break;
        case 4:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.Space();};
            nameV="space";
            break;
        case 5:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PushBack(t1);return nothing;};
            nameV="push back";
            break;
        case 6:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PopBack();return nothing;};
            nameV="pop back";
            break;
        case 7:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PushFront(t1);return nothing;};
            nameV="push front";
            break;
        case 8:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PopFront();return nothing;};
            nameV="pop front";
            break;
        case 9:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Insert(t1,i1);return nothing;};
            nameV="insert";
            break;
        case 10:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Erase(i1);return nothing;};
            nameV="erase";
            break;
        default:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return nothing;};
    }

    return f;
}



auto AiSD::DoFunction(DynamicArray& arr,int NO,T t,size_t i)
{

    auto f = FunctionByNO(NO);

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
    auto v=f(arr,t,i);
    auto endTime=_setNow();
    std::string time=_timeTook(startTime,endTime);

    //informacja o sukcesie
    ss<<"Success. Took "<<time<<" microseconds; returned ";

    if (std::holds_alternative<bool>(v))
        ss<<std::get<bool>(v);
    else if(std::holds_alternative<size_t>(v))
        ss<<std::get<size_t>(v);
    else ss<<"Void";

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
    std::uniform_int_distribution<> dis2(0, 10);//dla czytelnosci print nie bedzie testowany


    for(int i=0;i<t;i++)
    {
        int a=dis1(gen);
        T b=dis2(gen);
        size_t c=dis2(gen);
        DoFunction(arr,a,b,c);
    }
}
//DRUGA FUNKCJA TESTUJACA

void AiSD::OverflowTable(DynamicArray& arr)
{
    T arg1=0;
    size_t arg2=0;

    for(int NOI=5;NOI<NOFunctions-1;NOI++)
    {
        auto f = FunctionByNO(NOI);

        //PESYMISTYCZNY SCENARIUSZ CZYLI NAJWIEKSZE LICZBY JAKIE MOGE WYKORZYSTAC
        if(NOI==5||NOI==7){arg1=-1;arg2=arr.capacity-1;}; //MAKSYMALNA WARTOSC T
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
void AiSD::ClearLogTxt()
{
    std::ofstream emptyFile;
    emptyFile.open(LogFileName, std::ofstream::out | std::ofstream::trunc);
    emptyFile.close();
}
void AiSD::Presentation(DynamicArray& arr)
{
    while(true)
    {
        cout<<"Choose operation: "<<endl;
        cout<<"0- print"<<endl<<"1- save"<<endl<<"2- isEmpty"<<endl<<"3- isFull"<<endl<<"4- Space"<<endl<<"5- PushBack"<<endl<<"6- pushFront"<<endl<<"7- popFront"<<endl<<"8- insert"<<endl<<"9- erase"<<endl<<"Your opeartion: ";
        int userInput1=0;
        cin>>userInput1;

        bool g1=false;//g1 nalezy wczytac jeden argument, g2 nalezy wczytac drugi argument
        bool g2=false;
        if(userInput1==5||userInput1==7||userInput1==9)g1=true; //T
        if(userInput1==9||userInput1==10)g2=true;               //size_t
        T a1=0;
        size_t a2=0;

        if(g1)
        {
            cout<<"T a1=";
            cin>>a1;
        }
        if(g2)
        {
            cout<<"size_t a2=";
            cin>>a2;
        }
        DoFunction(arr,userInput1,a1,a2);
    }


}

#endif // TESTINGFUNCTION_CPP
