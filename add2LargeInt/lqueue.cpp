#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error

#include "lqueue.h"
/***************************
Default constructor
rear will be pointing to
front if the queue is empty
***************************/
LQueue::LQueue() {
	front = new Node;
	rear = front;
	front->next = NULL;
	rear->next = NULL;
	count = 0;
}
/***************************
Destructor that will
traverse the entire linked 
queue deleting data inside 
the nodes
***************************/
LQueue::~LQueue() {
	Node *tempNode; // instantiate Node pointer
	for(int i = 0; i < count; i++) {
		tempNode = front; // create
		front = front->next;
		delete tempNode;
	}
	tempNode = NULL;
}
/***************************
If there is an error
such as a queue underflow
exit application with 
a message and exit error
errorMessage is the message
that is going to print
***************************/
void LQueue::queueError(std::string errorMessage) {
	std::cout << errorMessage << std::endl;
	exit(1);
}
/***************************
If Linked Queue is empty
return true
if not full return false
***************************/
bool LQueue::isEmpty() {
	if(count == 0) return true; // check if num of elements is == 0
	return false;
}

/***************************
add an element to the end of
the queue
el_t e is the item to be added

***************************/
void LQueue::addRear(el_t el) {
	Node *n = new Node; // n is the new node we create in the heap
	n->elem = el; // assign the node elem to el parameter
	if(isEmpty()) { // if the queue is empty then the front and 
					// rear will both point to the same node
		front = n; 
		rear = n;
		n->next = NULL;
	} 
	else { // if there are more than 1 nodes
		rear->next = n; // point current rear to new node
		rear = n; // assign rear to newly created node
	}
	rear->next = NULL;
	n = NULL; // set n to NULL since we are no longer using it
	count++; // increment the number of elements in the linked queue
	return;
}

el_t LQueue::deleteFront() { // this function needs  to be fixed
	if(isEmpty()) queueError("Queue Underflow"); // cannot delete from an empty queue
	el_t item = front->elem; // get the item we are going to return from the front node
	count--; // decrement the number of elements
	
	if(isEmpty()) { // then check if empty so we can delete and redirect 
					// front and rear nodes
		delete front; // delete all information inside the front
		front = NULL; // point to NULL
		rear = NULL; // point to NULL
	} 
	else { // if not full
		Node *tempNode = front; // instantiate a temporary node and point it to the front
		front = front->next; // make the following node the front node
		delete tempNode; // delete data in the temporary node
		tempNode = NULL; // set to NULL to avoid dangling ptr
	}
	return item; // return the deleted item
}
/***************************
Display all the contents of
the linked queue with a space
***************************/
void LQueue::displayAll() {
	if(isEmpty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	Node *temp; // instantiate temporary node pointer
	temp = front; // point temp to front 
	for(int i = 0; i < count; i++) { // traverse the linked queue for how many elements there are
		std::cout << temp->elem << " "; // output the element
		temp = temp->next; // move to the node
	}
	temp = NULL; // point temp to NULL after finishing traversing
	std::cout << std::endl; // print an extra line
}
/***************************
This function is going to
be used as a buffer
***************************/
void LQueue::printAllReverse() {
	if(isEmpty()) std::cout << "Empty" << std::endl; // if empty we print empty
	Node *p = front; // instantiate static node pointer and point to front
	printAllReverse(p); // pass to overloaded function to recursively print backwrads
	std::cout << std::endl; // print new output line
}
/***************************
This overloaded function
is going to recursively 
print the contents of the 
linked queue in reverse

Node *p static pointer 
***************************/
void LQueue::printAllReverse(Node *p) {
	if(p == NULL) return; // if P reaches NULL (end of linked queue we return)
	printAllReverse(p->next); // recursive function call to print
	std::cout << p->elem; // print the current element
}