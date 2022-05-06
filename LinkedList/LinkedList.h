// Template Linked List Implementation
// Created by Neal A for CS211 Class
#ifndef	LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream> // std::cout
#include <cstdlib> // exit()

template<class T>
class LLNode {
template<typename U> friend class LinkedList;
private:
	T elem;
	LLNode<T> *next;
};

template<class T>
class LinkedList {
private:
	LLNode<T> *front;
	LLNode<T> *rear;
	int count;
	void queueError(const char *errorMessage);
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& source);
	void addRear(const T &el);
	void addFront(const T &el);
	T deleteRear();
	T deleteFront();
	bool isEmpty();
	void displayAll();
	void deleteLLNode(const T &e);
	void deleteLLNodes(const T &e);
	int search(const T &key);
	void addInOrderAscend(const T &el);
	void addInOrderDescend(const T &e);
};

template<class T>
LinkedList<T>::LinkedList() {
	front = rear = nullptr;
	count = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
	LLNode<T> *tempLLNode = front;
	while(tempLLNode != nullptr) {
		front = front->next;
		delete tempLLNode;
		tempLLNode = front;
	}
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &source) {
	front = rear = nullptr;
	count = 0;
	LLNode<T> *p;
	while(p != nullptr) {
		addRear(p->elem);
		p = p->next;
	}
}

template<class T>
void LinkedList<T>::queueError(const char *errorMessage) {
	std::cout << errorMessage << std::endl;	
	exit(1); // exit with code 1
}

template<class T>
void LinkedList<T>::addRear(const T &el) {
	LLNode<T> *n = new LLNode<T>;
	n->elem = el;
	n->next = nullptr;
	isEmpty() ? front = n : rear->next = n;
	rear = n;
	count++;
	n = nullptr;
}

template<class T>
void LinkedList<T>::addFront(const T &el) {
	LLNode<T> *n = new LLNode<T>;
	n->elem = el;
	isEmpty() ? rear = n : n->next = front;
	front = n;
	count++;
}

template<class T>
T LinkedList<T>::deleteFront() {
	if(isEmpty()) throw "Exception: Queue Underflow";
	T item = front->elem;
	count--;
	if(isEmpty()) {
		delete front;
		front = rear = nullptr;
	} else {
		LLNode<T> *temp;
		temp = front->next;
		delete front;
		front = temp;
		temp = nullptr;
	}
	return item;
}

template<class T>
T LinkedList<T>::deleteRear() {
	if(isEmpty()) throw "Exception: Queue Underflow"; 
	T item = rear->elem;
	count--;
	if(isEmpty()) {
		delete front;
		front = rear = nullptr;
		return item;
	}
	LLNode<T> *tempPtr = front;
	for(int i = 0; i < count - 1; i++) tempPtr = tempPtr->next;
	delete rear;
	rear = tempPtr;
	rear->next = nullptr;
	return item;
}

template<class T>
bool LinkedList<T>::isEmpty() {
	if(count <= 0) return true;
	return false;
}

template<class T>
void LinkedList<T>::displayAll() {
	if(isEmpty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	for(LLNode<T> *tempLLNode = front; tempLLNode != nullptr; tempLLNode = tempLLNode->next) {
		std::cout << tempLLNode->elem << " ";
	}
	std::cout << std::endl;
}

// const T &el is the key
template<class T>
void LinkedList<T>::deleteLLNode(const T &el) {
	if(isEmpty()) return;
	if(el == front->elem) {deleteFront(); return;} // if elem is front

	LLNode<T> *pre, *del;
	for(pre = front, del = front->next; del != nullptr && del->elem != el; 
		pre = del, del = del->next);
	
	if(del == nullptr && rear->elem != el) { // if element is not in list
		pre = del = nullptr;
		return;
	} else if(del->next == nullptr && rear->elem == el) { // update the rear pointer
		deleteRear();
	} else { // if e is in the middle
		pre->next = del->next;
		delete del;
		count--;
	}
	pre = del = nullptr;
}

template<class T>
void LinkedList<T>::deleteLLNodes(const T &el) {
	int occurences = search(el);
	for(int i = 0; i < occurences; i++) deleteLLNode(el);
}

template<class T>
int LinkedList<T>::search(const T &el) {
	int LLNodesSearched = 0, occurences = 0;
	for(LLNode<T> *tempLLNode = front; tempLLNode != nullptr; tempLLNode = tempLLNode->next) {
		if(tempLLNode->elem == el) occurences++;
		LLNodesSearched++;
	}
	//std::cout << LLNodesSearched << " LLNodes searched" << std::endl; 
	return occurences;
}

template<class T>
void LinkedList<T>::addInOrderAscend(const T &el) {
	LLNode<T> *nLLNode = new LLNode<T>; // instantiate new LLNode to add to list
	nLLNode->elem = el;
	if(front == nullptr && rear == nullptr) {
		front = rear = nLLNode;
		nLLNode->next = nullptr;
		count++;
		return;
	}
	LLNode<T> *p, *c; // static pointers to traverse list
	for(p = front, c = front->next; c != nullptr && el > c->elem; 
		p = c, c = c->next);
	
	if(p->next == nullptr && p->elem <= el) { // update rear
		rear->next = nLLNode;
		rear = nLLNode;
		nLLNode->next = nullptr;
	} else if(p->elem > el) { // if added the smaLinkedListest element update front
		nLLNode->next = front;
		front = nLLNode;
	} else {
		p->next = nLLNode;
		nLLNode->next = c;
	}
	nLLNode = p = c = nullptr;
	count++;
}

template<class T>
void LinkedList<T>::addInOrderDescend(const T &el) {
	LLNode<T> *nLLNode = new LLNode<T>;
	nLLNode->elem = el;
	if(front == nullptr && rear == nullptr) {
		front = rear = nLLNode;
		nLLNode->next = nullptr;
		count++;
		return;
	}
	LLNode<T> *p, *c;
	for(p = front, c = front->next; c != nullptr && el < c->elem;
	p = c, c = c->next);
	if(p->next == nullptr && p->elem >= el) {
		rear->next = nLLNode;
		rear = nLLNode;
		nLLNode->next = nullptr;
	} else if(p->elem < el) {
		nLLNode->next = front;
		front = nLLNode;
	} else {
		p->next = nLLNode;
		nLLNode->next = c;
	}
	nLLNode = p = c = nullptr;
	count++;
}

#endif
