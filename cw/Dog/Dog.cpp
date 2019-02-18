#include "Shelter.h"
Dog::Dog(){
    this->breed = NULL;
}
Dog::Dog(int id, char * breed){
    this->id = id;
    this->breed = breed;
}