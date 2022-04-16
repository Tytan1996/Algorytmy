#include "SortThread.hpp"
#include<iostream>

//ZMIANA USTAWIEN
settingsPreset preset={notSelectedMethod,notSelectedType,-1};
void setSetting(SortingMethod a)
{
    preset.method=a;
}
void setSetting(TableTypes a)
{
    preset.tabType=a;
}
void setSetting(long int a)
{
    preset.size=a;
}

bool normalStart=false;
void Start()
{
    if(preset.method!=notSelectedMethod&&preset.size!=-1&&preset.tabType!=notSelectedType)
        normalStart=true;
}

bool processing=false;
bool getProcessing()
{
    return processing;
}

std::vector<Record> Tab;

std::vector<Record> getTab()
{
    return Tab;
}



void watek()
{
    while(true)
    {
        if(normalStart)
        {
            processing=true;
            Sort classSort;

            generateTable(Tab,preset.tabType,preset.size);
            switch(preset.method)
            {
            case Shell:
                classSort.ShellSort(Tab,true);
                break;
            case Quick:
                classSort.QuickSort(Tab,0,Tab.size(),true);
                break;
            case Merge:
                classSort.MergeSort(Tab,0,Tab.size(),true);
                break;
            case Insertion:
                classSort.InsertionSort(Tab,true);
                break;
            }
            normalStart=false;
            processing=false;
        }
    }

}


std::vector<std::vector<Record>> Benchmark()
{

}
