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
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1)
            */
            bool IsEmpty();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1)
            */
            bool IsFull();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1)
            */
            size_t Space();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1)
            *   Jesli zakres tablicy jest przepelniony to czas jest troche inny.
            */
            void PushBack(T t);
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(1)
            */
            void PopBack();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size)
            *   Jesli zakres tablicy jest przepelniony to czas jest troche inny.
            */
            void PushFront(T t);
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size)
            */
            void PopFront();
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size)
            */
            void Insert(T t, size_t i);
            /**@brief
            *   Ta metoda dziala zgodnie jak wedlug instrukcji w czasie O(size)
            */
            void Erase(size_t i);
            /**@brief
            *   Ten przeciazony operator dziala tak samo jak dla tablic
            */
            T& operator [](size_t i);
            //Funkcje na wymagania dodatkowe
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w czasie O(size)
            */
            void Clear();
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w czasie O(size)
            */
            size_t Search(const T& t);
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w czasie O(size)
            */
            bool EraseFirst(const T& t);
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji NIE w czasie O(size)
            */
            size_t EraseAll(const T& t);
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak wedlug instrukcji w NIE JESTEM PEWNY czasie O(size)
            */
            size_t Erase(size_t from, size_t to);
            /**@brief
            *   Ten operator czyta plik z wartosciami tablic;
            */
            void Read();
            /**@brief
            *   Ta metoda (dodatkowa) dziala poprawnie.
            */
            void PowiekszanieTablicy();
            /**@brief
            *   Ta metoda (dodatkowa) dziala zgodnie jak w isntrukcji w czasie O(1)
            */
            T& at(size_t i);
            //funkcje z gwiazdka
            /**@brief
            *   Ta metoda (dodatkowa z *) dodaje na pozycji 'i' tyle elementow t ile jest nadanie w operacji
            */
            void Insert(T t, size_t iloscElementow, size_t i);

        protected:

        private:
            friend auto DoFunction(DynamicArray&,int,T,size_t);
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
