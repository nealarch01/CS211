#include <iostream>
#include <string>
#include <cstdlib>
#include "queue.h"
using namespace std;

Queue::Queue() {
    count = 0;
    front = 0;
    rear = -1; // front has to be in front of rear for the stack to be empty
}

void Queue::add(el_t element) {
    if(isFull() == true) {
        queueError("Queue Overflow");
    }
    rear = (rear + 1) % MAX;
    elem[rear] = element;
    count++; // increment the number of elements found inside the array
}

el_t Queue::remove() {
    if(isEmpty() == true) {
        queueError("Queue Underflow");
    }
    el_t elret = elem[front];
    front = (front + 1) % MAX; // used to change to the new front
    count--; // decrement the number of elements found
    return elret; 
}

el_t Queue::getFront() const {
    if(isEmpty() == true) {
        cout << "Queue is empty" << endl;
    }
    return elem[front];
}

bool Queue::isEmpty() const {
    if(count == 0) {
        return true;
    }
    return false;
}

bool Queue::isFull() const {
    if(count == MAX) {
        return true;
    }
    return false;
}

void Queue::queueError(string errorMessage) const {
    cout << errorMessage << endl;
    exit(1);
}

void Queue::goToBack() {
    if(isEmpty() == true) {
        queueError("Queue Underflow");
    }
    // since we are essentially moving it back even if the queue is full, it is possible
    add(remove());
}

int Queue::getSize() const {
    return count;
}
void Queue::displayAll() const {
    int index = front;
    for(int i = 0; i < count; i++) {
        cout << elem[index] << " ";
        index = (index + 1) % MAX;

    }
    cout << endl;
}
