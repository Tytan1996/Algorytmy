#include "GenerateTable.hpp"
#include <iostream>


const char letters[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
// 0123456789abcdefghijklmnopqrstuvwxyz (jest ich 63 ze spacja)
const int letters_size=36;




std::string AiSD::getUniqueId(const size_t &num)
{
    size_t act=num;
    char id[5]="    ";
    for(int i=1;i<=5;i++)
    {
        id[5-i]=letters[act%letters_size];
        act/=letters_size;
    }
    return id;
}

std::random_device rd;
void AiSD::generateTable(std::vector<AiSD::Record> &tab,TableTypes type,long int size)
{

    tab.clear();
    switch(type)
    {
    case Random:

        for(long int i=0;i<size;i++)
        {

            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis1(0, std::numeric_limits<int>::max());
            Record newRecord={dis1(gen),""};
            strncpy(newRecord.ID,getUniqueId(i).c_str(),5);
            tab.push_back(newRecord);
        }
        break;
    case ReversSorted:
        for(long int i=size;i>=0;i--)
        {

            Record newRecord={i,""};
            strncpy(newRecord.ID,getUniqueId(i).c_str(),5);
            tab.push_back(newRecord);
        }
        break;
    case Sorted:
        for(long int i=0;i<size;i++)
        {

            Record newRecord={i,""};
            strncpy(newRecord.ID,getUniqueId(i).c_str(),5);
            tab.push_back(newRecord);
        }
        break;
    }
}


