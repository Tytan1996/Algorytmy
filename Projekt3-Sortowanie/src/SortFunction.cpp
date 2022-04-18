#include "SortFunction.h"
#include "Sort.h"
#include <iostream>
#include <Sort.h>

Sort sortujaca;

clock_t AiSD::ShellSort(std::vector<Record>& records){
    return sortujaca.ShellSort(records);
}
clock_t AiSD::QuickSort(std::vector<Record>& records)
{
    size_t wielkoscVectora=records.size();
    return sortujaca.QuickSort(records, 0, wielkoscVectora);
}
clock_t MergeShort(std::vector<Record>& records){

    size_t wielkoscVectora=records.size();
    return sortujaca.MergeSort(records,0,wielkoscVectora);

}
clock_t InsertionSort(std::vector<Record>& records){

    return sortujaca.InsertionSort(records);

}
