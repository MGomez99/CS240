#include "Vector.h"

Vector::Vector(){
 this->planetList = new Planet * [0];
 this->size = 0;
}

Vector::~Vector(){

  for(int i = 0; i<this->size; i++){
    delete this->planetList[i];
  }
  delete[] this->planetList;
}

/* Insert takes in a location to add a planet and the planet itself
 * It first checks to see if the index is negative, in which case it will not do anything.
 * If the index is less than the size, then it iterates through the list and adds it in the correct spot
 * If the index is greater than or equal to the size, it copies the list and increases the size accordingly,
 * then adds the planet in the correct spot.
 */
void Vector::insert(int index, Planet* p){
  if(index>=0){
    if(index<size){
      this->size++;
      Planet ** newList = new Planet * [this->size]; 
      for(int i = 0; i<this->size; i++){
	if(i < index){
	  newList[i] = this->planetList[i];
	}
	if(i==index){
	  newList[i] = p;
	}
	if(i>index){
	  newList[i] = this->planetList[i-1];
	}
      }
      this->planetList = newList;
      delete [] this->planetList;
    }
    else{
      Planet ** longList = new Planet * [index+1];
      for(int i = 0; i<index+1; i++){
	if(i<size){
	  longList[i] = this->planetList[i];
	}
      }
      longList[index] = p;
      this->planetList = longList;
      delete[] this->planetList;
    }
  }
}

Planet *  Vector:: read(int index){
  if(index<0 || index>=size){
    return NULL;
  }

  return this->planetList[index];
  
}

/* remove takes in the index of the desired planet to be removed. 
 * It first checks if the index of the planet is invalid, for which it would return false and not execute any code
 * It then iterates through the list, copying over planets into the new list
 * until it finds the planet at the index. It then does not copy that planet over
 * and copies the rest of the planets. 
 * The method returns true on a positive removal.
 */
bool Vector:: remove(int index){
  
  if(index>=0 && index < size){
    this->size--;
    Planet ** newList  = new Planet * [this->size];
    for(int i = 0; i<size; i++){
      if(i < index){
	newList[i] = this->planetList[i];
      }
      if(i >= index){
	newList[i] = this->planetList[i+1];
      }
    }
    this->planetList = newList;
    delete[] planetList;
    return true;
  }
  return false;
  
}


