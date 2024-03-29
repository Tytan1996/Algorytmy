/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef BST_TPP
#define BST_TPP

template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::BSTNode<key_t,data_t>::BSTNode(key_t k,data_t dataArg)
{
    parent=nullptr;
    left=nullptr;
    right=nullptr;
    key=k;
    data=dataArg;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::Insert(const key_t k,data_t data)
{
    /* Jezeli chcemy zablokowac te same klucze, to wystarczy usunac komentarz!
    if(Search(k)!=nullptr)
    {
        std::cout<<"This key is already taken! ("<<k<<")"<<std::endl;
        return;
    }*/
    BSTNode<key_t,data_t>* prev=nullptr;
    BSTNode<key_t,data_t>* tmp=root;
    BSTNode<key_t,data_t>* newNode=new BSTNode<key_t,data_t>(k,data);

    while(tmp!=nullptr)
    {
        prev=tmp;

        if(newNode->key<tmp->key)
        {
            tmp=tmp->left;
        }
        else if(newNode->key>tmp->key)
        {
            tmp=tmp->right;
        }
        else
        {
            while(tmp!=nullptr&&tmp->key==prev->key)
            {
                prev=tmp;
                tmp=tmp->right;
            }
            break;
        }
    }
    newNode->parent=prev;
    if(root==nullptr)
    {
        root=newNode;
    }else
    {
        if(newNode->key<prev->key)
        {
            prev->left=newNode;
        }
        else if(newNode->key>prev->key)
        {
            prev->right=newNode;
        }else //ZDUBLOWANE KLUCZE
        {
            if(prev->right==nullptr)
            {
                prev->right=newNode;
            }else
            {
                newNode->right=prev->right;
                prev->right->parent=newNode;
                prev->right=newNode;
                newNode->parent=prev;
            }
        }
    }
}


template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::Transplant(BSTNode<key_t,data_t>* u,BSTNode<key_t,data_t>* v)
{
    if(u->parent==nullptr)
    {
        v->parent=nullptr;
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

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::PrintAscending(BSTNode<key_t,data_t> *node,int deep)
{
    if(node==nullptr)
    {
        if(root!=nullptr)
            node=root;
        else
            return;
    }

    if(node->left!=nullptr)
    {
        PrintAscending(node->left,deep+1);
    }
    for(int i=0;i<deep;i++)std::cout<<".";
    std::cout<<"node={key="<<node->key<<" data=\""<<node->data<<"\"}"<<std::endl;
    if(node->right!=nullptr)
    {
        PrintAscending(node->right,deep+1);
    }
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::VectorOfNodes(BSTNode<key_t,data_t> *node,std::vector<BSTNode<key_t,data_t>*>& vec)
{
    if(node==nullptr)
        return;
    vec.push_back(node);
    if(node->left!=nullptr)
        VectorOfNodes(node->left,vec);
    if(node->right!=nullptr)
        VectorOfNodes(node->right,vec);
}


template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::Delete(const key_t k)
{
    BSTNode<key_t,data_t>* x=Search(k);
    if(x==nullptr)//SPRAWDZAMY, CZY TAKI OBIEKT ISTNIEJE
    {
        std::cout<<"nie znaleziono obiektu do usuniecia"<<std::endl;
        return;
    }

    if(x->left==nullptr&&x->right==nullptr)//CASE 1. FORGET CHILDREN BY PARENT
    {
        if(x!=nullptr)
        {
            if(x->parent!=nullptr)
            {
                if(x->parent->left!=nullptr&&x->key==x->parent->left->key)
                {
                    x->parent->left=nullptr;
                }
                if(x->parent->right!=nullptr&&x->key==x->parent->right->key)
                {
                    x->parent->right=nullptr;
                }
            }else
            {
                root=nullptr;
            }
        }
    }
    else if(x->left==nullptr&&x->right!=nullptr)//CASE 2 Z DOKUMENTACJI. MOVE RIGHT TO PARENT
    {
        Transplant(x,x->right);
    }
    else if(x->right==nullptr&&x->left!=nullptr)//CASE 3 Z DOKUMENTACJI. MOVE LEFT TO PARENT
    {
        Transplant(x,x->left);
    }
    else if(x->right!=nullptr&&x->left!=nullptr)//CASE 4 Z DOKUMENTACJI. TRANSPLANT
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
    delete(x);
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::Save(std::string src)
{
    mINI::INIFile file(src);
    mINI::INIStructure ini;
    file.read(ini);
    ini.clear();//jezeli cos tu juz jest to to usun

    std::vector<BSTNode<key_t,data_t>*> vec;
    VectorOfNodes(root,vec);
    for(int i=0;i<vec.size();i++)
    {
        ini[std::to_string(i)]["key"] = convertString<key_t>(vec[i]->key);
        ini[std::to_string(i)]["data"] = convertString<data_t>(vec[i]->data);
    }
    file.write(ini);
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::Load(std::string src)
{
    Clear();//usun dotychczasowa zawartosc BST
    mINI::INIFile file(src);
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
template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Search(const key_t k,BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    while(subtree_root!=nullptr && k != subtree_root->key)
    {
        if(k<subtree_root->key)
            subtree_root=subtree_root->left;
        else
            subtree_root=subtree_root->right;
    }
    return subtree_root;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::Clear(AiSD::BSTNode<key_t,data_t>* node)
{
    if(node==nullptr)
    {
        if(root!=nullptr)
            node=root;
        else
            return;
    }
    if(node->left!=nullptr)
        Clear(node->left);
    if(node->right!=nullptr)
        Clear(node->right);
    if(node->parent!=nullptr)
    {
        if(node->parent->left!=nullptr&&node->key==node->parent->left->key)
            node->parent->left=nullptr;
        if(node->parent->right!=nullptr&&node->key==node->parent->right->key)
            node->parent->right=nullptr;
    }else
    {
        root=nullptr;
    }
    delete(node);
}


template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Min(BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<BSTNode<key_t,data_t>*> vec;
    VectorOfNodesAscending(subtree_root,vec);//tablica wezlow posortowana rosnaco

    BSTNode<key_t,data_t>* found=vec[0];//Mozemy tak zalozyc poniewaz uprzednio wspomnielismy ze BST nie ma byc pusty
    for(int i=0;i<vec.size();i++)
    {
        if(found->key>vec[i]->key)
            found=vec[i];
    }
    return found;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Max(BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<BSTNode<key_t,data_t>*> vec;
    VectorOfNodesAscending(subtree_root,vec);//tablica wezlow posortowana rosnaco

    BSTNode<key_t,data_t>* found=vec[0];//Mozemy tak zalozyc poniewaz uprzednio wspomnielismy ze BST nie ma byc pusty
    for(int i=0;i<vec.size();i++)
    {
        if(found->key<vec[i]->key)
            found=vec[i];
    }
    return found;
}



template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::VectorOfNodesAscending(BSTNode<key_t,data_t> *node,std::vector<BSTNode<key_t,data_t>*>& vec)
{
    if(node==nullptr)
        return;
    if(node->left!=nullptr)
        VectorOfNodesAscending(node->left,vec);
    vec.push_back(node);
    if(node->right!=nullptr)
        VectorOfNodesAscending(node->right,vec);
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Predecessor(const key_t k,BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<BSTNode<key_t,data_t>*> vec;
    VectorOfNodesAscending(subtree_root,vec);
    BSTNode<key_t,data_t>* found=nullptr;//znaleziony wezel
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]->key==k)
        {
            if(i>0)//BY NIE WYPASC POZA TABLICE
            {
                found=vec[i-1];
                break;
            }
        }
    }
    if(found!=nullptr)
    {
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]->key==found->key)
            {
                found=vec[i];
                break;
            }
        }
    }
    //UWAGA
    //ponizej celowy komentarz (nullptr jak wspomnialem w dokumentacji)
    //if(found!=nullptr&&found->key==subtree_root->key)return nullptr;

    return found;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::BSTNode<key_t,data_t>* AiSD::BST<key_t,data_t>::Successor(const key_t k,BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<BSTNode<key_t,data_t>*> vec;
    VectorOfNodesAscending(subtree_root,vec);//tablica wezlow posortowana rosnaco
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]->key==k)//szukamy najblizszego elementu o takim samym kluczu w tablicy
        {
            if(i<vec.size()-1)//nie chcemy wypasc poza tablice
            {
                for(int j=0;j<vec.size()-i;j++)//sprawdzamy tak dlugo az znajdziemy koniec tego samego klucza
                {
                    if(vec[i+j]->key!=k)//jezeli znalazles cos wiecej niz ten sam klucz to go zwroc
                        return vec[i+j];
                }
                return vec[i];//jesli nie, to zwroc samo poddrzewo jak podalem w dokumentacji UWAGA (mozna zmienic na "=nullptr" jak wspomnialem w dokumentacji)
            }
        }

    }
    return nullptr;
}


template <AiSD::RightType Type>
Type AiSD::convert(std::string str)
{
    Type val;
    std::replace(str.begin(), str.end(), ' ', '_');
    std::stringstream ss(str);
    ss >> val;
    return val;
}
template <AiSD::RightType Type>
std::string AiSD::convertString(const Type val)
{
    std::stringstream ss;
    ss << val;
    std::string str = ss.str();
    return str;
}


#include <queue>
#include <list>
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::ShowBSTTree()
{
    BSTNode<key_t,data_t> *tmp;
    std::list<BSTNode<key_t,data_t>*> listBST;
    std::queue<BSTNode<key_t,data_t>*> kolejkaBST;
    int nextMaxSons=1;
    int number=0;
    int height1=4;
    bool sonsIsNull=false;
    tmp=root;
    if(tmp!=nullptr)
    {
        kolejkaBST.push(tmp);
        for(int i=0; i<height1*3; ++i)
        {
            std::cout<<"    ";
        }
        std::cout<<'\ ';
        while(!kolejkaBST.empty() && height1!=0)
        {
            tmp=kolejkaBST.front();
            number++;
            if(height1==3)
            {
                if(tmp!=nullptr)
                {
                    std::cout<<tmp->key<<" "<<tmp->data;
                }
                else
                {
                    std::cout<<"null ";
                }
                std::cout<<"        ";

            }
            else
            {
                if(tmp!=nullptr)
                {
                    std::cout<<tmp->key<<" "<<tmp->data;
                }
                else
                {
                    std::cout<<"null ";
                }
            }
            for(int i=0;i<height1*2;++i){

                std::cout<<"   ";

            }




            if(height1>1)
            {
                if(tmp!=nullptr)
                {
                    if(tmp->left!=nullptr)
                    {
                        kolejkaBST.push(tmp->left);
                    }
                    else
                    {
                        kolejkaBST.push(nullptr);
                    }
                }
                else
                {
                    kolejkaBST.push(nullptr);
                }
                if(tmp!=nullptr)
                {
                    if(tmp->right!=nullptr)
                    {
                        kolejkaBST.push(tmp->right);
                    }
                }
                else
                {
                    kolejkaBST.push(nullptr);
                }
            }
            else
            {
                kolejkaBST.push(nullptr);
            }
            if(nextMaxSons==number)
            {
                if(height1==1)
                {
                    return;
                }
                std::cout<<'\n';
                nextMaxSons*=2;
                int helpNumber=nextMaxSons;
                number=nextMaxSons;

                if(height1==3 ||height1==4)
                {
                    for(int i=0; i<height1*2; ++i)
                    {
                        std::cout<<"    ";
                    }
                }
                else
                {
                    for(int i=0; i<height1*2; ++i)
                    {
                        std::cout<<"     ";
                    }
                }
                while(number>0)
                {
                    if(height1==4)
                    {
                        for(int i=0; i<height1*6; ++i)
                        {
                            std::cout<<"_";
                        }
                        std::cout<<"|";
                        for(int i=0; i<height1*6; ++i)
                        {
                            std::cout<<"_";
                        }
                        for(int i=0; i<height1*3; ++i)
                        {
                            std::cout<<"        ";
                        }
                        number-=2;
                    }
                    else if(height1==3)
                    {
                        for(int i=0; i<height1*3; ++i)
                        {
                            std::cout<<"_";
                        }
                        std::cout<<"|";
                        for(int i=0; i<height1*3; ++i)
                        {
                            std::cout<<"_";
                        }
                        std::cout<<'_';
                        for(int i=0; i<height1*2; ++i)
                        {
                            std::cout<<"     ";
                        }
                        number-=2;
                    }
                    else
                    {
                        for(int i=0; i<height1*2; ++i)
                        {
                            std::cout<<"_";
                        }
                        std::cout<<"|";
                        for(int i=0; i<height1*2; ++i)
                        {
                            std::cout<<"_";
                        }
                        for(int i=0; i<height1; ++i)
                        {
                            std::cout<<"       ";
                        }
                        number-=2;
                    }
                }
                std::cout<<'\n';
                if(height1==4 || height1==3)
                {
                    for(int i=0; i<height1*2; ++i)
                    {
                        std::cout<<"    ";
                    }
                }
                else
                {
                    for(int i=0; i<height1*2; ++i)
                    {
                        std::cout<<"     ";
                    }
                }
                while(helpNumber!=0)
                {
                    if(height1==4)
                    {
                        std::cout<<'/';
                        for(int i=0; i<height1*2; ++i)
                        {
                            std::cout<<"      ";
                        }
                        std::cout<<'\\';
                        for(int i=0; i<height1; ++i)
                        {
                            std::cout<<"    ";
                        }

                        helpNumber-=2;
                    }
                    else if(height1==3)
                    {
                        std::cout<<'/';
                        for(int i=0; i<height1; ++i)
                        {
                            std::cout<<"      ";
                        }
                        std::cout<<'\\';
                        for(int i=0; i<height1*1.7; ++i)
                        {
                            std::cout<<"     ";
                        }

                        helpNumber-=2;
                    }
                    else
                    {
                        std::cout<<'/';
                        for(int i=0; i<height1; ++i)
                        {
                            std::cout<<"    ";
                        }
                        std::cout<<'\\';
                        for(int i=0; i<height1; ++i)
                        {
                            std::cout<<"      ";
                        }
                        helpNumber-=2;
                    }
                }
                std::cout<<'\n';
                if(height1==4 ||height1==3 ||height1==2)
                {
                    for(int i=0; i<height1*2; ++i)
                    {
                        std::cout<<"    ";
                    }
                }
                else
                {
                    for(int i=0; i<height1; ++i)
                    {
                        std::cout<<"  ";
                    }
                }
                number=0;
                --height1;
            }
            kolejkaBST.pop();

        }

    }
    std::cout<<'\n';
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::ShowBST(){
    BSTNode<key_t,data_t> *tmp;
    std::queue<BSTNode<key_t,data_t>> kolejka;
    int height=0,maxSons=1;
    int sons=0;
    int nextMaxSons=0;
    std::cout<<"aktualna wysokosc drzewa: "<<++height<<'\n';
    tmp=root;
    if(tmp!=nullptr){
        kolejka.push(*tmp);
        while(!kolejka.empty()){
            tmp=&kolejka.front();
            if(sons==maxSons){
                std::cout<<"aktualana wysokosc drzewa: "<<++height<<'\n';
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
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::ListOfNodesInLevel(const int level,std::vector<AiSD::BSTNode<key_t,data_t>*>& table,AiSD::BSTNode<key_t,data_t>* node)
{
    if(level<0)return;
    if(node==nullptr)
    {
        if(root!=nullptr)
            node=root;
        else
            return;
    }
    if(level==0)
    {
        table.push_back(node);
    }
    else
    {
        if(node->left!=nullptr)
            ListOfNodesInLevel(level-1,table,node->left);
        if(node->right!=nullptr)
            ListOfNodesInLevel(level-1,table,node->right);
    }
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
int AiSD::BST<key_t,data_t>::height(BSTNode<key_t,data_t>* subtree_root,int sum)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return 0;
    }
    int v=0;
    if(subtree_root->left!=nullptr)
    {
        v=height(subtree_root->left,sum+1);
        if(v>sum)
            sum=v;
    }
    if(subtree_root->right!=nullptr)
    {
        v=height(subtree_root->right,sum+1);
        if(v>sum)
            sum=v;
    }

    return sum;
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
int AiSD::BST<key_t,data_t>::leavesCount(BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return 0;
    }

    if(subtree_root->left==nullptr&&subtree_root->right==nullptr)
        return 1;

    int l=0;
    int r=0;
    if(subtree_root->left!=nullptr)
        l=leavesCount(subtree_root->left);
    if(subtree_root->right!=nullptr)
        r=leavesCount(subtree_root->right);
    return r+l;

}
template <AiSD::RightType key_t,AiSD::RightType data_t>
int AiSD::BST<key_t,data_t>::nodesCount(BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return 0;
    }
    std::vector<BSTNode<key_t,data_t>*> vec;
    VectorOfNodes(subtree_root,vec);
    return vec.size();
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
int AiSD::BST<key_t,data_t>::nodesCountOnLevel(const int level,AiSD::BSTNode<key_t,data_t>* subtree_root)
{
    if(level<0)return 0;
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return 0;
    }
    std::vector<AiSD::BSTNode<key_t,data_t>*> table;
    ListOfNodesInLevel(level,table,subtree_root);
    return table.size();
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::BST<key_t,data_t>::pointersInfo(BSTNode<key_t,data_t>* subtree_root)
{
    if(subtree_root==nullptr)
    {
        std::cout<<"Subtree unvalid"<<std::endl;
        return;
    }
    std::cout<<std::endl<<std::endl<<"INFO SUBTREE ID: "<<subtree_root->data<<std::endl;

    std::cout<<"PARENT ID: ";
    if(subtree_root->parent!=nullptr)
        std::cout<<subtree_root->parent->data;
    else
        std::cout<<"NULL";
    std::cout<<std::endl;

    std::cout<<"LEFT ID: ";
    if(subtree_root->left!=nullptr)
        std::cout<<subtree_root->left->data;
    else
        std::cout<<"NULL";
    std::cout<<std::endl;

    std::cout<<"RIGHT ID: ";
    if(subtree_root->right!=nullptr)
        std::cout<<subtree_root->right->data;
    else
        std::cout<<"NULL";
    std::cout<<std::endl;

    std::cout<<std::endl<<std::endl<<std::endl;
}
#endif // BST_TPP
