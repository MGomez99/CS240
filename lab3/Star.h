#include <cstdlib>
#include <iostream>
#include "Planet.h"
#ifndef SLAB3_MG
#define SLAB3_MG


class Star{
	private:
		int current_planets;
		int next_id;
	public:
		Planet ** planets;
		Star();
		~Star();
		int addPlanet();
		Planet getFurthest();
		void orbit();
		void printStarInfo();
		int getCurrentNumPlanets(){return this->current_planets;}
		int getMaxPlanets();
        //you may add any additional methodas you may need.
};
#endif
