/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    std::cout<<"INSERT"<<std::endl;
    AiSD::BST<int,string> BT;
    BT.Insert(10,"text A");
    BT.Insert(2,"text B");
    BT.Insert(2,"text C");
    std::cout<<"INSERT"<<std::endl;
    BT.Insert(1,"text E");
    BT.Insert(4,"text F");
    BT.Save("file.ini");
    BT.Load("file.ini");
    std::cout<<"Predecessor"<<std::endl;
    BT.Predecessor(1);
    std::cout<<"Successor"<<std::endl;
    BT.Successor(4);

    std::cout<<"PRINT"<<std::endl;
    BT.PrintAscending();

    std::cout<<"BT height "<<BT.height()<<std::endl;
    std::cout<<"BT leavesCount "<<BT.leavesCount()<<std::endl;
    std::cout<<"BT nodesCount "<<BT.nodesCount()<<std::endl;
    std::cout<<"BT nodesCountOnLevel "<<BT.nodesCountOnLevel(3)<<std::endl;

    std::cout<<"PRINT drzewo"<<std::endl;
    BT.ShowBSTTree();
    BT.ShowBST();

    std::cout<<"MIN"<<std::endl;
    BT.Min();
    std::cout<<"MAX"<<std::endl;
    BT.Max();
    std::cout<<"DELETE"<<std::endl;
    BT.Delete(10);
    std::cout<<"CLEAR"<<std::endl;
    BT.Clear();
    std::vector<AiSD::BSTNode<int,string>*> tab;
    BT.ListOfNodesInLevel(0,tab);


    return 0;
}
