#include "Sort.h"



void Sort::ShellSort(int *tab, int n){
    start = clock();
    for (int i=1; i<n; i++)
    {
        for (int j=n-1; j>=1; j--)
        {
            if (tab[j]<tab[j-1])
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
}
void Sort::QuickSort(int *tablica, int lewy, int prawy){

    start = clock();
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy) QuickSort(tablica,lewy, j);
    if (i<prawy) QuickSort(tablica, i, prawy);
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
}
void Sort::MergeSort(int tablica[], int start, int koniec)
{

    start = clock();
    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec)/2;
        MergeSort(tablica, start, srodek);
        MergeSort(tablica, srodek+1, koniec);
        scalanie(tablica, start, srodek, koniec);
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
}
void Sort::scalanie(int tablica[], int start, int srodek, int koniec)
{

    int *tab_pom = new int[(koniec-start+1)]; // utworzenie tablicy pomocniczej
    int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

    while (i <= srodek && j <= koniec)
    {
        if (tablica[j] < tablica[i])
        {
            tab_pom[k] = tablica[j];
            j++;
        }
        else
        {
            tab_pom[k] = tablica[i];
            i++;
        }
        k++;
    }

    if (i <= srodek)
    {
        while (i <= srodek)
        {
            tab_pom[k] = tablica[i];
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
        tablica[start+i] = tab_pom[i];

    delete [] tab_pom;
}
void Sort::InsertionSort(int *tab, int n)
{
    start = clock();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > key)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }
    stop=clock();
    czas=(double)(stop-start) / CLOCKS_PER_SEC;
}
