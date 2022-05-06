#include <iostream>
#include <string>

int main() {
    int n = 1;
    int *p1;
    p1 = &n;
    *p1 = 2;
    std::cout << "n = " << n << std::endl;
    std::cout << "*p1 = " << p1 << std::endl;

    std::string *strptr;
    strptr = new std::string;
    *strptr =  "Hello ";
    
    std::string *strptr2;
    strptr2 = new std::string;
    *strptr2 = "World";

    *strptr += *strptr2;
    std::cout << *strptr << std::endl;
    std::cout << strptr << std::endl;

    
    return 0;
}