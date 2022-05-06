#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error

#include "LL.h"

LL::LL() {
	front = rear = NULL;
	count = 0;
}

LL::~LL() {
	Node* tempNode;
	for(int i = 0; i < count; i++) {
		tempNode = front;
		front = front->next;
		delete tempNode;
	}
	tempNode = NULL;
}

LL::LL(const LL &source) {
	front = NULL;
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


void LL::queueError(std::string errorMessage) {
	std::cout << errorMessage << std::endl;
	exit(1);
}

bool LL::isEmpty() {
	if(count == 0) {
		return true;
	}
	return false;
}

void LL::addRear(el_t el) {
	Node *n = new Node; // n is the new node we create in the heap
	n->elem = el; // assign the first value
	n->next = NULL; // we already know the contents if we add to rear so set to NULL
	if(isEmpty()) {
		front = n; // if queue is empty then point front to n
	} else { // if not empty
		rear->next = n; // point old rear to new node
	}
	rear = n;
	count++;
}

void LL::addFront(el_t el) {
	Node *n = new Node;
	n->elem = el;
	if(isEmpty()) {
		rear = n;
		n->next = NULL;
	} 
	else {
		n->next = front; // point new node to the front address
	}
	front = n;
	count++; // increment, we don't have to change rear
	n = NULL;
	return;
}


el_t LL::deleteFront() { // this function needs  to be fixed
	if(isEmpty()) queueError("Queue Underflow");
	el_t item = front->elem;
	count--;
	
	if(isEmpty()) { // 
		delete front;
		front = NULL;
		rear = NULL;
	} 
	else {
		Node *nFront; // instantiate temporary new front
		nFront = front->next;
		delete front;
		front = nFront;
		nFront = NULL;
	}
	return item;
}

el_t LL::deleteRear() {
	if(isEmpty()) queueError("Queue Underflow");
	count--;
	el_t item = rear->elem;
	Node *p = front;
	for(int i = 0; i < count - 1; i++) {
		p = p->next;
	}
	delete rear;
	rear = p;
	rear->next = NULL;
	p = NULL;
	return item;
}

void LL::displayAll() {
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

void LL::deleteNode(el_t e) {
	if(isEmpty()) return;
	if(e == front->elem) { // we don't delete rear beacuse we remove the front most which might be in the middle
		deleteFront(); // deleteFront decrements count
		return;
	}
	Node *pre, *del;
	for(pre = front, del = front->next; del != NULL && del->elem != e; pre = del, del = del->next); // loop to iterate until we reach e or end of linked list
	if(rear->elem == e && del->next == NULL) { // need to reassign the rear pointer if e is at the end of the loop
		deleteRear();
	} else if(rear->elem != e && del == NULL) { // if delete is after the last node and not equal too return
		return;
	} else {
		pre->next = del->next;
		delete del;
		count--;
	}
	pre = del = NULL;
	return;
}

void LL::deleteNodes(el_t e) {
	if(isEmpty()) return;
	int occurences = search(e);
	for(int i = 0; i < occurences; i++) { // iterate for the number of occurenecs
		deleteNode(e);
	}
}
// NOT ORIGINAL LL SEARCH. CHANGED FOR BST SEARCH
int LL::search(el_t key) {
	if(isEmpty()) return 0; // return 0 if the linked list is empty
	int counter = 0; // 
	int iterations = 0;
	for(Node *tempNode = front; tempNode != NULL; tempNode = tempNode->next, iterations++) {
		if(key == tempNode->elem) {counter++; break;}
	}
	std::cout << iterations << " nodes checked" << std::endl;
	return counter; // 
}
/****************************************
Two node pointers prev and curr. Travserse
the  linked list, if el > current node 
element or current node == NULL (end of
list) break the loop and run conditionals

If prev->next == NULL we are at the rear 
of the list so we add to the rear

If el < previous and current node then we 
are at the front of the list so add front

If neither insert in between prev and
curr by pointing prev node to new node
and the 

el_t el is the item we are adding
*******************************************/
void LL::addInOrderAscend(el_t el) {
	Node *prev, *curr, *nNode = new Node;
	nNode->elem = el;
	if(front == NULL && rear == NULL) { // if the first two nodes are null then the linked list is empty so add front
		front = nNode;
		rear = nNode;
		nNode->next = NULL;
		count++;
		return;
	}
	for(prev = front, curr = front->next; curr != NULL && el > curr->elem; prev = prev->next, curr = curr->next); // traverse until we find a node with a larger integer
	if(prev->next == NULL && prev->elem <= el) { // if we reach the end of the list and we did not find largest number add rear
		rear->next = nNode;
		nNode->next = NULL;
		rear = nNode;
	} else if(prev->elem > el) { // if first case fails (prev->elem is <= to e) the smallest number has been added
	// if the same smallest number is added it is going to be added after the front element
		nNode->next = front;
		front = nNode;
	} else { // if el > prev->elem && el < curr->elem insert in the middle
		prev->next = nNode;
		nNode->next = curr;
	}
	nNode = prev = curr = NULL; // point all new nodes to NULL
	count++;
}

void LL::addInOrderDescend(el_t el) {
	Node *prev, *curr, *nNode = new Node;
	nNode->elem = el;
	if(front == NULL && rear == NULL) { // if the first two elements are null then the linked list is empty
		front = nNode;
		rear = nNode;
		nNode->next = NULL;
		count++;
		return;
	}
	for(prev = front, curr = front->next; curr != NULL && el < curr->elem; prev = prev->next, curr = curr->next); // traverse until we find a node with a larger integer
	if(curr == NULL && prev->elem >= el) { // if the largest number is added, update rear pointer
		rear->next = nNode;
		nNode->next = NULL;
		rear = nNode;
	} else if(prev->elem < el) { // if smallest number is added
		nNode->next = front;
		front = nNode;
	} else {
		prev->next = nNode;
		nNode->next = curr;
	}
	prev = curr = NULL; // change back 
	count++;
}