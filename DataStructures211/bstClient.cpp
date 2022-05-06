#include <iostream>
#include <cstdlib>
#include <chrono>
#include "bst.h"
void generateRand(BST &b1) {
	srand(time(NULL));
	int numNodes, min, max;
	std::cout << "Enter number of nodes to be generated: ";
	std::cin >> numNodes;
	std::cout << "Enter max number: ";
	std::cin >> max;
	std::cout << "Enter min number: ";
	std::cin >> min;
	for(int i = 0; i < numNodes; i++) {
		b1.insertNode(rand() % max + min);
	}
}

void compareFunc(const BST &bst, int input) {
	
}

int main() {
	srand(time(NULL));
	BST b1;
	generateRand(b1);
	b1.printInOrder();
	int n;
	double duration;
	std::cout << "Find iterative: ";
	std::cin >> n;
	std::cout << n << " was ";
	auto start = std::chrono::steady_clock::now();
	b1.findIterative(n) ? std::cout << "found" : std::cout << "not found";
	std::cout << std::endl;	
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> timetaken_chrono = end - start;
	duration = timetaken_chrono.count();
	std::cout << "Time taken: " << duration << "s" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Find recursive: ";
	std::cin >> n;
	std::cout << n << " was ";
	start = std::chrono::steady_clock::now();
	b1.findRecursive(n) ? std::cout << "was found" : std::cout << "was not found";
	std::cout << std::endl;
	end = std::chrono::steady_clock::now();
	timetaken_chrono = end - start;
	duration = timetaken_chrono.count();
	std::cout << "Time taken: " << duration << "s" << std::endl;	
	return 0;
}
