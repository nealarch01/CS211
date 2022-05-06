#include <iostream>
using namespace std;

int main() {
    int *p1, *p2;
    p1 = new int;
    *p1 = 1;
    cout << *p1 << endl;
    p2 = p1;

    p2 = new int;
    *p2 = 2;
    cout << *p2 << endl;

    delete p2;
    p2 = p1;

    cout << *p2 << endl;
    delete p2;
    p1 = NULL;

    p2 = new int;
    *p2 = 3;
    cout << *p2 << endl;
    delete p2;
    return 0;
}