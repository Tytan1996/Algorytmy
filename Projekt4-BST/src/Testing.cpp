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
int AiSD::Testing::rand(float mnoznik) {
    std::string randomString="";
    int liczba;
    srand( time( NULL ) );
    liczba=mnoznik*test.root->key;
    dane.push_back(liczba);
    for(int j=0;j<10;++j){
        randomString+=std::rand()%90+33;
    }

    test.Insert(liczba,randomString);
    return liczba;

}
void AiSD::Testing::detailsTest(){

    std::cout<<"Prosze czekac, testy moga troche zajac!"<<std::endl;
    //testy zwiazanie z insert
    if(!testInsert(0,test.root)){
        std::cout<<"root jest zle ustawiony, gdy nie ma ustawionego drzewa"<<'\n';
    }
    randing(1);
    if(!testInsert(1,test.root)){
        std::cout<<"priewszy element nie zostal poprawnie ustawiony"<<'\n';
    }
    rand(1.0/2);
    if(!testInsert(2,test.root->left)){
        std::cout<<"drzewo jest zle ustawione gdy dodanie jest lewy syn"<<'\n';
    }
    rand(2);
    if(!testInsert(3,test.root->right)){
        std::cout<<"drzewo jest zle ustawione gdy dodanie jest prawy syn, po dodaniu lewego syna"<<'\n';
    }
    if(!testClear()){
        std::cout<<"Clear dziala zle"<<'\n';
    }
    if(!testInsert(0,test.root)){
        std::cout<<"wskaznik root zle pokazuje po clean"<<'\n';
    }
    randing(1);
    if(!testInsert(1,test.root)){
        std::cout<<"priewszy element jest zle ustawiony"<<'\n';
    }
    rand(2);
    if(!testInsert(3,test.root->right)){
        std::cout<<"dodawy jako priewszy prawy syn i poszlo cos nie tak"<<'\n';
    }
    rand(1.0/2);
    if(!testInsert(2,test.root->left)){
        std::cout<<"dodany jako drugi element jako lewego syna i poszlo cos nie tak"<<'\n';
    }
    if(!testDelete(1)){
        std::cout<<"Jedno elementowe drzewo jest zle usuwanie"<<'\n';
    }
    if(!testDelete(2)){
        std::cout<<"Dwu elementowe drzewo jest zle usuwanie (1)"<<'\n';
    }
    if(!testDelete(3)){
        std::cout<<"Dwu elementowe drzewo jest zle usuwanie (2)"<<'\n';
    }
    if(!testDelete(4)){
        std::cout<<"Usuwanie priewszego elementu cos poszlo nie tak"<<'\n';
    }
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
        if(tmp!=nullptr){
            std::cout<<"Element root NIE jest ustawiony na nullptr"<<std::endl;
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
    test.Clear();
    randing(1);
    int licz;
    switch(opcja){
    case 1: //dla drzewa, ktory zawiera jeden element
        test.Delete(dane.front());
        tmp=test.root;
        if(tmp!=nullptr){
            std::cout<<"root NIE jest ustawiony na nullptr"<<'\n';
            return false;
        }
        randing(1);
        tmp=test.root;
        if(!testInsert(1,tmp)){
            std::cout<<"dodanie nowego elmentu po DELETE, gdy z drzewa usunieto wszystkie elementy"<<'\n';
            return false;
        }
        break;
    case 2: //dla drzewa, ktore ma dwa elementy (jeden z nich to jest lewy syn)
        rand(1.0/2);
        test.Delete(dane.back());
        tmp=test.root;
        if(tmp==nullptr){
            return false;
        }
        if(tmp->left!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na lewego syna"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na prawego synka"<<'\n';
            return false;
        }
        if(tmp->parent!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na rodzica"<<'\n';
            return false;
        }
        rand(1.0/2);
        if(!testInsert(2,tmp->left)){
            return false;
        }
        test.Delete(dane.back());
        rand(2);
        tmp=test.root;
        if(!testInsert(3,tmp->right)){
            return false;
        }
        break;
    case 3: //usuwanie prawego syna
        rand(2);
        test.Delete(dane.back());
        tmp=test.root;
        if(tmp==nullptr){
            std::cout<<"root jest ustwawiony na nullptr"<<'\n';
            return false;
        }
        if(tmp->left!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na lewego syna"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na prawego synka"<<'\n';
            return false;
        }
        if(tmp->parent!=nullptr){
            std::cout<<"wskaznik posiada wskaznik na rodzica"<<'\n';
            return false;
        }
        rand(2);
        if(!testInsert(3,tmp->right)){
            return false;
        }
        test.Delete(dane.back());
        rand(1.0/2);
        if(!testInsert(2,tmp->left)){
            return false;
        }
        break;
    case 4:
        licz=rand(2);
        test.ShowBSTTree();
        test.Delete(dane[0]);
        std::cout<<'\n';
        test.ShowBSTTree();
        tmp=test.root;
        if(!testInsert(dane[0],tmp)){
            std::cout<<"zle przupisanie wskazniki po usuniecu priewszego elementu drzewa (1)"<<'\n';
            return false;
        }
        if(licz!=tmp->key){
            std::cout<<"Wartosci key sie nie zgadzaja"<<'\n';
            return false;
        }

        licz=rand(1.0/2);
        test.Delete(dane[0]);
        dane.pop_back();
        tmp=test.root;
        if(!testInsert(dane[0],tmp)){
            std::cout<<"zle przupisanie wskazniki po usuniecu priewszego elementu drzewa (2)"<<'\n';
            return false;
        }
        if(licz!=tmp->key){
            std::cout<<"Wartosci key sie nie zgadzaja"<<'\n';
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
}
bool AiSD::Testing::testMin(){
    return true;
}
bool AiSD::Testing::testMax(){
    return true;
}
