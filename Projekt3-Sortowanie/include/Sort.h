#ifndef SORT_H
#define SORT_H
#include <chrono>
#include <vector>
#include <iostream>
#include <struktura.h>
#include <map>



class Sort
{
    public:
        Sort();
        clock_t ShellSort(std::vector<Record>& records);
        clock_t QuickSort(std::vector<Record>& records, int lewy, int prawy);
        clock_t MergeSort(std::vector<Record>& records, int start, int koniec);
        clock_t InsertionSort(std::vector<Record>& records);
        void Diag_ShellSort(std::vector<Record>& records);
        void Diag_QuickSort(std::vector<Record>& records);
        void Diag_MergeSort(std::vector<Record>& records);
        void Diag_InsertionSort(std::vector<Record>& records);
        void pokaz(std::vector<Record> records );

    protected:

    private:
        void scalanie(std::vector<Record>& records, int start, int srodek, int koniec);
        clock_t start,stop;
        double czas;
        std::map <std::string,int> mapaDoDiag;

};


#endif // SORT_H
