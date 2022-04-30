#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    AiSD::BST<int> BT;
    BT.Insert(10,5);
    BT.Insert(5,5);
    BT.Insert(2,5);
    BT.Insert(1,5);
    BT.Insert(4,5);
    BT.PrintFromLeftBottom();
    return 0;
}
