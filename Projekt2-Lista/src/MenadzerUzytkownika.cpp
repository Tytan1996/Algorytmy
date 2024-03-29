#include "MenadzerUzytkownika.h"

AiSD::Logger2 plikZZapisem("Log1.txt");

int AiSD::MenadzerUzytkownika::wczytajOpcjeZMenuGlowneg() {
    int opcja;
    std::cout<<"0 - zakon program"<<std::endl;
    std::cout<<"1 - dodaj element na poczatku listy"<<std::endl;
    std::cout<<"2 - dodaj element na konczu listy"<<std::endl;
    std::cout<<"3 - usun element z poczatku listy"<<std::endl;
    std::cout<<"4 - usun element z koncu listy"<<std::endl;
    std::cout<<"5 - dodaj elemeten na i-tej pozycji"<<std::endl;
    std::cout<<"6 - usun element na i-tej pozycji"<<std::endl;
    std::cout<<"7 - zwroc element na poczatku listy"<<std::endl;
    std::cout<<"8 - zwroc element na koncu listy"<<std::endl;
    std::cout<<"9 - sprawdzenie czy lista jest pusta"<<std::endl;
    std::cout<<"10 - sprawdz rozmiar listy"<<std::endl;
    std::cout<<"11 - usun wszystkie elementy listy"<<std::endl;
    std::cout<<"12 - pokaz liste od poczatku"<<std::endl;
    std::cout<<"13 - pokaz liste od konca"<<std::endl;
    std::cout<<"14 - sprawdz czy wiezel jest na liscie"<<std::endl;
    std::cout<<"15 - dodaj element przed elementem"<<std::endl;
    std::cout<<"16 - dodaj element po elemencie"<<std::endl;
    std::cout<<"17 - usun element przed elementem"<<std::endl;
    std::cout<<"18 - usun element po elemencie"<<std::endl;
    std::cout<<"19 - zapis liste do pliku"<<std::endl;
    std::cout<<"20 - wczytaj liste z pliku"<<std::endl;
    opcja=wczytajLiczbeCalkowita();
    return opcja;

}


unsigned AiSD::MenadzerUzytkownika::wczytajLiczbe() {
    std::string wejscie = "";
    unsigned liczba = 0;
    while (true) {
        getline(std::cin, wejscie);

        std::stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    return liczba;
}
std::string AiSD::MenadzerUzytkownika::wczytajString() {
    std::string wejscie = "";
    getline(std::cin, wejscie);
    return wejscie;
}

void AiSD::MenadzerUzytkownika::dodajElementNaPoczatku() {
    try {
        start=pobierzCzas();
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        lista.PushFront(nowyRecod);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("PushFront", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::dodajElementNaKoncu() {
    try {
        start=pobierzCzas();
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        lista.PushBack(nowyRecod);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("PushBack", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::usunElementZPoczatku() {
    try {
        start=pobierzCzas();
        lista.PopFront();
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("PopFront", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::usunElementZKoncu() {
    try {
        start=pobierzCzas();
        lista.PopBack();
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("PopBack", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::pokazElementZPoczatku() {
    try {
        start=pobierzCzas();
        std::cout<<"Poczatek na poczatku listy: "<<lista.Front().name<<","<<lista.Front().grade<<std::endl;
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Front", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::pokazElementZKoncu() {
    try {
        start=pobierzCzas();
        std::cout<<"Poczatek na koncu listy: "<<lista.Back().name;
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Back", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::pokazListe() {
    try {
        start=pobierzCzas();
        lista.Print();
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Print (pokaz liste z przodu)", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::pokazListeOdTylu() {
    try {
        start=pobierzCzas();
        lista.Print1();
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Print1 (pokaz elementy z tylu)", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::czyListaJestPusta() {
    try {
        start=pobierzCzas();
        if(lista.IsEmpty()==true) {
            std::cout<<"Lista jest pusta"<<std::endl;
        } else {
            std::cout<<"Lista NIE jest pusta"<<std::endl;
        }
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("IsEmpty", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::pokazRozmiar() {
    try {
        start=pobierzCzas();
        std::cout<<"Rozmiar tablicy: "<<lista.Size()<<std::endl;
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Size", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::usunListe() {
    try {
        start=pobierzCzas();
        lista.Clear();
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Clear", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::pokazCzyWezelJestNaLisce() {
    try {
        start=pobierzCzas();
        std::cout<<"Podaj wartosc szukanie wezla: ";
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        if(lista.IsInList(nowyRecod)==true) {
            std::cout<<"Jest wezel na liscie!"<<std::endl;
        } else {
            std::cout<<"Nie ma wezla na liscie!"<<std::endl;
        }
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("IsInList", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::wstawElementNaPozycjiI() {
    try {
        start=pobierzCzas();
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.Insert(nowyRecod, i);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Insert", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::usunElementNaPozycjiI() {
    try {
        start=pobierzCzas();
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.Delete(i);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("Delete", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::wstawElementPrzedPozycjiI() {
    try {
        start=pobierzCzas();
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.InsertBefore(nowyRecod, i);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("InsertBefore", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::wstawElementPoPozycjiI() {
    try {
        start=pobierzCzas();
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.InsertAfter(nowyRecod, i);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("InsertAfter", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::usunElementPrzedPozycjiI() {
    try {
        start=pobierzCzas();
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.DeleteBefore(i);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("DeleteBefore", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::usunElementPoPozycjiI() {
    try {
        start=pobierzCzas();
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.DeleteAfter(i);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("DeleteAfter", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::zapisListeDoPliku() {
    try {
        start=pobierzCzas();
        std::cout<<"Nazwa pliku: "<<std::endl;
        std::string nazwaPliku=wczytajString();
        lista.SaveCSV(nazwaPliku);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("SaveCSV", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}
void AiSD::MenadzerUzytkownika::odczytListeZPliku() {
    try {
        start=pobierzCzas();
        std::cout<<"Nazwa pliku z ktorego chcesz wczytac plik: "<<std::endl;
        std::string nazwaPliku=wczytajString();
        lista.LoadCSV(nazwaPliku);
        koniec=pobierzCzas();
        czas=policzCzas(koniec,start);
        std::string nowyString=utworzString("LoadCSV", czas);
        plikZZapisem.zapis(nowyString);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
        plikZZapisem.zapis(komunitakBledu);
    }
}


clock_t AiSD::MenadzerUzytkownika::pobierzCzas(){
    return clock();
}
double AiSD::MenadzerUzytkownika::policzCzas(clock_t koniec,clock_t start){
    double czas;
    czas=double(koniec-start)/CLOCKS_PER_SEC;
    return czas;
}

std::string AiSD::MenadzerUzytkownika::utworzString(std::string nazwaFunkcji, double czas){
    std::string komunikat="";
    komunikat+=nazwaFunkcji;
    komunikat+=" wykonala sie w czasie: ";
    komunikat+=std::to_string(czas);
    std::cout<<komunikat<<std::endl;
    return komunikat;
}
int AiSD::MenadzerUzytkownika::wczytajLiczbeCalkowita(){
    std::string wejscie = "";
    unsigned liczba = 0;
    while (true) {
        getline(std::cin, wejscie);

        std::stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    system("cls");
    return liczba;
}
