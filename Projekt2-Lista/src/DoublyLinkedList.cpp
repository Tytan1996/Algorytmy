#include "DoublyLinkedList.h"

AiSD::DLLNode::DLLNode(){
    next=nullptr;
    prev=nullptr;
}
AiSD::DLLNode::DLLNode(DLLNode* n,DLLNode* p, const Record& t){
    next=n;
    prev=p;
    data=t;
}
AiSD::DLL::DLL(){
    lista=nullptr;
    head=nullptr;
    tail=nullptr;
}
AiSD::DLL::~DLL(){
    for(size_t i=0;i<iloscElementow;++i){
        DLLNode *tmp=head;
        lista=lista->pobierzWskaznikNaKolejnyElement();
        delete tmp;
        head=lista;
    }
    delete lista;
    delete head;
    delete tail;
    iloscElementow=0;
}
void AiSD::DLLNode::ustawElement(T nowaWartosc){
    data=nowaWartosc;
}
void AiSD::DLLNode::ustawWskaznikiNaKolejnyElement(DLLNode *kolejnyElement){
    next=kolejnyElement;
}
void AiSD::DLLNode::ustawWskaznikiNaPoprzedniElement(DLLNode *poprzedniElement){
    prev=poprzedniElement;
}
AiSD::Record AiSD::DLLNode::pokazElement(){
    return data;
}
AiSD::DLLNode *AiSD::DLLNode::pobierzWskaznikNaKolejnyElement(){
    return next;
}
AiSD::DLLNode *AiSD::DLLNode::pobierzWskaznikNaPoprzednyElement(){
    return prev;
}
void AiSD::DLL::PushFront(const T& el){
    if(head==NULL && tail==NULL && lista==NULL){
        utworzenieListy(el);
        iloscElementow++;
        std::cout<<"Lista zostala utworzona z 1 elementem"<<std::endl;
        return;
    }
    AiSD::DLLNode *nowyElement =new DLLNode;
    nowyElement->ustawElement(el);
    nowyElement->ustawWskaznikiNaKolejnyElement(head);
    lista->ustawWskaznikiNaPoprzedniElement(nowyElement);
    lista=nowyElement;
    head=lista;
    iloscElementow++;
    std::cout<<"Element zostal dodany do listy"<<std::endl;
}
void AiSD::DLL::utworzenieListy(T el){
    AiSD::DLLNode *nowyElement =new DLLNode;
    nowyElement->ustawElement(el);
    lista=nowyElement;
    head=tail=nowyElement;
}
void AiSD::DLL::Print(){
    if(lista==NULL){
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }
    while(lista!=NULL){
        std::cout<<"{name=\"";
        std::cout<<lista->pokazElement().name<<"\", grade=";
        std::cout<<lista->pokazElement().grade<<"}"<<std::endl;
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    lista=head;

}
void AiSD::DLL::Print1(){
    if(lista==NULL){
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }
    lista=tail;
    while(lista!=NULL){
        std::cout<<lista->pokazElement().name<<" ";
        std::cout<<lista->pokazElement().grade<<std::endl;
        lista=lista->pobierzWskaznikNaPoprzednyElement();
    }
    lista=head;

}
void AiSD::DLL::PopFront(){
    if(head==NULL && tail==NULL && lista==NULL){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return;
    }
    AiSD::DLLNode *tmp =head;
    if(head->pobierzWskaznikNaKolejnyElement()==NULL){
        delete tmp;
        head=tail=lista=NULL;
        std::cout<<"Usuniales ostatni element z listy."<<std::endl;
        iloscElementow--;
        return;
    }
    lista=head->pobierzWskaznikNaKolejnyElement();
    lista->ustawWskaznikiNaPoprzedniElement(nullptr);
    head=lista;
    delete tmp;
    iloscElementow--;
    std::cout<<"Element zostal usuniety do listy"<<std::endl;
}
void AiSD::DLL::PushBack(const T& el){
    if(head==NULL && tail==NULL && lista==NULL){
        utworzenieListy(el);
        iloscElementow++;
        std::cout<<"Lista zostala utworzona z 1 elementem"<<std::endl;
        return;
    }
    AiSD::DLLNode *nowyElement =new DLLNode;
    nowyElement->ustawElement(el);
    nowyElement->ustawWskaznikiNaPoprzedniElement(head);
    tail->ustawWskaznikiNaKolejnyElement(nowyElement);
    tail=nowyElement;
    iloscElementow++;
    std::cout<<"Element zostal dodany do listy"<<std::endl;
}
void AiSD::DLL::PopBack(){
    if(head==NULL && tail==NULL && lista==NULL){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return;
    }
    AiSD::DLLNode *tmp =tail;
    if(tail->pobierzWskaznikNaPoprzednyElement()==NULL){
        delete tmp;
        head=tail=lista=NULL;
        iloscElementow--;
        std::cout<<"Usuniales ostatni element z listy."<<std::endl;
        return;
    }
    lista=tail->pobierzWskaznikNaPoprzednyElement();
    lista->ustawWskaznikiNaKolejnyElement(nullptr);
    tail=lista;
    lista=head;
    delete tmp;
    iloscElementow--;
    std::cout<<"Element zostal usuniety z konca"<<std::endl;
}

AiSD::Record AiSD::DLL::Front(){
    T wartoscPriewszegoElemntu;
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta"<<std::endl;
        return wartoscPriewszegoElemntu;
    }
    wartoscPriewszegoElemntu=head->pokazElement();
    return wartoscPriewszegoElemntu;
}
AiSD::Record AiSD::DLL::Back(){
    T wartoscOstatniegoElementu;
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta"<<std::endl;
        return wartoscOstatniegoElementu;
    }
    wartoscOstatniegoElementu=tail->pokazElement();
    return wartoscOstatniegoElementu;
}
bool AiSD::DLL::IsEmpty(){
    if(tail==NULL && head==NULL && lista==NULL){
        return true;
    }
    return false;
}
size_t AiSD::DLL::Size(){
    return iloscElementow;
}
void AiSD::DLL::Clear(){
    std::cout<<"Starting Clear"<<std::endl;
    while(lista!=NULL){
        AiSD::DLLNode *tmp=head;
        lista=lista->pobierzWskaznikNaKolejnyElement();
        delete tmp;
        head=lista;
    }
    tail=head=lista=NULL;
    iloscElementow=0;
    std::cout<<"Ending Clear"<<std::endl;
}
bool AiSD::DLL::IsInList(const T& t){
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return false;
    }
    if(lista->pokazElement().name==t.name){
        std::cout<<"Udalo sie znalezc element"<<std::endl;
        return true;
    }
    while(lista->pokazElement().name!=t.name){
        if(lista->pobierzWskaznikNaKolejnyElement()!=nullptr){
            lista=lista->pobierzWskaznikNaKolejnyElement();
            if(lista->pokazElement().name==t.name &&lista->pokazElement().grade==t.grade){
                std::cout<<"Zneleziono element!"<<std::endl;
                lista=head;
                return true;
            }
        }else{
            std::cout<<"Przeszukana cala liste i nie znalezniono elementu"<<std::endl;
            lista=head;
            return false;
        }
    }
    std::cout<<"Nie udalo sie znalezc elementu"<<std::endl;
    return false;
}
AiSD::DLLNode* AiSD::DLL::Find(const T &t){
    DLLNode *wskaznik;

    while(lista->pobierzWskaznikNaKolejnyElement()!=nullptr){
        if(lista->pokazElement().name==t.name &&lista->pokazElement().grade==t.grade){
            return lista;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    std::cout<<"Nie ma elementu!"<<std::endl;
    return nullptr;
}
void AiSD::DLL::Insert(const T& t, size_t i){
    if(IsEmpty()==true){
        std::cout<<"Nie udalo sie dodac elementu!"<<std::endl;
        return;
    }
    for(size_t j=0;j<i;++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie dodac elementu"<<std::endl;
            return;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    DLLNode *nowyElement= new DLLNode;
    nowyElement->ustawElement(t);
    nowyElement->ustawWskaznikiNaKolejnyElement(lista);
    nowyElement->ustawWskaznikiNaPoprzedniElement(lista->pobierzWskaznikNaPoprzednyElement());
    lista->pobierzWskaznikNaPoprzednyElement()->ustawWskaznikiNaKolejnyElement(nowyElement);
    lista->ustawWskaznikiNaPoprzedniElement(nowyElement);
    lista=head;
    iloscElementow++;
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
void AiSD::DLL::Delete(size_t i){
    if(IsEmpty()==true){
        std::cout<<"Nie udalo sie usunac elementu!"<<std::endl;
        return;
    }
    for(size_t j=0;j<i;++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie usunac elementu"<<std::endl;
            return;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    DLLNode *tmp=lista;
    lista->pobierzWskaznikNaPoprzednyElement()->ustawWskaznikiNaKolejnyElement(lista->pobierzWskaznikNaKolejnyElement());
    lista->pobierzWskaznikNaKolejnyElement()->ustawWskaznikiNaPoprzedniElement(lista->pobierzWskaznikNaPoprzednyElement());
    delete tmp;
    lista=head;
    iloscElementow--;
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
void AiSD::DLL::InsertAfter(const T& t, size_t i){
    if(IsEmpty()==true){
        std::cout<<"Nie udalo sie dodac elementu!"<<std::endl;
        return;
    }
    for(size_t j=0;j<=i;++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie dodac elementu"<<std::endl;
            return;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    DLLNode *nowyElement= new DLLNode;
    nowyElement->ustawElement(t);
    nowyElement->ustawWskaznikiNaKolejnyElement(lista);
    nowyElement->ustawWskaznikiNaPoprzedniElement(lista->pobierzWskaznikNaPoprzednyElement());
    lista->pobierzWskaznikNaPoprzednyElement()->ustawWskaznikiNaKolejnyElement(nowyElement);
    lista->ustawWskaznikiNaPoprzedniElement(nowyElement);
    lista=head;
    iloscElementow++;
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
void AiSD::DLL::InsertBefore(const T& t, size_t i){
    if(IsEmpty()==true){
        std::cout<<"Nie udalo sie dodac elementu!"<<std::endl;
        return;
    }
    for(size_t j=0;j<(i-1);++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie dodac elementu"<<std::endl;
            return;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    DLLNode *nowyElement= new DLLNode;
    nowyElement->ustawElement(t);
    nowyElement->ustawWskaznikiNaKolejnyElement(lista);
    nowyElement->ustawWskaznikiNaPoprzedniElement(lista->pobierzWskaznikNaPoprzednyElement());
    lista->pobierzWskaznikNaPoprzednyElement()->ustawWskaznikiNaKolejnyElement(nowyElement);
    lista->ustawWskaznikiNaPoprzedniElement(nowyElement);
    lista=head;
    iloscElementow++;
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
void AiSD::DLL::DeleteAfter(size_t i){
    if(IsEmpty()==true){
        std::cout<<"Nie udalo sie usunac elementu!"<<std::endl;
        return;
    }
    for(size_t j=0;j<=i;++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie usunac elementu"<<std::endl;
            return;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    DLLNode *tmp=lista;
    lista->pobierzWskaznikNaPoprzednyElement()->ustawWskaznikiNaKolejnyElement(lista->pobierzWskaznikNaKolejnyElement());
    lista->pobierzWskaznikNaKolejnyElement()->ustawWskaznikiNaPoprzedniElement(lista->pobierzWskaznikNaPoprzednyElement());
    delete tmp;
    lista=head;
    iloscElementow--;
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
void AiSD::DLL::DeleteBefore(size_t i){
    if(IsEmpty()==true){
        std::cout<<"Nie udalo sie usunac elementu!"<<std::endl;
        return;
    }
    for(size_t j=0;j<(i-1);++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie usunac elementu"<<std::endl;
            return;
        }
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    DLLNode *tmp=lista;
    lista->pobierzWskaznikNaPoprzednyElement()->ustawWskaznikiNaKolejnyElement(lista->pobierzWskaznikNaKolejnyElement());
    lista->pobierzWskaznikNaKolejnyElement()->ustawWskaznikiNaPoprzedniElement(lista->pobierzWskaznikNaPoprzednyElement());
    delete tmp;
    lista=head;
    iloscElementow--;
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
AiSD::DLLNode *AiSD::DLL::operator [](size_t i){
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta!"<<std::endl;
    }
    DLLNode *wskaznik=new DLLNode;
    for(size_t j=0;j<=i;++j){
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    wskaznik=lista;
    lista=head;
    return wskaznik;
}
