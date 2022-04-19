#include "Sort.h"
#include <iostream>

using clockH=std::chrono::high_resolution_clock;



int AiSD::Sort::ShellSort(std::vector <Record> &records,bool ThreadSleep){
    int iloscElementow=records.size();
    auto start = clockH::now();

    for (int i=1; i<iloscElementow; i++)
    {
        for (int j=iloscElementow-1; j>=1; j--)
        {
            if (records[j].key<records[j-1].key)
            {
                Record bufor;
                bufor=records[j-1];
                records[j-1]=records[j];
                records[j]=bufor;
            }
            if(ThreadSleep)boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
        }

    }

    clock_t stop = clockH::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
}


int AiSD::Sort::QuickSort(std::vector <Record> &records, int lewy, int prawy,bool ThreadSleep){


    auto CzasStart = clockH::now();

    int v=records[(lewy+prawy)/2].key;
    Record record;
    int i,j;
    i=lewy;
    j=prawy;
    do
    {
        while (records[i].key<v) i++;
        while (records[j].key>v) j--;
        if (i<=j)
        {
            record=records[i];
            records[i]=records[j];
            records[j]=record;
            i++;
            j--;
        }
        if(ThreadSleep)boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
    }
    while (i<=j);
    if (j>lewy) QuickSort(records,lewy, j,ThreadSleep);
    if (i<prawy) QuickSort(records, i, prawy,ThreadSleep);

    auto CzasStop = clockH::now();
    //if(lewy==0)
    //std::cout<<"z "<<std::chrono::duration_cast<std::chrono::microseconds>(CzasStop-CzasStart).count()<<std::endl;
    return std::chrono::duration_cast<std::chrono::microseconds>(CzasStop-CzasStart).count();
}

int AiSD::Sort::MergeSort(std::vector <Record> &records, int start, int koniec,bool ThreadSleep)
{
    auto CzasStart = clockH::now();
    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec)/2;
        MergeSort(records, start, srodek,ThreadSleep);
        MergeSort(records, srodek+1, koniec,ThreadSleep);
        scalanie(records, start, srodek, koniec);
    }
    if(ThreadSleep)boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
    auto CzasStop = clockH::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(CzasStop-CzasStart).count();
}

void AiSD::Sort::scalanie(std::vector <Record> &records, int start, int srodek, int koniec)
{
    /*
    int *tab_pom = new int[(koniec-start+1)]; // utworzenie tablicy pomocniczej
    int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

    while (i <= srodek && j <= koniec)
    {
        if (records[j].key < records[i].key)
        {
            tab_pom[k] = records[j].key;
            j++;
        }
        else
        {
            tab_pom[k] = records[i].key;
            i++;
        }
        k++;
    }

    if (i <= srodek)
    {
        while (i <= srodek)
        {
            tab_pom[k] = records[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= koniec)
        {
            tab_pom[k] = tablica[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= koniec-start; i++)
        records[start+i] = tab_pom[i];

    delete [] tab_pom;*/
}

int AiSD::Sort::InsertionSort(std::vector <Record> &records,bool ThreadSleep)

{
    auto start = clockH::now();
    int n=records.size();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = records[i].key;
        j = i - 1;

        while (j >= 0 && records[j].key > key)
        {
            records[j + 1] = records[j];
            j = j - 1;
        }
        if(ThreadSleep)boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
        records[j + 1].key = key;
    }

    auto stop = clockH::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
}
