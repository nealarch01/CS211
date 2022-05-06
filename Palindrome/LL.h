#ifndef LL_H
#define LL_H
#include <string>
typedef char el_t;

struct Node {
	el_t elem;
	Node* next;
};

class LL {
private:
	Node* front;
	Node* rear;
	int count;
	void queueError(std::string);
public:
	LL();
	~LL();
	LL(const LL& source);
	void addRear(el_t);
	void addFront(el_t);
	el_t deleteRear();
	el_t deleteFront();
	bool isEmpty();
	void displayAll();
	LL operator=(LL &source);
};

#endif
