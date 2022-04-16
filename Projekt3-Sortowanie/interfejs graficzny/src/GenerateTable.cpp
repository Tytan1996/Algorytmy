#include "GenerateTable.hpp"
#include <iostream>


const char letters[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
// abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 (jest ich 63 ze spacja)
const int letters_size=63;


size_t pow(const size_t &num,int pow)
{
    size_t n=1;
    for(int i=0;i<pow;i++)
        n*=num;
        //std::cout<<"n "<<n<<std::endl;
    return n;
}

std::string getUniqueId(const size_t &num)
{
    size_t act=num;
    //std::cout<<"start";
    char id[5]="    ";

    for(int i=1;i<=5;i++)
    {
        //std::cout<<"for "<<act%letters_size<<" got "<<letters[act%letters_size]<<std::endl;
        id[5-i]=letters[act%letters_size];
        act/=letters_size;
    }
    //std::cout<<"nor: "<<id<<std::endl;
    //std::cout<<"koniec"<<std::endl;
    return id;
}

std::random_device rd;
void generateTable(std::vector<Record> &tab,TableTypes type,long int size)
{
    tab.clear();
    switch(type)
    {
    case Random:

        for(long int i=0;i<size;i++)
        {
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis1(0, std::numeric_limits<int>::max());


            /*size_t act=i;
            char id[5];
            for(int i=1;i<=5;i++)
            {
                id[5-i]=letters[act%letters_size];
                act/=letters_size;
            }*/


            Record newRecord={dis1(gen),""};
            strncpy(newRecord.ID,getUniqueId(i).c_str(),5);

            std::cout<<"id: "<<newRecord.ID<<std::endl;
            tab.push_back(newRecord);
        }
        break;
    case ReversSorted:
        for(long int i=size;i>=0;i--)
        {
            std::cout<<*getUniqueId(i).c_str()<<std::endl;
            Record newRecord={i,*getUniqueId(i).c_str()};
            tab.push_back(newRecord);
        }
        break;
    case Sorted:
        for(long int i=0;i<size;i++)
        {
            Record newRecord={i,*getUniqueId(i).c_str()};
            tab.push_back(newRecord);
        }
        break;
    }
}
