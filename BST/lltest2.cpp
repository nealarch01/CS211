#include <iostream>
#include <cstdlib> // rand()
#include "LL_T.h"

int main() {
    LL<int> list3, list4;
    srand(time(NULL));
    std::cout << "\nRandom Inputs Test ASCEND" << std::endl;
    int randint;
    for(int i = 0; i < 10; i++) { // generate random numbers
        randint = rand() % 25 + 1;
        list3.addInOrderAscend(randint);
        std::cout << randint << " ";
    }
    std::cout << std::endl; 
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