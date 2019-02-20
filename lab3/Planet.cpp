#include "Planet.h"

Planet::Planet(int distance, int idnum){

	this->ID = idnum;
	this->distance = distance;
	this->pos = rand() % 360;
	int randomType = rand() % 3; //to choose random type
	switch(randomType){
		case 0: this->type = 'h';
				break;
		case 1: this->type = 'r';
				break;
		case 2: this->type = 'g';
				break;
	};


}

int Planet::orbit(){
	if(this->pos == 359){
		this->pos = 0;
        return 0;
    }
	
	this->pos++;
    return this->pos;

}
