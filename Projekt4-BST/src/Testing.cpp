/*


*/
#include "Testing.h"
#include "BST.h"
#include <chrono>
#include <vector>
#include <map>
void AiSD::Testing::randing(size_t amountOfElements){
    std::vector<std::string> strukturaString;
    std::string randomString="";
    int liczba;
    srand( time( NULL ) );
    for(size_t i=0; i<amountOfElements; ++i) {
        liczba=std::rand();
        dane.push_back(liczba);
        for(int j=0;j<10;++j){
            randomString+=std::rand()%90+33;
        }
        strukturaString.push_back(randomString);
        randomString="";
    }
    for(size_t i=0; i<amountOfElements; ++i) {
        test.Insert(dane[i],strukturaString[i]);
    }
}
void AiSD::Testing::rand(float mnoznik) {
    std::string randomString="";
    int liczba;
    srand( time( NULL ) );
    liczba=mnoznik*test.root->key;
    dane.push_back(liczba);
    for(int j=0;j<10;++j){
        randomString+=std::rand()%90+33;
    }

    test.Insert(liczba,randomString);

}
void AiSD::Testing::detailsTest(){

    std::cout<<"Prosze czekac, testy moga troche zajac!"<<std::endl;
    //testy zwiazanie z insert
    testInsert(0,test.root);
    randing(1);
    testInsert(1,test.root);
    rand(1.0/2);
    testInsert(2,test.root->left);
    rand(2);
    testInsert(3,test.root->right);
    testClear();
    randing(1);
    testInsert(1,test.root);
    rand(2);
    testInsert(3,test.root->right);
    rand(1.0/2);
    testInsert(2,test.root->left);
    testClear();
    randing(1);
    //test.Delete(1);


}
void AiSD::Testing::generalTest(){
    size_t amountTest;
    std::cout<<"Ile chcesz wykonac testow?"<<std::endl;
    std::cout<<"Ilosc testow: ";
    std::cin>>amountTest;
    for(size_t i=0;i<amountTest;++i){
        int opcja;
        switch(opcja){
        case 1:
            //if(!testInsert(1)){
                std::cout<<"blad insert!"<<std::endl;
                std::cout<<"Zle dziala funkcja."<<std::endl;
                return;
            //}
            break;
        case 2:
            //if(!testDelete(1)){
                std::cout<<"blad delete!"<<std::endl;
                std::cout<<"Zle dziala funkcja."<<std::endl;
                return;
           // }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;

        }

    }

}
bool AiSD::Testing::testInsert(int opcja,BSTNode<int,std::string> *tmp) {
    switch(opcja){
    case 0:
        if(tmp==nullptr){
            return false;
        }
        break;
    case 1:
        if(tmp->parent!=nullptr){
            std::cout<<"priewszy utworozny element MA ustawionego wskiaznika na parent"<<'\n';
            return false;
        }
        if(tmp->left!=nullptr){
            std::cout<<"priewszy utworozny element MA ustawionego wskiaznika na left"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr){
            std::cout<<"priewszy utworozny element ma ustawionego wskiaznika na right"<<'\n';
            return false;
        }
        break;
    case 2:
        if(tmp->parent==nullptr){
            std::cout<<"Kolejny wartosc dodania do drzeqa nie posiada wskaznika na rodzica."<<'\n';
            return false;
        }else{
            if(tmp->parent->left==nullptr){
                std::cout<<"Rodzic nie zawiera ustawionego wskaznika na lewego syna"<<'\n';
                return false;
            }
        }
        if(tmp->left!=nullptr){
            std::cout<<"Nowy utworzony element posiada wskaznik na lewego syna (ktory nie ma prawa istniec)"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr){
            std::cout<<"Nowy utworozny element posiada wskaznik na prawego syna (ktory nie ma prawa istniec)"<<'\n';
            return false;
        }
        break;
    case 3:
        if(tmp->parent==nullptr){
            std::cout<<"Kolejny wartosc dodania do drzewa nie posiada wskaznika na rodzica."<<'\n';
            return false;
        }else{
            if(tmp->parent->right==nullptr){
                return false;
            }
        }
        if(tmp->left!=nullptr){
            return false;
        }
        if(tmp->right!=nullptr){
            return false;
        }
        break;

    }
    return true;
}
bool AiSD::Testing::testDelete(int opcja){
    BSTNode<int,std::string> *tmp;
    switch(opcja){
    case 1:
        tmp=test.root;
        if(tmp!=nullptr){
            return false;
        }
        break;
    case 2:
        if(tmp!=nullptr){
            return false;
        }
        if(tmp->left!=nullptr){
            std::cout<<"wskaznik posiada na lewego syna"<<'\n';
        }
        if(tmp->right!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na prawego synka"<<'\n';
        }
        if(tmp->parent!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na rodzica"<<'\n';
        }
        break;
    case 3:
        if(tmp!=nullptr){
            return false;
        }
        break;
    }
    return true;
}
bool AiSD::Testing::testClear(){
    test.Clear();
    dane.clear();
    if(test.root==nullptr){
        return true;
    }else{
        std::cout<<"drzewo nie zostalo usuniete"<<'\n';
        return false;
    }
    return false;
}
bool AiSD::Testing::testMin(){
    return true;
}
bool AiSD::Testing::testMax(){
    return true;
}
