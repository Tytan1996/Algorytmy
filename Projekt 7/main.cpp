#include <iostream>
#include "RodCut.hpp"

using namespace std;

int main()
{
    // 1 2 3 4
    // 1 5 3 6
    //n=4 wynik=10

    AiSD::tab a{1,5,3,6};
    std::cout<<AiSD::RodCutRecursive(a,4)<<"\n";

    return 0;
}
