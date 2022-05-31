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
        using Node=AiSD::RBTNode<key_t,data_t>;
        Node* Delete(Node* subtree_root, key_t key);
        void FixInsert(Node* subtree_root);
        void FixDelete(Node* subtree_root);
        void rotateRight(Node* subtree_root);
        void rotateLeft(Node* subtree_root);

        public:

            void Insert(const key_t k,data_t data);//zbudblowane key beda po prawej stronie poddrzewa o tym samym key
            void Delete(const key_t k);

            Node* Search(const key_t k,Node* subtree_root=nullptr);
            void Clear(Node* node=nullptr);
            void Transplant(Node* u,Node* v);
            Node* Min(Node* subtree_root=nullptr);
            Node* Max(Node* subtree_root=nullptr);
            Node* Predecessor(const key_t k,Node* subtree_root=nullptr);
            Node* Successor(const key_t k,Node* subtree_root=nullptr);
            void PrintAscending(Node *node=nullptr,int deep=0);
            void VectorOfNodes(Node *node,std::vector<Node*>& vec);
            void VectorOfNodesAscending(Node *node,std::vector<Node*>& vec);
            void Save(std::string src);
            void Load(std::string src);

            void ListOfNodesInLevel(const int level,std::vector<Node*>& table,Node* node=nullptr);
            int height(Node* subtree_root=nullptr,int sum=0);
            int leavesCount(Node* subtree_root=nullptr);
            int nodesCount(Node* subtree_root=nullptr);
            int nodesCountOnLevel(const int level,Node* subtree_root=nullptr);//poziom root to liczymy jako 0

            void pointersInfo(Node* subtree_root);
            //metody MP
            void ShowRBTTree();
            void ShowRBT();
            void SaveRBTTREE();

            void ReplaceColor(Node* subtree_root,Color newColor);
            Color WhatColorIs(Node* subtree_root);

            Node *root=nullptr;
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
