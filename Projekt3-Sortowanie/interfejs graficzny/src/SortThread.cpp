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
bool startBenchmarkThr=false;
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
                classSort.MergeSort(Tab,0,0,true);
                break;
            case Insertion:
                classSort.InsertionSort(Tab,true);
                break;
            }
            normalStart=false;
            processing=false;
        }else if(startBenchmarkThr)
        {
            Benchmark();
            startBenchmarkThr=false;
        }
    }

}


void startBenchmark()
{
    startBenchmarkThr=true;
}
std::vector<std::vector<Record>> resultBenchmark;
std::vector<std::vector<Record>> getResultBenchmark()
{
    return resultBenchmark;
}
const float stepBenchmark=100.0f;
void Benchmark()
{
    if(preset.tabType==notSelectedType)
        return;
    resultBenchmark.clear();
    std::cout<<"Starting Benchmark"<<std::endl;
    Sort classSort;
    processing=true;

    for(int i=0;i<4;i++)
    {
        std::vector<Record> SortResult;
        resultBenchmark.push_back(SortResult);
        for(int j=0;j<100;j++)
        {
            //std::cout<<"type "<<i<<" size "<<j*stepBenchmark<<std::endl;
            generateTable(Tab,preset.tabType,(j+1)*stepBenchmark);

            int time=0;
            switch(i)
            {
            case 0:
                time=(int)(classSort.QuickSort(Tab,0,Tab.size(),false));
                break;
            case 1:
                //time=(int)(classSort.MergeSort(Tab,0,Tab.size(),false));
                break;
            case 2:
                time=(int)(classSort.InsertionSort(Tab,false));
                break;
            case 3:
                time=(int)(classSort.ShellSort(Tab,false));
                break;
            }
            //if(i==1&&j==0)
            //    for(Record a :Tab)
            //        std::cout<<a.key<<std::endl;


            //std::cout<<"tra"<<std::endl;
            //std::cout<<"time: "<<time<<std::endl;
            Record newRecord={time,(char)i};

            resultBenchmark[i].push_back(newRecord);
            //std::cout<<"located";
        }
        //resultBenchmark.push_back(SortResult);
    }
    processing=false;
    std::cout<<"Finished"<<std::endl;
}
