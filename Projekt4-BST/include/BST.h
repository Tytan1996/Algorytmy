/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <concepts>

#include "simpleini/ini.h"

namespace AiSD
{

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
    class BSTNode
    {
        public:
        key_t key;
        data_t data;

        BSTNode(key_t k,data_t data);

        BSTNode* parent;
        BSTNode* left;
        BSTNode* right;
    };

    template<RightType key_t,RightType data_t>
    class BST
    {

        public:
            void Insert(const key_t k,data_t data);//zbudblowane key beda po prawej stronie poddrzewa o tym samym key
            void Delete(const key_t k);
            BSTNode<key_t,data_t>* Search(const key_t k,BSTNode<key_t,data_t>* subtree_root=nullptr);
            void Clear(BSTNode<key_t,data_t>* node=nullptr);
            void Transplant(BSTNode<key_t,data_t>* u,BSTNode<key_t,data_t>* v);
            BSTNode<key_t,data_t>* Min(BSTNode<key_t,data_t>* subtree_root=nullptr);
            BSTNode<key_t,data_t>* Max(BSTNode<key_t,data_t>* subtree_root=nullptr);
            BSTNode<key_t,data_t>* Predecessor(const key_t k,BSTNode<key_t,data_t>* subtree_root=nullptr);
            BSTNode<key_t,data_t>* Successor(const key_t k,BSTNode<key_t,data_t>* subtree_root=nullptr);
            void PrintAscending(BSTNode<key_t,data_t> *node=nullptr,int deep=0);
            void VectorOfNodes(BSTNode<key_t,data_t> *node,std::vector<BSTNode<key_t,data_t>*>& vec);
            void VectorOfNodesAscending(BSTNode<key_t,data_t> *node,std::vector<BSTNode<key_t,data_t>*>& vec);
            void Save(std::string src);
            void Load(std::string src);

            void ListOfNodesInLevel(const int level,std::vector<AiSD::BSTNode<key_t,data_t>*>& table,AiSD::BSTNode<key_t,data_t>* node=nullptr);
            int height(BSTNode<key_t,data_t>* subtree_root=nullptr,int sum=0);
            int leavesCount(BSTNode<key_t,data_t>* subtree_root=nullptr);
            int nodesCount(BSTNode<key_t,data_t>* subtree_root=nullptr);
            int nodesCountOnLevel(const int level,BSTNode<key_t,data_t>* subtree_root=nullptr);//poziom root to liczymy jako 0

            void pointersInfo(BSTNode<key_t,data_t>* subtree_root);
            //metody MP
            void ShowBSTTree();
            void ShowBST();

            BSTNode<key_t,data_t> *root=nullptr;
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
#include "BST.tpp"

#endif // BST_H
