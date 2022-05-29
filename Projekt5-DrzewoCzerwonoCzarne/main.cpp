/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#include <iostream>
#include "BST.h"
#include "Testing.h"

using namespace std;

int main() {
    int option, number;
    string text="";
    AiSD::BST<int,string> BT;
    std::cout<<"TESTY"<<'\n';
    AiSD::Testing testy;
    testy.detailsTest();

    BT.Insert(10,"10a");
    BT.Insert(5,"5aa");
    BT.Insert(15,"15a");
    BT.Delete(10);
    std::cout<<"5\n";
    BT.pointersInfo(BT.Search(5));
    std::cout<<"15\n";
    BT.pointersInfo(BT.Search(15));
    BT.ShowBSTTree();
    std::cout<<std::endl<<std::endl<<std::endl;
    BT.Insert(5,"5bb");
    BT.ShowBSTTree();
    BT.pointersInfo(BT.Search(5)->right);


    AiSD::BSTNode<int,string> *act;//tu przechowywane beda wskazniki do min/max

    std::cout<<'\n'<<"-------------------------"<<'\n';
    //testy.generalTest();
    std::cout<<'\n'<<"-------------------------"<<'\n';
    std::cout<<"Koniec testow";
    std::cout<<'\n'<<"-------------------------"<<'\n';

    //MENU//
    std::cout<<"-------------------------"<<'\n';
    std::cout<<"MENU"<<'\n';
    std::cout<<"-------------------------"<<'\n';
    while(true){
        std::cout<<"1 - INSERT (dodaj);"<<'\n';
        std::cout<<"2 - DELETE (usun);"<<'\n';
        std::cout<<"3 - SHOW BST (TREE) (pokaz drzewo w formie drzewa);"<<'\n';
        std::cout<<"4 - SHOW BST (pokaz drzewo);"<<'\n';
        std::cout<<"5 - SHOW HEIGHT BST (pokaz wysokosc BST);"<<'\n';
        std::cout<<"6 - SHOW AMOUNT LEAVES (pokaz ilosc lisci BST);"<<'\n';
        std::cout<<"7 - SHOW AMOUNT NODES (pokaz ilosc wiezlow BST);"<<'\n';
        std::cout<<"8 - SHOW AMOUNT NODES ON LEVEL (pokaz ilosc wiezlow BST od poziomu);"<<'\n';
        std::cout<<"9 - SHOW MIN (pokaz min);"<<'\n';
        std::cout<<"10 - SHOW MAX (pokaz max);"<<'\n';
        std::cout<<"11 - SAVE (zapis);"<<'\n';
        std::cout<<"12 - LOAD (wczytaj);"<<'\n';
        std::cout<<"13 - BST CLEAR;"<<'\n';
        std::cout<<"14 - SHOW Predecessor;"<<'\n';
        std::cout<<"15 - SHOW Successor;"<<'\n';
        std::cout<<"16 - Print Ascending;"<<'\n';
        std::cout<<"0 - EXIT;"<<'\n';
        std::cin>>option;
        switch(option){
        case 1:
            std::cout<<"Dodaj wartosc elemetnu (int): ";
            std::cin>>number;
            std::cout<<"Dodaj wartosc elemetnu (string): ";
            std::cin>>text;
            BT.Insert(number,text);
            break;
        case 2:
            std::cout<<"Jaki element chcesz usunac (podaj int): ";
            std::cin>>number;
            BT.Delete(number);
            break;
        case 3:
            BT.ShowBSTTree();
            break;
        case 4:
            BT.ShowBST();
            break;
        case 5:
            std::cout<<"Wysokosc: "<<BT.height();
            break;
        case 6:
            std::cout<<"Ilosc lisci: "<<BT.leavesCount();
            break;
        case 7:
            std::cout<<"Ilosc wezlow: "<<BT.nodesCount();
            break;
        case 8:
            std::cout<<"od jakiego poziomu wyswietlisc ilosc wezlow: ";
            std::cin>>number;
            std::cout<<"Wysokosc (od poziomu "<<number<<" ): "<<BT.nodesCountOnLevel(number);
            break;
        case 9:
            act=BT.Min();

            if(act!=nullptr)
            {
                std::cout<<"Najmniejszy element: "<<act;
                std::cout<<std::endl<<act->key<<"\t"<<act->data<<std::endl;
            }else
            {
                std::cout<<"NIE ISTNIEJE"<<std::endl;
            }
            break;
        case 10:
            act=BT.Max();
            if(act!=nullptr)
            {
                std::cout<<"Najwiekszy element: "<<act;
                std::cout<<std::endl<<act->key<<"\t"<<act->data<<std::endl;
            }else
            {
                std::cout<<"NIE ISTNIEJE"<<std::endl;
            }
            break;
        case 14:
            std::cout<<"Szukaj od klucza (int): ";
            std::cin>>number;
            act=BT.Predecessor(number);
            if(act!=nullptr)
            {
                std::cout<<"Predecessor element: "<<act;
                std::cout<<std::endl<<act->key<<"\t"<<act->data<<std::endl;
            }else
            {
                std::cout<<"NIE ISTNIEJE"<<std::endl;
            }
            break;
        case 15:
            std::cout<<"Szukaj od klucza (int): ";
            std::cin>>number;
            act=BT.Successor(number);
            if(act!=nullptr)
            {
                std::cout<<"Successor element: "<<act;
                std::cout<<std::endl<<act->key<<"\t"<<act->data<<std::endl;
            }else
            {
                std::cout<<"NIE ISTNIEJE"<<std::endl;
            }
            break;
        case 11:
            BT.Save("file.ini");
            std::cout<<"Zapisano do pliku;";
            break;
        case 12:
            BT.Load("file.ini");
            std::cout<<"Wczytano plik;";
            break;
        case 13:
            BT.Clear();
            std::cout<<"Dziewo jest puste";
            break;
        case 16:
            BT.PrintAscending();
            break;
        case 0:
            std::cout<<"koniec";
            return 0;
            break;
        default:
            std::cout<<"Nie ma takiej opcji!";
            break;
        }
        std::cout<<'\n';
    }

    return 0;
}