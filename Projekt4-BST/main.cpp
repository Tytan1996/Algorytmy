#include <iostream>
#include "Testing.h"
using namespace std;

int main()
{
    AiSD::Testing test;
    size_t liczba;
    std::cin>>liczba;
    test.randing(liczba);
    return 0;
}
