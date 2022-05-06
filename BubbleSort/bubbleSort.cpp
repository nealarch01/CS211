#include <iostream>
#include <cstdlib>
using namespace std;

void bubbleSort(int array[], int SIZE) { // to descending order
    bool isSorted;
    int temp, smallestnum;
    do {
        isSorted = true;
        for (int i = 0; i < SIZE - 1; i++) {
            if (array[i] < array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                isSorted = false;
            }
        }
    } while(isSorted == false);
}

int main() {
    const int SIZE1 = 10;
    int somearray[SIZE1] = {42, 12, 82, 100, 16, 14, 10, 4, 22, 20};
    bubbleSort(somearray, SIZE1);
    for (int i = 0; i < SIZE1; i++) cout << somearray[i] << " ";


}