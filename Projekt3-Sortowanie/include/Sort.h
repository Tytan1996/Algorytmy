#ifndef SORT_H
#define SORT_H
#include <vector>
#include <iostream>
#include <struktura.h>
#include <map>



class Sort {
public:
    Sort();
    void ShellSort(std::vector<Record>& records);
    void QuickSort(std::vector<Record>& records, int lewy, int prawy);
    void MergeSort(std::vector<Record>& records, int start, int koniec);
    void InsertionSort(std::vector<Record>& records);
    void Diag_ShellSort(std::vector<Record>& records);
    void Diag_QuickSort(std::vector<Record>& records);
    void Diag_MergeSort(std::vector<Record>& records,int poczatek, int koniec);
    void Diag_InsertionSort(std::vector<Record>& records);
    void pokaz(std::vector<Record> records );
    void pokazWynikDiag();


private:
    void scalanie(std::vector<Record>& records, int start, int srodek, int koniec);
    std::map <std::string,int> mapaDoDiag;

};


#endif // SORT_H
