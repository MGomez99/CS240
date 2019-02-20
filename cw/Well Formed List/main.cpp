#include <cstdlib>
#include <iostream>

class Node{
    public:
        Node * next = NULL;
        int data;
};
class List{
    public:
        int size;
        List(const List& o);
        void insert(Node * n);
        Node * head;
};
List::List(const List& o){
    if(wellformed(o)){
        for(Node * n = o.head; n != NULL; n=n->next){
            insert(n);
        }
    }    
};

bool wellformed(const List &l){
    Node * slow = l.head, * fast1 = l.head, * fast2 = l.head;
    while(slow && fast1 = fast2->next && fast2 = fast1->next){
        if(slow == fast1 || slow == fast2) return false;
        slow = slow->next;
    }
    return true;
}