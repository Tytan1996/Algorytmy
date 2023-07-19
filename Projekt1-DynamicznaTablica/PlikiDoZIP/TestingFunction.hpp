//Algorytmy Dynamiczna Tablica
//Damian Szopinski 185394
//Maciej Pestka 170088

/*
*TESTINGFUNCTION_HPP_FILE
*/
#ifndef TESTINGFUNCTION_HPP
#define TESTINGFUNCTION_HPP

#include "DynamicArray.h"

#include <cstddef>
#include <sstream>
#include <functional>
#include <chrono>
#include <string>
#include <random>
#include <variant>


namespace AiSD
{

    /**@brief
    *   Ta funkcja zapisuje do pliku o sciezce src zawartosc in
    *
    *@param src
    *   Sciezka pliku
    *@param in
    *   Zawartosc do dodania do pliku
    */
    void Log(std::string src,std::string in);

    /**@brief
    *   Ta funkcja wykonuje funkcje Dynamic Array, gdzie NO to numer funkcji od 0.
    *   Zapisje wszystkie operacje do pliku (LogFileName "Log.txt") na wypadek crashu. Mierzy takze czas wykonywania operacji w mikrosekundach.
    *   Zwraca variant<bool,size_t,noneV (nothing)> (jako to co pierwotna funkcja Dynamic Array nam zwracala)
    *
    *@param arr
    *   Dynamic Array
    *@param NO
    *   Numer funkcji Dynamic Array od 0
    *@param t
    *   Pierwszy parametr funkcji Dynamic Array
    *@param i
    *   Drugi parametr funkcji Dynamic Array
    */
    auto DoFunction(DynamicArray& arr,int NO,T t,size_t i,size_t i2);

    /**@brief
    *   Zwraca makro funkcji z Dynamic Array.
    *   A dokladniej std::function<variant <bool, size_t,noneV> (AiSD::DynamicArray& a,T t1,size_t i1,size_t i2)>
    *@param NO
    *   Numer funkcji Dynamic Array od 0
    *@param cap
    *   Rozmiar tablicy
    */
    auto FunctionByNO(int NO,size_t cap);


    /**@brief
    *   Symulacja zaklocen funkcji. Wykonuje losowe funkcje dla losowych arguumentow. Mierzy czas. Zapisuje dane do pliku log, na wypadek crashu.
    *
    *@param arr
    *   Dynamic Array
    *@param t
    *   Ile losowych operacji ma sie wykonac
    */
    void DistortionsSimulation(DynamicArray& arr,int t);

    /**@brief
    *   Wykonuje te same funkcje Dynamic Array do pusta i pelna. Pesymistyczny scenariusz jest taki, ze przyjmujemy zawsze te najwieksze liczby jakie moge wprowadzic.
    *   Mierzy czas dla funkcji powtarzanej tyle razy jaka jest wielkosc tablicy.
    *   Przy okazji testuje takie sytuacje kiedy dodajemy kolejny element do pelnej tablicy oraz usuwamy element z pustej tablicy. Robi to poza mierzeniem czasu.
    *   Zmierzony czas jest w mikrosekundach i wyswietla sie na ekranie.
    *
    *@param arr
    *   Dynamic Array
    */
    void OverflowTable(DynamicArray& arr);

    /**@brief
    *   NIESKONCZONA PETLA!!! (Interacja z uzytkownikiem).
    *   Korzystanie z klasy Dynamic Array z poziomu wiersza polecen. (Reczne testowanie)
    *   Oprocz wyswietlanych danych w konsoli zapisuje rowniez tez logi w pliku "Log.txt"
    *@param arr
    *   Dynamic Array
    */
    void Presentation(DynamicArray& arr);

    /**@brief
    *   Mala funkcja do otrzymania bierzacego czasu.
    */
    auto _setNow();

    /**@brief
    *   Zwraca dlugosc czasu pomiedzy dwoma chrono podany w string w mikrosekundach
    */
    std::string _timeTook(auto a,auto b);

    /**@brief
    *   Oproznia plik Log.
    */
    void ClearLogTxt();

    /**@brief
    *   Pusta struktura. Varianty nie moga przyjmowac typ void. Alternatywnie moglem uzyc wbudowanego "monostate".
    */
    struct noneV{};
}



#endif // TESTINGFUNCTION_HPP
