#ifndef BST_TPP
#define BST_TPP

template <typename T>
AiSD::BSTNode<T>::BSTNode(key_t k,T dataArg)
{
    parent=nullptr;
    left=nullptr;
    right=nullptr;
    key=k;
    data=dataArg;
}

template <typename T>
void AiSD::BST<T>::Insert(const key_t k,T data)
{
    if(Search(k)!=nullptr)
    {
        std::cout<<"This key is already taken! ("<<k<<")"<<std::endl;
        return;
    }
    BSTNode<T>* newNode=new BSTNode<T>(k,data);
    BSTNode<T>* tmp=root;
    BSTNode<T>* prev=nullptr;

    while(tmp!=nullptr)
    {
        prev=tmp;

        if(newNode->key<tmp->key)
            tmp=tmp->left;
        else
            tmp=tmp->right;

    }
    newNode->parent=prev;
    if(root==nullptr)
    {
        root=newNode;
    }else
    {
        if(newNode->key<prev->key)
            prev->left=newNode;
        else
            prev->right=newNode;
    }
}


template <typename T>
void AiSD::BST<T>::Transplant(BSTNode<T>* u,BSTNode<T>* v)
{
    if(u->parent==nullptr)
    {
        root=v;
    }else
    {
        if(u==u->parent->left)
            u->parent->left=v;
        else
            u->parent->right=v;
        if(v!=nullptr)
            v->parent=u->parent;
    }
}

template <typename T>
void AiSD::BST<T>::PrintFromLeftBottom(BSTNode<T> *node)
{
    if(node==nullptr)
        node=root;
    if(node->left!=nullptr)
        PrintFromLeftBottom(node->left);
    if(node->right!=nullptr)
        PrintFromLeftBottom(node->right);
    std::cout<<"node={key="<<node->key<<" data="<<node->data<<"}"<<std::endl;
}

template <typename T>
void AiSD::BST<T>::Delete(const key_t k)
{
    BSTNode<T>* x=Search(k);
    if(x->left==nullptr)
    {
        Transplant(x,x->right);
    }else
    {
        if(x->right==nullptr)
        {
            Transplant(x,x->left);
        }else
        {
            BSTNode<T>* y=Min(x->right);
            if(y->parent!=x)
            {
                Transplant(y,y->right);
                y->right=x->right;
                y->right->parent=y;
            }
            Transplant(x,y);
            y->left=x->left;
            y->left->parent=y;
        }
    }
    delete(x);
}

template <typename T>
AiSD::BSTNode<T>* AiSD::BST<T>::Search(const key_t k)
{
    BSTNode<T>* tmp=root;
    while(tmp!=nullptr && k != tmp->key)
    {
        if(k<tmp->key)
            tmp=tmp->left;
        else
            tmp=tmp->right;
    }
    return tmp;
}


template <typename T>
void AiSD::BST<T>::Clear()
{
    Clear(root);
    root=nullptr;
}

template <typename T>
void AiSD::BST<T>::Clear(AiSD::BSTNode<T>* node)
{
    if(node->left!=nullptr)
        Clear(node->left);
    if(node->right!=nullptr)
        Clear(node->right);
    delete(node);
}

template <typename T>
AiSD::BSTNode<T>* AiSD::BST<T>::Min()
{
    BSTNode<T>* tmp=root;
    while(tmp!=nullptr&&tmp->left == nullptr)
        tmp=tmp->left;
    return tmp;

}

template <typename T>
AiSD::BSTNode<T>* AiSD::BST<T>::Min(BSTNode<T>* subtree_root)
{

}

template <typename T>
AiSD::BSTNode<T>* AiSD::BST<T>::Max()
{
    BSTNode<T>* tmp=root;
    while(tmp!=nullptr&&tmp->right==nullptr)
        tmp=tmp->right;
    return tmp;
}

template <typename T>
AiSD::BSTNode<T>* AiSD::BST<T>::Predecessor(const key_t k)
{
    BSTNode<T>* x=Search(k);
    if(x.left!=nullptr)
        return Max(x.right);
    BSTNode<T>* y=x.parent;
    while(y==nullptr&&x==y.left)
    {
        x=y;
        y=y.parent;
    }
    return y;
}

template <typename T>
AiSD::BSTNode<T>* AiSD::BST<T>::Successor(const key_t k)
{
    BSTNode<T>* x=Search(k);
    if(x.right!=nullptr)
        return Min(x.right);
    BSTNode<T>* y=x.parent;
    while(y==nullptr&&x==y.right)
    {
        x=y;
        y=y.parent;
    }
    return y;
}


#endif // BST_TPP
