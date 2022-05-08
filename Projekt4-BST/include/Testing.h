/*


*/
#ifndef TESTING_H
#define TESTING_H
#include <iostream>
#include <vector>
#include <BST.h>
namespace AiSD{
class Testing
{
    public:
        void randing(size_t amountOfElements);
        int  rand(float mnoznik);
        void detailsTest();
        void generalTest();


    private:
        std::vector< int > dane;
        BST<int,std::string>test;
        BSTNode<int,std::string> *tmp;
        bool testInsert(int opcja, BSTNode<int,std::string> *tmp);
        bool testDelete(int opcja);
        bool testClear();
        bool testMin();
        bool testMax();

};
}
#endif // TESTING_H
