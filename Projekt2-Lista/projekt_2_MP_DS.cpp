#include <iostream>

#include "MenadzerUzytkownika.cpp"
#include "DoublyLinkedList.cpp"

int main() {

    AiSD::MenadzerUzytkownika menadzerUzytkownika;
    int wybor;
    while(true) {
        wybor=menadzerUzytkownika.wczytajOpcjeZMenuGlowneg();
        switch(wybor) {
        case 0:
            exit(0);
            break;
        case 1:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 2:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 3:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 4:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 5:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 6:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 7:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 8:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 9:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 10:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 11:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 12:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 13:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 14:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 15:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 16:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 17:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 18:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 19:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 20:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        default:
            std::cout<<"Nie ma takiej opcji!"<<std::endl<<std::endl;
            break;
        }
    }
    return 0;
}
