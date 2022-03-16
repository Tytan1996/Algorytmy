//Algorytmy Dynamiczna Tablica
//Maciej Pestka 170088
//Damian Szopinski 185394

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#define T long

#include <cstddef>
#include <iostream>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <malloc.h>


namespace AiSD{
    class DynamicArray
    {

        public:
            DynamicArray();
            DynamicArray(size_t rozmiar);
            DynamicArray(size_t rozmiar, size_t N, const T& t);
            DynamicArray(const DynamicArray &dynamicArray1);//copyconstruktor
            DynamicArray(DynamicArray&& dynamicArray); //move-constructor
            DynamicArray &operator =(const DynamicArray other); //copy assignment operator
            DynamicArray& operator =(DynamicArray& dynamicArray); //move assignment operator
            virtual ~DynamicArray();
            void Print();
            void Save();
            bool IsEmpty();
            bool IsFull();
            size_t Space();
            void PushBack(T t);
            void PopBack();
            void PushFront(T t);
            void PopFront();
            void Insert(T t, size_t i);
            void Erase(size_t i);
            //Funkcje na wymagania dodatkowe
            void Clear();
            size_t Search(const T& t);
            bool EraseFirst(const T& t);
            size_t EraseAll(const T& t);
            size_t Erase(size_t from, size_t to);
            T& operator [](size_t i);
            void Read();
            void PowiekszanieTablicy();
            T& at(size_t i);
            //funkcje z gwiazdka
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
struct Record{
    std::string name;
    unsigned grade;
};
#endif // DYNAMICARRAY_H
