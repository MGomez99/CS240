#include "Star.h"

Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
	this->pos = 0;
}

int Planet::getID(){
	return this->id;
}

int Planet::orbit(){
	if(this->pos < 359){
		this->pos++;
	}else{
		this->pos = 0;
	}
	return this->pos;
}

int Planet::getDistance(){
	return this->distance;
}	
int Planet::getPos(){
	return this->pos;
}

Star::Star(int planets){
    this->max_planets = planets;
}

bool Star::addPlanet(){
    int current_num = this->getCurrentNumPlanets();
    if(current_num < this->getMaxPlanets()){ //wont add a planet if the star is at its capacity
	int distance = rand() % 3000; //RANDOM DISTANCE BETWEEN 1 and 3000
        Planet p = Planet(this->next_id, distance); //MAKE NEW PLANET
	
        this->planets[current_num] = p; //add the new planet to the Star's array of planets
        this->current_planets ++;
	    next_id++;
        return true;
    }
    else{
        return false;
	}
}

Planet Star::getFurthest(){
    int current_num = this->getCurrentNumPlanets();
    //if(current_num == 0){return null;}
    Planet *currentFurthest = &this->planets[0];
    for(int i = 1; i < current_num; i++){
        if(this->planets[i].getDistance() > currentFurthest->getDistance()){
            currentFurthest = &this->planets[i];
        }
    }
    return *currentFurthest;
}

void Star::orbit(){
    int max_num = this->getMaxPlanets();
    for(int i = 0; i < max_num; i++){
        this->planets[i].orbit();
    }
}
void Star::printStarInfo(){
    int current_num = this->getCurrentNumPlanets();
    int max_num = this->getMaxPlanets();
    std::cout <<"The star currently has "<<current_num<<" planets." <<std::endl;
    std::cout <<"The star can support up to "<<max_num<<" planets." <<std::endl;
    std::cout <<"Planets:"<<std::endl;
    for(int i = 0; i < current_num; i++){
        std::cout << "\tPlanet "<< i <<" is "<< this->planets[i].getDistance() <<" million miles away at position "<< this->planets[i].getPos() << " around the star." <<std::endl;
    }
}
    

int Star::getCurrentNumPlanets(){
	return this->current_planets;
}
int Star::getMaxPlanets(){
	return this->max_planets;
}

