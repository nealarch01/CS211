#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;
const int MAX = 5;
typedef int el_t;
class Stack {
private:
    el_t el[MAX];
    int top;
    void stackError(string errorMessage) const;
public:
    Stack(); // default constructor
    bool isEmpty() const; // check if the stack is empty
    bool isFull() const; // check if the stack is full and return empty
    void push(el_t item);
    el_t pop();
    el_t topElem() const;
    void clearIt();
    void displayAll() const;
};
#endif