#include <cstdlib>
#include <iostream>
#ifndef PLAB3_MG
#define PLAB3_MG
class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type; // 'h' = habitable, 'r'=rocky, 'g'=gaseous
	public:
		Planet(){this->id=-1;};
		Planet(int,int);
        int orbit();
		int getID(){return this->id;}
		int getDistance(){return this->distance;}
		int getPos(){return this->pos;}
		char getType(){return this->type;}
		//you may add any additional methods you may need.
};
#endif
