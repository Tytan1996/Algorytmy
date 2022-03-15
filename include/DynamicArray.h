#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#define T long

#include <cstddef>
#include <iostream>
#include <array>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace AiSD{
    class DynamicArray
    {

        public:
            DynamicArray(T rozmiar);
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

        protected:

        private:
            T wczytajLiczbeCalkowita();
            size_t capacity;
            size_t size;
            const string nazwaPliku="ZawartoscTablicy.txt";
            T *tablica;

    };
}

#endif // DYNAMICARRAY_H
