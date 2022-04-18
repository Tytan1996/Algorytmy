#include "Sort.h"
#include <time.h>

clock_t Sort::ShellSort(std::vector<Record>& records){
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
clock_t Sort::QuickSort(std::vector<Record>& records, int lewy, int prawy){

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
clock_t Sort::MergeSort(std::vector<Record>& records, int poczatek, int koniec)
{

    start = clock();
    int srodek;

    if (start != koniec)
    {
        srodek = records[(poczatek + koniec)/2].key;
        MergeSort(records, poczatek, srodek);
        MergeSort(records, srodek+1, koniec);
        scalanie(records, poczatek, srodek, koniec);
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    return czas;
}
void Sort::scalanie(std::vector<Record>& records, int start, int srodek, int koniec)
{
    std::vector<Record> newRecords;
    int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

    while (i <= srodek && j <= koniec)
    {
        if (records[j].key < records[i].key)
        {
            newRecords.push_back(records[j]);
            j++;
        }
        else
        {
            newRecords.push_back(records[i]);
            i++;
        }
        k++;
    }

    if (i <= srodek)
    {
        while (i <= srodek)
        {
            newRecords.push_back(records[i]);
            i++;
            k++;
        }
    }
    else
    {
        while (j <= koniec)
        {
            newRecords.push_back(records[j]);
            j++;
            k++;
        }
    }

    for (i = 0; i <= koniec-start; i++)
        records[start+i] = newRecords[i];
        newRecords.clear();

}
clock_t Sort::InsertionSort(std::vector<Record>& records)
{
    start = clock();
    Record newRecord;
    int n=records.size();
    int i, j;
    for (i = 1; i < n; i++)
    {
        newRecord = records[i];
        j = i - 1;

        while (j >= 0 && records[j].key > newRecord.key)
        {
            records[j + 1] = records[j];
            j = j - 1;
        }
        records[j + 1] = newRecord;
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    return czas;
}
void Sort::Diag_ShellSort(std::vector<Record>& records){
    int iloscElementow=records.size();
    int iloscPorownan=0, iloscPrzypisania=0;
    for (int i=1; i<iloscElementow; i++)
    {
        for (int j=iloscElementow-1; j>=1; j--)
        {
            if (records[j].key<records[j-1].key; ++iloscPorownan)
            {
                Record bufor;
                bufor=records[j-1];
                ++iloscPrzypisania;
                records[j-1]=records[j];
                ++iloscPrzypisania;
                records[j]=bufor;
                ++iloscPrzypisania;
            }
        }
    }
    std::cout<<"Ilosc porownia: "<<iloscPorownan<<std::endl;
    std::cout<<"Ilosc przipisan: "<<iloscPrzypisania<<std::endl;
}
void Sort::Diag_QuickSort(std::vector<Record>& records){
    /*
    int iloscPorownian=0,iloscPrzypisania=0,iloscWywolanRekurencyjnych=0;
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
    if (i<prawy) QuickSort(records, i, prawy);*/
}
void Sort::Diag_MergeSort(std::vector<Record>& records){
}
void Sort::Diag_InsertionSort(std::vector<Record>& records){
}

void Sort::pokaz(std::vector<Record> records )
{
    for (std::vector<Record> :: iterator itr = records.begin(); itr != records.end(); itr++)
    {
        std::cout<<itr->key<<" ";
    }
}
