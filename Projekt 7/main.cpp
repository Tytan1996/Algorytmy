#include <iostream>
#include "RodCut.hpp"

using namespace std;

int main()
{
    AiSD::tab p{1,5,3,6,3,8};
    AiSD::num n=p.size();
    AiSD::price k=1;
    std::cout<<"Rod Cut rekurencyjnie: "<<AiSD::RodCutRecursive(p,n,k)<<"\n";
    std::cout<<"Rod Cut rekurencyjnie ze spamietywaniem: "<<AiSD::RodCutRecursiveMem(p,n,k)<<"\n";
    std::cout<<"Rod Cut Rekurencyjnie: "<<AiSD::RodCutBottomUp(p,n,k)<<"\n";
    AiSD::printPossibilities(p,n,k);
    return 0;
}