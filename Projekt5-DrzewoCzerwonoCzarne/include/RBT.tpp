/*
    Maciej Pestka
    Damian Szopinski 185394
*/
#ifndef RBT_TPP
#define RBT_TPP
#include <queue>
#include <list>

template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::RBTNode<key_t,data_t>::RBTNode(key_t k,data_t dataArg)
{
    parent=nullptr;
    left=nullptr;
    right=nullptr;
    color=RED;
    key=k;
    data=dataArg;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::Insert(const key_t k,data_t data)
{
    // Jezeli chcemy zablokowac te same klucze, to wystarczy usunac komentarz!
    if(Search(k)!=nullptr)
    {
        std::cout<<"This key is already taken! ("<<k<<")"<<std::endl;
        return;
    }
    Node* prev=nullptr;
    Node* tmp=root;
    Node* newNode=new Node(k,data);

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
    FixInsert(newNode);
}


template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::Transplant(Node* u,Node* v)
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
void AiSD::RBT<key_t,data_t>::PrintAscending(Node *node,int deep)
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
void AiSD::RBT<key_t,data_t>::VectorOfNodes(Node *node,std::vector<Node*>& vec)
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
AiSD::RBTNode<key_t,data_t>* AiSD::RBT<key_t,data_t>::Delete(Node* subtree_root, key_t k)
{
    if (subtree_root == nullptr)
        return subtree_root;
    else if (k < subtree_root->key)
        return Delete(subtree_root->left, k);
    else if (k > subtree_root->key)
        return Delete(subtree_root->right, k);
    else if (subtree_root->left == nullptr || subtree_root->right == nullptr)
        return subtree_root;
    else
    {
        Node* tmp = Min(subtree_root->right);
        subtree_root->key = tmp->key;
        subtree_root->data = tmp->data;
        return Delete(subtree_root->right, tmp->key);//rekurencja
    }
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::Delete(key_t k)
{
    FixDelete(Delete(root,k));
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::Save(std::string src)
{
    mINI::INIFile file(src);
    mINI::INIStructure ini;
    file.read(ini);
    ini.clear();//jezeli cos tu juz jest to to usun

    std::vector<Node*> vec;
    VectorOfNodes(root,vec);
    for(int i=0;i<vec.size();i++)
    {
        ini[std::to_string(i)]["key"] = convertString<key_t>(vec[i]->key);
        ini[std::to_string(i)]["data"] = convertString<data_t>(vec[i]->data);
    }
    file.write(ini);
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::Load(std::string src)
{
    Clear();//usun dotychczasowa zawartosc RBT
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
AiSD::RBTNode<key_t,data_t>* AiSD::RBT<key_t,data_t>::Search(const key_t k,Node* subtree_root)
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
void AiSD::RBT<key_t,data_t>::Clear(Node* node)
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
AiSD::RBTNode<key_t,data_t>* AiSD::RBT<key_t,data_t>::Min(Node* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<Node*> vec;
    VectorOfNodesAscending(subtree_root,vec);//tablica wezlow posortowana rosnaco

    Node* found=vec[0];//Mozemy tak zalozyc poniewaz uprzednio wspomnielismy ze RBT nie ma byc pusty
    for(int i=0;i<vec.size();i++)
    {
        if(found->key>vec[i]->key)
            found=vec[i];
    }
    return found;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::RBTNode<key_t,data_t>* AiSD::RBT<key_t,data_t>::Max(Node* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<Node*> vec;
    VectorOfNodesAscending(subtree_root,vec);//tablica wezlow posortowana rosnaco

    Node* found=vec[0];//Mozemy tak zalozyc poniewaz uprzednio wspomnielismy ze RBT nie ma byc pusty
    for(int i=0;i<vec.size();i++)
    {
        if(found->key<vec[i]->key)
            found=vec[i];
    }
    return found;
}



template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::VectorOfNodesAscending(Node *node,std::vector<Node*>& vec)
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
AiSD::RBTNode<key_t,data_t>* AiSD::RBT<key_t,data_t>::Predecessor(const key_t k,Node* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<Node*> vec;
    VectorOfNodesAscending(subtree_root,vec);
    Node* found=nullptr;//znaleziony wezel
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
AiSD::RBTNode<key_t,data_t>* AiSD::RBT<key_t,data_t>::Successor(const key_t k,Node* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return nullptr;
    }
    std::vector<Node*> vec;
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



template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::ShowRBTTree() {
    RBTNode<key_t,data_t> *tmp;
    std::list<RBTNode<key_t,data_t>*> listBST;
    std::list<RBTNode<key_t,data_t>*> listBST2;
    std::queue<RBTNode<key_t,data_t>*> kolejkaBST;
    int nextMaxSons=1;
    int number=0;
    int height1=4;
    bool parentsIsNull=false;
    tmp=root;
    if(tmp!=nullptr) {
        kolejkaBST.push(tmp);
        listBST.push_back(tmp);
        for(int i=0; i<height1*3; ++i) {
            std::cout<<"    ";
        }
        std::cout<<'\ ';
        while(!kolejkaBST.empty() && height1!=0) {
            tmp=kolejkaBST.front();
            number++;
            if(tmp!=nullptr) {
                if(height1!=1){
                    std::cout<<tmp->key<<" "<<tmp->data;
                    if(tmp->color==1){
                        std::cout<<" B";
                    }else if(tmp->color==0){
                        std::cout<<" R";
                    }else if(tmp->color==2){
                        std::cout<<" P";
                    }
                }
                else{
                    std::cout<<tmp->key;
                }
            } else {
                if(height1!=1){
                    std::cout<<"    ";
                }

            }
            if(height1==3){
                for(int i=0;i<height1*3;++i){
                    std::cout<<"     ";
                }
                if(number==2){
                    std::cout<<"              ";
                }
            }else if(height1==2){
                for(int i=0;i<height1;++i){
                    std::cout<<"      ";
                }
                if(number==2){
                    std::cout<<"             ";
                }
            }else{
                if(number==2 || number==6){
                    std::cout<<"         ";
                }else if(number==4){
                    std::cout<<"         ";
                }else{
                    std::cout<<"             ";
                }
            }
            if(height1>1) {
                if(tmp!=nullptr) {
                    if(tmp->left!=nullptr) {
                        kolejkaBST.push(tmp->left);
                        listBST.push_back(tmp->left);
                    } else {
                        kolejkaBST.push(nullptr);
                        listBST.push_back(nullptr);
                    }
                } else {
                    kolejkaBST.push(nullptr);
                    listBST.push_back(nullptr);
                }
                if(tmp!=nullptr) {
                    if(tmp->right!=nullptr) {
                        kolejkaBST.push(tmp->right);
                        listBST.push_back(tmp->right);
                    } else {
                        kolejkaBST.push(nullptr);
                        listBST.push_back(nullptr);
                    }
                } else {
                    kolejkaBST.push(nullptr);
                    listBST.push_back(nullptr);
                }
            } else {
                kolejkaBST.push(nullptr);
                listBST.push_back(nullptr);
            }
            if(nextMaxSons==number) {
                if(height1==1) {
                    return;
                }
                std::cout<<'\n';
                nextMaxSons*=2;
                int helpNumber=nextMaxSons;
                number=nextMaxSons;
                if(height1==3 ||height1==4) {
                    for(int i=0; i<height1*2; ++i) {
                        std::cout<<"    ";
                    }
                } else {
                    for(int i=0; i<height1*2; ++i) {
                        std::cout<<"     ";
                    }
                }
                while(number>0) {
                    if(height1==4) {
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*6; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*6; ++i) {
                                    std::cout<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                std::cout<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*6; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*6; ++i) {
                                    std::cout<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*12; ++i) {
                                std::cout<<" ";
                            }
                        }
                        for(int i=0; i<height1*3; ++i) {
                            std::cout<<"        ";
                        }
                        number-=2;
                    } else if(height1==3) {
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*3; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*3; ++i) {
                                    std::cout<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                std::cout<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*3; ++i) {
                                    std::cout<<"_";
                                }
                                std::cout<<"_";
                            }else{
                                for(int i=0; i<height1*3; ++i) {
                                    std::cout<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*6; ++i) {
                                std::cout<<" ";
                            }
                        }
                        for(int i=0; i<height1*2; ++i) {
                            std::cout<<"     ";
                        }
                        number-=2;
                    } else if(height1==2 ){
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                std::cout<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*4; ++i) {
                                std::cout<<" ";
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            std::cout<<"       ";
                        }
                        number-=2;
                    }else if(height1==1 ){
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                std::cout<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    std::cout<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*4; ++i) {
                                std::cout<<" ";
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            std::cout<<"       ";
                        }
                        number-=2;
                    }
                    listBST2.push_back(listBST.front());
                    listBST.pop_front();

                }
                std::cout<<'\n';
                if(height1==4 || height1==3)  {
                    for(int i=0; i<height1*2; ++i) {
                        std::cout<<"    ";
                    }
                } else{
                    for(int i=0; i<height1*2; ++i) {
                        std::cout<<"     ";
                    }
                }
                while(helpNumber!=0) {
                    if(height1==4) {
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->left!=nullptr){
                                std::cout<<'/';
                            }
                        }
                            for(int i=0; i<height1*2; ++i) {
                                std::cout<<"      ";
                            }
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->right!=nullptr){
                                std::cout<<'\\';
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            std::cout<<"    ";
                        }
                        helpNumber-=2;
                    } else if(height1==3) {
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->left!=nullptr){
                                std::cout<<'/';
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            std::cout<<"      ";
                        }
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->right!=nullptr){
                                std::cout<<'\\';
                            }
                        }
                        for(int i=0; i<height1*1.7; ++i) {
                            std::cout<<"     ";
                        }


                        helpNumber-=2;
                    } else{
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->left!=nullptr){
                                std::cout<<'/';
                            }
                        }
                        std::cout<<"        ";

                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->right!=nullptr){
                                std::cout<<"\\  ";
                            }
                        }
                        if(helpNumber==6){
                            std::cout<<"          ";
                        }else if(helpNumber==4){
                            for(int i=0; i<height1; ++i) {
                                std::cout<<"        ";
                            }
                        }else{
                            for(int i=0; i<height1; ++i) {
                                std::cout<<"      ";
                            }
                        }


                        helpNumber-=2;
                    }
                    listBST2.pop_front();
                }
                std::cout<<'\n';
                if(height1==4 ||height1==3 ||height1==2) {
                    for(int i=0; i<height1*2; ++i) {
                        std::cout<<"    ";
                    }
                } else {
                    for(int i=0; i<height1; ++i) {
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
#include <fstream>
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::SaveRBTTREE(){
    std::fstream zapis;
    zapis.open("RBTTree.txt", std::ios::out);
    RBTNode<key_t,data_t> *tmp;
    std::list<RBTNode<key_t,data_t>*> listBST;
    std::list<RBTNode<key_t,data_t>*> listBST2;
    std::queue<RBTNode<key_t,data_t>*> kolejkaBST;
    int nextMaxSons=1;
    int number=0;
    int height1=4;
    bool parentsIsNull=false;
    tmp=root;
    if(tmp!=nullptr) {
        kolejkaBST.push(tmp);
        listBST.push_back(tmp);
        for(int i=0; i<height1*3; ++i) {
            zapis<<"    ";
        }
       zapis<<'\ ';
        while(!kolejkaBST.empty() && height1!=0) {
            tmp=kolejkaBST.front();
            number++;
            if(tmp!=nullptr) {
                if(height1!=1){
                    zapis<<tmp->key<<" "<<tmp->data;
                    if(tmp->color==1){
                        zapis<<" B";
                    }else if(tmp->color==0){
                        zapis<<" R";
                    }else if(tmp->color==2){
                        zapis<<" P";
                    }
                }
                else{
                    zapis<<tmp->key;
                }
            } else {
                if(height1!=1){
                    zapis<<"    ";
                }

            }
            if(height1==3){
                for(int i=0;i<height1*3;++i){
                    zapis<<"     ";
                }
                if(number==2){
                    zapis<<"              ";
                }
            }else if(height1==2){
                for(int i=0;i<height1;++i){
                    zapis<<"      ";
                }
                if(number==2){
                   zapis<<"             ";
                }
            }else{
                if(number==2 || number==6){
                    zapis<<"         ";
                }else if(number==4){
                    zapis<<"         ";
                }else{
                    zapis<<"             ";
                }
            }
            if(height1>1) {
                if(tmp!=nullptr) {
                    if(tmp->left!=nullptr) {
                        kolejkaBST.push(tmp->left);
                        listBST.push_back(tmp->left);
                    } else {
                        kolejkaBST.push(nullptr);
                        listBST.push_back(nullptr);
                    }
                } else {
                    kolejkaBST.push(nullptr);
                    listBST.push_back(nullptr);
                }
                if(tmp!=nullptr) {
                    if(tmp->right!=nullptr) {
                        kolejkaBST.push(tmp->right);
                        listBST.push_back(tmp->right);
                    } else {
                        kolejkaBST.push(nullptr);
                        listBST.push_back(nullptr);
                    }
                } else {
                    kolejkaBST.push(nullptr);
                    listBST.push_back(nullptr);
                }
            } else {
                kolejkaBST.push(nullptr);
                listBST.push_back(nullptr);
            }
            if(nextMaxSons==number) {
                if(height1==1) {
                    return;
                }
                zapis<<'\n';
                nextMaxSons*=2;
                int helpNumber=nextMaxSons;
                number=nextMaxSons;
                if(height1==3 ||height1==4) {
                    for(int i=0; i<height1*2; ++i) {
                        zapis<<"    ";
                    }
                } else {
                    for(int i=0; i<height1*2; ++i) {
                        zapis<<"     ";
                    }
                }
                while(number>0) {
                    if(height1==4) {
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*6; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*6; ++i) {
                                    zapis<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                zapis<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*6; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*6; ++i) {
                                    zapis<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*12; ++i) {
                                zapis<<" ";
                            }
                        }
                        for(int i=0; i<height1*3; ++i) {
                            zapis<<"        ";
                        }
                        number-=2;
                    } else if(height1==3) {
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*3; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*3; ++i) {
                                    zapis<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                               zapis<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*3; ++i) {
                                    zapis<<"_";
                                }
                                zapis<<"_";
                            }else{
                                for(int i=0; i<height1*3; ++i) {
                                    zapis<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*6; ++i) {
                                zapis<<" ";
                            }
                        }
                        for(int i=0; i<height1*2; ++i) {
                            zapis<<"     ";
                        }
                        number-=2;
                    } else if(height1==2 ){
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                zapis<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*4; ++i) {
                                zapis<<" ";
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            zapis<<"       ";
                        }
                        number-=2;
                    }else if(height1==1 ){
                        if(listBST.front()!=nullptr){
                            if(listBST.front()->left!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<" ";
                                }
                            }
                            if(listBST.front()->right!=nullptr || listBST.front()->left!=nullptr){
                                zapis<<"|";
                            }
                            if(listBST.front()->right!=nullptr){
                                for(int i=0; i<height1*2; ++i) {
                                    zapis<<"_";
                                }
                            }else{
                                for(int i=0; i<height1*2; ++i) {
                                   zapis<<" ";
                                }
                            }
                        }else{
                            for(int i=0; i<height1*4; ++i) {
                                zapis<<" ";
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            zapis<<"       ";
                        }
                        number-=2;
                    }
                    listBST2.push_back(listBST.front());
                    listBST.pop_front();

                }
                zapis<<'\n';
                if(height1==4 || height1==3)  {
                    for(int i=0; i<height1*2; ++i) {
                        zapis<<"    ";
                    }
                } else{
                    for(int i=0; i<height1*2; ++i) {
                        zapis<<"     ";
                    }
                }
                while(helpNumber!=0) {
                    if(height1==4) {
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->left!=nullptr){
                                zapis<<'/';
                            }
                        }
                            for(int i=0; i<height1*2; ++i) {
                                zapis<<"      ";
                            }
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->right!=nullptr){
                                zapis<<'\\';
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            zapis<<"    ";
                        }
                        helpNumber-=2;
                    } else if(height1==3) {
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->left!=nullptr){
                                zapis<<'/';
                            }
                        }
                        for(int i=0; i<height1; ++i) {
                            zapis<<"      ";
                        }
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->right!=nullptr){
                                zapis<<'\\';
                            }
                        }
                        for(int i=0; i<height1*1.7; ++i) {
                            zapis<<"     ";
                        }


                        helpNumber-=2;
                    } else{
                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->left!=nullptr){
                               zapis<<'/';
                            }
                        }
                        zapis<<"        ";

                        if(listBST2.front()!=nullptr){
                            if(listBST2.front()->right!=nullptr){
                                zapis<<"\\  ";
                            }
                        }
                        if(helpNumber==6){
                            zapis<<"          ";
                        }else if(helpNumber==4){
                            for(int i=0; i<height1; ++i) {
                                zapis<<"        ";
                            }
                        }else{
                            for(int i=0; i<height1; ++i) {
                                zapis<<"      ";
                            }
                        }


                        helpNumber-=2;
                    }
                    listBST2.pop_front();
                }
                zapis<<'\n';
                if(height1==4 ||height1==3 ||height1==2) {
                    for(int i=0; i<height1*2; ++i) {
                        zapis<<"    ";
                    }
                } else {
                    for(int i=0; i<height1; ++i) {
                        zapis<<"  ";
                    }
                }
                number=0;
                --height1;
            }
            kolejkaBST.pop();

        }
    }
    zapis<<'\n';
    zapis.close();

}
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::ShowRBT(){
    Node *tmp;
    std::queue<Node> kolejka;
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
void AiSD::RBT<key_t,data_t>::ListOfNodesInLevel(const int level,std::vector<Node*>& table,Node* node)
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
int AiSD::RBT<key_t,data_t>::height(Node* subtree_root,int sum)
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
int AiSD::RBT<key_t,data_t>::leavesCount(Node* subtree_root)
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
int AiSD::RBT<key_t,data_t>::nodesCount(Node* subtree_root)
{
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return 0;
    }
    std::vector<Node*> vec;
    VectorOfNodes(subtree_root,vec);
    return vec.size();
}
//JEZELI ZAMIENIAMY KOLOR DZIADKA NA CZERWONY TO JEGO DZIECI I JEGO OJCIEC NIE MOGA BYC JUZ CZERWONI BO ZABUZYLOBY TO DRZEWO CZERWONO CZARNE
template <AiSD::RightType key_t,AiSD::RightType data_t>
int AiSD::RBT<key_t,data_t>::nodesCountOnLevel(const int level,Node* subtree_root)
{
    if(level<0)return 0;
    if(subtree_root==nullptr)
    {
        if(root!=nullptr)
            subtree_root=root;
        else
            return 0;
    }
    std::vector<Node*> table;
    ListOfNodesInLevel(level,table,subtree_root);
    return table.size();
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::pointersInfo(Node* subtree_root)
{
    if(subtree_root==nullptr)
    {
        std::cout<<"Subtree unvalid"<<std::endl;
        return;
    }
    std::cout<<std::endl<<std::endl<<"THIS: ";
    std::cout<<"key: "<<subtree_root->key<<" data:"<<subtree_root->data<<" color:"<<subtree_root->color<<std::endl;;

    std::cout<<"PARENT ID: ";
    if(subtree_root->parent!=nullptr)
        std::cout<<"key: "<<subtree_root->parent->key<<" data:"<<subtree_root->parent->data<<" color:"<<subtree_root->parent->color;
    else
        std::cout<<"NULL";
    std::cout<<std::endl;

    std::cout<<"LEFT ID: ";
    if(subtree_root->left!=nullptr)
        std::cout<<"key: "<<subtree_root->left->key<<" data:"<<subtree_root->left->data<<" color:"<<subtree_root->left->color;
    else
        std::cout<<"NULL";
    std::cout<<std::endl;

    std::cout<<"RIGHT ID: ";
    if(subtree_root->right!=nullptr)
        std::cout<<"key: "<<subtree_root->right->key<<" data:"<<subtree_root->right->data<<" color:"<<subtree_root->right->color;
    else
        std::cout<<"NULL";
    std::cout<<std::endl;

    std::cout<<"\n\n\n";
}



/*DRZEWO CZERWONO CZARNE*/

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::rotateRight(Node* subtree_root)
{
    Node* prev= subtree_root->left;
    subtree_root->left = prev->right;
    if (subtree_root->left!=nullptr)
    {
        subtree_root->left->parent=subtree_root;
    }
    prev->parent=subtree_root->parent;
    if (subtree_root->parent==nullptr)
    {
        root = prev;
    }
    else if (subtree_root==subtree_root->parent->left)
    {
        subtree_root->parent->left = prev;
    }
    else
    {
        subtree_root->parent->right = prev;
    }
    prev->right = subtree_root;
    subtree_root->parent = prev;
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::rotateLeft(Node* subtree_root)
{
    Node *prev = subtree_root->right;
    subtree_root->right = prev->left;
    if (subtree_root->right!=nullptr)
    {
        subtree_root->right->parent=subtree_root;
    }
    prev->parent = subtree_root->parent;
    if (subtree_root->parent==nullptr)
    {
        root = prev;
    }
    else if (subtree_root==subtree_root->parent->left)
    {
        subtree_root->parent->left=prev;
    }
    else
    {
        subtree_root->parent->right=prev;
    }
    prev->left = subtree_root;
    subtree_root->parent = prev;
}


template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::ReplaceColor(Node* subtree_root,Color newColor)
{
    if(subtree_root==nullptr)
        return;
    subtree_root->color=newColor;
}
template <AiSD::RightType key_t,AiSD::RightType data_t>
AiSD::Color AiSD::RBT<key_t,data_t>::WhatColorIs(Node* subtree_root)
{
    if(subtree_root==nullptr)
        return BLACK;
    return subtree_root->color;
}

template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::FixInsert(Node* subtree_root)
{
    Node *parent = nullptr;
    Node *grand = nullptr;
    while(subtree_root != root && WhatColorIs(subtree_root) == RED && WhatColorIs(subtree_root->parent) == RED)
    {
        subtree_root->parent;
        grand = subtree_root->parent!=nullptr?subtree_root->parent->parent:nullptr;
        if(parent!=nullptr&&parent->parent!=nullptr
            &&parent==grand->left)
            {
                Node *uncle=grand->right;
                if(WhatColorIs(uncle)==RED)
                {
                    ReplaceColor(parent,BLACK);
                    ReplaceColor(uncle,BLACK);
                    ReplaceColor(grand,RED);
                    if(grand!=nullptr)
                    {
                        if(grand->parent!=nullptr)
                            ReplaceColor(grand->parent,BLACK);
                        ReplaceColor(grand->left,BLACK);
                        ReplaceColor(grand->right,BLACK);
                    }
                    subtree_root=grand;
                }
                else
                {
                    if(parent!=nullptr&&subtree_root==parent->right)
                    {
                        rotateLeft(parent);
                        subtree_root=parent;
                        parent=subtree_root->parent;
                    }
                    rotateRight(grand);
                    ReplaceColor(parent,BLACK);
                    ReplaceColor(grand,RED);
                    if(grand!=nullptr)
                    {
                        if(grand->parent!=nullptr)
                            ReplaceColor(grand->parent,BLACK);
                        ReplaceColor(grand->left,BLACK);
                        ReplaceColor(grand->right,BLACK);
                    }
                    subtree_root=parent;
                }
            }
            else
            {
               //to samo co wyzej z zamienionymi wskaznikami left i right
                Node *uncle=grand->left;
                if(WhatColorIs(uncle)==RED)
                {
                    ReplaceColor(parent,BLACK);
                    ReplaceColor(uncle,BLACK);
                    ReplaceColor(grand,RED);
                    if(grand!=nullptr)
                    {
                        if(grand->parent!=nullptr)
                            ReplaceColor(grand->parent,BLACK);
                        ReplaceColor(grand->left,BLACK);
                        ReplaceColor(grand->right,BLACK);
                    }
                    subtree_root=grand;
                }
                else
                {
                    if(parent!=nullptr&&subtree_root==parent->left)
                    {
                        rotateRight(parent);
                        subtree_root=parent;
                        parent=subtree_root->parent;

                    }
                    rotateLeft(grand);
                    ReplaceColor(parent,BLACK);
                    ReplaceColor(grand,RED);
                    if(grand!=nullptr)
                    {
                        if(grand->parent!=nullptr)
                            ReplaceColor(grand->parent,BLACK);
                        ReplaceColor(grand->left,BLACK);
                        ReplaceColor(grand->right,BLACK);
                    }
                    subtree_root=parent;
                }
            }
    }
    ReplaceColor(root,BLACK);
}




template <AiSD::RightType key_t,AiSD::RightType data_t>
void AiSD::RBT<key_t,data_t>::FixDelete(Node* subtree_root)
{
    if(root==nullptr)
    {
        return;
    }
    if (subtree_root==nullptr)
    {
        return;
    }
    if (subtree_root==root)
    {
        Node *to_delete=nullptr;
        if(root->right!=nullptr)
        {
            Node *left=root->left;
            to_delete=root;
            root=root->right;
            root->parent=nullptr;
            if(root->left!=nullptr)
            {
                Node *mins=Min(root);
                left->parent=mins;
                mins->left=left;
            }
            ReplaceColor(root,BLACK);
        }else if(root->left!=nullptr)
        {
            to_delete=root;
            root=root->left;
            root->parent=nullptr;
            ReplaceColor(root,BLACK);
        }else
        {
            to_delete=root;
            root=nullptr;
        }

        delete(to_delete);
        return;
    }


    Node *parent=nullptr;
    Node *brother=nullptr;
    Node *kid=nullptr;

    if (WhatColorIs(subtree_root->left) == RED
        ||WhatColorIs(subtree_root) == RED
        ||WhatColorIs(subtree_root->right) == RED)
    {
        //PRZYPADEK 1
        if(subtree_root->left!=nullptr)
        {
            kid=subtree_root->left;
        }
        else if(subtree_root->right!=nullptr)
        {
            kid=subtree_root->right;
        }
        if (subtree_root==subtree_root->parent->left)
        {
            subtree_root->parent->left=kid;

            if (kid != nullptr)
                kid->parent=subtree_root->parent;


            ReplaceColor(kid,BLACK);
            delete(subtree_root);
        }
        else
        {
            subtree_root->parent->right=kid;
            if(kid!=nullptr)
                kid->parent=subtree_root->parent;


            ReplaceColor(kid,BLACK);
            delete(subtree_root);
        }
    }
    else
    {
        //PRZYPADEK 2
        Node *ptr=subtree_root;

        ReplaceColor(ptr,PINK);
        while (WhatColorIs(ptr)==PINK&&ptr!=root)
        {
            //Jedna strona
            parent=ptr->parent;
            if (ptr==parent->left)
            {
                brother=parent->right;
                if (WhatColorIs(brother)==RED)
                {
                    ReplaceColor(parent,RED);
                    ReplaceColor(brother,BLACK);

                    rotateLeft(parent);
                }
                else
                {
                    if (WhatColorIs(brother->left)==BLACK
                        &&WhatColorIs(brother->right)==BLACK)
                    {
                        ReplaceColor(brother,RED);
                        if(WhatColorIs(parent)==RED)
                        {
                            ReplaceColor(parent,BLACK);
                        }
                        else
                        {
                            ReplaceColor(parent,PINK);
                        }

                        ptr=parent;
                    }
                    else
                    {
                        if (WhatColorIs(brother->right)==BLACK)
                        {
                            ReplaceColor(brother->left,BLACK);
                            ReplaceColor(brother,RED);
                            rotateRight(brother);
                            brother = parent->right;
                        }

                        ReplaceColor(brother,WhatColorIs(parent));
                        ReplaceColor(brother->right,BLACK);
                        ReplaceColor(parent,BLACK);

                        rotateLeft(parent);
                        break;
                    }
                }
            }
            else
            {
                //to samo co wyzej z zamienionymi wskaznikami left i right
                brother=parent->left;
                if (WhatColorIs(brother)==RED)
                {

                    ReplaceColor(brother,BLACK);
                    ReplaceColor(parent,RED);
                    rotateRight(parent);
                }
                else
                {
                    if (WhatColorIs(brother->right)==BLACK
                        &&WhatColorIs(brother->left)==BLACK)
                    {
                        ReplaceColor(brother,RED);

                        if (WhatColorIs(parent)==RED)
                        {
                            ReplaceColor(parent,BLACK);
                        }
                        else
                        {
                            ReplaceColor(parent,PINK);
                        }
                        ptr = parent;
                    }
                    else
                    {

                        if (WhatColorIs(brother->left)==BLACK)
                        {
                            ReplaceColor(brother->right,BLACK);
                            ReplaceColor(brother,RED);
                            rotateLeft(brother);
                            brother = parent->left;
                        }

                        ReplaceColor(brother,WhatColorIs(parent));
                        ReplaceColor(brother->left,BLACK);
                        ReplaceColor(parent,BLACK);

                        rotateRight(parent);
                        break;
                    }
                }
            }
        }

        if (subtree_root==subtree_root->parent->left)
        {
            subtree_root->parent->left=nullptr;
        }
        else
        {
            subtree_root->parent->right=nullptr;
        }
        //na koncu ustawiamy root na czarny
        ReplaceColor(root,BLACK);
        //tak jak wspominalem w dokumentacji tutaj kasujemy wezel.
        delete(subtree_root);
    }
}



#endif // RBT_TPP
