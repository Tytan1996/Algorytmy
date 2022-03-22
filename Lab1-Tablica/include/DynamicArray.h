//Algorytmy Dynamiczna Tablica
//Maciej Pestka 170088
//Damian Szopinski 185394

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#define T long

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


namespace AiSD{
    class DynamicArray
    {

        public:
            /**@brief
            *   Ta metoda jest konstruktorem, ktora ustawia parametry poczatkowe.
            */
            DynamicArray();
            /**@brief
            *   Te konstuktory dzialaja jak wedlug instrukcji
            */
            DynamicArray(size_t rozmiar);
            DynamicArray(size_t rozmiar, size_t N, const T& t);
            /**@brief
            *   Te konstuktory dodatkowe z * dzialaja.
            */
            DynamicArray(const DynamicArray &dynamicArray1);//copyconstruktor
            DynamicArray(DynamicArray&& dynamicArray); //move-constructor
            DynamicArray &operator =(const DynamicArray other); //copy assignment operator
            DynamicArray& operator =(DynamicArray& dynamicArray); //move assignment operator
            /**@brief
            *   Te destruktor usuwa dynamiczna tablice;
            */
            virtual ~DynamicArray();
            /**@brief
            *   Ta metoda pokazuje zawartsc tablicy
            */
            void Print();
            /**@brief
            *   Ta metoda zapisuje do pliku
            */
            void Save();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1).
            *   Sprawdza czy tablica jest pusta
            */
            bool IsEmpty();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1).
            *   Sprawdza czy tablica jest pelna.
            */
            bool IsFull();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1).
            *   Pokazuje wartosc miejsca w tablicy
            */
            size_t Space();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1)
            *   Jesli zakres tablicy jest przepelniony to czas jest troche inny.
            *   Dodaje element t do tablicy na koncu tablicy.
            */
            void PushBack(T t);
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1).
            *   Ta metoda usuwa ostatni element z tablicy.
            */
            void PopBack();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size)
            *   Jesli zakres tablicy jest przepelniony to czas jest troche inny.
            *   Dodaje element t na poczartku tablicy.
            */
            void PushFront(T t);
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size).
            *   Usuwa element tablicy na poczatku.
            */
            void PopFront();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size).
            *   Dodaje element t na pozycji i.
            */
            void Insert(T t, size_t i);
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size).
            *   Usuwa element na i-tej pozycji.
            */
            void Erase(size_t i);
            /**@brief
            *   Ten przeciazony operator dziala tak samo jak dla tablic.
            */
            T& operator [](size_t i);
            //Funkcje na wymagania dodatkowe
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w czasie O(size).
            *   Usuwa cala zawartosc tablicy i ustawa size na 0.
            */
            void Clear();
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w czasie O(size).
            *   Szuka priewszy element t w tablicy.
            */
            size_t Search(const T& t);
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w czasie O(size).
            *   Usuwa prierwszy element t w tablicy.
            */
            bool EraseFirst(const T& t);
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji NIE w czasie O(size).
            *   Usuwa wszystkie elementy t w tablicy.
            */
            size_t EraseAll(const T& t);
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w NIE JESTEM PEWNY czasie O(size).
            *   Usuwa elementy tablicy od i-tej pozycji(from) do j-tej pozycji (to). Zakres usuwania elementow to [from,to).
            */
            size_t Erase(size_t from, size_t to);
            /**@brief
            *   Ten operator czyta plik z wartosciami tablic.
            */
            void Read();
            /**@brief
            *   Ta metoda (dodatkowa) dziala poprawnie.
            *   Powieksza rozmiar tablicy o 2.
            */
            void PowiekszanieTablicy();
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak w isntrukcji w czasie O(1)
            */
            T& at(size_t i);
            //funkcje z gwiazdka
            /**@brief
            *   Ta metoda (dodatkowa z *) dodaje na pozycji 'i' tyle elementow t ile jest nadanie w operacji.
            */
            void Insert(T t, size_t iloscElementow, size_t i);

        protected:

        private:
            friend auto DoFunction(DynamicArray&,int,T,size_t,size_t);
            friend void OverflowTable(DynamicArray&);

            T wczytajLiczbeCalkowita();
            size_t capacity;
            size_t size;
            const std::string nazwaPliku="ZawartoscTablicy.txt";
            T *tablica;


    };
}
/**@brief
*   struktora zostala utworzona i próbowalem zamiast T ja zastapic, ale cos sie nie udalo.
*/
struct Record{
    std::string name;
    unsigned grade;
};
#endif // DYNAMICARRAY_H
