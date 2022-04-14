#ifndef SORT_H
#define SORT_H
#include <chrono>
#include <vector>
#include <boost/thread.hpp>

struct Record{
    int key;
    char ID[5];

};
class Sort
{

    public:
        clock_t ShellSort(std::vector <Record> &records,bool ThreadSleep);
        clock_t QuickSort(std::vector <Record> &records, int lewy, int prawy,bool ThreadSleep);
        clock_t MergeSort(std::vector <Record> &records, int start, int koniec,bool ThreadSleep);
        clock_t InsertionSort(std::vector <Record> &records,bool ThreadSleep);

    protected:

    private:
        //std::vector <Record> records;
        void scalanie(std::vector <Record> &records, int start, int srodek, int koniec);
        clock_t start,stop;
        double czas;
        void wcztyajTabliceZPliku();
        void zapisPosortowonaTabliceDoPliku();


};

#endif // SORT_H
