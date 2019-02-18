#include "Star.h"
#include <iostream>
#include <cstdlib>

Star::Star(){
  this->current_planets = 0;
  this->planets = NULL;
}

Star::~Star(){
  for(int i = 0; i<this->current_planets;i++){
    delete this->planets[i];
  }
  delete[] this->planets;
  this->planets = NULL;
}

int Star::addPlanet(){
  this->current_planets++;
  Planet ** hold = new Planet * [this->current_planets];
  for(int i = 0; i<this->current_planets-1;i++){
    hold[i] = this->planets[i];
  }
  Planet * newPlanet = new Planet(current_planets);
  hold[this->current_planets-1] = newPlanet;
  delete [] this->planets;
  this->planets = hold;
  return (*(newPlanet)).getID();
}

bool Star::removePlanet(int idNum){
  bool wasRemoved = false;
  if(idNum<0 || idNum>this->current_planets){
    return false;
  }
  Planet ** hold = new Planet*[this->current_planets-1];
  for(int i = 0; i<this->current_planets;i++){
    if((*(this->planets[i])).getID()==idNum && !(wasRemoved)){
      delete this->planets[i];
      wasRemoved = true;
    }
    else{
      if(!wasRemoved){
	hold[i] = this->planets[i];
      }
      else {
	hold[i-1] = this->planets[i];
      }
    }
  }
  if(wasRemoved){
    this->current_planets--;
    delete [] this->planets;
    this->planets = hold;
  }
  else{
    delete [] hold;
  }
  return wasRemoved;
}

Planet * Star:: getPlanet(int IDnum){
  for(int i = 0; i<this->current_planets;i++){
    if((*(this->planets[i])).getID()==IDnum){
      return this->planets[i];
    }
  }
  return NULL;
}
   
Planet Star:: getFurthest(){
  Planet* placeholder;
  int maxDistance = 0;
  for(int i = 0; i<this->current_planets; i++){
    if((*(this->planets[i])).getDistance()> maxDistance){
      placeholder = this->planets[i];
    }
  }
  return *(placeholder);
}

void Star:: orbit(){
  for(int i = 0; i<this->current_planets; i++){
    (*this->planets[i]).orbit();
  }
}

void Star:: printStarInfo(){
  std::cout<< "The star has "<< this->current_planets << " planets."<< std::endl;
  std::cout<< "Planets:" << std::endl;
  Planet* placeholder = NULL; 
  for(int i = 0; i<this->current_planets; i++){
    placeholder = this->planets[i];
    std::cout<<"Planet "<< (*placeholder).getType() << (*placeholder).getID()<< " is " << (*placeholder).getDistance()<< " million miles away at position "<< (*placeholder).getPos()<< " around the star."<<std::endl;
  }
}
