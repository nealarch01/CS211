#include <iostream>
using namespace std;

bool isEven(const int);

int main() {
    int someArray[5] = {12, 27, 24, 45, 50};
    // cout << isEven(someArray[0]) << endl;
    if (isEven(someArray[1]) == 0) {
        cout << "The number is odd" << endl;
    }
    else {
        cout << "The number is even" << endl;
    }
    return 0;
}

bool isEven(const int n1) {
    return n1 % 2 == 0; return true;
}