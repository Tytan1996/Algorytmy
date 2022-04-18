#ifndef SORTFUNCTION_H
#define SORTFUNCTION_H
#include <chrono>
#include <vector>
#include <struktura.h>

namespace AiSD{
    clock_t ShellSort(std::vector<Record>& records);
    clock_t QuickSort(std::vector<Record>& records);
    clock_t MergeShort(std::vector<Record>& records);
    clock_t InsertionSort(std::vector<Record>& records);
}
#endif // SORTFUNCTION_H
