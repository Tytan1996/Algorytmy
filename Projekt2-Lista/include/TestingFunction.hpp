//Algorytmy Dynamiczna Tablica
//Damian Szopinski 185394
//Maciej Pestka 170088

/*
*TESTINGFUNCTION_HPP_FILE
*/
#ifndef TESTINGFUNCTION_HPP
#define TESTINGFUNCTION_HPP

#include "DoublyLinkedList.h"

#include <cstddef>
#include <sstream>
#include <functional>
#include <chrono>
#include <string>
#include <random>
#include <variant>
#include <limits>
#include <windows.h>

#include <memory>

#include "Logger.hpp"



namespace AiSD
{
    using T=Record;

    /**@brief
    *   Pusta struktura. Varianty nie moga przyjmowac typ void. Alternatywnie moglem uzyc wbudowanego "monostate".
    */
    struct noneV{};

    /**@brief
    *   Klasa bazowa, na ktorej postawie klase OverflowTable, DistortionsSimulation i Presentation
    */
    class ClassTest
    {
    public:
        std::unique_ptr<DLL> pointer;
        ClassTest()
        {
            pointer=std::unique_ptr<DLL>(new DLL());
        }

        virtual void test();

        using arg_t = std::variant <bool, T, size_t,noneV>;
        using return_t = std::function<arg_t(DLL& a,T t1,size_t i1)>;

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
        //tutaj zostawiam auto gdyz nie musze w ten sposob includowac wszystkich bibliotek do DynamicArray.h
        arg_t DoFunction(DLL& arr,short int NO,T t,size_t i);

        struct FunctionInfo
        {
            std::string type;
            return_t func;
        };
        /**@brief
        *   Funkcja zwraca strukture FunctionInfo zawierajaca string nazwy funkcji i makro funkcji.
        *@param NO
        *   Numer funkcji Dynamic Array od 0
        *@param cap
        *   Rozmiar tablicy
        */
        FunctionInfo FunctionByNO(short int NO);

    };

    class OverflowTable : public ClassTest
    {
        int repeat;
    public:
        OverflowTable(int repeatOperation):ClassTest()
        {
            repeat=repeatOperation;
        }

        /**@brief
        *   Wykonuje te same funkcje Dynamic Array do pusta i pelna. Pesymistyczny scenariusz jest taki, ze przyjmujemy zawsze te najwieksze liczby jakie moge wprowadzic.
        *   Mierzy czas dla funkcji powtarzanej tyle razy jaka jest wielkosc tablicy.
        *   Przy okazji testuje takie sytuacje kiedy dodajemy kolejny element do pelnej tablicy oraz usuwamy element z pustej tablicy. Robi to poza mierzeniem czasu.
        *   Zmierzony czas jest w mikrosekundach i wyswietla sie na ekranie.
        *
        *@param arr
        *   Dynamic Array
        */
        void test() override;
    };

    class DistortionsSimulation : public ClassTest
    {
    private:
        int t;
    public:
        //TUTAJ ZROBIC JESZCZE KONSTRUKTOR WCZYTUJACY T
        DistortionsSimulation(int NumberOfOperations):ClassTest()
        {
            t=NumberOfOperations;
        }

        /**@brief
        *   Symulacja zaklocen funkcji. Wykonuje losowe funkcje dla losowych arguumentow. Mierzy czas. Zapisuje dane do pliku log, na wypadek crashu.
        *
        *@param arr
        *   Dynamic Array
        *@param t
        *   Ile losowych operacji ma sie wykonac
        */
        void test() override;

        /**@brief
        *   Execute test function multiple times
        */
        void doMultipleTimes(unsigned int times);
    };

    class Presentation : public ClassTest
    {
    public:
        Presentation():ClassTest(){}

        /**@brief
        *   NIESKONCZONA PETLA!!! (Interacja z uzytkownikiem).
        *   Korzystanie z klasy Dynamic Array z poziomu wiersza polecen. (Reczne testowanie)
        *   Oprocz wyswietlanych danych w konsoli zapisuje rowniez tez logi w pliku "Log.txt"
        *@param arr
        *   Dynamic Array
        */
        void test() override;

        /**@brief
        *   Funkcja wczytujaca od uzytkownika zmienna typu G
        */
        template<typename G> G getNum();
    };
}



#endif // TESTINGFUNCTION_HPP
