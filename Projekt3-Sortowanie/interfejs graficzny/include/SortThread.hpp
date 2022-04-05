#ifndef SORTTHREAD_HPP
#define SORTTHREAD_HPP

#include <stdio.h>//printf

#include<vector>


struct Record
{
    int key;
    char ID[5];
};

std::vector<Record> getTab();

void watek();

#endif // SORTTHREAD_HPP
