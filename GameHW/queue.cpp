#include <iostream>
#include <string>
#include <cstdlib>
#include "queue.h"
using namespace std;
/**************************************************************************
Default constructor assigns the queue counters
count is the number of elements
rear increments when something is added into the queue, starts at -1 as 
front has to be ahead of rear if empty
front will increment when something is removed from the queue
***************************************************************************/
Queue::Queue() {
    count = 0;
    front = 0; // front by default in front of rear (empty)
    rear = -1; // front has to be in front of rear for the stack to be empty
}
/**************************************************************
This function is going to add a new element into the queue 
*************************************************************/
void Queue::add(el_t element) {
    if(isFull() == true) { // if the queue is full then we cannot push anymore
        queueError("Queue Overflow");
    }
    rear = (rear + 1) % MAX; // algorithm to wrap when the index reaches the maximum
    elem[rear] = element; // set the rear index to the newly added element
    count++; // increment the number of elements found inside the array
}
/**************************************************************
This function is going to remove one element from the queue
*************************************************************/
el_t Queue::remove() {
    if(isEmpty() == true) { // if the queue is empty we cannot remove anymore
        queueError("Queue Underflow");
    }
    el_t elret = elem[front];
    front = (front + 1) % MAX; // used to change to the new front and wrap if it reaches the max
    count--; // decrement the number of elements found
    return elret; 
}
/**************************************************************
This function is going to get the front element without
removing it from the queue
*************************************************************/
el_t Queue::getFront() const {
    if(isEmpty() == true) { // if the queue is empty there is nothing to be taken
        cout << "Queue is empty" << endl;
    }
    return elem[front];
}
/**************************************************************
This function is going to check if the queue is empty 
*************************************************************/
bool Queue::isEmpty() const { 
    if(count == 0) { // if the count is 0 then the queue is empty so return true
        return true;
    }
    return false;
}
/**************************************************************
This function is going to check if count is == max which means
the queue is full
*************************************************************/
bool Queue::isFull() const {
    if(count == MAX) { // if count is == max then we have reached the maximum number of inputs the queue can hold
        return true;
    }
    return false;
}
/**************************************************************
This function is going to print an error message and end
the program if there is a queue underflow (removing when empty)
or queue overflow (adding when full)
errorMessage is a string to prompt the application on the 
error type
*************************************************************/
void Queue::queueError(string errorMessage) const {
    cout << errorMessage << endl;
    exit(1);
}
/**************************************************************
This function is going to swap the front element with the 
rear elment (element at the back of the queue) 
*************************************************************/
void Queue::goToBack() {
    if(isEmpty() == true) { // if the stack is empty then we cannot swap so we prompt error
        queueError("Queue Underflow");
    }
    // since we are essentially moving it back even if the queue is full, it is possible
    add(remove());
}
/**************************************************************
This function is going to get the size of the queue 
const since we are not changing data in the queue
*************************************************************/
int Queue::getSize() const {
    return count;
}
/**************************************************************
Overloaded operator function to print out expression for
game.cpp homework
ostream is the output "pipe" pass by reference since we are 
going to take in and return the same output pipe
const el_t object since we are not changing object data, pass
by reference since e might be a large object
*************************************************************/
ostream& operator<<(ostream& out, const el_t& e) {
    out << e.oprd1 << " " << e.oprt << " = " << e.oprd2 << endl; 
    return out; // return the output
}
/**************************************************************
This function is going to display all queue object data
const since we are not making changes to the queue
*************************************************************/
void Queue::displayAll() const {
    int index = front; // set the start of the index to the front 
    for(int i = 0; i < count; i++) { // set i = 0 and iterate through the number of elements in the queue
        cout << elem[index] << " "; // display the information
        index = (index + 1) % MAX; // algorithm to wrap around
    }
    cout << endl; // print a new line 
}
