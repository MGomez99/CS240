#ifndef planet_NM
#define planet_NM

class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
	Planet();
        int orbit();
	long getID(){
	  return (long)this;
	};
        int getDistance(){
	  return this->distance;
	};
        int getPos(){
	  return this->pos;
	};
	char getType(){
	  return this->type;
	};
};

#endif
