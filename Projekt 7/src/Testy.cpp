#include "Testy.hpp"

using clockH=std::chrono::high_resolution_clock;

/*Funkcja przeznaczona do narysowania wykresow*/
std::random_device rd;
void AiSD::testing()
{
    std::cout<<"Te dane nalezy wpisac do generatora wykresow"<<std::endl;
    std::cout<<"RodCut"<<std::endl;
    int ird=rd();
    std::mt19937 gen(ird);
    std::uniform_int_distribution<> dis(1, 1000);

    std::cout<<std::endl<<"RodCutRecursive"<<std::endl;
    AiSD::tab p;
    //pomiar czasu
    for(int i=0;i<300;i++)
    {
        p.push_back(dis(gen));
        auto a=clockH::now();
        AiSD::RodCutRecursive(p,p.size(),0);
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
        if(std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()>300)
            break;
    }
    p.clear();

    std::cout<<std::endl<<"RodCutRecursiveMem"<<std::endl;
    for(int i=0;i<300;i++)
    {
        p.push_back(dis(gen));
        auto a=clockH::now();
        AiSD::RodCutRecursiveMem(p,p.size(),0);
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
    }
    p.clear();

    std::cout<<std::endl<<"RodCutBottomUp"<<std::endl;
    for(int i=0;i<300;i++)
    {
        p.push_back(dis(gen));
        auto a=clockH::now();
        AiSD::RodCutBottomUp(p,p.size(),0);
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Podtytul wykresu"<<std::endl;
    for(int i=0;i<300;i++)
        std::cout<<i+1<<" ";
    p.clear();
    std::cout<<std::endl;







    std::cout<<std::endl<<"Matrix"<<std::endl;
    dim_arr Macierz;
    for(int i=0;i<20;i++)
    {
        Macierz.push_back(dis(gen));
        cost_arr cost1;
        cost1.resize(Macierz.size());
        for(auto& el: cost1){
            el.resize(Macierz.size());
        }
        pos_arr bracket_pos1;
        bracket_pos1.resize(Macierz.size()-1);
        for(auto& el: bracket_pos1){
            el.resize(Macierz.size());
        }
        auto a=clockH::now();
        MatrixChainOrder( Macierz,cost1,bracket_pos1 );
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
    }
    Macierz.clear();

    Macierz.push_back(dis(gen));
    std::cout<<std::endl<<"Memory"<<std::endl;
    for(int i=0;i<20;i++)
    {
        Macierz.push_back(dis(gen));
        cost_arr cost1;
        cost1.resize(Macierz.size());
        for(auto& el: cost1){
            el.resize(Macierz.size());
        }
        pos_arr bracket_pos1;
        bracket_pos1.resize(Macierz.size()-1);
        for(auto& el: bracket_pos1){
            el.resize(Macierz.size());
        }
        auto a=clockH::now();
        MatrixChainResursive1( Macierz,cost1,bracket_pos1 );
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
    }
    Macierz.clear();





    std::cout<<std::endl<<"CiagFic"<<std::endl;
    for(int i=0;i<30;i++)
    {
        auto a=clockH::now();
        CiagFic(i);
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
    }
    std::cout<<std::endl<<"CiagFic1"<<std::endl;
    for(int i=0;i<30;i++)
    {
        auto a=clockH::now();
        CiagFic1(i);
        auto b=clockH::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(b-a).count()<<" ";
    }
}
