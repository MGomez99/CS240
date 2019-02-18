#include <iostream>
#include <cstdlib>
class Node{
    public:
        Node();
        int data;
        Node * next = NULL;
        Node * prev = NULL;
};
class LL{
    
    public:
        LL();
        bool insert(Node * node);
        Node * next();
        void reset();
        Node * read();
        void append(LL * list);
        Node * head = NULL;
        Node * tail = NULL;
};

LL** split(LL * list){
    if(list == NULL) return NULL;
    LL** ret; //ret val
    LL * even = new LL();
    LL * odd = new LL();
    Node * current = list-> head->next; //current node in list
   do{
        even->insert(list->read());
        if(list->next()){
            odd->insert(list->next());
        }

   }while(current->next != NULL);
    LL ** lists = new LL*[2];
    lists[0] = even; lists[1] = odd;
}

void LL::append(LL* list){
    this->tail->next = list->head;
    list->head->prev= this->tail;
    this->tail = list -> tail;
    
}
