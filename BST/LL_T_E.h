#ifndef LL_H
#define LL_H
#include <iostream> // std::cout
#include <cstdlib> // exit()
#include <string> // error message parameter

template<class T>
struct Node {
	T elem;
	Node<T>* next;
};

template<class T>
class LL {
private:
	Node<T> *front;
	Node<T> *rear;
	int count;
	void queueError(std::string);
public:
	LL();
	~LL();
	LL(const LL& source);
	void addRear(const T &el);
	void addFront(const T &el);
	T deleteRear();
	T deleteFront();
	bool isEmpty();
	void displayAll();
	void deleteNode(const T &e);
	void deleteNodes(const T &e);
	int search(const T &key);
	void addInOrderAscend(const T &el);
	void addInOrderDescend(const T &e);
	class Underflow{};
};


template<class T>
LL<T>::LL() {
	front = rear = NULL;
	count = 0;
}

template<class T>
LL<T>::~LL() {
	Node<T> *tempNode = front;
	while(tempNode != NULL) {
		front = front->next;
		delete tempNode;
		tempNode = front;
	}
}

template<class T>
LL<T>::LL(const LL &source) {
	front = rear = NULL;
	count = 0;
	Node<T> *p;
	while(p != NULL) {
		addRear(p->elem);
		p = p->next;
	}
}

template<class T>
void LL<T>::queueError(std::string errorMessage) {
	std::cout << errorMessage << std::endl;	
	exit(1); // exit with code 1
}

template<class T>
void LL<T>::addRear(const T &el) {
	Node<T> *n = new Node<T>;
	n->elem = el;
	n->next = NULL;
	if(isEmpty()) front = n;
	else rear->next = n;
	rear = n;
	count++;
	n = NULL;
}

template<class T>
void LL<T>::addFront(const T &el) {
	Node<T> *n = new Node<T>;
	n->elem = el;
	if(isEmpty()) {
		rear = n;
		n->next = NULL;
	}
	else  n->next = front;
	front = n;
	count++;
}

template<class T>
T LL<T>::deleteFront() {
	if(isEmpty()) {
		throw Underflow();
	}
	T item = front->elem;
	count--;
	if(isEmpty()) {
		delete front;
		front = rear = NULL;
	} else {
		Node<T> *temp;
		temp = front->next;
		delete front;
		front = temp;
		temp = NULL;
	}
	return item;
}

template<class T>
T LL<T>::deleteRear() {
	if(isEmpty()) throw Underflow();
	T item = rear->elem;
	count--;
	if(isEmpty()) {
		delete front;
		front = rear = NULL;
		return item;
	}
	Node<T> *tempPtr = front;
	for(int i = 0; i < count - 1; i++) tempPtr = tempPtr->next;
	delete rear;
	rear = tempPtr;
	rear->next = NULL;
	return item;
}

template<class T>
bool LL<T>::isEmpty() {
	if(count <= 0) return true;
	return false;
}

template<class T>
void LL<T>::displayAll() {
	if(isEmpty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	for(Node<T> *tempNode = front; tempNode != NULL; tempNode = tempNode->next) {
		std::cout << tempNode->elem << " ";
	}
	std::cout << std::endl;
}

// const T &el is the key
template<class T>
void LL<T>::deleteNode(const T &el) {
	if(isEmpty()) return;
	if(el == front->elem) {deleteFront(); return;} // if elem is front

	Node<T> *pre, *del;
	for(pre = front, del = front->next; del != NULL && del->elem != el; 
		pre = del, del = del->next);
	
	if(del == NULL && rear->elem != el) { // if element is not in list
		pre = del = NULL;
		return;
	} else if(del->next == NULL && rear->elem == el) { // update the rear pointer
		deleteRear();
	} else { // if e is in the middle
		pre->next = del->next;
		delete del;
		count--;
	}
	pre = del = NULL;
}

template<class T>
void LL<T>::deleteNodes(const T &el) {
	int occurences = search(el);
	for(int i = 0; i < occurences; i++) deleteNode(el);
}

template<class T>
int LL<T>::search(const T &el) {
	int nodesSearched = 0, occurences = 0;
	for(Node<T> *tempNode = front; tempNode != NULL; tempNode = tempNode->next) {
		if(tempNode->elem == el) occurences++;
		nodesSearched++;
	}
	//std::cout << nodesSearched << " nodes searched" << std::endl; 
	return occurences;
}

template<class T>
void LL<T>::addInOrderAscend(const T &el) {
	Node<T> *nNode = new Node<T>; // instantiate new node to add to list
	nNode->elem = el;
	if(front == NULL && rear == NULL) {
		front = rear = nNode;
		nNode->next = NULL;
		count++;
		return;
	}
	Node<T> *p, *c; // static pointers to traverse list
	for(p = front, c = front->next; c != NULL && el > c->elem; 
		p = c, c = c->next);
	
	if(p->next == NULL && p->elem <= el) { // update rear
		rear->next = nNode;
		rear = nNode;
		nNode->next = NULL;
	} else if(p->elem > el) { // if added the smallest element update front
		nNode->next = front;
		front = nNode;
	} else {
		p->next = nNode;
		nNode->next = c;
	}
	nNode = p = c = NULL;
	count++;
}

template<class T>
void LL<T>::addInOrderDescend(const T &el) {
	Node<T> *nNode = new Node<T>;
	nNode->elem = el;
	if(front == NULL && rear == NULL) {
		front = rear = nNode;
		nNode->next = NULL;
		count++;
		return;
	}
	Node<T> *p, *c;
	for(p = front, c = front->next; c != NULL && el < c->elem;
	p = c, c = c->next);
	if(p->next == NULL && p->elem >= el) {
		rear->next = nNode;
		rear = nNode;
		nNode->next = NULL;
	} else if(p->elem < el) {
		nNode->next = front;
		front = nNode;
	} else {
		p->next = nNode;
		nNode->next = c;
	}
	nNode = p = c = NULL;
	count++;
}

#endif
