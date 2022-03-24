#include "DoublyLinkedList.h"
AiSD::DLLNode::DLLNode(){
    next=nullptr;
    perv=nullptr;
}
AiSD::DLLNode::DLLNode(const DLLNode* n,const DLLNode* p, const short& t){
    //next=n;
    //prev=p;
    data=t;
}
AiSD::DLL::DLL(){
    lista=nullptr;
    head=nullptr;
    tail=nullptr;
}
void AiSD::DLLNode::ustawElement(T nowaWartosc){
    data=nowaWartosc;
}
void AiSD::DLLNode::ustawWskaznikiNaKolejnyElement(DLLNode *kolejnyElement){
    next=kolejnyElement;
}
void AiSD::DLLNode::ustawWskaznikiNaPoprzedniElement(DLLNode *poprzedniElement){
    perv=poprzedniElement;
}
short AiSD::DLLNode::pokazElement(){
    return data;
}
AiSD::DLLNode *AiSD::DLLNode::pobierzWskaznikNaKolejnyElement(){
    return next;
}
AiSD::DLLNode *AiSD::DLLNode::pobierzWskaznikNaPoprzednyElement(){
    return perv;
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
        std::cout<<lista->pokazElement()<<std::endl;
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
        std::cout<<lista->pokazElement()<<std::endl;
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
    lista=head;
    delete tmp;
    iloscElementow--;
    std::cout<<"Element zostal usuniety z konca"<<std::endl;
}

short AiSD::DLL::Front(){
    T wartoscPriewszegoElemntu=0;
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta"<<std::endl;
        return wartoscPriewszegoElemntu;
    }
    wartoscPriewszegoElemntu=head->pokazElement();
    return wartoscPriewszegoElemntu;
}
short AiSD::DLL::Back(){
    T wartoscOstatniegoElementu=0;
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
    while(lista!=NULL){
        AiSD::DLLNode *tmp=head;
        lista=lista->pobierzWskaznikNaKolejnyElement();
        delete tmp;
    }
    tail=head=lista=NULL;
}
bool AiSD::DLL::IsInList(const T& t){
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return false;
    }
    if(lista->pokazElement()==t){
        std::cout<<"Udalo sie znalezc element"<<std::endl;
        return true;
    }
    while(lista->pokazElement()!=t){
        if(lista->pobierzWskaznikNaKolejnyElement()!=nullptr){
            lista=lista->pobierzWskaznikNaKolejnyElement();
            if(lista->pokazElement()==t){
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
        if(lista->pokazElement()==t){
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

    //lista->perv->next->ustawWskaznikiNaKolejnyElement(nowyElement);
    //lista->perv->ustawWskaznikiNaPoprzedniElement(nowyElement);
    std::cout<<"Dodano element "<<t<<" na "<<i<<"-tej Pozycji"<<std::endl;
}
