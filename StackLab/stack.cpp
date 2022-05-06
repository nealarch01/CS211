#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;


Stack::Stack() {
    top = -1; //initialize the default to -1 (stack is empty)
}

bool Stack::isEmpty() const {
    if(top == -1) return true;
    return false;
}
bool Stack::isFull() const {
    if(top == MAX - 1) return true;
    return false;
}
void Stack::push(el_t el) {
    if(isFull() == true) {
        stackError("Stack Overflow");
    }
    top++;
    names[top] = el;
}
el_t Stack::pop() {
    if(isEmpty() == true) {
        stackError("Stack Underflow");
        exit(1);
    }
    return names[top--];
}
el_t Stack::topElem() const {
    if(isEmpty() == true) {
        cout << "Cannot get top element. Stack is empty" << endl;
    }
    return names[top];
}

void Stack::clearIt() {
    if(isEmpty() == true) {
        cout << "Cannot clear stack. Stack is empty" << endl;
    }
    top = -1; // set the stack status back to empty
}

void Stack::stackError(string errorMessage) const {
    cout << errorMessage << endl;
    exit(1);
}
void Stack::displayAll() const {
    for(int i = top; i > -1; i--) { // we stop at -1 so we don't access -1 index
        cout << names[i] << endl;     
    }
}