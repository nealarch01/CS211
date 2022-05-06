#ifndef LL_H
#define LL_H
#include <string>
typedef int el_t;

struct Node {
	el_t elem;
	Node* prev;
	Node* next;
};

class DLL {
private:
	Node* front;
	Node* rear;
	int count;
	void queueError(std::string);
public:
	DLL();
	~DLL();
	DLL(const DLL& source);
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
	void printAllReverseDLL();
};
#endif
