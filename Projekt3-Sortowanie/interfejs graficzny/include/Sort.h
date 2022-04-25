#ifndef SORT_H
#define SORT_H
#include <chrono>
#include <vector>
#include <boost/thread.hpp>
#include "SortThread.hpp"
#include "StructRecord.hpp"

namespace AiSD
{

class Sort
{
public:
    void ShellSort(std::vector<Record>& records);
    void QuickSort(std::vector<Record>& records, size_t start, size_t end);
    void MergeSort(std::vector<Record>& records, size_t start, size_t end);
    void InsertionSort(std::vector<Record>& records);
    void Diag_ShellSort(std::vector<Record>& records, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep);
    void Diag_QuickSort(std::vector<Record>& records, size_t start, size_t end, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep);
    void Diag_MergeSort(std::vector<Record>& records,size_t start,size_t end, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep);
    void Diag_InsertionSort(std::vector<Record>& records, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep);

private:
    void Merge(std::vector<Record>& records, size_t start, size_t middle, size_t end);
    void Diag_Merge(std::vector<Record>& records, size_t start, size_t middle, size_t end, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep);


};

}
#endif // SORT_H
