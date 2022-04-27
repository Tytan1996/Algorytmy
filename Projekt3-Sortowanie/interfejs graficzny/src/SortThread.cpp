#include "SortThread.hpp"
#include<iostream>

//ZMIANA USTAWIEN
AiSD::settingsPreset preset={AiSD::notSelectedMethod,AiSD::notSelectedType,-1};
void AiSD::setSetting(SortingMethod a)
{
    preset.method=a;
}
void AiSD::setSetting(TableTypes a)
{
    preset.tabType=a;
}
void AiSD::setSetting(long int a)
{
    preset.size=a;
}
int BackupTime=0;
int AiSD::getTime()
{
    return BackupTime;
}


bool normalStart=false;
bool startBenchmarkThr=false;
bool skipSleepState=false;
void AiSD::Start(bool skipSleep)
{
    skipSleepState=skipSleep;
    normalStart=true;
}

bool processing=false;
bool AiSD::getProcessing()
{
    return processing;
}

std::vector<AiSD::Record> Tab;
std::vector<AiSD::Record> AiSD::getTab()
{
    return Tab;
}
std::vector<AiSD::Record> TabBeforeSorting;


std::vector<AiSD::Record> PrintingTable;
void AiSD::setPrintingTable(std::vector<AiSD::Record> tab)
{
    PrintingTable=tab;
}
std::vector<AiSD::Record> AiSD::getPrintTable()
{
    return PrintingTable;
}

using clockH=std::chrono::high_resolution_clock;


bool strictDraw=false;
bool AiSD::restrictDraw()
{
    return strictDraw;
}
void AiSD::SetRestrictDraw(bool OnOff)
{
    strictDraw=OnOff;
}
void AiSD::thread1()
{

    while(true)
    {

        if(normalStart)
        {
            SetRestrictDraw(true);
            Sort classSort;
            if(preset.tabType!=notSelectedType)
                generateTable(Tab,preset.tabType,preset.size);
            TabBeforeSorting=Tab;
            SetRestrictDraw(false);


            if(preset.method==notSelectedMethod)
                tinyfd_messageBox("Error","Method is not selected","ok","error",0);
            else if(Tab.size()==0)
                tinyfd_messageBox("Error","Type of table/size is not selected, or is empty","ok","error",0);
            else
            {

                processing=true;
                //std::cout<<Tab.size()<<std::endl;

                for(int i=0;i<2;i++)//2 RAZY -> 0 WIZUALIZACJA, 1 FAKTYCZNE SORTOWANIE (DLA UZYSKANIA CZASU)
                {
                    std::map <std::string,size_t> mapToDiag;
                    Tab=TabBeforeSorting;//sortuj tylko nieposortowana tablce
                    if(skipSleepState==true||Tab.size()>200)i=1;

                    SetRestrictDraw(false);

                    size_t tabSize=Tab.size();
                    auto TimeStart = clockH::now();

                    switch(preset.method)//ZAPISZE SIE TYLKO TEN BACKUP OSTATNI
                    {
                    case Shell:
                        if(i==1)classSort.ShellSort(Tab);
                        else classSort.Diag_ShellSort(Tab,mapToDiag,true);
                        break;
                    case Quick:
                        if(i==1)classSort.QuickSort(Tab,0,tabSize);
                        else classSort.Diag_QuickSort(Tab,0,tabSize,mapToDiag,true);
                        break;
                    case Merge:
                        if(i==1)classSort.MergeSort(Tab,0,tabSize);
                        else classSort.Diag_MergeSort(Tab,0,tabSize,mapToDiag,true);
                        break;
                    case Insertion:
                        if(i==1)classSort.InsertionSort(Tab);
                        else classSort.Diag_InsertionSort(Tab,mapToDiag,true);
                        break;
                    }
                    auto TimeStop = clockH::now();
                    BackupTime=(int)(std::chrono::duration_cast<std::chrono::microseconds>(TimeStop-TimeStart).count());
                    if(i==0)
                    {
                        std::cout<<"Diag ostatniego sortowania"<<std::endl;
                        for (auto const &m: mapToDiag)
                            std::cout << "{" << m.first << ": " << m.second << "}"<<std::endl;
                    }


                    setPrintingTable(Tab);
                }
                processing=false;
            }
            boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
            normalStart=false;

        }else if(startBenchmarkThr)
        {
            Benchmark();
            startBenchmarkThr=false;
        }

        SetRestrictDraw(false);
    }
}


void AiSD::startBenchmark()
{
    startBenchmarkThr=true;
}
std::vector<std::vector<AiSD::Record>> resultBenchmark;

std::vector<std::vector<AiSD::Record>> resultBenchmarkSafeCopy;
std::vector<std::vector<AiSD::Record>> AiSD::getResultBenchmark()
{
    return resultBenchmarkSafeCopy;
}


void updateBenchmarkCopy(std::vector<std::vector<AiSD::Record>> &a)
{
    AiSD::SetRestrictDraw(true);
    resultBenchmarkSafeCopy=a;
    AiSD::SetRestrictDraw(false);
}

float AiSD::stepSizeBenchmark()
{
    return preset.size;
}
void AiSD::Benchmark()
{
    if(preset.tabType==AiSD::notSelectedType)
    {
        tinyfd_messageBox("Error","Type of table was not selected, try again","ok","error",0);
        return;
    }
    if(preset.size<10)
    {
        tinyfd_messageBox("Error","Invalid step size","ok","error",0);
        return;
    }

    resultBenchmark.clear();
    std::cout<<"Starting Benchmark"<<std::endl;
    AiSD::Sort classSort;
    processing=true;

    for(int i=0;i<4;i++)
    {
        std::vector<AiSD::Record> SortResult;
        resultBenchmark.push_back(SortResult);

        for(int j=0;j<100;j++)
        {
            generateTable(Tab,preset.tabType,(j+1)*(preset.size));

            int time=0;
            auto TimeStart = clockH::now();
            switch(i)
            {
            case 0:
                classSort.QuickSort(Tab,0,Tab.size());
                break;
            case 1:
                classSort.MergeSort(Tab,0,Tab.size());
                break;
            case 2:
                classSort.InsertionSort(Tab);
                break;
            case 3:
                classSort.ShellSort(Tab);
                break;
            }
            auto TimeStop = clockH::now();
            time=(int)(std::chrono::duration_cast<std::chrono::microseconds>(TimeStop-TimeStart).count());
            AiSD::Record newRecord={time,(char)i};

            resultBenchmark[i].push_back(newRecord);

        }
        updateBenchmarkCopy(resultBenchmark);

    }
    processing=false;
    std::cout<<"Finished"<<std::endl;
}

AiSD::PresetStruct AiSD::GeneratePresetStruct(std::string description,bool unsorted)
{
    PresetStruct newPresetStruct;

    newPresetStruct.description=description;
    if(preset.method==Shell)
        newPresetStruct.method="Shell";
    else if(preset.method==Quick)
        newPresetStruct.method="Quick";
    else if(preset.method==Merge)
        newPresetStruct.method="Merge";
    else newPresetStruct.method="Insertion";

    if(!unsorted)
    {
        newPresetStruct.description+=". Took "+std::to_string(BackupTime)+" microsecounds";
        newPresetStruct.Tab=Tab;
    }
    else
    {
        newPresetStruct.Tab=TabBeforeSorting;
    }
    return newPresetStruct;
}


std::string description="";
std::string AiSD::getDescription()
{
    return description;
}

void AiSD::ApplyPresetStruct(AiSD::PresetStruct presetStruct)
{
    description=presetStruct.description;
    if(presetStruct.method=="Shell")
        preset.method=Shell;
    else if(presetStruct.method=="Quick")
        preset.method=Quick;
    else if(presetStruct.method=="Merge")
        preset.method=Merge;
    else preset.method=Insertion;
    preset.tabType=notSelectedType;
    Tab=presetStruct.Tab;
    TabBeforeSorting=presetStruct.Tab;
    setPrintingTable(Tab);
}
