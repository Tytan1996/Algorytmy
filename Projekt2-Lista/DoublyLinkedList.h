#ifndef DoublyLinkedList
#define DoublyLinkedList

#define T short


namespace AiSD {
class DLLNode {

    T element;
    DLLNode *next;
    DLLNode *perv;
public:
    void pokazElement();
    T ustawWartosc(T nowaWartosc, DLLNode *nastepny);

};
class DLL {
    DLLNode *lista;
    DLLNode *head;
    DLLNode *ogon;

};
}


#endif // DoublyLinkedList_h
