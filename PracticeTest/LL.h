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
	LL(const LL &source);
	void addRear(const T &el);
	void addFront(const T &el);
	T deleteRear();
	T deleteFront();
	bool isEmpty() const;
	void displayAll() const;
	void deleteNode(const T &e);
	void deleteNodes(const T &e);
	int search(const T &key);
	void addInOrderAscend(const T &el);
	void addInOrderDescend(const T &e);
	int getCount() const;
};

template<typename T>
LL<T>::LL() {
    front = rear = NULL;
    count = 0;
}

template<typename T>
LL<T>::~LL() {
    while(!isEmpty()) {
        deleteFront();
    }
}

template<typename T>
bool LL<T>::isEmpty() const {
    return count == 0 ? true : false; // using ternary operator for one liner
}

template<typename T>
void LL<T>::displayAll() const {
    if(isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    for(Node<T> *temp = front; temp != NULL; temp = temp->next) {
        std::cout << temp->elem << "->";
    }
    std::cout << std::endl;
}

template<typename T>
void LL<T>::addRear(const T &el) {
    Node<T> *nNode = new Node<T>;
    nNode->elem = el;   
    nNode->next = NULL; // new rear node next will always be null / nullptr
    if(isEmpty()) front = nNode;
    else rear->next = nNode;
    rear = nNode;
    count++;
}

template<typename T>
void LL<T>::addFront(const T &el) {
    Node<T> *nNode = new Node<T>;
    nNode->elem = el;
    if(isEmpty()) {
        rear = nNode;
        nNode->next = NULL;
    } else {
        nNode->next = front;
    }
    front = nNode;
    count++;
}

template<typename T>
T LL<T>::deleteFront() {
    if(isEmpty()) queueError("Underflow");
    T item = front->elem;
    count--;
    if(isEmpty()) {
        delete front;
        front = rear = NULL;
    } else {
        Node<T> *tempFront = front->next;
        delete front;
        front = tempFront;   
    }
    return item;
}

template<typename T>
T LL<T>::deleteRear() {
    if(isEmpty()) queueError("Underflow");
    T item = front->elem;
    count--;
    if(isEmpty()) {
        delete rear;
        front = rear = NULL;
    } else {
        Node<T> *p, *c;
        for(p = front, c = front->next; c->next != NULL; p = c, c = c->next);
        delete rear;
        rear = p;
        p->next = c = NULL;
    }
    return item;
}

template<typename T>
void LL<T>::queueError(std::string errorMessage) {
    std::cout << errorMessage << std::endl;
    exit(1);
}

#endif