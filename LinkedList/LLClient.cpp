#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> l1;
    l1.displayAll();
    l1.addRear(2);
    l1.addRear(4);
    l1.addRear(6);
    l1.displayAll();
    l1.addInOrderAscend(8);
    l1.addInOrderAscend(10);
    l1.displayAll();
    l1.addInOrderAscend(10);
    l1.displayAll();
    l1.deleteRear();
    l1.displayAll();
    l1.deleteRear();
    l1.displayAll();
}