#include "Planet.h"

Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
	this->pos = rand() % 360;
	int randomType = rand % 3; //to choose random type
	switch(randomType){
		case 0: this->type = 'h';
		case 1: this->type = 'r';
		case 2: this->type = 'g';
	}
	
}

int Planet::orbit(){
	if(this->pos < 359){
		this->pos++;}
	else{
		this->pos = 0;}
	return this->pos;
}

