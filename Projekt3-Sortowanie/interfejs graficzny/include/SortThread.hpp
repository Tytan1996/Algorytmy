#ifndef SORTTHREAD_HPP
#define SORTTHREAD_HPP

#include <stdio.h>//printf

#include<vector>

enum SortingMethod{Shell,Quick,Merge,Insertion};
enum TableTypes{Random,Sorted,ReversSorted};

struct settingsPreset
{
    SortingMethod method;
    TableTypes tabType;
    int size;
};
void setSetting(SortingMethod);
void setSetting(TableTypes);
void setSetting(int);

void Start();

struct Record
{
    int key;
    char ID[5];
};




std::vector<Record> getTab();

void watek();

#endif // SORTTHREAD_HPP
