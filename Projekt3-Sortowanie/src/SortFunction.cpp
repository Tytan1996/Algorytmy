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
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}
int AiSD::QuickSort(std::vector<Record>& records) {
    Sort sortujaca;
    size_t wielkoscVectora=records.size();
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.QuickSort(records, 0, wielkoscVectora);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}
int AiSD::MergeSort(std::vector<Record>& records) {
    Sort sortujaca;
    size_t wielkoscVectora=records.size();
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.MergeSort(records,0,wielkoscVectora);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}

int AiSD::InsertionSort(std::vector<Record>& records) {
    Sort sortujaca;
    auto startTimeSort=std::chrono::high_resolution_clock::now();
    sortujaca.InsertionSort(records);
    auto endTimeSort = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();std::chrono::duration_cast<std::chrono::microseconds>(endTimeSort-startTimeSort).count();
}
void Diag_ShellSort(std::vector<Record>& records){
    Sort sortujaca;
    sortujaca.Diag_ShellSort();
    sortujaca.pokazWynikDiag();

}
void Diag_QuickSort(std::vector<Record>& records){
    Sort sortujaca;
    sortujaca.Diag_QuickSort();
    sortujaca.pokazWynikDiag();
    }
void Diag_MergeShort(std::vector<Record>& records){
    Sort sortujaca;
    sortujaca.Diag_MergeShort();
    sortujaca.pokazWynikDiag();
    }
void Diag_InsertionSort(std::vector<Record>& records){
    Sort sortujaca;
    sortujaca.InsertionSort();
    sortujaca.pokazWynikDiag();
    }
