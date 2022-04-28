#include "Sort.h"

using clockH=std::chrono::high_resolution_clock;

void FunctionFinish(std::vector <AiSD::Record> &records)
{
    AiSD::SetRestrictDraw(true);
    AiSD::setPrintingTable(records);
    AiSD::SetRestrictDraw(false);
}

void FuntionForPrinting(bool threadSleep,std::vector <AiSD::Record> &records)
{
    if(threadSleep)
    {
        FunctionFinish(records);
        boost::this_thread::sleep_for(boost::chrono::milliseconds(15));
    }
}

void AiSD::Sort::ShellSort(std::vector <Record> &records){

    size_t vectorSize=records.size();
    size_t halfSizeVector=vectorSize/2;

    for(size_t i =halfSizeVector; i>0; i/=2) {
        for(size_t j=i; j<vectorSize; ++j) {
            Record newRecords;
            newRecords=records[j];
            int k;
            for(k=j; k>=i &&records[k-i].key>newRecords.key; k-=i) {
                records[k]=records[k-i];
            }
            records[k]=newRecords;
        }
    }
}

void AiSD::Sort::QuickSort(std::vector <Record> &records, size_t start, size_t end)
{
    if(end<=start)return;
    int v=records[(start+end)/2].key;
    size_t i=start;
    size_t j=end;

    do
    {
        if(j>records.size())j=end;
        while(v>records[i].key)i++;
        while(v<records[j].key)j--;
        if (i<=j)
        {
            std::swap(records[i], records[j]);
            i++;
            j--;
        } else {
            break;
        }

    }while(i<=j);
    if (j>start) QuickSort(records,start, j);
    if (i<end) QuickSort(records, i, end);
}

void AiSD::Sort::Merge(std::vector<Record>& records, size_t start, size_t middle, size_t end)
{
    std::vector<Record> newRecords;
    size_t i = start, j = middle+1, k = 0; // zmienne pomocnicze

    while (i <= middle && j <= end) {
        if (records[j].key < records[i].key) {
            newRecords.push_back(records[j]);
            j++;
        } else {
            newRecords.push_back(records[i]);
            i++;
        }
        k++;
    }

    if (i <= middle) {
        while (i <= middle) {
            newRecords.push_back(records[i]);
            i++;
            k++;
        }
    } else {
        while (j <= end) {
            newRecords.push_back(records[j]);
            j++;
            k++;
        }
    }

    for (i = 0; i <= end-start; i++)
        records[start+i] = newRecords[i];

    newRecords.clear();
}
void AiSD::Sort::MergeSort(std::vector <Record> &records, size_t start, size_t end)
{
    size_t middle;

    if (start != end) {
        middle = (start + end)/2;
        MergeSort(records, start, middle);
        MergeSort(records, middle+1, end);
        Merge(records, start, middle, end);

    }
}

void AiSD::Sort::InsertionSort(std::vector <Record> &records)
{
    Record newRecord;
    size_t sizeVector=records.size();
    size_t i, j;
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

void AiSD::Sort::Diag_ShellSort(std::vector<Record>& records, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep)
{
    ++mapToDiag ["ilosc wywolania funkcji Diag_ShellSort"];
    size_t vectorSize=records.size();
    size_t halfSizeVector=vectorSize/2;
    for(size_t i =halfSizeVector; i>0; i/=2) {
        for(size_t j=i; j<vectorSize; ++j) {
            Record newRecords;
            newRecords=records[j];
            ++mapToDiag ["ilosc przypisania"];
            size_t k;
            for(k=j; k>=i &&records[k-i].key>newRecords.key; k-=i,++mapToDiag["ilosc porownian"]) {
                records[k]=records[k-i];
                ++mapToDiag ["ilosc przypisania"];
                FuntionForPrinting(ThreadSleep,records);
            }
            records[k]=newRecords;
            ++mapToDiag ["ilosc przypisania"];
        }
    }
    FunctionFinish(records);
}
void AiSD::Sort::Diag_QuickSort(std::vector<Record>& records, size_t start, size_t end, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep)
{
    ++mapToDiag ["ilosc wywolania funkcji Diag_QuickSort"];
    if(end<=start)return;
    int v=records[(start+end)/2].key;
    size_t i=start;
    size_t j=end;

    do
    {
        if(j>records.size())j=start;
        while(v>records[i].key){i++;++mapToDiag["ilosc porownian"];}
        while(v<records[j].key){j--;++mapToDiag["ilosc porownian"];}
        if (i<=j)
        {
            std::swap(records[i], records[j]);
            ++mapToDiag ["ilosc zamian"];
            i++;
            j--;
            FuntionForPrinting(ThreadSleep,records);
        } else {
            break;
        }

    }while(i<=j);
    if (j>start) Diag_QuickSort(records,start, j,mapToDiag,ThreadSleep);
    if (i<end) Diag_QuickSort(records, i, end,mapToDiag,ThreadSleep);
    FunctionFinish(records);

}
void AiSD::Sort::Diag_MergeSort(std::vector<Record>& records,size_t start,size_t end, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep)
{
    size_t middle;
    ++mapToDiag["ilosc wywolania funkcji Diag_MergeSort"];
    if (start != end) {
        middle = (start + end)/2;
        Diag_MergeSort(records, start, middle, mapToDiag,ThreadSleep);
        Diag_MergeSort(records, middle+1, end, mapToDiag,ThreadSleep);
        Diag_Merge(records, start, middle, end, mapToDiag,ThreadSleep);
    }
    FunctionFinish(records);
}
void AiSD::Sort::Diag_InsertionSort(std::vector<Record>& records, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep)
{
    ++mapToDiag["ilosc wywolania funkcji Diag_InsertionSort"];
    Record newRecord;
    size_t n=records.size();
    size_t i, j;
    for (i = 1; i < n; i++) {
        newRecord = records[i];
        ++mapToDiag ["ilosc przypisania"];
        j = i - 1;

        while (j >= 0 && records[j].key > newRecord.key,++mapToDiag["ilosc porownan"]) {

            records[j + 1] = records[j];
            ++mapToDiag ["ilosc przypisania"];
            j = j - 1;
            FuntionForPrinting(ThreadSleep,records);
        }
        records[j + 1] = newRecord;
        ++mapToDiag ["ilosc przypisania"];
    }
    FunctionFinish(records);
}
void AiSD::Sort::Diag_Merge(std::vector<Record>& records, size_t start, size_t middle, size_t end, std::map <std::string,size_t>& mapToDiag,bool ThreadSleep)
{
    ++mapToDiag["ilosc wywolania funkcji Diag_Merge"];
    std::vector<Record> newRecords;
    ++mapToDiag["ilosc utworzenie nowego wektora"];
    size_t i = start, j = middle+1, k = 0; // zmienne pomocnicze

    while (i <= middle && j <= end) {

        if (records[j].key < records[i].key,++mapToDiag["ilosc porownian"]) {

            newRecords.push_back(records[j]);
            ++mapToDiag["ilosc wstawienia wartosci do wektora"];
            j++;
        } else {
            newRecords.push_back(records[i]);
            ++mapToDiag["ilosc wstawienia wartosci do wektora"];
            i++;
        }
        k++;
        FuntionForPrinting(ThreadSleep,records);
    }

    if (i <= middle) {
        while (i <= middle) {

            newRecords.push_back(records[i]);
            ++mapToDiag["ilosc wstawienia wartosci do wektora"];
            i++;
            k++;
        }
    } else {
        while (j <= end) {

            newRecords.push_back(records[j]);
            ++mapToDiag["ilosc wstawienia wartosci do wektora"];
            j++;
            k++;
        }
    }
    for (i = 0; i <= end-start; i++) {
        records[start+i] = newRecords[i];
        ++mapToDiag["ilosc przypisania"];
    }
    newRecords.clear();
}


