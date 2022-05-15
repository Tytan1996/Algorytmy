/*


*/
#include "Testing.h"
#include "BST.h"
#include <chrono>
#include <vector>
#include <map>
#include <queue>
void AiSD::Testing::randing(size_t amountOfElements) {
    std::vector<std::string> strukturaString;
    std::string randomString="";
    int liczba;
    int malypom;
    srand( time( NULL ) );
    for(size_t i=0; i<amountOfElements; ++i) {
        liczba=std::rand();
        dane.push_back(liczba);
        if(i==0) {
            malypom=liczba;
            duzy=liczba;
        }
        if(malypom>liczba) {
            malypom=liczba;
        }
        if(duzy<liczba) {
            duzy=liczba;
        }
        for(int j=0; j<10; ++j) {
            randomString+=std::rand()%90+33;
        }
        strukturaString.push_back(randomString);
        randomString="";
    }
    for(size_t i=0; i<amountOfElements; ++i) {
        test.Insert(dane[i],strukturaString[i]);
    }
    maly=malypom;
}
int AiSD::Testing::rand(float mnoznik) {
    std::string randomString="";
    int liczba;
    srand( time( NULL ) );
    liczba=mnoznik*test.root->key;
    dane.push_back(liczba);
    for(int j=0; j<10; ++j) {
        randomString+=std::rand()%90+33;
    }

    test.Insert(liczba,randomString);
    return liczba;

}
void AiSD::Testing::detailsTest() {

    std::cout<<"Prosze czekac, testy moga troche zajac!"<<std::endl;
    //testy zwiazanie z insert
    if(!testInsert(0,test.root)) {
        std::cout<<"root jest zle ustawiony, gdy nie ma ustawionego drzewa"<<'\n';
    }
    randing(1);
    if(!testInsert(1,test.root)) {
        std::cout<<"priewszy element nie zostal poprawnie ustawiony"<<'\n';
    }
    rand(1.0/2);
    if(!testInsert(2,test.root->left)) {
        std::cout<<"drzewo jest zle ustawione gdy dodanie jest lewy syn"<<'\n';
    }
    rand(2);
    if(!testInsert(3,test.root->right)) {
        std::cout<<"drzewo jest zle ustawione gdy dodanie jest prawy syn, po dodaniu lewego syna"<<'\n';
    }
    if(!testClear()) {
        std::cout<<"Clear dziala zle"<<'\n';
    }
    if(!testInsert(0,test.root)) {
        std::cout<<"wskaznik root zle pokazuje po clean"<<'\n';
    }
    randing(1);
    if(!testInsert(1,test.root)) {
        std::cout<<"priewszy element jest zle ustawiony"<<'\n';
    }
    rand(2);
    if(!testInsert(3,test.root->right)) {
        std::cout<<"dodawy jako priewszy prawy syn i poszlo cos nie tak"<<'\n';
    }
    rand(1.0/2);
    if(!testInsert(2,test.root->left)) {
        std::cout<<"dodany jako drugi element jako lewego syna i poszlo cos nie tak"<<'\n';
    }
    if(!testDelete(1)) {
        std::cout<<"Jedno elementowe drzewo jest zle usuwanie"<<'\n';
    }
    if(!testDelete(2)) {
        std::cout<<"Dwu elementowe drzewo jest zle usuwanie (1)"<<'\n';
    }
    if(!testDelete(3)) {
        std::cout<<"Dwu elementowe drzewo jest zle usuwanie (2)"<<'\n';
    }
    if(!testDelete(4)) {
        std::cout<<"Usuwanie root nie dzialaj poprawnie"<<'\n';
    }
    if(!testClear()) {
        std::cout<<"Clear dziala zle"<<'\n';
    }
    //if(!testMin()){
    //std::cout<<"MIN nie dziala poprawnie"<<'\n';
    //}
    if(!testClear()) {
        std::cout<<"Clear dziala zle"<<'\n';
    }
    //if(!testMax()){
    // std::cout<<"MAX nie dziala poprawnie"<<'\n';
    //}

}
void AiSD::Testing::generalTest() {
    size_t amountTest;
    int ilosc=0;
    std::vector<int>::iterator itr;
    std::cout<<"Ile chcesz wykonac testow?"<<std::endl;
    std::cout<<"Ilosc testow: ";
    std::cin>>amountTest;
    srand( time( NULL ) );
    int liczba;
    for(size_t i=0; i<amountTest; ++i) {
        int opcja;
        randing(amountTest);
        for(size_t j=0; j<10; ++j) {
            opcja=std::rand()%2+1;
            switch(opcja) {
            case 1:
                liczba=std::rand();
                test.Insert(liczba,"ff:");
                dane.push_back(liczba);
                break;

            case 2:
                liczba=std::rand();
                test.Delete(liczba);
                for(itr=dane.begin(); itr!=dane.end(); ++itr) {
                    if(liczba==*itr) {
                        dane.erase(itr);
                    }
                }
                break;
            }
            if(!sprawdWskazniki()) {
                ++ilosc;
            }

        }
        std::cout<<"Ilosc nieudanych testow: "<<ilosc<<'\n';

    }

}
bool AiSD::Testing::testInsert(int opcja,BSTNode<int,std::string> *tmp) {

    switch(opcja) {
    case 0:
        if(tmp!=nullptr) {
            std::cout<<"Element root NIE jest ustawiony na nullptr"<<std::endl;
            return false;
        }
        break;
    case 1:
        if(tmp->parent!=nullptr) {
            std::cout<<"priewszy utworozny element MA ustawionego wskiaznika na parent"<<'\n';
            return false;
        }
        if(tmp->left!=nullptr) {
            std::cout<<"priewszy utworozny element MA ustawionego wskiaznika na left"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr) {
            std::cout<<"priewszy utworozny element ma ustawionego wskiaznika na right"<<'\n';
            return false;
        }
        break;
    case 2: // sprawdzanie insert kiedy dodaje sie lewego syna
        if(tmp->parent==nullptr) {
            std::cout<<"Kolejny wartosc dodania do drzeqa nie posiada wskaznika na rodzica."<<'\n';
            return false;
        } else {
            if(tmp->parent->left==nullptr) {
                std::cout<<"Rodzic nie zawiera ustawionego wskaznika na lewego syna"<<'\n';
                return false;
            }
        }
        if(tmp->left!=nullptr) {
            std::cout<<"Nowy utworzony element posiada wskaznik na lewego syna (ktory nie ma prawa istniec)"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr) {
            std::cout<<"Nowy utworozny element posiada wskaznik na prawego syna (ktory nie ma prawa istniec)"<<'\n';
            return false;
        }
        break;
    case 3:// sprawdzanie insert kiedy dodaje sie prawego syna
        if(tmp->parent==nullptr) {
            std::cout<<"Kolejny wartosc dodania do drzewa nie posiada wskaznika na rodzica."<<'\n';
            return false;
        } else {
            if(tmp->parent->right==nullptr) {
                return false;
            }
        }
        if(tmp->left!=nullptr) {
            return false;
        }
        if(tmp->right!=nullptr) {
            return false;
        }
        break;

    }
    return true;
}
bool AiSD::Testing::testDelete(int opcja) {
    test.Clear();
    randing(1);
    int licz;
    switch(opcja) {
    case 1: //dla drzewa, ktory zawiera jeden element
        test.Delete(dane.front());
        tmp=test.root;
        if(tmp!=nullptr) {

            std::cout<<"root NIE jest ustawiony na nullptr"<<'\n';
            return false;
        }
        randing(1);
        tmp=test.root;
        if(!testInsert(1,tmp)) {
            std::cout<<"dodanie nowego elmentu po DELETE, gdy z drzewa usunieto wszystkie elementy"<<'\n';
            return false;
        }
        break;
    case 2: //dla drzewa, ktore ma dwa elementy (jeden z nich to jest lewy syn)
        rand(1.0/2);
        test.Delete(dane.back());
        tmp=test.root;
        if(tmp==nullptr) {
            return false;
        }
        if(tmp->left!=nullptr) {
            std::cout<<"wskaznik posiada wskaznik na lewego syna"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr) {
            std::cout<<"wskaznik posiada wskaznik na prawego syna"<<'\n';
            return false;
        }
        if(tmp->parent!=nullptr) {
            std::cout<<"wskaznik posiada wskaznik na rodzica"<<'\n';
            return false;
        }
        rand(1.0/2);
        if(!testInsert(2,tmp->left)) {
            return false;
        }
        test.Delete(dane.back());
        rand(2);
        tmp=test.root;
        if(!testInsert(3,tmp->right)) {
            return false;
        }
        break;
    case 3: //usuwanie prawego syna
        rand(2);
        test.Delete(dane.back());
        tmp=test.root;
        if(tmp==nullptr) {
            std::cout<<"root jest ustwawiony na nullptr"<<'\n';
            return false;
        }
        if(tmp->left!=nullptr) {
            std::cout<<"wskaznik posiada wskaznik na lewego syna"<<'\n';
            return false;
        }
        if(tmp->right!=nullptr) {
            std::cout<<"wskaznik posiada wskaznik na prawego synka"<<'\n';
            return false;
        }
        if(tmp->parent!=nullptr) {
            std::cout<<"wskaznik posiada wskaznik na rodzica"<<'\n';
            return false;
        }
        rand(2);
        if(!testInsert(3,tmp->right)) {
            return false;
        }
        test.Delete(dane.back());
        rand(1.0/2);
        if(!testInsert(2,tmp->left)) {
            return false;
        }
        break;
    case 4: //usuwanie root
        licz=rand(2);
        test.Delete(dane[0]);
        tmp=test.root;
        if(tmp->parent!=nullptr) {
            std::cout<<"root posiada wskaznik na parent, kiedy ma prawego syna"<<'\n';
            return false;
        }

        licz=rand(1.0/2);
        test.Delete(dane[0]);
        dane.pop_back();
        tmp=test.root;
        if(tmp->parent!=nullptr) {
            std::cout<<"nowy root ma zle ustawony wskaznik na parent"<<'\n';
            return false;
        }
        rand(2);
        rand(1.0/2);
        test.Delete(dane[0]);
        tmp=test.root;
        if(tmp->parent!=nullptr) {
            std::cout<<"nowy root ma ustawiony wskaznik na parent."<<'\n';
            return false;
        }
        break;
    }
    return true;
}
bool AiSD::Testing::testClear() {
    test.Clear();
    dane.clear();
    if(test.root==nullptr) {
        return true;
    } else {
        std::cout<<"drzewo nie zostalo usuniete"<<'\n';
        return false;
    }
}
bool AiSD::Testing::testMin() {
    randing(10);
    test.Min();
    if(maly!=test.Min()->key) {
        std::cout<<"wartosc Min sie nie zgadza"<<'\n';
        return false;
    }
    maly1=rand(1.0/2);
    if(maly1!=test.Min()->key) {
        std::cout<<"wartosc min nie dziala gdy nowy element jest dodany"<<'\n';
        return false;
    }
    test.Delete(maly1);
    if(maly!=test.Min()->key) {
        std::cout<<"wartosc min nie dziala gdy najmniejszy elemnt sie usuwa"<<'\n';
        return false;
    }
    return true;
}
bool AiSD::Testing::testMax() {
    randing(10);
    if(duzy!=test.Max()->key) {
        std::cout<<"wartosc Max sie nie zgadza"<<'\n';
        return false;
    }
    int duzy1=rand(2);
    std::cout<<duzy<<std::endl<<duzy1<<std::endl;
    if(duzy1!=test.Max()->key) {
        std::cout<<"wartosc max nie dziala gdy nowy element jest dodany"<<'\n';
        return false;
    }
    test.Delete(duzy1);
    if(duzy!=test.Max()->key) {
        std::cout<<"wartosc max nie dziala gdy najwiekszy elemnt sie usuwa"<<'\n';
        return false;
    }
    return true;
}
bool AiSD::Testing::sprawdWskazniki() {
    int ilosc;
    int iloscLisc=0;
    bool check=true;
    tmp=test.root;
    std::queue<BSTNode<int,std::string>> kolejka;
    if(tmp!=nullptr) {
        kolejka.push(*tmp);

        while(!kolejka.empty()) {
            tmp=&kolejka.front();
            if(tmp->left!=nullptr) {
                kolejka.push(*tmp->left);
                if(tmp->left->key>tmp->key) {
                    std::cout<<"lewy syn jest wiekszy niz rodzic."<<'\n';
                    check=false;

                }
                if(tmp->left->parent==nullptr) {
                    std::cout<<"lewy syn nie ma ustawionego wskanznika na rodzica."<<'\n';
                    check=false;
                } else {
                    if(tmp->left->parent->key!=tmp->key) {
                        std::cout<<"wartosc KEY nie zgadza sie."<<'\n';
                        check=false;
                    } else if(tmp->left->parent->data!=tmp->data) {
                        std::cout<<"wartosc DATA nie zgadza sie."<<'\n';
                        check=false;
                    }
                }
            }
            if(tmp->right!=nullptr) {
                kolejka.push(*tmp->right);
                if(tmp->right->key<tmp->key ) {
                    std::cout<<"prawy syn jest mniejszy niz rodzic."<<'\n';
                    check=false;

                }
                if(tmp->right->parent==nullptr) {
                    std::cout<<"prawy syn nie ma ustawionego wskanznika na rodziaca."<<'\n';
                    check=false;
                } else {
                    if(tmp->right->parent->key!=tmp->key) {
                        std::cout<<"wartosc KEY nie zgadza sie."<<'\n';
                        check=false;
                    } else if(tmp->right->parent->data!=tmp->data) {
                        std::cout<<"wartosc DATA nie zgadza sie."<<'\n';
                        check=false;
                    }
                }
            }
            if(tmp->right==nullptr && tmp->left==nullptr) {
                ++iloscLisc;
            }
            kolejka.pop();
            ilosc++;

        }
        if(iloscLisc!=test.leavesCount()) {
            std::cout<<"Ilosc lisci sie nie zgadza."<<'\n';
            check=false;
        }

    }
    return check;
}
