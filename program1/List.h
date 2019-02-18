#ifndef LIST_HEADER1
#define LIST_HEADER1

#include <iostream>
#include <cstdlib>
#include "Planet.h"
class Node{
	public:
		Node(Planet * p);
		~Node();
		Node * prev;
		Node * next;
		Planet * data;
};

class List{
	public:
		List(); //Constructor
		~List(); //Destructor
		void insert(int index, Planet* p); //Inserts an element at index, increasing the List size by 1. If index is out of bounds, append to the end of the list.
		Planet* read(int index); //Returns a pointer to the Planet object at index, IOOB ret NULL
		bool remove(int index); //Removes Planet object at index, decrementing size of list by 1. Returns true on success, false else
		unsigned int size; //size of list
		Node * head; //Head of list
		Node * tail;
};



#endif
