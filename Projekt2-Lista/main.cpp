#include <iostream>


#include "MenadzerUzytkownika.h"


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
            menadzerUzytkownika.dodajElementNaPoczatku();
            break;
        case 2:
            menadzerUzytkownika.dodajElementNaPoczatku();
            break;
        case 3:
            menadzerUzytkownika.usunElementZPoczatku();
            break;
        case 4:
            menadzerUzytkownika.usunElementZKoncu();
            break;
        case 5:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 6:
            std::cout<<"obecna opcja jest niedostepna"<<std::endl;
            break;
        case 7:
            menadzerUzytkownika.pokazElementZPoczatku();
            break;
        case 8:
            menadzerUzytkownika.pokazElementZKoncu();
            break;
        case 9:
            menadzerUzytkownika.czyListaJestPusta();
            break;
        case 10:
            menadzerUzytkownika.pokazRozmiar();
            break;
        case 11:
            menadzerUzytkownika.usunListe();
            break;
        case 12:
            menadzerUzytkownika.pokazListe();
            break;
        case 13:
            menadzerUzytkownika.pokazListeOdTylu();
            break;
        case 14:
            menadzerUzytkownika.pokazCzyWezelJestNaLisce();
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
