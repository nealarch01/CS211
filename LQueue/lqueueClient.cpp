#include <iostream>

#include "lqueue.h"
using namespace std;

int main() {
    LQueue lq;
    el_t temp;
    if (lq.isEmpty()) cout << "Queue is empty" << endl;
    else cout << "Queue is not empty" << endl;

    lq.displayAll();
    lq.addRear(1);
    lq.displayAll();

    for (int i = 2; i < 5; i++) lq.addRear(i);

    lq.displayAll();

    for (int i = 0; i < 3; i++) {
        temp = lq.deleteFront();
        std::cout << "Removed " << temp << endl;
    }
	
	lq.displayAll();
	if (lq.isEmpty()) cout << "Queue is empty" << endl;
    else cout << "Queue is Not Empty" << endl;

	temp = lq.deleteFront();
	cout << "Removed " << temp << endl;

	if (lq.isEmpty()) cout << "Queue is empty" << endl;
    else cout << "Queue is Not Empty" << endl;

	lq.displayAll();
	return 0;
}
