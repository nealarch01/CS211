#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

void addPerson(Stack& s, el_t name);

int main() {
    Stack s1;
    if(s1.isEmpty() == true) {
        cout << "The stack is empty (from 2)" << endl;
    }
    else {
        cout << "The stack is not empty (from 2)" << endl;
    }
    addPerson(s1, "Mike");
    addPerson(s1, "Kathy");
    cout << s1.topElem() << " is at the top of the stack (from 4)" << endl;
    addPerson(s1, "Dave");
    addPerson(s1, "Alice");
    addPerson(s1, "Tom");
    if(s1.isFull() == true) {
        cout << "Stack is full (from 6)" << endl;
    }
    else {
        cout << "The stack is not full (from 6)" << endl;
    }

    s1.displayAll();

    addPerson(s1, "Meg");

    cout << s1.pop() << endl;
    cout << s1.topElem() << " is at the top of the stack (from 10)" << endl;
    s1.clearIt();
    if(s1.isEmpty() == true) {
        cout << "The stack is empty (from 12)" << endl;
    }
    else {
        cout << "The stack is not empty (from 12)" << endl;
    }
    return 0;
}


void addPerson(Stack& s, el_t name) {
    if(s.isFull() == true) {
        cout << "Cannot add " << name << " because the stack is full" << endl;
        return;
    }
    s.push(name);
}