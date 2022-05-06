#ifndef LL_H
#define LL_H
#include <string>
typedef int el_t;

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
	void deleteNode(el_t e);
	void deleteNodes(el_t e);
	int search(el_t key);
	void addInOrderAscend(el_t el);
	void addInOrderDescend(el_t e);
};
#endif
