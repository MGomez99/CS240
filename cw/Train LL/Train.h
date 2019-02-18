#ifndef TRAIN__
#define TRAIN__
#include <iostream>
#include <cstdlib>

class Car{
    public:
        Car * next;
        int weight;
        Car(int){this->next = NULL;};

};
class Train{

    public:
        Train();
        ~Train();
        Car * engine;


};
#endif