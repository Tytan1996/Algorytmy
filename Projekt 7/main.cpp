#include <iostream>
#include "RodCut.hpp"
#include "macierz.h"
#include "fibonacco.h"



int main()
{
    //AiSD::testing();

    AiSD::tab p{2,5,3,2};

    AiSD::num n=p.size();
    AiSD::price k=1;
    std::cout<<"Rod Cut rekurencyjnie: "<<AiSD::RodCutRecursive(p,n,k)<<"\n";
    std::cout<<"Rod Cut rekurencyjnie ze spamietywaniem: "<<AiSD::RodCutRecursiveMem(p,n,k)<<"\n";
    std::cout<<"Rod Cut Rekurencyjnie: "<<AiSD::RodCutBottomUp(p,n,k)<<"\n";
    AiSD::printPossibilities(p,n,k);
    std::cout<<"\nRekurencja ze spametywaniem: \n";
    AiSD::calculateMatrixMemory();
    std::cout<<"\nZwykla rekurencja: \n";
    AiSD::calculateMatrix();
    std::cout<<"\n\nCiag Fibaccaniego: \n";
    std::cout<<"20 liczba ciagu Fibocannego (rekurencja): "<<AiSD::CiagFic(20);
    std::cout<<"\n50 liczba ciagu Fibocannego (iteracyjne): "<<AiSD::CiagFic1(50);
    std::cout<<'\n';
    return 0;
}
