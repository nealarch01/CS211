#include <iostream>
#include <time.h>

int fib1(int pos);
int fib2(int pos);

int main() {
    std::cout << "Enter number: ";
    int pos;
    std::cin >> pos;
    if(pos >= 47) {
        std::cout << "Stack overflow" << std::endl;
        return 1;
    }
    else if(pos <= -1) {
        std::cout << "Cannot be negative number" << std::endl;
        return 1;
    }
    int fibNum;
    clock_t start, end;
    start = std::clock();
    fibNum = fib1(pos);
    end = std::clock();
    std::cout << "Recursive Function Elapsed Time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << std::endl;
    std::cout << pos << " = " << fibNum << std::endl;

    start = std::clock();
    fibNum = fib2(pos);
    end = std::clock();
    std::cout << "Loop Function Elapsed Time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << std::endl;
    std::cout << pos << " = " << fibNum << std::endl;
    
    return 0;
}

int fib1(int pos) {
    if(pos <= 1) return pos;
    return fib1(pos - 2) + fib1(pos - 1);
}

int fib2(int pos) {
    int n1 = 0, n2 = 1, n3;
    for(int i = pos; i > 0; i--) {
        n3 = n1 + n2;
        n2 = n1;    
        n1 = n3;
    }
    return n3;
}