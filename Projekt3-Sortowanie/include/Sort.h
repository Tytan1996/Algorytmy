#ifndef SORT_H
#define SORT_H
#include <chrono>

class Sort
{
    struct Record{
    int key;
    char ID[5];

};
    public:
        void ShellSort(int *tab, int n);
        void QuickSort(int *tablica, int lewy, int prawy);
        void MergeSort(int tablica[], int start, int koniec);
        void InsertionSort(int *tab, int n);

    protected:

    private:

        void scalanie(int tablica[], int start, int srodek, int koniec);
        clock_t start,stop;
        double czas;
        void wcztyajTabliceZPliku();
        void zapisPosortowonaTabliceDoPliku();


};

#endif // SORT_H
