#ifndef GENERATETABLE_HPP
#define GENERATETABLE_HPP
#include <vector>
#include "StructRecord.hpp"
#include <random>
#include <stdio.h>
#include <string.h>

namespace AiSD
{

enum TableTypes{Random,Sorted,ReversSorted,notSelectedType};
std::string getUniqueId(const size_t &num);
void generateTable(std::vector<AiSD::Record> &tab,TableTypes type,long int size);
}



#endif // GENERATETABLE_HPP
