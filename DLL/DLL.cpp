#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error

#include "DLL.h"

/***********************************
Default constructor
************************************/
DLL::DLL() {
	front = rear = NULL;
	count = 0;
}

/**********************************
Destructor to delete all nodes
created when out of 
**********************************/
DLL::~DLL() {
	Node* tempNode; // temporary static pointer
	for(int i = 0; i < count; i++) {
		tempNode = front;
		front = front->next;
		delete tempNode;
	}
	tempNode = NULL;
}

/******************************
 Copy constructor copy data
 from an existing list to another

 const DLL &source const restrict
 change to source object and pass
 by reference to copy
*******************************/
DLL::DLL(const DLL &source) {
	front = NULL;
	rear = NULL;
	count = 0;
	Node *p; 
	p = source.front; 
	while(p != NULL) {
		addRear(p->elem); 
		p = p->next; // no need to increment count since it will be incremented in addRear function
	}
	// don't have to set p to NULL since the last node of the source is already NULL
}

/**********************************
Exit application if there is an 
underflow error

errorMessage error message displayed
to screen before terminating app
**********************************/
void DLL::queueError(std::string errorMessage) {
	std::cout << errorMessage << std::endl;
	exit(1);
}

/**********************************
Check if list is empty
**********************************/
bool DLL::isEmpty() {
	if(count == 0) {
		return true;
	}
	return false;
}

/**********************************
Add an element to the rear of the
list and update rear pointer

el_t el item to add to list
**********************************/
void DLL::addRear(el_t el) {
	Node *n = new Node; // create new node in heap
	n->elem = el; 
	n->next = NULL; // rear->next will always be NULL
	if(isEmpty()) {
		front = n; // if queue is empty then point front to n
		n->prev = NULL;
	} else { // if not empty
		rear->next = n; // point old rear to new node
		n->prev = rear;
	}
	rear = n;
	count++;
}

/**********************************
Add a new front node and update
front pointer

el_t el item to add to list
**********************************/
void DLL::addFront(el_t el) {
	Node *n = new Node;
	n->elem = el;
	n->prev = NULL; // front prev is always going to be NULL
	if(isEmpty()) {
		rear = n;
		n->next = NULL;
	} else { // if not empty
		n->next = front; 
		front->prev = n;
	}
	front = n;
	count++;
	n = NULL;
	return;
}

/**********************************
Delete the node front is pointing to
and return the item removed
**********************************/
el_t DLL::deleteFront() { 
	if(isEmpty()) queueError("Queue Underflow");
	el_t item = front->elem;
	count--;
	
	if(isEmpty()) { 
		delete front;
		front = rear = NULL;
	} 
	else {
		Node *nFront; // instantiate temporary new front
		nFront = front->next;
		nFront->prev = NULL;
		delete front;
		front = nFront;
		nFront = NULL;
	}
	return item;
}

/**********************************
Delete the node rear is pointing to
and return the item of the node
**********************************/
el_t DLL::deleteRear() {
	if(isEmpty()) queueError("Queue Underflow");
	el_t item = rear->elem;
	count--;
	if(isEmpty()) {
		delete rear;
		front = rear = NULL;
	} 
	else {
		Node *tempNode = rear->prev;
		delete rear;
		rear = tempNode;
		rear->next = NULL;
		tempNode = NULL;
	}
	return item;
}


/**********************************
Display all elements inside the list
**********************************/
void DLL::displayAll() {
	if(isEmpty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	Node *temp;
	temp = front;
	for(int i = 0; i < count; i++) {
		std::cout << temp->elem << " ";
		temp = temp->next;
	}
	temp = NULL;
	std::cout << std::endl;
}

/**********************************
Delete one node

el_t e item we want to remove from
list
**********************************/
void DLL::deleteNode(el_t e) {
	if(isEmpty()) return;
	if(e == front->elem) { // if the front element is equal to e delete front
		deleteFront(); // deleteFront decrements count
		return;
	}
	Node *pre, *del; // static pointers to traverse
	for(pre = front, del = front->next; del != NULL && del->elem != e; pre = del, del = del->next); // loop to iterate until we reach e or end of linked list
	if(rear->elem == e && del->next == NULL) { // if e exists at the end of the list deleteRear to update rearPointer
		deleteRear();
	} else if(rear->elem != e && del == NULL) { // if del is after the last node (NULL) and not equal to e then e does not exist return
		return;
	} else { // delete an element in the middle of the list
		pre->next = del->next;
		del->next->prev = pre;
		delete del;
		count--;
	}
	pre = del = NULL;
	return;
}

/**********************************
Delete multiple nodes

el_t e item to be removed in the
list
**********************************/
void DLL::deleteNodes(el_t e) {
	if(isEmpty()) return;
	int occurences = search(e);
	for(int i = 0; i < occurences; i++) { // iterate for the number of occurenecs
		deleteNode(e);
	}
}

/**********************************
Search list and return the number
of occurences of key in the list

el_t key item to be found in the 
list
**********************************/
int DLL::search(el_t key) {
	if(isEmpty()) return 0; // return 0 if the linked list is empty
	int counter = 0; // 
	for(Node *tempNode = front; tempNode != NULL; tempNode = tempNode->next) {
		if(key == tempNode->elem) counter++;
	}
	return counter; // 
}

/**********************************
Add an element to list in ascending 
order

el_t el item to add in list
**********************************/
void DLL::addInOrderAscend(el_t el) {
	Node *p, *curr, *nNode = new Node;
	nNode->elem = el;
	if(front == NULL && rear == NULL) { // if the first two elements are null then the linked list is empty
		rear = front = nNode;
		nNode->next = nNode->prev = NULL;
		count++;
		return;
	}
	for(p = front, curr = front->next; curr != NULL && el > curr->elem; p = p->next, curr = curr->next); // traverse until we find a node with a larger integer
	if(p->next == NULL && p->elem <= el) { // if we reach the end of the list and we did not find largest number add rear
		// if the largest / larger number is added, update rear to point towards the new node
		rear->next = nNode;
		nNode->next = NULL;
		nNode->prev = rear;
		rear = nNode;
	} else if(p->elem > el) { // if first case fails (p->elem is <= to e) the smallest number has been added (addFront)
	// if the same smallest number is added it is going to be added after the front element
		nNode->next = front;
		front->prev = nNode;
		front = nNode;
		nNode->prev = NULL;
	} else { // if neither largest or smallest then new node will be in the middle
		p->next = nNode;
		curr->prev = nNode;
		nNode->prev = p;
		nNode->next = curr;
	}
	nNode = p = curr = NULL; // make pointers to null now
	count++;
}

/**********************************
Add an element to list in descending 
order

el_t el item we want to add
**********************************/
void DLL::addInOrderDescend(el_t el) {
	Node *p, *curr, *nNode = new Node;
	nNode->elem = el;
	if(front == NULL && rear == NULL) { // if the first two elements are null then the linked list is empty
		rear = front = nNode;
		nNode->next = nNode->prev = NULL;
		count++;
		return;
	}
	for(p = front, curr = front->next; curr != NULL && el < curr->elem; p = p->next, curr = curr->next); // traverse until we find a node with a larger integer
	if(p->next == NULL && p->elem >= el) { // if we reach the end of the list and we did not find largest number add rear
		// if the smallest number is added, update rear to point towards the new node
		rear->next = nNode;
		nNode->next = NULL;
		nNode->prev = rear;
		rear = nNode;
	} else if(p->elem < el) { // if first case fails (p->elem is <= to e) the smallest number has been added (addFront)
	// if the same / largest number is added it is going to be added after the front element
		nNode->next = front;
		front->prev = nNode;
		front = nNode;
		nNode->prev = NULL;
	} else { // if neither largest or smallest then new node will be in the middle
		p->next = nNode;
		curr->prev = nNode;
		nNode->prev = p;
		nNode->next = curr;
	}
	nNode = p = curr = NULL; // make pointers to null now
	count++;
}


/***********************************
Display all items reverse but 
start from rear and end at front
************************************/
void DLL::printAllReverseDLL() {
	if(isEmpty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	Node *tempNode = rear; // create node and point to rear
	while(tempNode != NULL) { // while tempNode is not past 
		std::cout << tempNode->elem << " ";
		tempNode = tempNode->prev;
	}
	tempNode = NULL;
	std::cout << std::endl;
}