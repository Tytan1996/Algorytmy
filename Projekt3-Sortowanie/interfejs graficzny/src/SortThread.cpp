#include "SortThread.hpp"


//ZMIANA USTAWIEN
settingsPreset preset;
void setSetting(SortingMethod a)
{
    preset.method=a;
}
void setSetting(TableTypes a)
{
    preset.tabType=a;
}
void setSetting(int a)
{
    preset.size=a;
}

void Start()
{

}



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
