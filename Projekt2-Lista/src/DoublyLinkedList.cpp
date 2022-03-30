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
    lista=head;
    if(head==nullptr && tail==nullptr && lista==nullptr){
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
    lista=head;
    if(lista==nullptr){
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }
    while(lista!=nullptr){
        std::cout<<"{name=\"";
        std::cout<<lista->pokazElement().name<<"\", grade=";
        std::cout<<lista->pokazElement().grade<<"}"<<std::endl;
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    lista=head;
}
void AiSD::DLL::Print1(){

    lista=tail;
    if(lista==nullptr){
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    lista=tail;
    while(lista!=nullptr){
        std::cout<<"{name=\"";
        std::cout<<lista->pokazElement().name<<"\", grade=";
        std::cout<<lista->pokazElement().grade<<"}"<<std::endl;
        lista=lista->pobierzWskaznikNaPoprzednyElement();
    }
    lista=head;

}
void AiSD::DLL::PopFront(){
    lista=head;
    if(head==nullptr && tail==nullptr && lista==nullptr){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return;
    }
    AiSD::DLLNode *tmp =head;
    if(head->pobierzWskaznikNaKolejnyElement()==nullptr){
        delete tmp;
        head=tail=lista=nullptr;
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
    if(head==nullptr && tail==nullptr && lista==nullptr){
        utworzenieListy(el);
        iloscElementow++;
        std::cout<<"Lista zostala utworzona z 1 elementem"<<std::endl;
        return;
    }
    AiSD::DLLNode *nowyElement =new DLLNode;
    nowyElement->ustawElement(el);
    nowyElement->ustawWskaznikiNaPoprzedniElement(tail);
    tail->ustawWskaznikiNaKolejnyElement(nowyElement);
    tail=nowyElement;
    iloscElementow++;
    std::cout<<"Element zostal dodany do listy"<<std::endl;
}
void AiSD::DLL::PopBack(){
    lista=head;
    if(head==nullptr && tail==nullptr && lista==nullptr){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return;
    }
    AiSD::DLLNode *tmp =tail;
    if(tail->pobierzWskaznikNaPoprzednyElement()==nullptr){
        delete tmp;
        head=tail=lista=nullptr;
        iloscElementow--;
        std::cout<<"Usuniales ostatni element z listy."<<std::endl;

        return;
    }
    lista=tail->pobierzWskaznikNaPoprzednyElement();
    lista->ustawWskaznikiNaKolejnyElement(nullptr);
    delete tmp;
    tail=lista;
    lista=head;
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
    lista=head;
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
    size_t ilosceElementowWLisce;
    if(iloscElementow==0){
        std::cout<<"Lista jest pusta"<<std::endl;
        ilosceElementowWLisce=0;
        return ilosceElementowWLisce;
    }
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta"<<std::endl;
        ilosceElementowWLisce=0;
        return ilosceElementowWLisce;
    }
    ilosceElementowWLisce=iloscElementow;
    return ilosceElementowWLisce;
}
void AiSD::DLL::Clear(){
    lista=head;
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
    lista=head;
    if(IsEmpty()==true){
        std::cout<<"Lista jest pusta!"<<std::endl;
        return false;
    }
    if(lista->pokazElement().name==t.name &&lista->pokazElement().grade==t.grade){
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
    if(iloscElementow==i){
        PushBack(t);
        return;
    }else if(i==1){
        PushFront(t);
        return;
    }
    for(size_t j=0;j<i;++j){
        if(lista->pobierzWskaznikNaKolejnyElement()==nullptr){
            std::cout<<"Nie udalo sie dodac elementu"<<std::endl;
            lista=head;
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
    /*if(IsEmpty()==true){
        std::cout<<"Nie udalo sie usunac elementu!"<<std::endl;
        return;
    }
    if(iloscElementow==i){
        PopBack();
        return;
    }else if(i==1){
        PopFront();
        return;
    }else if(iloscElementow<i){
        std::cout<<"Nie mozna usunac."<<std::endl;
        return;
    }
    lista=head;

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
    std::cout<<"Dodano element "<<t.name<<","<<t.grade<<" na "<<i<<"-tej Pozycji"<<std::endl;*/
}
void AiSD::DLL::InsertAfter(const T& t, size_t i){
    lista=head;
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
    lista=head;
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
    if(i>=iloscElementow){
        return;
    }else if(i>1){
        return;
    }else if(iloscElementow==(i-1)){
        PopBack();
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
    if(i==2){
        PopFront();
        return;
    }else if(iloscElementow<i){
        std::cout<<"Za duzy wartosc i dales (poza zakres listy)."<<std::endl;
        std::cout<<"Zakres tablicy od 1 do "<<iloscElementow<<std::endl;
        return;
    }else if(i<=1){
        std::cout<<"Nie mozna usunac elementu przed 1 z powotu ze przed tym elementem nie ma elementu."<<std::endl;
        std::cout<<"Zakres tablicy od 1 do "<<iloscElementow<<std::endl;
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


void AiSD::DLL::SaveCSV(std::string nazwaPliku)
{
    std::ofstream file;
    file.open(nazwaPliku+".csv",std::ifstream::trunc);

    lista=head;
    while(lista!=nullptr)
    {
        std::cout<<"\""<<lista->pokazElement().name<<"\";"<<lista->pokazElement().grade<<std::endl;
        file<<"\""<<lista->pokazElement().name<<"\";"<<lista->pokazElement().grade<<std::endl;
        lista=lista->pobierzWskaznikNaKolejnyElement();
    }
    lista=head;
    file.close();
}
void AiSD::DLL::LoadCSV(std::string nazwaPliku)
{
    Clear();
    std::ifstream file;
    file.open(nazwaPliku+".csv");
    std::string line;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            if(line!="")
            {
                for(int i=1;i<line.size();i++)//bo pierwszy jest zawsze "
                {
                    if(line[i]=='"')
                    {
                        if(line.size()>=i+1)
                        {
                            if(line[i+1]==';')
                            {
                                std::cout<<"T={name=\""<<line.substr(1,i-1)<<"\",";
                                std::cout<<"grade="<<line.substr(i+2,line.size()-i-2)<<"}"<<std::endl;
                                T act={line.substr(1,i-1),stoul(line.substr(i+2,line.size()-i-2))};
                                PushBack(act);
                            }
                        }
                    }

                }
            }

        }
        file.close();
    }
}
