#ifndef SORTTHREAD_HPP
#define SORTTHREAD_HPP

#include <stdio.h>//printf

#include <vector>
#include <GL/freeglut.h>
#include <chrono>
#include "GenerateTable.hpp"
#include "Sort.h"
#include <map>

#include "PresetLoader.hpp"
#include "tinyfiledialog/tinyfiledialogs.h"

namespace AiSD
{

enum SortingMethod{Shell,Quick,Merge,Insertion,notSelectedMethod};


struct settingsPreset
{
    SortingMethod method=notSelectedMethod;
    TableTypes tabType=notSelectedType;
    long int size=-1;
};
void setSetting(SortingMethod);
void setSetting(TableTypes);
void setSetting(long int);

bool restrictDraw();
void SetRestrictDraw(bool OnOff);

std::vector<AiSD::Record> getPrintTable();
void setPrintingTable(std::vector<AiSD::Record> tab);

void Start(bool skipSleep);
bool getProcessing();
int getTime();

float stepSizeBenchmark();

void startBenchmark();
void Benchmark();
std::vector<std::vector<AiSD::Record>> getResultBenchmark();

std::vector<Record> getTab();

void thread1();
PresetStruct GeneratePresetStruct(std::string description,bool unsorted);
void ApplyPresetStruct(PresetStruct presetStruct);
std::string getDescription();

}

#endif // SORTTHREAD_HPP
