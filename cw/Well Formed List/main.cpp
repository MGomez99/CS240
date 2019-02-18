class Node{
    Node * next = NULL;
};
class List{
    int size;
    List(cont List& o);
    void insert(Node * n);
    Node * head;
};
List::List(const List& other){
    if(wellformed(o){
        for(Node * n = o.head; n != NULL; n=n->next){
            insert(n->data);
        }
    }    
}

bool wellformed(const List &l){
    return true;
}