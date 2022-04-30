/*


*/
#ifndef TESTING_H
#define TESTING_H
#include <iostream>
namespace AiSD{
class Testing
{
    public:
        void randing(size_t amountOfElements);
        void detailsTest();
        void generalTest();


    private:
        bool testInsert();
        bool testDelete();
        bool testClear();
        bool testMin();
        bool testMax();

};
}
#endif // TESTING_H
