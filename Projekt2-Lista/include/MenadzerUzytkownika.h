#ifndef MENADZERUZYTKOWNIKA_H
#define MENADZERUZYTKOWNIKA_H


#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include "DoublyLinkedList.h"
#include "Logger.hpp"

namespace AiSD{
    class MenadzerUzytkownika{
        unsigned wczytajLiczbe();
        std::string wczytajString();
        AiSD::DLL lista;

        clock_t start,koniec;
        double czas;

    public:
        int wczytajOpcjeZMenuGlowneg();
        void dodajElementNaPoczatku();
        void dodajElementNaKoncu();
        void usunElementZPoczatku();
        void usunElementZKoncu();
        void pokazElementZPoczatku();
        void pokazElementZKoncu();
        void czyListaJestPusta();
        void pokazRozmiar();
        void usunListe();
        void pokazCzyWezelJestNaLisce();
        void pokazListe();
        void pokazListeOdTylu();
        void wstawElementNaPozycjiI();
        void usunElementNaPozycjiI();
        void wstawElementPrzedPozycjiI();
        void wstawElementPoPozycjiI();
        void usunElementPrzedPozycjiI();
        void usunElementPoPozycjiI();
        void zapisListeDoPliku();
        void odczytListeZPliku();
        clock_t pobierzCzas();
        double policzCzas(clock_t koniec,clock_t start);
        void zapisDoPlikuLog(std::string nazwaMetody, double czas);
    };

}




#endif // MENADZERUZYTKOWNIKA_H
