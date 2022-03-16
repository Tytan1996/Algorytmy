//Algorytmy Dynamiczna Tablica
//Damian Szopinski 185394
//Maciej Pestka 170088

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
std::string AiSD::_timeTook(auto a,auto b)
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
auto AiSD::FunctionByNO(int NO,size_t cap)
//mozna to zrobic lepiej dla std::variant https://en.cppreference.com/w/cpp/utility/variant
//oraz https://en.cppreference.com/w/cpp/keyword/union
{
    std::function<std::variant <bool, size_t,noneV> (AiSD::DynamicArray& a,T t1,size_t i1)> f ;
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
        case 11:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Clear();return nothing;};
            nameV="clear";
            break;
        case 12:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.Search(t1);};
            nameV="search";
            break;
        case 13:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.EraseFirst(t1);};
            nameV="erase first";
            break;
        case 14:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.EraseAll(t1);};
            nameV="erase all";
            break;
        case 15:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return a.Erase(i1,i1+size_t(t1));};
            nameV="erase";
            break;
        case 16:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Read();return nothing;};
            nameV="read";
            break;
        case 17:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.PowiekszanieTablicy();return nothing;};
            nameV="powiekszanie tablicy";
            break;
        case 18:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){a.Insert(t1,i1,i1);return nothing;};
            nameV="Insert (3 arguments)";
            break;
        default:
            f=[](AiSD::DynamicArray& a,T t1,size_t i1){return nothing;};
    }

    return f;
}



auto AiSD::DoFunction(DynamicArray& arr,int NO,T t,size_t i)
{

    auto f = FunctionByNO(NO,arr.capacity);

    //podstawowe informacjedo logow
    std::stringstream ss;
    ss<<"Operation "<<nameV<<" ("<<NO<<")"<<" for arguments "<<t<<" & "<<i<<std::endl<<"Array content: ";
    for(size_t i=0;i<arr.size;++i){
        ss<<arr.tablica[i]<<":";
    }
    ss<<"Capcity/Size "<<arr.capacity<<"/"<<arr.size;
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

const int NOFunctions= 18;
//PIERWSZA FUNKCJA TESTUJACA

std::random_device rd;

void AiSD::DistortionsSimulation(DynamicArray& arr,int t)
{
    AiSD::Log(LogFileName,"-------------------------------------DistortionsSimulation");
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis1(-100, 1000);
    std::uniform_int_distribution<> dis2(0, NOFunctions);//dla czytelnosci print nie bedzie testowany


    for(int i=0;i<t;i++)
    {
        int a=dis2(gen);
        T b=dis1(gen);
        size_t c=dis1(gen);
        DoFunction(arr,a,b,c);
    }
}
//DRUGA FUNKCJA TESTUJACA

void AiSD::OverflowTable(DynamicArray& arr)
{
    AiSD::Log(LogFileName,"-------------------------------------OverflowTable");
    T arg1=0;
    size_t arg2=0;

    for(int NOI=5;NOI<10;NOI++)
    {
        auto f = FunctionByNO(NOI,arr.capacity);

        AiSD::Log(LogFileName,"Repeat "+nameV);
        std::cout<<nameV;

        //PESYMISTYCZNY SCENARIUSZ CZYLI NAJWIEKSZE LICZBY JAKIE MOGE WYKORZYSTAC
        if(NOI==5||NOI==7){arg1=-1;arg2=arr.size-1;}; //MAKSYMALNA WARTOSC T
        auto startTime=_setNow();
        for(size_t i=0;i<arr.capacity;++i)
            f(arr,arg1,arg2);
        auto endTime=_setNow();

        //TESTOWANIE PRZEKROCZENIA TABLICY!!!
        for(int i=0;i<10;i++)
            f(arr,0,0);

        std::string time=_timeTook(startTime,endTime);

        std::cout<<" "<<arr.capacity<<" times took "<<time<<" microseconds"<<std::endl;
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
    AiSD::Log(LogFileName,"-------------------------------------Presentation");
    while(true)
    {
        std::string wejscie = "";

        std::cout<<"Choose operation: "<<std::endl;
        std::cout<<"0- Print"<<std::endl<<"1- Save"<<std::endl<<"2- Is Empty"<<std::endl<<"3- Is Full"<<std::endl<<"4- Space"<<std::endl<<"5- Push Back (1 argument)"<<std::endl<<"6- Pop Back"<<std::endl<<"7- Push Front (1 argument)"<<std::endl<<"8- Pop Front"<<std::endl<<"9- Insert (2 arguments)"<<std::endl<<"10- Erase (1 argument)"<<std::endl<<"11- Clear"<<std::endl<<"12- Search (1 argument)"<<std::endl<<"13- Erase First (1 argument)"<<std::endl<<"14- Erase All (1 argument)"<<std::endl<<"15- Erase (2 arguments (size_t,size_t+long int))"<<std::endl<<"16- Read"<<std::endl<<"17- Powiekszenie tablicy"<<std::endl<<"18- Koniec programu"<<std::endl<<"Your opeartion: ";
        int userInput1=0;
        while (true)
        {
            getline(std::cin, wejscie);
            std::stringstream myStream(wejscie);
            if (myStream >> userInput1)
                break;
            std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
        }

        bool g1=false;//g1 nalezy wczytac jeden argument, g2 nalezy wczytac drugi argument
        bool g2=false;
        if(userInput1==5||userInput1==7||userInput1==9||userInput1==12||userInput1==13||userInput1==14||userInput1==15)g1=true; //T         (t1)
        if(userInput1==9||userInput1==10||userInput1==15)g2=true;               //size_t    (i1)
        if(userInput1==18)return;
        T a1=0;
        size_t a2=0;

        if(g1)
        {
            std::cout<<"T a1=";
            while (true)
            {
                getline(std::cin, wejscie);
                std::stringstream myStream(wejscie);
                if (myStream >> a1)
                    break;
                std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
            }
        }
        if(g2)
        {
            std::cout<<"size_t a2=";
            while (true)
            {
                getline(std::cin, wejscie);
                std::stringstream myStream(wejscie);
                if (myStream >> a2)
                    break;
                std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
            }
        }

        auto v=DoFunction(arr,userInput1,a1,a2);

        std::cout<<"Returned:";
        if (std::holds_alternative<bool>(v))
            std::cout<<std::get<bool>(v);
        else if(std::holds_alternative<size_t>(v))
            std::cout<<std::get<size_t>(v);
        else std::cout<<"Void";
        std::cout<<std::endl<<std::endl;
    }


}

#endif // TESTINGFUNCTION_CPP
