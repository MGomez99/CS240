#include "List.h"

Node::Node(Planet * p)
{
	this->data = p;
}

Node::~Node()
{
	delete this->data;
}

List::List()
{
	this->head = NULL;
	this->tail = NULL;	
}

List::~List()
{
	Node * temp = this->head;
	Node * current;
	while(temp->next)
	{
		Node * current = temp;
		temp = temp->next;
		delete current;
	}
}

void List::insert(int index, Planet *p)
{
	if(index >= this->size || index < 0)
	{
		this->tail->next = new Node(p); //create new node at the end
		this->tail->next->prev = this->tail; //set prev pointer of the new node
		this->tail= this->tail->next; //new node is now tail
		this->size++;
	}
	else
	{
		Node * newNode = new Node(p);
		Node * temp = this->head;
		if(this->size == 0)
		{
			//list is empty
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			//get to index position
			for(int i = 0; i < index; i++)
			{
				if(temp != NULL)
				{ //should never be false
					temp = temp->next;
				}
				else
				{
					break; //failsafe?
				}
			}
			
			//temp holds previous node at given index
			temp->prev->next = newNode; //insert at index
			newNode->prev = temp->prev;	
			newNode->next = temp;
			temp->prev = newNode; //previous node is put after inserted node
			}
			this->size++;
	}
}

Planet* List::read(int index)
{
	if(index >= this->size || index < 0) return NULL;
	if(this->size == 0) return NULL; //empty list
	else
	{		
		Node * temp = this->head;
		//get to index position
		for(int i = 0; i < index; i++)
		{
			if(temp != NULL){
				temp = temp->next;
			}
		}
		//temp holds previous node at given index
		return temp->data;
	}
}

bool List::remove(int index)
{
	if(index >= this->size || index < 0) return false; //IOOB
	if(this->size == 0) return false; //empty list
	else
	{
		//get to index position
		Node * temp = this->head;
		for(int i = 0; i < index; i++)
		{
			if(temp != NULL){
				temp = temp->next;
			}
		}
		//temp holds node to delete
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		
	}
	this->size--;
	return true;
}
