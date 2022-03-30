#include <iostream>


#include "MenadzerUzytkownika.h"
#include "TestingFunction.hpp"

#include <cstdlib>
#include <time.h>

const bool debugMode=false;

int main()
{

    clock_t start,koniec;
    double czas;
    std::cout<<"Szczegolowe informacje od. wykonywania funkcji znajduje sie w pliku Log.txt"<<std::endl;
    std::cout<<"Sprawdzanie czasu operacji na tablicy (najwieksze mozliwe argumenty funkcji)"<<std::endl;

        AiSD::OverflowTable testing(50);
        testing.test(debugMode);

        AiSD::DistortionsSimulation testing1(100);
        testing1.doMultipleTimes(20,debugMode);

        AiSD::Presentation testing2;
        testing2.test(debugMode);


    AiSD::MenadzerUzytkownika menadzerUzytkownika;
    int wybor;


    while(true) {
       wybor=menadzerUzytkownika.wczytajOpcjeZMenuGlowneg();
        switch(wybor) {
        case 0:
            exit(0);
            break;
        case 1:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.dodajElementNaPoczatku();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 2:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.dodajElementNaKoncu();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 3:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.usunElementZPoczatku();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 4:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.usunElementZKoncu();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 5:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.wstawElementNaPozycjiI();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 6:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.usunElementNaPozycjiI();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 7:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.pokazElementZPoczatku();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 8:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.pokazElementZKoncu();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 9:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.czyListaJestPusta();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 10:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.pokazRozmiar();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 11:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.usunListe();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 12:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.pokazListe();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 13:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.pokazListeOdTylu();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 14:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.pokazCzyWezelJestNaLisce();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 15:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.wstawElementPrzedPozycjiI();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 16:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.wstawElementPoPozycjiI();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 17:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.usunElementPrzedPozycjiI();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 18:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.usunElementNaPozycjiI();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 19:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.zapisListeDoPliku();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        case 20:
            start=menadzerUzytkownika.pobierzCzas();
            menadzerUzytkownika.odczytListeZPliku();
            koniec=menadzerUzytkownika.pobierzCzas();
            czas=menadzerUzytkownika.policzCzas(koniec,start);
            menadzerUzytkownika.zapisDoPlikuLog("1", czas);
            break;
        default:
            std::cout<<"Nie ma takiej opcji!"<<std::endl<<std::endl;
            break;
        }
    }
    return 0;
}
