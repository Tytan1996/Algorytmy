#ifndef GENERATETABLE_HPP
#define GENERATETABLE_HPP
#include <vector>
#include "Sort.h"
#include <random>
#include <stdio.h>
#include <string.h>

enum TableTypes{Random,Sorted,ReversSorted,notSelectedType};
std::string getUniqueId(const size_t &num);
void generateTable(std::vector<Record> &tab,TableTypes type,long int size);

#endif // GENERATETABLE_HPP
