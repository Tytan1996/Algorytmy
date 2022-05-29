/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef RBT_H
#define RBT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <concepts>

#include <cstdlib>

#include "simpleini/ini.h"

namespace AiSD
{

    enum Color
    {
        RED=0,
        BLACK=1,
        PINK=2
    };

    template <typename T>
    concept RightType =
    (requires(std::ostream& os, T a)//Drukowanie w oknie CMD
    {
        os << a;
    })
    &&
    (requires(std::stringstream& os, T a)//Zapis do pliku
    {
        os << a;
        os >> a;
    }
    )
    &&
    (requires(T a,T b)//Klucze sa porównywalne
    {
        a<b;
        a>b;
        a=b;
    }
    );


    template<RightType key_t,RightType data_t>
    class RBTNode
    {
        public:
        Color color;
        key_t key;
        data_t data;

        RBTNode(key_t k,data_t data);

        RBTNode* parent;
        RBTNode* left;
        RBTNode* right;
    };

    template<RightType key_t,RightType data_t>
    class RBT
    {
        private:
        AiSD::RBTNode<key_t,data_t>* Delete(AiSD::RBTNode<key_t,data_t>* subtree_root, key_t key);
        void FixInsert(RBTNode<key_t,data_t>* subtree_root);
        void FixDelete(RBTNode<key_t,data_t>* subtree_root);
        void rotateRight(RBTNode<key_t,data_t>* subtree_root);
        void rotateLeft(RBTNode<key_t,data_t>* subtree_root);

        public:
            void Insert(const key_t k,data_t data);//zbudblowane key beda po prawej stronie poddrzewa o tym samym key
            void Delete(const key_t k);

            RBTNode<key_t,data_t>* Search(const key_t k,RBTNode<key_t,data_t>* subtree_root=nullptr);
            void Clear(RBTNode<key_t,data_t>* node=nullptr);
            void Transplant(RBTNode<key_t,data_t>* u,RBTNode<key_t,data_t>* v);
            RBTNode<key_t,data_t>* Min(RBTNode<key_t,data_t>* subtree_root=nullptr);
            RBTNode<key_t,data_t>* Max(RBTNode<key_t,data_t>* subtree_root=nullptr);
            RBTNode<key_t,data_t>* Predecessor(const key_t k,RBTNode<key_t,data_t>* subtree_root=nullptr);
            RBTNode<key_t,data_t>* Successor(const key_t k,RBTNode<key_t,data_t>* subtree_root=nullptr);
            void PrintAscending(RBTNode<key_t,data_t> *node=nullptr,int deep=0);
            void VectorOfNodes(RBTNode<key_t,data_t> *node,std::vector<RBTNode<key_t,data_t>*>& vec);
            void VectorOfNodesAscending(RBTNode<key_t,data_t> *node,std::vector<RBTNode<key_t,data_t>*>& vec);
            void Save(std::string src);
            void Load(std::string src);

            void ListOfNodesInLevel(const int level,std::vector<AiSD::RBTNode<key_t,data_t>*>& table,AiSD::RBTNode<key_t,data_t>* node=nullptr);
            int height(RBTNode<key_t,data_t>* subtree_root=nullptr,int sum=0);
            int leavesCount(RBTNode<key_t,data_t>* subtree_root=nullptr);
            int nodesCount(RBTNode<key_t,data_t>* subtree_root=nullptr);
            int nodesCountOnLevel(const int level,RBTNode<key_t,data_t>* subtree_root=nullptr);//poziom root to liczymy jako 0

            void pointersInfo(RBTNode<key_t,data_t>* subtree_root);
            //metody MP
            void ShowRBTTree();
            void ShowRBT();

            void ReplaceColor(RBTNode<key_t,data_t>* subtree_root,Color newColor);
            Color WhatColorIs(RBTNode<key_t,data_t>* subtree_root);

            RBTNode<key_t,data_t> *root=nullptr;
    };


    //FUNKCJA DO KONWERSJI TYPOW
    template <RightType Type>
    Type convert(std::string str);
    template <RightType Type>
    std::string convertString(const Type val);
}




/*
To rozwiazanie znalazlem na stronie
https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
*/
#include "RBT.tpp"

#endif // RBT_H
