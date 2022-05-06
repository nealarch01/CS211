#include <iostream>

#include "DLL.h"

void print(el_t item) {
    std::cout << item << " has been deleted." << std::endl;
}

int main() {
    DLL l1;
    l1.addFront(1);
    l1.addFront(2);
    l1.addFront(3);
    l1.addRear(4);
    l1.addRear(5);
    l1.displayAll();
    l1.printAllReverseDLL();

    print(l1.deleteFront());
    print(l1.deleteRear());
    l1.displayAll();
    l1.printAllReverseDLL();

    print(l1.deleteFront());
    print(l1.deleteRear());
    l1.displayAll();

    print(l1.deleteFront());
    l1.displayAll();

    l1.addRear(10);
    l1.addFront(11);
    l1.displayAll();
    print(l1.deleteRear());
    print(l1.deleteRear());
    l1.displayAll();
}
