#include <iostream>
#include "LL.h"
using namespace std;

int main() {
    LL<int> l1;
    l1.addRear(2);
    l1.addRear(3);
    l1.addRear(4);
    l1.displayAll();
    l1.deleteFront();
    l1.deleteFront();
    l1.deleteFront();
    l1.displayAll();
    l1.addFront(2);
    l1.addFront(3);
    l1.addFront(4);
    l1.displayAll();
    l1.deleteRear();
    l1.displayAll();
    l1.deleteRear();
    l1.deleteRear();
    l1.displayAll();
    l1.addRear(2);
    l1.addRear(3);
    l1.displayAll();
}