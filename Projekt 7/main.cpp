#include <iostream>
#include "RodCut.hpp"


int main()
{
    AiSD::num n=8;
    AiSD::tab a{1,5,3,6,10,6,5,8};
    std::cout<<"Rod Cut rekurencyjnie: "<<AiSD::RodCutRecursive(a,n)<<"\n";
    std::cout<<"Rod Cut rekurencyjnie ze spamietywaniem: "<<AiSD::RodCutRecursiveMem(a,n)<<"\n";
    std::cout<<"Rod Cut Rekurencyjnie: "<<AiSD::RodCutBottomUp(a,n)<<"\n";
    AiSD::printPossibilities(a,n);
    return 0;
}
