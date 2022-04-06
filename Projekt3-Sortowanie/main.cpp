#include <iostream>
#include <algorithm>
#include <chrono>
#include <windows.h>

using namespace std;


clock_t start,stop;
double czas;


void sortowanie_babelkowe(int *tab, int n);
void quicksort(int *tablica, int lewy, int prawy);
void scalanie(int *tablica, int start, int srodek, int koniec);
void SortowaniePrzezScalanie(int *tablica, int start, int koniec);
void selectionSort(int *tab, int n);
void insertionSort(int *tab, int n);


int main()
{
    /*
    int *tablica1; //tablica do sorotwania babelkowo
    int *tablica2; //tablica do quicksort
    int *tablica3; //tablica do sortowanie przez scalenie
    int *tablica4; //tablica do sortowania przez selectionSort
    int *tablica5; //tablica do sortowania przez insertionSort
    int ilosc;
    cout<<"Ile chcesz miec elementow w tablicy?"<<endl;
    cout<<"Ilosc elementow w tablicy: ";cin>>ilosc;

    tablica1=new int [ilosc];
    tablica2=new int [ilosc];
    tablica3=new int [ilosc];
    tablica4=new int [ilosc];
    tablica5=new int [ilosc];

    srand(time(NULL));
    //cout<<"tablica przed posortowniem: "<<endl;
    for(int i=0;i<ilosc;++i){

        tablica1[i] = rand()%100000+1;
        tablica2[i]=tablica1[i];
        tablica3[i]=tablica1[i];
        tablica4[i]=tablica1[i];
        tablica5[i]=tablica1[i];

        //cout<<tablica1[i]<<" ";
    }
    cout<<endl;


    start = clock();
    sortowanie_babelkowe(tablica1, ilosc);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania babelkowego: "<<czas<<" s"<<endl;
    cout<<"Wynik sortowana: "<<endl;
    //for(int i=0;i<ilosc;++i){
    //    cout<<tablica1[i]<<" ";
    //}
    cout<<endl;
    start = clock();
    quicksort(tablica2,0,ilosc-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania quicksort: "<<czas<<" s"<<endl;
    cout<<"Wynik sortowana: "<<endl;
    //for(int i=0;i<ilosc;++i){
    //        cout<<tablica2[i]<<" ";
    //}
    cout<<endl;
    start = clock();
    SortowaniePrzezScalanie(tablica3,0,ilosc-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania SortowaniePrzezScalanie: "<<czas<<" s"<<endl;
    cout<<"Wynik sortowana: "<<endl;
    //for(int i=0;i<ilosc;++i){
    //        cout<<tablica3[i]<<" ";
    //}
    cout<<endl;
    start = clock();
    selectionSort(tablica4,ilosc);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania selectionSort: "<<czas<<" s"<<endl;
    cout<<"Wynik sortowana: "<<endl;
    //for(int i=0;i<ilosc;++i){
    //        cout<<tablica4[i]<<" ";
    //}
    cout<<endl;

    start = clock();
    insertionSort(tablica5,ilosc);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania insertionSort: "<<czas<<" s"<<endl;
    cout<<"Wynik sortowana: "<<endl;
    //for(int i=0;i<ilosc;++i){
    //        cout<<tablica5[i]<<" ";
    //}
    cout<<endl;
    delete [] tablica1 ;
    delete [] tablica2 ;
    delete [] tablica3 ;
    delete [] tablica4 ;
    delete [] tablica5 ;

*/
    return 0;
}

void sortowanie_babelkowe(int *tab, int n)
{
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
}
void quicksort(int *tablica, int lewy, int prawy)
{
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
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
}



void insertionSort(int *tab, int n)
{
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
}
void scalanie(int tablica[], int start, int srodek, int koniec)
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

void SortowaniePrzezScalanie(int tablica[], int start, int koniec)
{

    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec)/2;
        SortowaniePrzezScalanie(tablica, start, srodek);
        SortowaniePrzezScalanie(tablica, srodek+1, koniec);
        scalanie(tablica, start, srodek, koniec);
    }
}


void selectionSort(int *tab, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (tab[j] < tab[min_idx])
                min_idx = j;

        swap(tab[min_idx], tab[i]);
    }
}
