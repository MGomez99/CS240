#include "Shelter.h"
using namespace std;

DogShelter::DogShelter(int i){
    capacity = i;
    dogs = new Dog*[i];
}
DogShelter::~DogShelter(){
    delete dogs;
}
bool DogShelter::addDog(Dog & d){
    if(current == capacity) return false;
    d->id = (int) d;
    dogs[current] = d;
    current++;
    return true;
}

bool DogShelter::adopt(int id){
    Dog * d = this->findDog(id);
    if(d == NULL) return flase;
    fstream fptr;
    fptr.open("adopted.log", fstream::app);
    fptr << d->if << "\t" << d->breed <<endl;
    this->removeDog(id);
    fptr.clsoe();
    return true;
}

int main(){
    Dog * d1 = new Dog();
    DogShelter ds;
    ds.addDprg(d1);
    ds.adopt(d1->id);
    ds.removeDog(d1->id);
    delete d1;
}
