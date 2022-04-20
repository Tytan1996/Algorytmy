#include "Sort.h"
#include <time.h>


Sort::Sort() {
    mapaDoDiag ["ilosc Porownan"]=0;
    mapaDoDiag ["ilosc Przypisania"]=0;
    mapaDoDiag ["wywolania Rekurencyjne"]=0;

}
void Sort::ShellSort(std::vector<Record>& records) {
    int iloscElementow=records.size();
    int halfSizeVector=iloscElementow/2;
    for(int i =halfSizeVector; i>0; i/=2){
        for(int j=i; j<iloscElementow; ++j){
            Record newRecords;
            newRecords=records[j];
            int k;
            for(k=j;k>=i &&records[k-i].key>newRecords.key;k-=i){
                records[k]=records[k-i];
            }
            records[k]=newRecords;
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
    int iloscElementow=records.size();
    int halfSizeVector=iloscElementow/2;
    for(int i =halfSizeVector; i>0; i/=2){
        for(int j=i; j<iloscElementow; ++j){
            Record newRecords;
            newRecords=records[j]; ++mapaDoDiag ["ilosc Przypisania"];
            int k;
            for(k=j;k>=i &&records[k-i].key>newRecords.key;k-=i, ++mapaDoDiag["ilosc Porownan"]){
                records[k]=records[k-i]; ++mapaDoDiag ["ilosc Przypisania"];
            }
            records[k]=newRecords; ++mapaDoDiag ["ilosc Przypisania"];
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
        while (records[i].key<v, ++mapaDoDiag["ilosc Porownan"]) i++;
        while (records[j].key>v, ++mapaDoDiag["ilosc Porownan"]) j--;
        if (i<=j, ++mapaDoDiag["ilosc Porownan"]) {
            record=records[i]; ++mapaDoDiag ["ilosc Przypisania"];
            records[i]=records[j]; ++mapaDoDiag ["ilosc Przypisania"];
            records[j]=record; ++mapaDoDiag ["ilosc Przypisania"];
            i++;
            j--;
        }
    } while (i<=j, ++mapaDoDiag["ilosc Porownan"]);
    if (j>lewy, ++mapaDoDiag["ilosc Porownan"]) QuickSort(records,lewy, j);
    if (i<prawy, ++mapaDoDiag["ilosc Porownan"]) QuickSort(records, i, prawy);
}
void Sort::Diag_MergeSort(std::vector<Record>& records,size_t start,size_t endVector) {
    int srodek;

    if (start != endVector, ++mapaDoDiag["ilosc Porownan"]) {
        srodek = records[(start + endVector)/2].key;
        MergeSort(records, start, srodek);
        MergeSort(records, srodek+1, endVector);
        scalanie(records, start, srodek, endVector);
    }
}
void Sort::Diag_InsertionSort(std::vector<Record>& records) {

    Record newRecord;
    int n=records.size();
    int i, j;
    for (i = 1; i < n; i++) {
        newRecord = records[i]; ++mapaDoDiag ["ilosc Przypisania"];
        j = i - 1;

        while (j >= 0 && records[j].key > newRecord.key, ++mapaDoDiag["ilosc Porownan"] ) {
            records[j + 1] = records[j]; ++mapaDoDiag ["ilosc Przypisania"];
            j = j - 1;
        }
        records[j + 1] = newRecord; ++mapaDoDiag ["ilosc Przypisania"];
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
