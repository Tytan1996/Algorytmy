#include "MenadzerUzytkownika.h"



int AiSD::MenadzerUzytkownika::wczytajOpcjeZMenuGlowneg(){
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


int AiSD::MenadzerUzytkownika::wczytajLiczbe(){
    std::string wejscie = "";
    int liczba = 0;
    while (true)
    {
        getline(std::cin, wejscie);

        std::stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
        system("cls");
    return liczba;
}
void AiSD::MenadzerUzytkownika::dodajElementNaPoczatku(){
    std::cout<<"Dodaj liczbe: "<<std::endl;
    short element=wczytajLiczbe();
    lista.PushFront(element);
}
void AiSD::MenadzerUzytkownika::dodajElementNaKoncu(){
    std::cout<<"Dodaj liczbe: "<<std::endl;
    short element=wczytajLiczbe();
    lista.PushFront(element);
}
void AiSD::MenadzerUzytkownika::usunElementZPoczatku(){
    lista.PopFront();
}
void AiSD::MenadzerUzytkownika::usunElementZKoncu(){
    lista.PopBack();
}
void AiSD::MenadzerUzytkownika::pokazElementZPoczatku(){
    std::cout<<"Poczatek na poczatku listy: "<<lista.Front()<<std::endl;
}
void AiSD::MenadzerUzytkownika::pokazElementZKoncu(){
    std::cout<<"Poczatek na koncu listy: "<<lista.Back();
}
void AiSD::MenadzerUzytkownika::pokazListe(){
    lista.Print();
}
void AiSD::MenadzerUzytkownika::pokazListeOdTylu(){
    lista.Print1();
}
void AiSD::MenadzerUzytkownika::czyListaJestPusta(){
    if(lista.IsEmpty()==true){
        std::cout<<"Lista jest pusta"<<std::endl;
    }else{
        std::cout<<"Lista NIE jest pusta"<<std::endl;
    }
}
void AiSD::MenadzerUzytkownika::pokazRozmiar(){
    std::cout<<"Rozmiar tablicy: "<<lista.Size()<<std::endl;
}
void AiSD::MenadzerUzytkownika::usunListe(){
    lista.Clear();
}
void AiSD::MenadzerUzytkownika::pokazCzyWezelJestNaLisce(){
    std::cout<<"Podaj wartosc szukanie wezla: ";
    short wartosc=wczytajLiczbe();
    if(lista.IsInList(wartosc)==true){
        std::cout<<"Jest wezel na liscie!"<<std::endl;
    }else{
        std::cout<<"Nie ma wezla na liscie!"<<std::endl;
    }
}
