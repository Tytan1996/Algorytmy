#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#define T long

#include <cstddef>
#include <iostream>
#include <array>

using namespace std;

namespace AiSD{
    class DynamicArray
    {
        size_t capacity;
        size_t size;

        public:
            DynamicArray(T rozmiar);
            virtual ~DynamicArray();
            void Print();
            bool IsEmpty();
            bool IsFull();
            size_t Space();
            void PushBack(T t);
            void PopBack();
            void PushFront(T t);

            /*
            void PushFront(T t);
            void PopFront();
            void Insert(T t, size_t i);
            void Erase(size_t i);
            */


        protected:

        private:
            T tablica[];

    };
}
#endif // DYNAMICARRAY_H
