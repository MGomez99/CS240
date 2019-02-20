#ifndef SLAB3_MG
#define SLAB3_MG
#include <cstdlib>
#include <iostream>
#include "Planet.h"

class Star{
	private:
		int current_planets;
		int next_id;
	public:
		Planet ** planets;
		Star();
		~Star();
		int addPlanet();
		//Planet getFurthest();
		Planet * getPlanet(int);
		bool removePlanet(int);
		void orbit();
		void printStarInfo();
		int getCurrentNumPlanets(){return this->current_planets;}
        //you may add any additional methodas you may need.
};
#endif
