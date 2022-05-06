/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <vector>
#include "simpleini/ini.h"

//using key_t=unsigned short;

namespace AiSD
{
    template<typename key_t,typename data_t>
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

    template<typename key_t,typename data_t>
    class BST
    {

        public:
            void Insert(const key_t k,data_t data);
            void Delete(const key_t k);
            BSTNode<key_t,data_t>* Search(const key_t k);
            BSTNode<key_t,data_t>* Search(const key_t k,BSTNode<key_t,data_t>* subtree_root);
            void Clear();
            void Clear(BSTNode<key_t,data_t>* node);
            void Transplant(BSTNode<key_t,data_t>* u,BSTNode<key_t,data_t>* v);
            BSTNode<key_t,data_t>* Min();
            BSTNode<key_t,data_t>* Min(BSTNode<key_t,data_t>* subtree_root);
            BSTNode<key_t,data_t>* Max();
            BSTNode<key_t,data_t>* Max(BSTNode<key_t,data_t>* subtree_root);
            BSTNode<key_t,data_t>* Predecessor(const key_t k);
            BSTNode<key_t,data_t>* Predecessor(const key_t k,BSTNode<key_t,data_t>* subtree_root);
            BSTNode<key_t,data_t>* Successor(const key_t k);
            BSTNode<key_t,data_t>* Successor(const key_t k,BSTNode<key_t,data_t>* subtree_root);
            void PrintAscending(BSTNode<key_t,data_t> *node=nullptr);
            void VectorOfNodes(BSTNode<key_t,data_t> *node,std::vector<BSTNode<key_t,data_t>>& vec);
            void Save(std::string src);
            void Load(std::string src);

            //metody MP
            void ShowBSTTree();
            void ShowBST();


        //protected:
            BSTNode<key_t,data_t> *root=nullptr;
        private:
    };


    //FUNKCJA DO KONWERSJI TYPOW
    template <typename Type>
    Type convert(std::string str);
    template <typename Type>
    std::string convertString(const Type val);
}




/*
To rozwiazanie znalazlem na stronie
https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
*/
#include "BST.tpp"

#endif // BST_H
