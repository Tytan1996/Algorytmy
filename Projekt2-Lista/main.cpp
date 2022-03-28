#include <iostream>


#include "MenadzerUzytkownika.h"
#include "TestingFunction.hpp"

int main()
{

    std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl<<std::endl;
    std::cout<<"Sprawdzanie czasu operacji na tablicy (najwieksze mozliwe argumenty funkcji)"<<std::endl;
    {
        AiSD::OverflowTable testing(5);
        testing.test();
    }
    //{
    //    AiSD::DistortionsSimulation testing(1000);
    //    testing.doMultipleTimes(20);
    //}
    //{
        //AiSD::Presentation testing();
        //testing.test();
    //}





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