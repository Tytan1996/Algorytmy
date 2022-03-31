#include <iostream>


#include "MenadzerUzytkownika.h"
#include "TestingFunction.hpp"

#include <cstdlib>
#include <time.h>

const bool debugMode=false;

int main() {

    AiSD::MenadzerUzytkownika menadzerUzytkownika;
    std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl;
    std::cout<<"Sprawdzanie czasu operacji na tablicy (najwieksze mozliwe argumenty funkcji)"<<std::endl;

    AiSD::OverflowTable testing(500000);
    testing.test(debugMode);

    AiSD::DistortionsSimulation testing1(1000);
    testing1.doMultipleTimes(20,debugMode);
    std::cout<<"1 - menu1"<<std::endl;
    std::cout<<"2 - menu2"<<std::endl;
    std::cout<<"opcja: ";
    int wyborWybranaMenu=menadzerUzytkownika.wczytajLiczbeCalkowita();
    if(wyborWybranaMenu==1){
        AiSD::Presentation testing2;
        testing2.test(debugMode);
    }else if(wyborWybranaMenu==2){
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
                menadzerUzytkownika.dodajElementNaKoncu();
                break;
            case 3:
                menadzerUzytkownika.usunElementZPoczatku();
                break;
            case 4:
                menadzerUzytkownika.usunElementZKoncu();
                break;
            case 5:
                menadzerUzytkownika.wstawElementNaPozycjiI();
                break;
            case 6:
                menadzerUzytkownika.usunElementNaPozycjiI();
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
                menadzerUzytkownika.wstawElementPrzedPozycjiI();
                break;
            case 16:
                menadzerUzytkownika.wstawElementPoPozycjiI();
                break;
            case 17:
                menadzerUzytkownika.usunElementPrzedPozycjiI();
                break;
            case 18:
                menadzerUzytkownika.usunElementNaPozycjiI();
                break;
            case 19:
                menadzerUzytkownika.zapisListeDoPliku();
                break;
            case 20:
                menadzerUzytkownika.odczytListeZPliku();
                break;
            default:
                std::cout<<"Nie ma takiej opcji!"<<std::endl<<std::endl;
                break;
            }
        }
    }else{
        std::cout<<"wybrano zla opcje"<<std::endl;
    }

    return 0;
}
