#ifndef BST_H
#define BST_H

#include <iostream>

using key_t=unsigned short;

namespace AiSD
{
    template<typename T>
    class BSTNode
    {
        public:
        key_t key;
        T data;

        BSTNode(key_t k,T data);

        BSTNode* parent;
        BSTNode* left;
        BSTNode* right;
    };

    template<typename T>
    class BST
    {

        public:
            void Insert(const key_t k,T data);
            void Delete(const key_t k);
            BSTNode<T>* Search(const key_t k);
            void Clear();
            void Transplant(BSTNode<T>* u,BSTNode<T>* v);
            BSTNode<T>* Min();
            BSTNode<T>* Min(BSTNode<T>* subtree_root);
            BSTNode<T>* Max();
            BSTNode<T>* Predecessor(const key_t k);
            BSTNode<T>* Successor(const key_t k);
            void PrintFromLeftBottom(BSTNode<T> *node=nullptr);
        protected:
            BSTNode<T> *root=nullptr;
        private:
    };

}


/*
To rozwiazanie znalazlem na stronie
https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
*/
#include "BST.tpp"

#endif // BST_H
