/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef BST_TPP
#define BST_TPP

#include <queue>

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>::BSTNode(key_t k,data_t dataArg)
{
    parent=nullptr;
    left=nullptr;
    right=nullptr;
    key=k;
    data=dataArg;
}

template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Insert(const key_t k,data_t data)
{
    if(Search(k)!=nullptr)
    {
        std::cout<<"This key is already taken! ("<<k<<")"<<std::endl;
        return;
    }
    BSTNode<key_t,data_t>* newNode=new BSTNode<key_t,data_t>(k,data);
    BSTNode<key_t,data_t>* tmp=root;
    BSTNode<key_t,data_t>* prev=nullptr;

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


template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Transplant(BSTNode<key_t,data_t>* u,BSTNode<key_t,data_t>* v)
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

template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::PrintAscending(BSTNode<key_t,data_t> *node)
{
    if(node==nullptr)
        node=root;
    if(node->left!=nullptr)
        PrintAscending(node->left);
    std::cout<<"node={key="<<node->key<<" data=\""<<node->data<<"\"}"<<std::endl;
    if(node->right!=nullptr)
        PrintAscending(node->right);
}
template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::VectorOfNodes(BSTNode<key_t,data_t> *node,std::vector<BSTNode<key_t,data_t>>& vec)
{
    if(node==nullptr)
        return;
    vec.push_back(*node);
    if(node->left!=nullptr)
        VectorOfNodes(node->left,vec);
    if(node->right!=nullptr)
        VectorOfNodes(node->right,vec);
}

template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Delete(const key_t k)
{
    BSTNode<key_t,data_t>* x=Search(k);
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
            BSTNode<key_t,data_t>* y=Min(x->right);
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

template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Save(std::string src)
{
    mINI::INIFile file(src);
    mINI::INIStructure ini;
    file.read(ini);
    ini.clear();//jezeli cos tu juz jest to to usun

    std::vector<BSTNode<key_t,data_t>> vec;
    VectorOfNodes(root,vec);
    for(int i=0;i<vec.size();i++)
    {
        ini[std::to_string(i)]["key"] = convertString<key_t>(vec[i].key);
        ini[std::to_string(i)]["data"] = convertString<data_t>(vec[i].data);
    }
    file.write(ini);
}
template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Load(std::string src)
{
    Clear();//usun dotychczasowa zawartosc BST
    mINI::INIFile file(src);std::cout<<"PRINT"<<std::endl;
    mINI::INIStructure ini;
    file.read(ini);

    for(int i=0;true;i++)
    {
        if(ini.has(std::to_string(i)))
        {
            key_t cpyKey=convert<key_t>(ini[std::to_string(i)]["key"]);
            data_t cpyData=convert<data_t>(ini[std::to_string(i)]["data"]);
            Insert(cpyKey,cpyData);
        }else
        {
            break;
        }
    }

}
template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Search(const key_t k,BSTNode<key_t,data_t>* subtree_root)
{
    while(subtree_root!=nullptr && k != subtree_root->key)
    {
        if(k<subtree_root->key)
            subtree_root=subtree_root->left;
        else
            subtree_root=subtree_root->right;
    }
    return subtree_root;
}

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Search(const key_t k)
{
    Search(k,root);
}


template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Clear()
{
    Clear(root);
    root=nullptr;
}

template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::Clear(AiSD::BSTNode<key_t,data_t>* node)
{
    if(node==nullptr)
        return;
    if(node->left!=nullptr)
        Clear(node->left);
    if(node->right!=nullptr)
        Clear(node->right);
    delete(node);
}

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Min()
{
    return Min(root);
}

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Min(BSTNode<key_t,data_t>* subtree_root)
{
    while(subtree_root!=nullptr&&subtree_root->left == nullptr)
        subtree_root=subtree_root->left;
    return subtree_root;
}

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Max()
{
    return Max(root);
}

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Max(BSTNode<key_t,data_t>* subtree_root)
{
    while(subtree_root!=nullptr&&subtree_root->right==nullptr)
        subtree_root=subtree_root->right;
    return subtree_root;
}

template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Predecessor(const key_t k,BSTNode<key_t,data_t>* subtree_root)
{
    BSTNode<key_t,data_t>* x=Search(k,subtree_root);
    if(x==nullptr)
    {
        std::cout<<"Key dont exist!"<<std::endl;
        return nullptr;
    }
    if(x->left!=nullptr)
        return Max(x->right);
    BSTNode<key_t,data_t>* y=x->parent;
    while(y!=nullptr&&x==y->left)
    {
        x=y;
        y=y->parent;
    }
    return y;
}
template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Predecessor(const key_t k)
{
    return Predecessor(k,root);
}
template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Successor(const key_t k,BSTNode<key_t,data_t>* subtree_root)
{
    BSTNode<key_t,data_t>* x=Search(k,subtree_root);
    if(x==nullptr)
    {
        std::cout<<"Key dont exist!"<<std::endl;
        return nullptr;
    }
    if(x->right!=nullptr)
        return Min(x->right);
    BSTNode<key_t,data_t>* y=x->parent;
    while(y!=nullptr&&x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;
}
template <typename key_t,typename data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Successor(const key_t k)
{
    return Successor(k,root);
}

template <typename Type>
Type AiSD::convert(std::string str)
{
    Type val;
    std::replace(str.begin(), str.end(), ' ', '_');
    std::stringstream ss(str);
    ss >> val;
    return val;
}
template <typename Type>
std::string AiSD::convertString(const Type val)
{
    std::stringstream ss;
    ss << val;
    std::string str = ss.str();
    return str;
}



//metody MP
template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::ShowBSTTree(){
    BSTNode<key_t,data_t> *tmp;
    std::queue<BSTNode<key_t,data_t>> kolejka;
    int height,nextMaxSons,number,numberOfMaxSons;
    numberOfMaxSons=2;
    number=nextMaxSons=0;
    height=3;
    tmp=root;
    if(tmp!=nullptr){
        kolejka.push(*tmp);
        for(int i=0;i<height*3;++i){
            std::cout<<"   ";
        }
        std::cout<<'\ ';
        while(!kolejka.empty() && height!=0){
            tmp=&kolejka.front();
            if(tmp->parent!=nullptr){
                if(tmp->parent->left==nullptr){
                    std::cout<<"null ";
                    for(int i=0;i<height;++i){
                        std::cout<<"        ";
                    }
                }
            }
            std::cout<<tmp->key<<" "<<tmp->data;
            for(int i=0;i<height;++i){
                std::cout<<"        ";
            }
            if(tmp->parent!=nullptr){
                if(tmp->parent->right==nullptr){
                    std::cout<<"null ";
                    for(int i=0;i<height;++i){
                        std::cout<<"        ";
                    }
                }
            }
            if(height>1){
                if(tmp->left!=nullptr){
                    kolejka.push(*tmp->left);
                    nextMaxSons+=2;
                    number++;
                }else{
                    number++;
                }
                if(tmp->right!=nullptr){
                    kolejka.push(*tmp->right);
                    nextMaxSons+=2;
                    number++;
                }else{
                    number++;
                }

                if(numberOfMaxSons==number){
                    std::cout<<'\n';
                    numberOfMaxSons=nextMaxSons;
                    nextMaxSons=0;
                    int helpNumber=number;
                    for(int i=0;i<height;++i){
                        std::cout<<"        ";
                    }
                    while(number!=0){
                        for(int i=0;i<height*3;++i){
                            std::cout<<"_";
                        }
                        std::cout<<"|";
                        for(int i=0;i<height*3;++i){
                            std::cout<<"_";
                        }
                        for(int i=0;i<height;++i){
                            std::cout<<"     ";
                        }
                        number-=2;

                    }

                    std::cout<<'\n';

                    for(int i=0;i<height*2;++i){
                        std::cout<<"    ";
                    }
                    while(helpNumber!=0){
                        std::cout<<'/';
                        for(int i=0;i<height;++i){
                            std::cout<<"      ";
                        }
                        std::cout<<'\\';
                        for(int i=0;i<height;++i){
                        std::cout<<"    ";
                        }

                        helpNumber-=2;
                    }
                    std::cout<<'\n';
                    for(int i=0;i<height;++i){
                        std::cout<<"      ";
                    }
                    number=0;
                    --height;
                }
            }
            kolejka.pop();
        }

    }
    std::cout<<'\n';
}
template <typename key_t,typename data_t>
void AiSD::BST<key_t,data_t>::ShowBST(){
    BSTNode<key_t,data_t> *tmp;
    std::queue<BSTNode<key_t,data_t>> kolejka;
    int height=0,maxSons=1;
    int sons=0;
    int nextMaxSons=0;
    std::cout<<"aktualan wysokosc drzewa: "<<++height<<'\n';
    tmp=root;
    if(tmp!=nullptr){
        kolejka.push(*tmp);
        while(!kolejka.empty()){
            tmp=&kolejka.front();
            if(sons==maxSons){
                std::cout<<"aktualan wysokosc drzewa: "<<++height<<'\n';
                sons=0;
                maxSons=nextMaxSons;
                nextMaxSons=0;
            }
            if(tmp->parent!=nullptr){
                if(tmp->parent->left==nullptr){
                    std::cout<<"null "<<'\n';
                    ++sons;
                }
            }
            std::cout<<tmp->key<<" "<<tmp->data<<'\n';
            if(tmp->parent!=nullptr){
                if(tmp->parent->right==nullptr){
                    std::cout<<"null "<<'\n';
                    ++sons;
                }
            }
            ++sons;
            if(tmp->left!=nullptr){
                kolejka.push(*tmp->left);
                nextMaxSons+=2;
            }
            if(tmp->right!=nullptr){
                kolejka.push(*tmp->right);
                nextMaxSons+=2;
            }

            kolejka.pop();
        }
    }
}



#endif // BST_TPP
