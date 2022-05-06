// Doubly linked list implementation
// Created by Neal A.
#ifndef DLL_T_H
#define DLL_T_H
#include <iostream>
#include <cstdlib> // exit(1) for error

template<class T>
class DLLNode {
template<class U> friend class DLL;
private:
    T elem;
    DLLNode<T> *next;
    DLLNode<T> *prev;
};

template<class T>
class DLL {
private:
    DLL<T> *front;
    DLL<T> *rear;
    int count; // num of items inside the doubly linked list
    void dllError(const char *errorMessage); 
public:
    DLL();
    ~DLL();
    DLL(const DLL &source);
    T deleteRear();
    T deleteFront();
    void addRear(const T &el);
    void addFront(const T &el);
    bool isEmpty();
    void displayAll();
    void deleteNode(const T &e);
    void deleteNodes(const T &e);
    int search(const T &key);
    void addInOrderAscend(const T &el);
    void addInOrderDescend(const T &e);
};

template <class T>
DLL<T>::DLL() {
    front = rear = nullptr;
}
template<class T>
DLL<T>::DLL(const DLL &source) {
	front = rear = nullptr;
	count = 0;
	DLLNode<T> *p;
	while(p != nullptr) {
		addRear(p->elem);
		p = p->next;
	}
}

template<class T>
void DLL<T>::dllError(const char *errorMessage) {
	std::cout << errorMessage << std::endl;	
	exit(1); // exit with code 1
}

template<class T>
void DLL<T>::addRear(const T &el) {
	DLLNode<T> *n = new DLLNode<T>;
	n->elem = el;
	n->next = nullptr;
    n->prev = rear;
    isEmpty() ? front = n : rear->next = n;
	rear = n;
	count++;
	n = nullptr;
}

template<class T>
void DLL<T>::addFront(const T &el) {
	DLLNode<T> *n = new DLLNode<T>;
	n->elem = el;
    isEmpty() ? rear = n : n->next = front;
	front = n;
	count++;
}

template<class T>
T DLL<T>::deleteFront() {
	if(isEmpty()) dllERror("DLL Underflow");
	T item = front->elem;
	count--;
	if(isEmpty()) {
		delete front;
		front = rear = nullptr;
	} else {
		DLLNode<T> *temp;
		temp = front->next;
		delete front;
		front = temp;
		temp = nullptr;
	}
	return item;
}

template<class T>
T DLL<T>::deleteRear() {
	if(isEmpty() dllError("DLL Underflow");
	T item = rear->elem;
	count--;
	if(isEmpty()) {
		delete front;
		front = rear = nullptr;
		return item;
	}
	DLLNode<T> *tempPtr = front;
	for(int i = 0; i < count - 1; i++) tempPtr = tempPtr->next;
	delete rear;
	rear = tempPtr;
	rear->next = nullptr;
	return item;
}

template<class T>
bool DLL<T>::isEmpty() {
	if(count <= 0) return true;
	return false;
}

template<class T>
void DLL<T>::displayAll() {
	if(isEmpty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	for(DLLNode<T> *tempNode = front; tempNode != nullptr; tempNode = tempNode->next) {
		std::cout << tempNode->elem << " ";
	}
	std::cout << std::endl;
}

// const T &el is the key
template<class T>
void DLL<T>::deleteNode(const T &el) {
	if(isEmpty()) return;
	if(el == front->elem) {deleteFront(); return;} // if elem is front

	DLLNode<T> *pre, *del;
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
void DLL<T>::deleteNodes(const T &el) {
	int occurences = search(el);
	for(int i = 0; i < occurences; i++) deleteNode(el);
}

template<class T>
int DLL<T>::search(const T &el) {
	int nodesSearched = 0, occurences = 0;
	for(DLLNode<T> *tempNode = front; tempNode != nullptr; tempNode = tempNode->next) {
		if(tempNode->elem == el) occurences++;
		nodesSearched++;
	}
	//std::cout << nodesSearched << " nodes searched" << std::endl; 
	return occurences;
}

template<class T>
void DLL<T>::addInOrderAscend(const T &el) {
	DLLNode<T> *nNode = new DLLNode<T>; // instantiate new node to add to list
	nNode->elem = el;
	if(front == nullptr && rear == nullptr) {
		front = rear = nNode;
		nNode->next = nullptr;
		count++;
		return;
	}
	DLLNode<T> *p, *c; // static pointers to traverse list
	for(p = front, c = front->next; c != nullptr && el > c->elem; 
		p = c, c = c->next);
	
	if(p->next == nullptr && p->elem <= el) { // update rear
		rear->next = nNode;
		rear = nNode;
		nNode->next = nullptr;
	} else if(p->elem > el) { // if added the smaDLLest element update front
		nNode->next = front;
		front = nNode;
	} else {
		p->next = nNode;
		nNode->next = c;
	}
	nNode = p = c = nullptr;
	count++;
}

template<class T>
void DLL<T>::addInOrderDescend(const T &el) {
	DLLNode<T> *nNode = new DLLNode<T>;
	nNode->elem = el;
	if(front == nullptr && rear == nullptr) {
		front = rear = nNode;
		nNode->next = nullptr;
		count++;
		return;
	}
	DLLNode<T> *p, *c;
	for(p = front, c = front->next; c != nullptr && el < c->elem;
	p = c, c = c->next);
	if(p->next == nullptr && p->elem >= el) {
		rear->next = nNode;
		rear = nNode;
		nNode->next = nullptr;
	} else if(p->elem < el) {
		nNode->next = front;
		front = nNode;
	} else {
		p->next = nNode;
		nNode->next = c;
	}
	nNode = p = c = nullptr;
	count++;
}

#endif
