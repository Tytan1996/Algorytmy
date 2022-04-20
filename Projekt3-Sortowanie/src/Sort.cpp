#include "Sort.h"
#include <time.h>


Sort::Sort() {
    mapaDoDiag ["ilosc Porownan"]=0;
    mapaDoDiag ["ilosc Przypisania"]=0;
    mapaDoDiag ["wywolania Rekurencyjne"]=0;

}
void Sort::ShellSort(std::vector<Record>& records) {
    int iloscElementow=records.size();
    for (int i=1; i<iloscElementow; i++) {
        for (int j=iloscElementow-1; j>=1; j--) {
            if (records[j].key<records[j-1].key) {
                Record bufor;
                bufor=records[j-1];
                records[j-1]=records[j];
                records[j]=bufor;
            }
        }
    }
}
void Sort::QuickSort(std::vector<Record>& records, int lewy, int prawy) {

    int v=records[(lewy+prawy)/2].key;
    Record record;
    int i,j;
    i=lewy;
    j=prawy;
    do {
        while (records[i].key<v) i++;
        while (records[j].key>v) j--;
        if (i<=j) {
            record=records[i];
            records[i]=records[j];
            records[j]=record;
            i++;
            j--;
        }
    } while (i<=j);
    if (j>lewy) QuickSort(records,lewy, j);
    if (i<prawy) QuickSort(records, i, prawy);
}
void Sort::MergeSort(std::vector<Record>& records, int poczatek, int koniec) {

    int srodek;

    if (poczatek != koniec) {
        srodek = (poczatek + koniec)/2;
        MergeSort(records, poczatek, srodek);
        MergeSort(records, srodek+1, koniec);
        scalanie(records, poczatek, srodek, koniec);
    }
}
void Sort::scalanie(std::vector<Record>& records, int start, int srodek, int koniec) {
    std::vector<Record> newRecords;
    int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

    while (i <= srodek && j <= koniec) {
        if (records[j].key < records[i].key) {
            newRecords.push_back(records[j]);
            j++;
        } else {
            newRecords.push_back(records[i]);
            i++;
        }
        k++;
    }

    if (i <= srodek) {
        while (i <= srodek) {
            newRecords.push_back(records[i]);
            i++;
            k++;
        }
    } else {
        while (j <= koniec) {
            newRecords.push_back(records[j]);
            j++;
            k++;
        }
    }

    for (i = 0; i <= koniec-start; i++)
        records[start+i] = newRecords[i];

    newRecords.clear();

}
void Sort::InsertionSort(std::vector<Record>& records) {
    Record newRecord;
    int sizeVector=records.size();
    int i, j;
    for (i = 1; i < sizeVector; i++) {
        newRecord = records[i];
        j = i - 1;

        while (j >= 0 && records[j].key > newRecord.key) {
            records[j + 1] = records[j];
            j = j - 1;
        }
        records[j + 1] = newRecord;
    }
}
void Sort::Diag_ShellSort(std::vector<Record>& records) {
    int sizeVector=records.size();
    for (int i=1; i<sizeVector; i++) {
        for (int j=sizeVector-1; j>=1; j--) {
            if (records[j].key<records[j-1].key) {
                Record bufor;
                bufor=records[j-1];
                ++mapaDoDiag ["ilosc Przypisania"];
                records[j-1]=records[j];
                ++mapaDoDiag ["ilosc Przypisania"];
                records[j]=bufor;
                ++mapaDoDiag ["ilosc Przypisania"];
            }
        }
    }
}
void Sort::Diag_QuickSort(std::vector<Record>& records) {

    int lewy=0;
    int prawy=records.size();
    int v=records[(lewy+prawy)/2].key;
    Record record;
    int i,j;
    i=lewy;
    j=prawy;
    do {
        while (records[i].key<v) i++;
        while (records[j].key>v) j--;
        if (i<=j) {
            record=records[i]; ++mapaDoDiag ["ilosc Przypisania"];
            records[i]=records[j]; ++mapaDoDiag ["ilosc Przypisania"];
            records[j]=record; ++mapaDoDiag ["ilosc Przypisania"];
            i++;
            j--;
        }
    } while (i<=j);
    if (j>lewy) QuickSort(records,lewy, j);
    if (i<prawy) QuickSort(records, i, prawy);
}
void Sort::Diag_MergeSort(std::vector<Record>& records,int poczatek, int koniec) {
    int srodek;

    if (poczatek != koniec) {
        srodek = records[(poczatek + koniec)/2].key;
        MergeSort(records, poczatek, srodek);
        MergeSort(records, srodek+1, koniec);
        scalanie(records, poczatek, srodek, koniec);
    }
}
void Sort::Diag_InsertionSort(std::vector<Record>& records) {

    Record newRecord;
    int n=records.size();
    int i, j;
    for (i = 1; i < n; i++) {
        newRecord = records[i];
        ++mapaDoDiag["ilosc Przypisania"];
        j = i - 1;

        while (j >= 0 && records[j].key > newRecord.key ) {
            ++mapaDoDiag["ilosc Porownan"];
            records[j + 1] = records[j];
            ++mapaDoDiag["ilosc Przypisania"];
            j = j - 1;
        }
        records[j + 1] = newRecord;
        ++mapaDoDiag["ilosc Przypisania"];
    }

}

void Sort::pokaz(std::vector<Record> records ) {
    for (std::vector<Record> :: iterator itr = records.begin(); itr != records.end(); itr++) {
        std::cout<<itr->key<<" ";
    }
}
void Sort::pokazWynikDiag(){
    std::cout<<mapaDoDiag ["ilosc Porownan"]<<std::endl;
    std::cout<<mapaDoDiag ["ilosc Przypisania"]<<std::endl;
    std::cout<<mapaDoDiag ["wywolania Rekurencyjne"]<<std::endl;
}
