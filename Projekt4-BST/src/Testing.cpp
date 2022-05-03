/*


*/
#include "Testing.h"
#include <chrono>
#include <vector>

void AiSD::Testing::randing(size_t amountOfElements) {
    std::vector<unsigned short> struktura;
    unsigned short liczba;
    srand( time( NULL ) );
    for(size_t i=0; i<amountOfElements; ++i) {
        liczba=std::rand();
        struktura.push_back(liczba);
    }
    for(size_t i=0; i<amountOfElements; ++i) {
        std::cout<<struktura[i]<<std::endl;
    }

}
void AiSD::Testing::detailsTest(){


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
            if(!testInsert()){
                std::cout<<"blad insert!"<<std::endl;
                std::cout<<"Zle dziala funkcja."<<std::endl;
                return;
            }
            break;
        case 2:
            if(!testDelete()){
                std::cout<<"blad delete!"<<std::endl;
                std::cout<<"Zle dziala funkcja."<<std::endl;
                return;
            }
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
bool AiSD::Testing::testInsert() {
    /*
    if(opcja==1){
        if(parent!=nullptr){
            return false;
        }
        if(left!=nullptr){
            return false;
        }
        if(right!=nullptr){
            return false;
        }
    }else if(opcja==2){
        if(parent==nullptr){
            return false;
        }
        if(left!=nullptr){
            return false;
        }
        if(right!=nullptr){
            return false;
        }
    }
    return true;*/
}
bool AiSD::Testing::testDelete(){
    return true;
}
bool AiSD::Testing::testClear(){
    return true;
}
bool AiSD::Testing::testMin(){
    return true;
}
bool AiSD::Testing::testMax(){
    return true;
}
