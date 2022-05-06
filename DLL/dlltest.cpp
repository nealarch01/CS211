#include <iostream>
#include <cstdlib>
#include "DLL.h"
int main() {
    srand(time(NULL));
    DLL list;
    for(int i = 0; i < 8; i++) {
        list.addInOrderDescend(rand() % 25 + 1);
    }
    list.displayAll();
}