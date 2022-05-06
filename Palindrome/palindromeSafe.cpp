#include <iostream>
#include <string>

#include "LL.h"

void createLL(LL &list, std::string message);
bool isLetter(char ch);
char myToLower(char ch);
bool palindrome(LL &list1, std::string message);

int main() {
    std::string message;
    bool isPalindrome;
    std::cout << "Enter a message: ";
    getline(std::cin, message);
    LL inputList;
    createLL(inputList, message);
    isPalindrome = palindrome(inputList, message);
    std::cout << "\"" << message << "\"";
    if(isPalindrome) std::cout << " is a palindrome" << std::endl;
    else std::cout << " is not a palindrome" << std::endl;
    return 0;
}

void createLL(LL &list, std::string message) {
    for(std::string::size_type i = 0; i < message.length(); i++) {
        if(isLetter(message[i])) 
            list.addFront(myToLower(message[i]));  // add into linkedlist and convert uppercase characters into lowercase
    }
}

bool isLetter(char ch) {
    if(ch >= 65 && ch <= 90) return true;
    else if(ch >= 97 && ch <= 122) return true;
    return false;
}

char myToLower(char ch) {
    if(ch >= 65 && ch <= 90) ch += 32;
    return ch;
}

bool palindrome(LL &list1, std::string message) {
    for(std::string::size_type i = 0; i < message.length(); i++) {
        if(isLetter(message[i])) {
            if(list1.deleteFront() == myToLower(message[i]));
            else return false;
        }
    }
    return true; // if we get to the end of the function with no returns
}