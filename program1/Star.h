#ifndef StarDeclared_NM

#define StarDeclared_NM

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
        Planet getFurthest();
        void orbit();
	bool removePlanet(int);
        void printStarInfo();
        int getCurrentNumPlanets(){
	  return this->current_planets;
	};
	Planet * getPlanet(int);
	
        //you may add any additional methodas you may need.
};
#endif
