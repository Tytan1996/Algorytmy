#include "SortFunction.h"
#include "Sort.h"
#include <iostream>
#include <Sort.h>
#include <chrono>

int AiSD::ShellSort(std::vector<Record>& records) {
    Sort sortujaca;
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.ShellSort(records);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
    std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}
int AiSD::QuickSort(std::vector<Record>& records) {
    Sort sortujaca;
    size_t wielkoscVectora=records.size();
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.QuickSort(records, 0, wielkoscVectora);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
    std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}
int AiSD::MergeSort(std::vector<Record>& records) {
    Sort sortujaca;
    size_t wielkoscVectora=records.size();
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.MergeSort(records,0,wielkoscVectora);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
    std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}

int AiSD::InsertionSort(std::vector<Record>& records) {
    Sort sortujaca;
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.InsertionSort(records);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
    std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}
std::map <std::string,size_t> AiSD::Diag_ShellSort(std::vector<Record>& records) {
    std::map <std::string, size_t> mapToShellSort;
    mapToShellSort ["ilosc wywolania funkcji Diag_ShellSort"]=0;
    mapToShellSort["ilosc porownian"]=0;
    mapToShellSort["ilosc przypisania"]=0;
    Sort sortujaca;
    sortujaca.Diag_ShellSort(records,mapToShellSort);
    return mapToShellSort;
}
std::map <std::string,size_t> AiSD::Diag_QuickSort(std::vector<Record>& records) {
    std::map<std::string, size_t> mapToQuickSort;
    mapToQuickSort["ilosc wywolania funkcji Diag_QuickSort"]=0;
    mapToQuickSort["ilosc porownian"]=0;
    mapToQuickSort["ilosc przypisania"]=0;
    Sort sortujaca;
    sortujaca.Diag_QuickSort(records,0,records.size(), mapToQuickSort);
    return mapToQuickSort;
}
std::map <std::string,size_t> AiSD::Diag_MergeSort(std::vector<Record>& records) {
    std::map<std::string, size_t> mapToMergeSort;
    mapToMergeSort["ilosc wywolania funkcji Diag_MergeSort"]=0;
    mapToMergeSort["ilosc wywolania funkcji Diag_Merge"]=0;
    mapToMergeSort["ilosc porownian"]=0;
    mapToMergeSort["ilosc przypisania"]=0;
    mapToMergeSort["ilosc utworzenie nowego wektora"]=0;
    mapToMergeSort["ilosc wstawienia wartosci do wektora"]=0;
    Sort sortujaca;
    sortujaca.Diag_MergeSort(records,0,records.size(),mapToMergeSort);
    return mapToMergeSort;
}
std::map <std::string,size_t> AiSD::Diag_InsertionSort(std::vector<Record>& records) {
    std::map<std::string, size_t> mapToInsertionSort;
    mapToInsertionSort["ilosc wywolania funkcji Diag_InsertionSort"]=0;
    mapToInsertionSort["ilosc porownian"]=0;
    mapToInsertionSort["ilosc przypisania"]=0;
    Sort sortujaca;
    sortujaca.Diag_InsertionSort(records,mapToInsertionSort);
    return mapToInsertionSort;
}
