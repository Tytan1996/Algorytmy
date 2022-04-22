#ifndef SORTFUNCTION_H
#define SORTFUNCTION_H
#include <chrono>
#include <vector>
#include <struktura.h>
#include <map>
#include <iostream>

namespace AiSD {
int ShellSort(std::vector<Record>& records);
int QuickSort(std::vector<Record>& records);
int MergeSort(std::vector<Record>& records);
int InsertionSort(std::vector<Record>& records);

std::map <std::string,size_t> Diag_ShellSort(std::vector<Record>& records);
std::map <std::string,size_t> Diag_QuickSort(std::vector<Record>& records);
std::map <std::string,size_t> Diag_MergeSort(std::vector<Record>& records);
std::map <std::string,size_t> Diag_InsertionSort(std::vector<Record>& records);
}
#endif // SORTFUNCTION_H
