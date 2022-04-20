#ifndef SORTFUNCTION_H
#define SORTFUNCTION_H
#include <chrono>
#include <vector>
#include <struktura.h>

namespace AiSD {
int ShellSort(std::vector<Record>& records);
int QuickSort(std::vector<Record>& records);
int MergeSort(std::vector<Record>& records);
int InsertionSort(std::vector<Record>& records);

void Diag_ShellSort(std::vector<Record>& records);
void Diag_QuickSort(std::vector<Record>& records);
void Diag_MergeSort(std::vector<Record>& records);
void Diag_InsertionSort(std::vector<Record>& records);
}
#endif // SORTFUNCTION_H
