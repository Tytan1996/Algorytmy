#include "Sort.h"



clock_t Sort::ShellSort(std::vector <Record> records){
    int iloscElementow=records.size();
    start = clock();
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
        }
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    return czas;
}
clock_t Sort::QuickSort(std::vector <Record> records, int lewy, int prawy){

    start = clock();

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
    }
    while (i<=j);
    if (j>lewy) QuickSort(records,lewy, j);
    if (i<prawy) QuickSort(records, i, prawy);
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    return czas;
}
clock_t Sort::MergeSort(std::vector <Record> records, int start, int koniec)
{

    start = clock();
    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec)/2;
        MergeSort(records, start, srodek);
        MergeSort(records, srodek+1, koniec);
        scalanie(records, start, srodek, koniec);
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    return czas;
}
void Sort::scalanie(std::vector <Record> records, int start, int srodek, int koniec)
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
clock_t Sort::InsertionSort(std::vector <Record> records)
{
    start = clock();
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
        records[j + 1].key = key;
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    return czas;
}
