#ifndef MENADZERUZYTKOWNIKA_H
#define MENADZERUZYTKOWNIKA_H


#include <iostream>
#include <sstream>
#include "DoublyLinkedList.h"


namespace AiSD{
    class MenadzerUzytkownika{
        int wczytajLiczbe();
        AiSD::DLL lista;

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
    };

}




#endif // MENADZERUZYTKOWNIKA_H
