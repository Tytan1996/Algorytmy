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


void AiSD::ClassTest::test(bool debugMode)
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
            fun.size_t_needed=false;
            fun.T_needed=true;
            break;
        case 1:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PopFront();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PopFront";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 2:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PushBack(t1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PushBack(1 argument)";
            fun.size_t_needed=false;
            fun.T_needed=true;
            break;
        case 3:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.PopBack();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="PopBack";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 4:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.Front();}catch(const char* msg){throw msg;}};
            fun.type="Front";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 5:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.Back();}catch(const char* msg){throw msg;}};
            fun.type="Back";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 6:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.IsEmpty();}catch(const char* msg){throw msg;}};
            fun.type="IsEmpty";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 7:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.Size();}catch(const char* msg){throw msg;}};
            fun.type="Size";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 8:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Clear();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Clear";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 9:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Print();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Print";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 10:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Print1();return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Print1";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 11:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{return a.IsInList(t1);}catch(const char* msg){throw msg;}};
            fun.type="IsInList(1 argument)";
            fun.size_t_needed=false;
            fun.T_needed=true;
            break;
        //DLLNode pominalem bo nie ma jak przekazac w konsoli DLLNode
        case 12:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Insert(t1,i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Insert(2 arguments)";
            fun.size_t_needed=true;
            fun.T_needed=true;
            break;
        case 13:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.Delete(i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="Delete(1 argument)";
            fun.size_t_needed=true;
            fun.T_needed=false;
            break;
        case 14:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.InsertAfter(t1,i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="InsertAfter(2 arguments)";
            fun.size_t_needed=true;
            fun.T_needed=true;
            break;
        case 15:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.InsertBefore(t1,i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="InsertBefore(2 arguments)";
            fun.size_t_needed=true;
            fun.T_needed=true;
            break;
        case 16:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.DeleteAfter(i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="DeleteAfter(1 argument)";
            fun.size_t_needed=true;
            fun.T_needed=false;
            break;
        case 17:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.DeleteBefore(i1);return nothing;}catch(const char* msg){throw msg;}};
            fun.type="DeleteBefore(1 argument)";
            fun.size_t_needed=true;
            fun.T_needed=false;
            break;
        case 18:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.SaveCSV("tabela");return nothing;}catch(const char* msg){throw msg;}};
            fun.type="SaveCSV";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        case 19:
            fun.func=[](AiSD::DLL& a,T t1,size_t i1){try{a.LoadCSV("tabela");return nothing;}catch(const char* msg){throw msg;}};
            fun.type="LoadCSV";
            fun.size_t_needed=false;
            fun.T_needed=false;
            break;
        default:
            throw "Invalid number of NO Function";
    }

    return fun;
}

AiSD::ClassTest::arg_t AiSD::ClassTest::DoFunction(DLL& arr,short int NO,T t,size_t i,bool debugMode)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    try{
        FunctionInfo f = FunctionByNO(NO);
        //podstawowe informacjedo logow
        std::stringstream ss;

        ss<<"Operation "<<f.type<<" ("<<NO<<")";
        if(f.T_needed||f.size_t_needed)
            ss<<" for arguments: ";
        if(f.T_needed)
            ss<<"T={name=\""<<t.name<<"\",grade="<<t.grade<<"}\t";
        if(f.size_t_needed)
            ss<<"size_t="<<i;
        ss<<std::endl<<"Array content: ";


        if(debugMode)
        {
            SetConsoleTextAttribute(hConsole, 5);
            std::cout<<std::endl<<"Operation ";
            SetConsoleTextAttribute(hConsole, 4);
            std::cout<<f.type;
            SetConsoleTextAttribute(hConsole, 5);
            std::cout<<" ("<<NO<<") ";
            if(f.T_needed||f.size_t_needed)
                std::cout<<"for arguments: ";
            SetConsoleTextAttribute(hConsole, 4);
            if(f.T_needed)
                std::cout<<"T={name=\""<<t.name<<"\",grade="<<t.grade<<"}\t";
            if(f.size_t_needed)
                std::cout<<"size_t="<<i;
            SetConsoleTextAttribute(hConsole, 5);
            std::cout<<std::endl<<"arr.Print():"<<std::endl;
            SetConsoleTextAttribute(hConsole, 3);
            try
            {
                arr.Print();
            }catch(const char* msg)
            {
                std::cout<<msg<<std::endl;
                TestingFunctionLogger.Log(msg);
            }

            //while(arr.lista!=NULL)
            //{
                //std::cout<<"name=\""<<arr.lista->pokazElement().name<<", grade="<<arr.lista->pokazElement().grade<<std::endl;
            //    ss<<arr.lista->pokazElement().name<<" ";
            //    ss<<arr.lista->pokazElement().grade<<";";
            //    arr.lista=arr.lista->pobierzWskaznikNaKolejnyElement();
            //}arr.lista=arr.head;
            SetConsoleTextAttribute(hConsole, 5);
            std::cout<<"SIZE OF ARRAY: "<<arr.Size()<<std::endl<<"arr."<<f.type<<"()"<<std::endl;
            SetConsoleTextAttribute(hConsole, 7);
        }
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
            TestingFunctionLogger.Log(msg);
        }
        auto endTime=clockH::now();
        std::string time=timeTook(startTime,endTime);

        //informacja o sukcesie
        if(debugMode)
        {
            SetConsoleTextAttribute(hConsole, 10);
            std::cout<<"Success"<<std::endl<<"Operation took "<<time<<" microsecounds"<<std::endl;
        }

        ss<<"Success. Took "<<time<<" microseconds; returned ";

        if (std::holds_alternative<bool>(v))
        {
            if(debugMode)std::cout<<"RETURN: "<<std::get<bool>(v)<<std::endl;
            ss<<std::get<bool>(v);
        }
        else if(std::holds_alternative<size_t>(v))
        {
            if(debugMode)std::cout<<"RETURN: "<<std::get<size_t>(v)<<std::endl;
            ss<<std::get<size_t>(v);
        }
        else
        {
            if(debugMode)std::cout<<"RETURN: Void"<<std::endl;
            ss<<"Void";
        }

        if(debugMode)SetConsoleTextAttribute(hConsole, 7);
        TestingFunctionLogger.Log(ss.str());
        return v;
    }catch (const char* msg)
    {
        throw msg;
    }
}

const int NOFunctions= 20;
//PIERWSZA FUNKCJA TESTUJACA

std::random_device rd;

//losowo wygenerowany string
std::string AiSD::DistortionsSimulation::randomStringGenerator()
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


void AiSD::DistortionsSimulation::test(bool debugMode)
{

    DLL* arr=pointer.get();
    TestingFunctionLogger.Log("-------------------------------------DistortionsSimulation");
    int ird=rd();
    std::stringstream ss;
    ss<<"Seed of DistortionsSimulation: "<<ird<<std::endl;
    TestingFunctionLogger.Log(ss.str());
    std::mt19937 gen(ird);
    //std::mt19937 gen(6);

    std::uniform_int_distribution<> dis1(-100, 1000);
    std::uniform_int_distribution<> dis2(0, NOFunctions);//dla czytelnosci print nie bedzie testowany


    for(int i=0;i<t;i++)
    {
        int a=dis2(gen);
        T b={randomStringGenerator(),dis1(gen)};
        size_t c=dis1(gen);

        try
        {
            DoFunction(*arr,a,b,c,debugMode);
        }catch(const char* msg)
        {
            TestingFunctionLogger.Log(msg);
            std::cout<<msg<<std::endl;
        }
    }
}
void AiSD::DistortionsSimulation::doMultipleTimes(unsigned int times,bool debugMode)
{
    std::cout<<std::endl<<"Random operations"<<std::endl<<"Please wait. Testing is in progress..."<<std::endl;
    std::streambuf *old = std::cout.rdbuf();
    for(unsigned int i=0;i<times;i++)
    {
        //TYMCZASOWE WYCISZANIE KONSOLI DLA DEBUGMODE=FALSE
        if (!debugMode)
        {
            std::cout<<char(219);
            std::cout.rdbuf(0);
        }
        else
        {
            std::cout<<"-------------"<<times<<"/"<<i<<std::endl;
        }

        test(debugMode);
        if (!debugMode) std::cout.rdbuf(old);
        //Blad krytyczny scrashuje program
    }std::cout<<std::endl<<"No problems found"<<std::endl;
    std::cout<<std::endl;
}
//DRUGA FUNKCJA TESTUJACA
void AiSD::OverflowTable::test(bool debugMode)
{
    std::streambuf *old = std::cout.rdbuf();
    DLL* arr=pointer.get();
    TestingFunctionLogger.Log("-------------------------------------OverflowTable");

    T arg1={"",0};



    size_t arg2=0;

    for(int NOI=0;NOI<4;NOI++)
    {
        auto f = FunctionByNO(NOI);

        TestingFunctionLogger.Log("Repeat "+f.type+" "+std::to_string(repeat)+" times");
        std::cout<<f.type;
        std::cout.rdbuf(0);

        //PESYMISTYCZNY SCENARIUSZ CZYLI NAJWIEKSZE LICZBY JAKIE MOGE WYKORZYSTAC
        if(NOI==5||NOI==7){arg1.grade=std::numeric_limits<unsigned>::max();arg2=arr->Size()-1;}; //MAKSYMALNA WARTOSC T
        auto startTime=clockH::now();

        for(size_t i=0;i<repeat;i++)
        {
            try
            {
                f.func(*arr,arg1,arg2);
            }catch(const char* msg)
            {
                std::cout.rdbuf(old);
                TestingFunctionLogger.Log("Unexpected error. "+std::string(msg)+". Problem was ignored");
                std::cout<<"Unexpected error. "<<msg<<". Problem was ignored"<<std::endl;
            }
        }
        std::cout.rdbuf(old);
        auto endTime=clockH::now();
        std::string time=timeTook(startTime,endTime);

        std::cout<<" "<<repeat<<" times took "<<time<<" microseconds"<<std::endl;

        TestingFunctionLogger.Log(std::to_string(repeat)+" times took "+time+" microseconds");
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

void AiSD::Presentation::test(bool debugMode)
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
        if(userInput1==NOFunctions)      //EXIT
        {
            SetConsoleTextAttribute(hConsole, 7);
            return;
        }

        T a1={"",0};
        size_t a2=0;



        FunctionInfo info;//zbieranie informacji o funkcji
        try
        {
            info = FunctionByNO(userInput1);
        }catch(const char* msg)
        {
            std::cout<<msg<<std::endl;
            TestingFunctionLogger.Log("Critical problem");
            TestingFunctionLogger.Log(msg);
            return;
        }

        if(info.T_needed)
        {
            std::cout<<"T.name=";
            getline(std::cin, a1.name);
            std::cout<<"T.grade=";
            a1.grade=getNum<unsigned>();
        }
        if(info.size_t_needed)
        {
            std::cout<<"size_t a2=";
            a2=getNum<size_t>();
        }
        SetConsoleTextAttribute(hConsole, 12);

        try{
            arg_t v;
            try
            {
                v=DoFunction(*arr,userInput1,a1,a2,debugMode);
            }catch(const char* msg)
            {
                std::cout<<msg<<std::endl;
                TestingFunctionLogger.Log(msg);
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
