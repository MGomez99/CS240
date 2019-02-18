#include "Planet.h"
#include <iostream>
#include <cstdlib>

Planet::Planet(){
	this->id = id;
	this->distance = rand()%3000 + 1 ;
	this->pos = rand()%360;
	if((long)this%3 == 0){
	  this->type = 'h';
	}
	else if((long)this%3 == 1){
	  this->type = 'r';
	}
	else{
	  this->type = 'g';
	}
}

int Planet::orbit(){
  if(this->pos==359){
    this->pos = 0;
    return 0;
  }
  this->pos++;
  return this->pos;
}
