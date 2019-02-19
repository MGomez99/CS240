#include "Planet.h"
#include "Star.h"
Star::Star(){
    this->current_planets = 0;
    this->planets = NULL;
}
Star::~Star(){
    for(int i = 0; i < this->current_planets; i++){
        delete this->planets[i];
    }
    delete[] this->planets;
    this->planets = NULL;
}

int Star::addPlanet(){
    int current_num = this->current_planets;
    int distance = rand() % 3000; //RANDOM DISTANCE BETWEEN 1 and 3000
    Planet ** newSystem = new Planet*[current_num+1];
    if(current_num != 0){
        for(int i = 0; i < current_num; i++) { //copy old planets
            newSystem[i] = this->planets[i];
        }
    }
    Planet *p = new Planet(this->next_id, distance); //MAKE NEW PLANET
    next_id++;//inc id to keep it unique
    newSystem[current_planets] = p; //Add planet to system and increment current
    this->current_planets++;
    delete[] this->planets;
    this->planets = newSystem; //Overwrite System
    return p->getID();

}
bool Star::removePlanet(int ID){
    bool removed = false;
    int current_num = this->current_planets;

    Planet ** newSystem = new Planet*[current_num-1];
    /**copy old planets, skip planet to remove and remove it in the process*/
    for(int i = 0; i < current_num-1; i++) {
        //if id found, delete and skip
        if((this->planets[i])->getID() == ID && !(removed)){
            delete this->planets[i];
            removed = true;
        }
        //planet hasn't been found yet, normal indexes
        else {
            if(!removed){
                newSystem[i] = this->planets[i];
            }
            //planet deleted, offset index to fill new system
            else{
                newSystem[i-1] = this->planets[i];
            }
        }
    }
    //planet was removed, delete old array and replace with new one
    if(removed){
        delete[] this->planets;
        this->planets = newSystem;
        this->current_planets--;
    }
    //planet not found
    else{
        delete[] newSystem;
    }
    return removed;

}
Planet * Star::getPlanet(int ID){
    for(int i = 0; i < this->current_planets; i++) {
        if((this->planets[i])->getID()==ID) return this->planets[i];
    }
    return NULL;
}

void Star::orbit(){
    for(int i = 0; i < this->current_planets; i++) {
        (this->planets[i])->orbit();
    }
}
void Star::printStarInfo(){
    int current_num = this->current_planets;
    std::cout <<"The star has "<<current_num<<" planets." <<std::endl;
    std::cout <<"Planets:"<<std::endl;
    for(int i = 0; i < current_num; i++) {
        std::cout << "Planet "<< this->planets[i]->getType()
        <<  this->planets[i]->getID() <<" is "<< this->planets[i]->getDistance()
        << " million miles away at position "
        << this->planets[i]->getPos() << " around the star." <<std::endl;
    }
}
