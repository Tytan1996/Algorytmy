#ifndef SORTTHREAD_HPP
#define SORTTHREAD_HPP

#include <stdio.h>//printf

#include <vector>
#include <GL/freeglut.h>
#include "GenerateTable.hpp"
#include "Sort.h"

#include "PresetLoader.hpp"


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

void Start();
bool getProcessing();


void startBenchmark();
void Benchmark();
std::vector<std::vector<Record>> getResultBenchmark();

std::vector<Record> getTab();

void watek();
PresetStruct GeneratePresetStruct(std::string description);
void ApplyPresetStruct(PresetStruct presetStruct);
std::string getDescription();


#endif // SORTTHREAD_HPP
