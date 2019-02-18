#ifndef VECT_HEADER1
#define VECT_HEADER1

#include <iostream>
#include <cstdlib>
#include "Planet.h"

class Vector{

 private:
  Planet ** planetList;
  unsigned int size;
  
 public:
  Vector();
  ~Vector();
  void insert(int, Planet * );
  Planet * read(int);
  bool remove(int);
  unsigned getSize(){
    return this->size;
  };
};

#endif
