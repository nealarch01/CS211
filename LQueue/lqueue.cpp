#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error

#include "lqueue.h"

LQueue::LQueue() {
	front = new Node;
	rear = front;
	front->next = NULL;
	rear->next = NULL;
	count = 0;
}

LQueue::~LQueue() {
	Node* tempNode;
	for(int i = 0; i < count; i++) {
		tempNode = front;
		front = front->next;
		delete tempNode;
	}
	tempNode = NULL;
}

void LQueue::queueError(std::string errorMessage) {
	std::cout << errorMessage << std::endl;
	exit(1);
}

bool LQueue::isEmpty() {
	if(count == 0) {
		return true;
	}
	return false;
}

void LQueue::addRear(el_t el) {
	Node *n = new Node; // n is the new node we create in the heap
	n->elem = el; // assign the first value
	if(isEmpty()) { // if the queue is empty then the front and 
					// rear will both point to the same node
		front = n;
		rear = n;
		n->next = NULL;
	} else {
		rear->next = n;
		rear = n;
	}
	rear->next = NULL;
	count++;
	return;
}


el_t LQueue::deleteFront() { // this function needs  to be fixed
	if(isEmpty()) queueError("Queue Underflow");

	el_t item = front->elem;

	count--;
	
	if(isEmpty()) { // 
		delete front;
		front = NULL;
		rear = NULL;
	} 
	else {
		Node *tempNode;
		tempNode = front;
		front = front->next;
		delete tempNode;
		tempNode = NULL;
	}
	return item;
}

void LQueue::displayAll() {
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
