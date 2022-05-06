#include <iostream>
#include "LL_T_E.h"

int main() {
	LL<int> l1;
	const char *errorMessage = "Error: Underflow";
	l1.displayAll();
	std::cout << "Trying deleteFront();" << std::endl;
	try {
		l1.deleteFront();
		std::cout << "No exception caught. Adding 2, 4, 6" << std::endl; // this should not print
		l1.addRear(2);
		l1.addRear(4);
		l1.addRear(6);
	} catch (LL<int>::Underflow) {
		std::cout << errorMessage << std::endl; 
	}
	std::cout << "---- Adding 2, 3, 4 ----" << std::endl;
	l1.addRear(2);
	l1.addRear(3);
	l1.addRear(4);
	l1.displayAll(); // display 2, 3, 4
	try {
		std::cout << "---- Deleting 3 times ----" << std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout << "Deleted " << l1.deleteRear() << std::endl;
		}
		// isEmpty should print empty
		l1.displayAll();
		std::cout << l1.deleteRear() << std::endl; // try to delete when empty
		std::cout << "No exceptions caught" << std::endl; // this should not print
	} catch (LL<int>::Underflow) {
		std::cout << errorMessage << std::endl;
	}
	l1.displayAll(); // should print empty
	std::cout << "---- Adding 8 ----" << std::endl;
	l1.addFront(8);
	l1.displayAll(); // 8
	std::cout << "Deleted: " << l1.deleteRear() << std::endl;
	l1.displayAll();
	try {
		std::cout << "Trying delete rear" << std::endl;
		l1.deleteRear();	
	} catch (LL<int>::Underflow) {
		std::cout << errorMessage << std::endl;
	}
	std::cout << "---- Deleting without catch ----" << std::endl;
	l1.deleteRear();
	return 0;
}
