/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#include <iostream>
#include "BST.h"
#include "Testing.h"

using namespace std;

int main()
{
    std::cout<<"TESTY"<<'\n';
    AiSD::Testing testy;
    testy.detailsTest();

    std::cout<<std::endl;



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
    BT.Delete(10);

    std::cout<<"PRINT"<<std::endl;
    BT.PrintAscending();

    std::cout<<"BT height "<<BT.height()<<std::endl;
    std::cout<<"BT leavesCount "<<BT.leavesCount()<<std::endl;
    std::cout<<"BT nodesCount "<<BT.nodesCount()<<std::endl;
    std::cout<<"BT nodesCountOnLevel "<<BT.nodesCountOnLevel(3)<<std::endl;

    std::cout<<"PRINT drzewo"<<std::endl;
    BT.ShowBSTTree();
    BT.ShowBST();



    BT.pointersInfo(BT.root->right);


    std::cout<<"MIN "<<BT.Min()->key<<std::endl;
    std::cout<<"MAX "<<BT.Max()->key<<std::endl;
    std::cout<<"DELETE"<<std::endl;
    BT.Delete(10);
    std::cout<<"CLEAR"<<std::endl;
    BT.Clear();
    std::vector<AiSD::BSTNode<int,string>*> tab;
    BT.ListOfNodesInLevel(0,tab);


    return 0;
}
