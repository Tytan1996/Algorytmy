/*


*/
#ifndef TESTING_H
#define TESTING_H
#include <iostream>
#include <vector>
#include <BST.h>
namespace AiSD {
class Testing {
public:
    void randing(size_t amountOfElements);
    int  rand(float mnoznik);
    void detailsTest();
    void generalTest();
//        RED=0,BLACK=1

private:
    std::vector< int > dane;
    BST<int,std::string>test;
    BSTNode<int,std::string> *tmp;
    bool testInsert(int opcja, BSTNode<int,std::string> *tmp);
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
