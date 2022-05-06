#include <iostream>
#include "myVector.h"

void print(const MyVector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
}

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.insert(1, 15);
    print(vec);
    std::cout << std::endl;
    return 0;
}