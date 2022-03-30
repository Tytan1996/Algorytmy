#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H



#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>



namespace AiSD{
struct Record{
    std::string name;
    unsigned grade;
};

class DLLNode{

    using  T=Record;
    //using T=short;
    T data;
    DLLNode *next;
    DLLNode *prev;
    //T rekord;

public:
    DLLNode();
    DLLNode(DLLNode* n, DLLNode* p, const T& t);
    void ustawElement(T nowaWartosc);
    T pokazElement();
    void ustawWskaznikiNaKolejnyElement(DLLNode *kolejnyElement);
    void ustawWskaznikiNaPoprzedniElement(DLLNode *poprzedniElement);
    DLLNode *pobierzWskaznikNaKolejnyElement();
    DLLNode *pobierzWskaznikNaPoprzednyElement();
};
class DLL{

    using  T=Record;
    size_t iloscElementow=0;
    //using T=short;
    T t;
    DLLNode *head;
    DLLNode *tail;
    DLLNode *lista;
    void utworzenieListy(T el);

public:
    DLL ();
    ~DLL ();
    void PushFront(const T& el);
    void PopFront();
    void PushBack(const T& el);
    void PopBack();
    T Front();
    T Back();
    bool IsEmpty();
    size_t Size();
    void Clear();
    void Print();
    void Print1();
    //metody dodatkowe
    bool IsInList(const T& t);
    DLLNode* Find(const T &t);
    void Insert(const T& t, size_t i);
    void Delete(size_t i);
    void InsertAfter(const T& t, size_t i);
    void InsertBefore(const T& t, size_t i);
    void DeleteAfter(size_t i);
    void DeleteBefore(size_t i);
    DLLNode* operator [](size_t i);
    void SaveCSV(std::string nazwaPliku);
    void LoadCSV(std::string nazwaPliku);

    friend class ClassTest;
    friend class OverflowTable;
};

}
#endif // DOUBLYLINKEDLIST_H
