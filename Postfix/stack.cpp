/*************************************************
Neal Archival
CS 211
Feb 28, 2021
Postfix.cpp homework stack.cpp file

This program will contain the methods the 
implementation file for the stack with functions
that check if it's full, empty and can push and 
pop elements into the stack object
**************************************************/
#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

/*************************************************
Default constructor that sets set the stack to -1
which evluates as empty when a stack
object is instantiated
*************************************************/
Stack::Stack() {
    top = -1; //initialize the default to -1 (stack is empty)
}
/************************************************
This function is going to check if the stack is
empty by looking at the variable "top" if 
top is == -1 then the stack is empty
using constant function since we are not making
any changes to the class object
************************************************/
bool Stack::isEmpty() const {
    if(top == -1) return true;
    return false;
}
/********************************************************************
This function is going to check if the variable top is equal to MAX
if top is == MAX then we have reached the maximum number of elements
that can be pushed before an overflow and will return true
if top < max then this will return false
constant function since we are not changing the class members 
**************************************************************** */
bool Stack::isFull() const {
    if(top == MAX - 1) return true;
    return false;
}
/***********************************************************************
this function is going to push an element into the stack but will
first check if the stack is full. If it is full and a push happens,
the program will have a stack overflow and the application will end
el_t e is the element that is going to be added into the stack
***********************************************************************/
void Stack::push(el_t e) {
    if(isFull() == true) {
        stackError("Stack Overflow");
    }
    top++;
    el[top] = e;
}
/***********************************************************************
This function is going to pop the top element of the stack. It will
first check if the stack is empty, if a pop occurs with an empty stack
then the program is going end with a stack underflow
el_t function since we are going to return the top most element to
the client and then decrement the top variable
************************************************************************/
el_t Stack::pop() {
    if(isEmpty() == true) {
        stackError("Stack Underflow");
        exit(1);
    }
    return el[top--];
}
/**************************************************************************
This function is going to get the top elmeent of the stack without 
decrementing it. It will first check if the stack is empty, if it is, then
an error message is going to be displayed. If not empty then the top
most element will be returned. const function since we are not making 
changes
**************************************************************************/
el_t Stack::topElem() const {
    if(isEmpty() == true) {
        cout << "Cannot get top element. Stack is empty" << endl;
    }
    return el[top];
}
/*********************************************************************
This function is clear the stack by setting top equal to -1 It will
first check if the stack is empty, if it is not empty then the stack
will be cleared. 
*********************************************************************/
void Stack::clearIt() {
    if(isEmpty() == true) {
        cout << "Cannot clear stack. Stack is empty" << endl;
    }
    top = -1; // set the stack status back to empty
}
/********************************************************************
This function is going to print some type of error message and
then terminate the program
********************************************************************/
void Stack::stackError(string errorMessage) const {
    cout << errorMessage << endl;
    exit(1);
}
/***********************************************************************
This function is going to display all the contents of the stack starting
from the top (LIFO). It is const since we are not making changes to the
stack object, just printing
************************************************************************/
void Stack::displayAll() const {
    for(int i = top; i > -1; i--) { // we stop at -1 so we don't access -1 index
        cout << el[i] << endl;     
    }
}
