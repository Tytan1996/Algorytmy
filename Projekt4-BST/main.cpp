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
    AiSD::Testing testy;
    testy.detailsTest();


    std::cout<<"INSERT"<<std::endl;
    AiSD::BST<int,string> BT;
    BT.Insert(10,"text A");
    BT.Insert(5,"text B");
    BT.Insert(2,"text C");
    std::cout<<"INSERT"<<std::endl;
    BT.Insert(1,"text E");
    BT.Insert(4,"text F");
    //std::cout<<BT.Max()->key<<'\n';
    BT.Save("file.ini");
    BT.Load("file.ini");
    std::cout<<"Predecessor"<<std::endl;
    BT.Predecessor(1);
    std::cout<<"Successor"<<std::endl;
    BT.Successor(4);
    std::cout<<"PRINT drzewo"<<std::endl;
    BT.ShowBSTTree();
    BT.ShowBST();
    std::cout<<"PRINT"<<std::endl;
    BT.PrintAscending();
    std::cout<<"MIN"<<std::endl;
    std::cout<<BT.Min()->key<<'\n';

    std::cout<<"MAX"<<std::endl;
    std::cout<<BT.Max()->key<<'\n';
    std::cout<<"DELETE"<<std::endl;
    BT.Delete(10);
    //BT.ShowBSTTree();
    //BT.ShowBST();
    std::cout<<"CLEAR"<<std::endl;
    BT.Clear();

    return 0;
}
