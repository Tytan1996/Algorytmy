#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    std::cout<<"INSERT"<<std::endl;
    AiSD::BST<int> BT;
    BT.Insert(10,5);
    BT.Insert(10,5);
    BT.Insert(2,5);
    std::cout<<"MIN"<<std::endl;
    BT.Min();
    std::cout<<"MAX"<<std::endl;
    BT.Max();
    std::cout<<"DELETE"<<std::endl;
    BT.Delete(10);
    std::cout<<"CLEAR"<<std::endl;
    BT.Clear();
    std::cout<<"INSERT"<<std::endl;
    BT.Insert(1,5);
    BT.Insert(4,5);
    BT.PrintFromLeftBottom();
    return 0;
}
