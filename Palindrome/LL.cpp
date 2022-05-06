#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error

#include "LL.h"
/*****************************************************************
Default Constructor. Front and rear will be assigned to an 
empty node
*****************************************************************/
LL::LL() {
	front = new Node; // create junk node
	rear = front;
	front->next = NULL;
	rear->next = NULL;
	count = 0;
}
/*****************************************************************
Destructor will iterate through the linked list and delete 
all nnodes inside the data
*****************************************************************/
LL::~LL() {
	Node* tempNode; // create static pointer to hold information of the new front
	for(int i = 0; i < count; i++) {
		tempNode = front;  //
		front = front->next;
		delete tempNode;
	}
	tempNode = NULL;
}

/*****************************************************************
Copy constructor that will copy a linked list to another
newly instantiated linked list with linked list parameter
const LL &source is the link list whose data we want to copy
*****************************************************************/
LL::LL(const LL &source) {
	front = NULL; // in case source list is empty
	rear = NULL;
	count = 0;
	Node *p; // instantiate dynamic pointer or static pointer?
	p = source.front; // point to the front address
	while(p != NULL) {
		addRear(p->elem); // add the node's element into the linked list
		p = p->next; // go to the next node
		// we don't need to increment count since it will be incremented in addRear function
	}
	p = NULL;
	// we don't have to set p to NULL since the last node of the source is already NULL
}

/*****************************************************************
Exit application is queue underflow occurs
*****************************************************************/
void LL::queueError(std::string errorMessage) {
	std::cout << errorMessage << std::endl;
	exit(1);
}
/*****************************************************************
Check if the list is empty
*****************************************************************/
bool LL::isEmpty() {
	if(count == 0) return true;
	return false;
}
/*****************************************************************
add a node to the rear of the list
el_t e is the element we will add to the rear of the list
*****************************************************************/
void LL::addRear(el_t el) {
	Node *n = new Node; // n is the new node we create in the heap
	// assign 
	n->elem = el; 
	n->next = NULL; 
	if(isEmpty()) {
		front = n; // if queue is empty then point front to n
	} else { // if not empty
		rear->next = n; // point old rear to new node
	}
	rear = n;
	count++;
}
/*****************************************************************
add node to the front of the list
el_t e is the element we will add to the front of the list
*****************************************************************/
void LL::addFront(el_t el) {
	Node *n = new Node;
	n->elem = el;
	if(isEmpty()) { // if empty set newly made node empty
		rear = n;
		n->next = NULL;
	} else { // if not empty
		n->next = front; // point new node to the front address
	}
	front = n; // make front the new node
	count++; // increment, we don't have to change rear
	n = NULL;
	return;
}

/*****************************************************************
delete the front node of the list
*****************************************************************/
el_t LL::deleteFront() { // this function needs  to be fixed
	if(isEmpty()) queueError("Queue Underflow");

	el_t item = front->elem; // get the item we are going to return
	count--; // decrement 
	
	if(isEmpty()) { // check if empty
		delete front; // delete front and set both front and rear to NULL
		front = NULL;
		rear = NULL;
	} 
	else {
		Node *nFront; // instantiate temporary new front
		nFront = front->next; //
		delete front; // delete old front
		front = nFront;
		nFront = NULL;
	}
	return item;
}
/*****************************************************************
delete the last node of teh linked list or the node rear is pointing
to
*****************************************************************/
el_t LL::deleteRear() {
	if(isEmpty()) queueError("Queue Underflow"); // check if the queue is empty
	count--; // decrement the number of elements in the queue
	el_t item = rear->elem; // point to the
	Node *p = front;
	// for loop to traverse to the 2nd to the last node
	for(int i = 0; i < count - 1; i++) {
		p = p->next;
	}
	delete rear;
	rear = p;
	rear->next = NULL;
	p = NULL;
	return item;
}
/*****************************************************************
this function will display all elements inside the linked list
*****************************************************************/
void LL::displayAll() {
	if(isEmpty()) { // check if empty
		std::cout << "Empty" << std::endl; // if there is nothing inside the list print empty and return
		return;
	}
	Node *temp;
	temp = front;
	for(int i = 0; i < count; i++) { // loop through the number of elements
		std::cout << temp->elem << " "; // print the element
		temp = temp->next; // move temp node to the next
	}
	temp = NULL; // set staitc pointer to null for safety purposes
	std::cout << std::endl;
}
