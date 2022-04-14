#include "SortThread.hpp"



std::vector<Record> Tab;

std::vector<Record> getTab()
{
    return Tab;
}


void watek()
{

    for(int i=0;i<10;i++)
    {
        Tab.push_back({i,'a'});
    }
    while(true)
    {

        //printf("test\n");
    }
}
