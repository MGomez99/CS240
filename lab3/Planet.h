#ifndef PLAB3_MG
#define PLAB3_MG
#include <cstdlib>
#include <iostream>
class Planet{
	private:
		int ID;
		int pos;
		int distance;
		char type; // 'h' = habitable, 'r'=rocky, 'g'=gaseous
	public:
		Planet(int distance,int ID);
        int orbit();
		int getID(){return this->ID;}
		int getDistance(){return this->distance;}
		int getPos(){return this->pos;}
		char getType(){return this->type;}
		//you may add any additional methods you may need.
};
#endif
