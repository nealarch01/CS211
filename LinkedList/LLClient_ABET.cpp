#include <iostream>
#include <cstdlib> // rand()
#include "LL.h"

int main() {
/*
    std::cout << "Testing addInOrderAscend function" << std::endl;
    LL list;
    list.addInOrderAscend(5);
    list.addInOrderAscend(1);
    list.addInOrderAscend(3);
    list.addInOrderAscend(7);
    list.addInOrderAscend(4);
    list.addInOrderAscend(0);
    list.displayAll(); //0, 1, 3, 4, 5, 7

    list.deleteRear();
    list.deleteRear();
    list.displayAll(); // 0, 1, 3, 4

    list.addInOrderAscend(2);
    list.displayAll(); // 0, 1, 2, 3, 4
    list.addInOrderAscend(1);
    list.displayAll(); // 0, 1, 1, 2, 3, 4
    list.deleteFront();
    list.deleteFront(); // 1, 2, 3, 4
    list.displayAll();
    list.addInOrderAscend(10);
    list.addInOrderAscend(12);
    list.displayAll(); // 1, 2, 3, 4, 10, 12
    list.addInOrderAscend(11); 
    list.displayAll(); // 1, 2, 3, 4, 10, 11, 12
    list.addInOrderAscend(0);
    list.addInOrderAscend(0);
    list.displayAll(); // 0, 0, 1, 2, 3, 4, 10, 11, 12
    list.deleteFront(); // should remove one zero
    list.displayAll(); // 0, 1, 2, 3, 4, 10, 11, 12
    list.deleteFront();
    list.displayAll(); // 1, 2, 3, 4, 10, 11, 12

    list.addInOrderAscend(1);
    list.displayAll(); // 1, 1, 2, 3, 4, 10, 11, 12
    list.deleteFront();
    list.displayAll(); // 1, 1, 2, 3, 4, 10, 11, 12
    for(int i = 0; i < 7; i++) list.deleteFront(); // delete all the front nodes
    list.displayAll(); // display empty

    list.addInOrderAscend(2);
    list.addInOrderAscend(2); 
    list.addInOrderAscend(5);
    list.displayAll(); // 2, 2, 5

    std::cout << "\nTesting addInOrderDescend func" << std::endl;
    LL list2;
    list2.addInOrderDescend(2);
    list2.displayAll(); // 2
    list2.addInOrderDescend(5);
    list2.displayAll();
    list2.addInOrderDescend(7);
    list2.displayAll();
    list2.addInOrderDescend(7);
    list2.addInOrderDescend(1);
    list2.addInOrderDescend(3);
    list2.displayAll();
*/

    LL list3, list4;
    srand(time(NULL));
    std::cout << "\nRandom Inputs Test ASCEND" << std::endl;
    for(int i = 0; i < 10; i++) { // generate random numbers
        list3.addInOrderAscend(rand() % 25 + 1);
    }
    list3.displayAll();
    std::cout << "\nRandom Inputs Test DESCEND" << std::endl;
    for(int i = 0; i < 10; i++) {
        list4.addInOrderDescend(rand() % 25 + 1);
    }
    list4.displayAll();
    // test front and rear are pointing at the right nodes by deleting front and rear element
    std::cout << "\nRemoving front and rear elements from ASCEND list" << std::endl;
    list3.deleteFront();
    list3.deleteRear();
    list3.displayAll();

    std::cout << "\nRemoving front and rear elements from DESCEND list" << std::endl;
    list4.deleteFront();
    list4.deleteRear();
    list4.displayAll();
}