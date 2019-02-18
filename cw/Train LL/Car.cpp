#include "Train.h"

Car::Car(int w){
    this->weight = w;
}

Train::Train(){
    int w1 = 1000+ rand() % 3000;
    int w2 = 1000+ rand() % 3000;
    int w3 = 1000+ rand() % 3000;
    Car *c1 = new Car(w1);
    Car *c2 = new Car(w2);
    Car *c3 = new Car(w3);

    this->engine = c1;
    c1->next = c2;
    c2->next = c3;
}
Train::~Train(){
    Car * c = this->engine;
    Car * temp;
    while(c->next != NULL){
        temp = c-> next;
        delete c;
        c = temp;
    }
    delete temp;
}