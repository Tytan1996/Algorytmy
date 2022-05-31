/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef TESTING_H
#define TESTING_H
#include <iostream>
#include <vector>
#include <RBT.h>
namespace AiSD {
class Testing {


    //    Color 0=RED  1=BLACK

public:
    void randing(size_t amountOfElements);
    int  rand(float mnoznik);
    void detailsTest();
    void generalTest();

private:
    std::vector< int > dane;
    RBT<int,std::string>test;
    RBTNode<int,std::string> *tmp;
    bool testInsert(int opcja, RBTNode<int,std::string> *tmp);
    bool testDelete(int opcja);
    bool testClear();
    bool testMin();
    bool testMax();
    bool sprawdWskazniki();
    int maly;
    int maly1;
    int duzy;

};
}
#endif // TESTING_H
