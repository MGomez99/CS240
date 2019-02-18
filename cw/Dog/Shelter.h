#include <cstdlib>
#include <iostream>
#include <fstream>

class Dog{
    public:
        char * breed;
        int id;
};
class DogShelter{
    public: 
        DogShelter(int i);
        int capacity;
        Dog * * dogs;
        int current;
}