#include "MenadzerUzytkownika.h"

AiSD::Logger2 plikZZapisem("log.txt");

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
    opcja=wczytajLiczbe();
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
    system("cls");
    return liczba;
}
std::string AiSD::MenadzerUzytkownika::wczytajString() {
    std::string wejscie = "";
    getline(std::cin, wejscie);
    return wejscie;
}

void AiSD::MenadzerUzytkownika::dodajElementNaPoczatku() {
    try {
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        lista.PushFront(nowyRecod);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::dodajElementNaKoncu() {
    try {
        Record nowyRecod;
        std::cout<<"Dodaj liczbe: "<<std::endl;
        unsigned element=wczytajLiczbe();
        std::cout<<"Dodaj nazwe: "<<std::endl;
        std::string nazwa=wczytajString();
        nowyRecod.grade=element;
        nowyRecod.name=nazwa;
        lista.PushBack(nowyRecod);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::usunElementZPoczatku() {
    try {
        lista.PopFront();
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::usunElementZKoncu() {
    try {
        lista.PopBack();
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazElementZPoczatku() {
    try {
        std::cout<<"Poczatek na poczatku listy: "<<lista.Front().name<<","<<lista.Front().grade<<std::endl;
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazElementZKoncu() {
    try {
        std::cout<<"Poczatek na koncu listy: "<<lista.Back().name;
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazListe() {
    try {
        lista.Print();
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazListeOdTylu() {
    try {
        lista.Print1();
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::czyListaJestPusta() {
    try {
        if(lista.IsEmpty()==true) {
            std::cout<<"Lista jest pusta"<<std::endl;
        } else {
            std::cout<<"Lista NIE jest pusta"<<std::endl;
        }
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazRozmiar() {
    try {
        std::cout<<"Rozmiar tablicy: "<<lista.Size()<<std::endl;
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::usunListe() {
    try {
        lista.Clear();
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazCzyWezelJestNaLisce() {
    try {
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
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::wstawElementNaPozycjiI() {
    try {
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
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::usunElementNaPozycjiI() {
    try {
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.Delete( i);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::wstawElementPrzedPozycjiI() {
    try {
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
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::wstawElementPoPozycjiI() {
    try {
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
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::usunElementPrzedPozycjiI() {
    try {
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.DeleteBefore(i);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::usunElementPoPozycjiI() {
    try {
        std::cout<<"Dodaj pozycje wstawienie elementu (1 do "<<lista.Size()<<")"<<std::endl;
        size_t i=wczytajLiczbe();
        lista.DeleteAfter(i);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
<<<<<<< HEAD
void AiSD::MenadzerUzytkownika::zapisListeDoPliku() {
    try {
        std::cout<<"Nazwa pliku: "<<std::endl;
        std::string nazwaPliku=wczytajString();
        lista.SaveCSV(nazwaPliku);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::odczytListeZPliku() {
    try {
        std::cout<<"Nazwa pliku z ktorego chcesz wczytac plik: "<<std::endl;
        std::string nazwaPliku=wczytajString();
        lista.LoadCSV(nazwaPliku);
    } catch(const char* komunitakBledu) {
        std::cout<<komunitakBledu<<std::endl;
    }
}

=======
clock_t AiSD::MenadzerUzytkownika::pobierzCzas(){
    return clock();
}
double AiSD::MenadzerUzytkownika::policzCzas(clock_t koniec,clock_t start){
    double czas;
    czas=double(koniec-start)/CLOCKS_PER_SEC;
    return czas;
}
void  AiSD::MenadzerUzytkownika::zapisDoPlikuLog(std::string nazwaMetody, double czas){
    std::string linia ="";
    linia+=nazwaMetody;
    linia+=" wykonala sie w: ";
    linia+=std::to_string(czas);
    std::cout<<linia<<std::endl;
    plikZZapisem.zapis(linia);
}
>>>>>>> feature/hmm
