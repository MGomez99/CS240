#include "Star.h"
#include "Planet.h"
Star::Star(){
    this->current_planets = 0;
	this->planets = NULL;
}
Star::~Star(){
	delete this->planets;
}

int Star::addPlanet(){
    int current_num = this->current_planets; //More planets
	int distance = rand() % 3000; //RANDOM DISTANCE BETWEEN 1 and 3000
	Planet ** newSystem = new Planet*[current_num+1];
	for(int i = 0; i < current_num; i++){ //copy old planets
		newSystem[i] = this->planets[i];
	}
	this->current_planets++;
    Planet *p = new 
	Planet(this->next_id, distance); //MAKE NEW PLANET
	next_id++;//inc id to keep it unique
	newSystem[current_planets] = p; //Add planet to system and increment current
	delete[] planets;
	planets = newSystem; //Overwrite System
    
    return p->getID();
    
    
}
bool Star::removePlanet(int id){
	int index = -1;
	/**look for id*/
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getID() == id){
			index = i;
		}
	}
	if(index == -1){ return false;} //if id not found
	Planet ** newSystem = new Planet*[current_num-1];
	/**copy old planets*/
	for(int i = 0; i < current_num-1; i++){
		if(i != index && i < index){
			newSystem[i] = this->planets[i];
		}
		if(i != index && i > index){
			newSystem[i-1] = this->planets[i];
		}
	}
	delete[] planets;
	planets = newSystem;
	this->current_planets--;
	return true;
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
    for(int i = 0; i < this->getCurrentNumPlanets(); i++){
        this->*(planets[i]).orbit();
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
    



