//Algorytmy Dynamiczna Tablica
//Damian Szopinski 185394
//Maciej Pestka 170088

#ifndef TESTINGFUNCTION_CPP
#define TESTINGFUNCTION_CPP

#include "TestingFunction.hpp"


AiSD::Logger TestingFunctionLogger("Log.txt");
AiSD::noneV nothing{};


using clockH=std::chrono::high_resolution_clock;
//usunalem to z hpp bo nie bylo tam potrzebne
std::string timeTook(clockH::time_point a,clockH::time_point b)
{
    std::stringstream ss;
    auto time=std::chrono::duration_cast<std::chrono::microseconds>(b-a);
    ss<<time.count();
    return ss.str();
}


void AiSD::ClassTest::test()
{
    std::cout<<"ERROR, wrong class!"<<std::endl;
    return;
}
//OTRZYMANIE FUNKCJI PRZEZ JEJ NUMER
AiSD::ClassTest::FunctionInfo AiSD::ClassTest::FunctionByNO(short int NO)
{
    ClassTest::FunctionInfo fun;
    //przypisanie funckji
    switch(NO)
    {
        case 0:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PushFront(t1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PushFront(1 argument)";
            break;
        case 1:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PopFront();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PopFront";
            break;
        case 2:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PushBack(t1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PushBack(1 argument)";
            break;
        case 3:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PopBack();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PopBack";
            break;
        case 4:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.Front();}catch(const char* msg){throw msg;}};
            fun.type="Front";
            break;
        case 5:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.Back();}catch(const char* msg){throw msg;}};
            fun.type="Back";
            break;
        case 6:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.IsEmpty();}catch(const char* msg){throw msg;}};
            fun.type="IsEmpty";
            break;
        case 7:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.Size();}catch(const char* msg){throw msg;}};
            fun.type="Size";
            break;
        case 8:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Clear();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Clear";
            break;
        case 9:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Print();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Print";
            break;
        case 10:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Print1();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Print1";
            break;
        case 11:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.IsInList(t1);}catch(const char* msg){throw msg;}};
            fun.type="IsInList(1 argument)";
            break;
        //DLLNode pominalem bo nie ma jak przekazac w konsoli DLLNode
        case 12:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Insert(t1,i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Insert(2 arguments)";
            break;
        case 13:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Delete(i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Delete(1 argument)";
            break;
        case 14:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.InsertAfter(t1,i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="InsertAfter(2 arguments)";
            break;
        case 15:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.InsertBefore(t1,i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="InsertBefore(2 arguments)";
            break;
        case 16:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.DeleteAfter(i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="DeleteAfter(1 argument)";
            break;
        case 17:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.DeleteBefore(i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="DeleteBefore(1 argument)";
            break;
        default:
            throw "Invalid number of NO Function";
    }

    return fun;
}

AiSD::ClassTest::arg_t AiSD::ClassTest::DoFunction(DLL& arr,short int NO,T t,size_t i)
{
    try{
        FunctionInfo f = FunctionByNO(NO);
        //podstawowe informacjedo logow
        std::stringstream ss;
        ss<<"Operation "<<f.type<<" ("<<NO<<")"<<" for arguments "<<t.name<<":"<<t.grade<<" & "<<i<<std::endl<<"Array content: ";

        while(arr.lista!=NULL)
        {
            ss<<arr.lista->pokazElement().name<<" ";
            ss<<arr.lista->pokazElement().grade<<";";
            arr.lista=arr.lista->pobierzWskaznikNaKolejnyElement();
        }arr.lista=arr.head;





        ss<<"Size "<<arr.Size();
        TestingFunctionLogger.Log(ss.str());
        ss.str("");//kasowanie dotychczasowej zawartosci

        //odliczanie czasu i wykonywanie funkcji
        arg_t v;
        auto startTime=clockH::now();
        try
        {
            v=f.func(arr,t,i);
        }catch(const char* msg)
        {
            std::cout<<msg<<std::endl;
        }
        auto endTime=clockH::now();
        std::string time=timeTook(startTime,endTime);

        //informacja o sukcesie
        ss<<"Success. Took "<<time<<" microseconds; returned ";

        if (std::holds_alternative<bool>(v))
            ss<<std::get<bool>(v);
        else if(std::holds_alternative<size_t>(v))
            ss<<std::get<size_t>(v);
        else ss<<"Void";

        TestingFunctionLogger.Log(ss.str());
        return v;
    }catch (const char* msg)
    {
        throw msg;
    }
}

const int NOFunctions= 17;
//PIERWSZA FUNKCJA TESTUJACA

std::random_device rd;

//losowo wygenerowany string
std::string randomString()
{
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis1(0, 16);
    std::uniform_int_distribution<> dis2(48, 146);
    short int lenght=dis1(gen);
    std::string act="";
    for(short int i=0;i<lenght;i++)
        act+=char(dis2(gen));
    return act;
}


void AiSD::DistortionsSimulation::test()
{
    DLL* arr=pointer.get();
    TestingFunctionLogger.Log("-------------------------------------DistortionsSimulation");
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis1(-100, 1000);
    std::uniform_int_distribution<> dis2(0, NOFunctions);//dla czytelnosci print nie bedzie testowany


    for(int i=0;i<t;i++)
    {
        int a=dis2(gen);
        T b={randomString(),dis1(gen)};
        size_t c=dis1(gen);

        try
        {
            DoFunction(*arr,a,b,c);
        }catch(const char* msg)
        {
            std::cout<<msg<<std::endl;
        }
    }
}
void AiSD::DistortionsSimulation::doMultipleTimes(unsigned int times)
{
    std::cout<<std::endl<<"Random operations"<<std::endl<<"Please wait. Testing is in progress..."<<std::endl;
    for(unsigned int i=0;i<times;i++)
    {
        //TYMCZASOWE WYCISZANIE KONSOLI
        std::streambuf *old = std::cout.rdbuf();
        std::cout<<char(219);
        std::cout<<"-------------"<<times<<"/"<<i<<std::endl;
        test();
        std::cout.rdbuf(0);

        std::cout.rdbuf(old);
        //Blad krytyczny scrashuje program
    }std::cout<<std::endl<<"No problems found"<<std::endl;
    std::cout<<std::endl;
}
//DRUGA FUNKCJA TESTUJACA
void AiSD::OverflowTable::test()
{
    DLL* arr=pointer.get();
    TestingFunctionLogger.Log("-------------------------------------OverflowTable");
    T arg1={"",0};
    size_t arg2=0;

    for(int NOI=0;NOI<4;NOI++)
    {
        //std::cout<<"----------NOI FUNCTION:"<<NOI<<std::endl;
        auto f = FunctionByNO(NOI);

        //TestingFunctionLogger.Log("Repeat "+f.type);
        std::cout<<f.type;

        //PESYMISTYCZNY SCENARIUSZ CZYLI NAJWIEKSZE LICZBY JAKIE MOGE WYKORZYSTAC
        if(NOI==5||NOI==7){arg1.grade=std::numeric_limits<unsigned>::max();arg2=arr->Size()-1;}; //MAKSYMALNA WARTOSC T
        auto startTime=clockH::now();

        for(size_t i=0;i<repeat;i++)
        {
            //std::cout<<i<<"/"<<repeat<<std::endl;
            try
            {
                f.func(*arr,arg1,arg2);
            }catch(const char* msg)
            {
                std::cout<<"Unexpected error. "<<msg<<". Problem was ignored"<<std::endl;
            }
            //std::cout<<i<<"/"<<repeat<<std::endl;
        }

        auto endTime=clockH::now();

        std::string time=timeTook(startTime,endTime);

        std::cout<<" "<<repeat<<" times took "<<time<<" microseconds"<<std::endl;
    }
}

template<typename G> G AiSD::Presentation::getNum()
{
    std::string wejscie = "";
    G num;
    while (true)
    {
        getline(std::cin, wejscie);
        std::stringstream myStream(wejscie);
        if (myStream >> num)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    return num;
}

void AiSD::Presentation::test()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DLL* arr=pointer.get();
    TestingFunctionLogger.Log("-------------------------------------Presentation");
    while(true)
    {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout<<"Choose operation: "<<std::endl;
        SetConsoleTextAttribute(hConsole, 9);
        for(int i=0;i<NOFunctions;i++)//Wypisanie funkcji
            std::cout<<i<<"- "<<FunctionByNO(i).type<<std::endl;
        std::cout<<NOFunctions<<"- Exit"<<std::endl;
        SetConsoleTextAttribute(hConsole, 10);
        std::cout<<"Your opeartion: ";
        int userInput1=getNum<int>();

        bool g[3]={false,false,false};//g1 nalezy wczytac jeden argument, g2 nalezy wczytac drugi argument, g3 nalezy wczytac trzeci argument
        if(userInput1==5||userInput1==7||userInput1==9||userInput1==12||userInput1==13||userInput1==14)g[0]=true;       //T         (t1)
        if(userInput1==9||userInput1==10||userInput1==15)g[1]=true;                                                     //size_t    (i1)
        if(userInput1==15)g[2]=true;                                                                                    //size_t    (i2)
        if(userInput1==18)return;                                                                                       //EXIT

        T a1={"",0};
        size_t a2=0;
        size_t a3=0;

        if(g[0])
        {
            std::cout<<"T a1=";
            a1.grade=getNum<unsigned>();
        }
        if(g[1])
        {
            std::cout<<"size_t a2=";
            a2=getNum<size_t>();
        }
        if(g[2])
        {
            std::cout<<"size_t a3=";
            a3=getNum<size_t>();
        }
        SetConsoleTextAttribute(hConsole, 12);

        try{
            arg_t v;
            try
            {
                v=DoFunction(*arr,userInput1,a1,a2);
            }catch(const char* msg)
            {
                std::cout<<msg<<std::endl;
                v=nothing;
            }
            std::cout<<"Returned:";
            if (std::holds_alternative<bool>(v))
                std::cout<<std::get<bool>(v);
            else if(std::holds_alternative<size_t>(v))
                std::cout<<std::get<size_t>(v);
            else std::cout<<"Void";
            std::cout<<std::endl;
        }catch(const char* msg)
        {
            TestingFunctionLogger.Log("Unexpected error");
            std::cout<<"Unexpected error"<<std::endl;
        }
    }
}

#endif // TESTINGFUNCTION_CPP
