/*****************************************************************
Neal Archival
April 12, 2021
Prof Slott
palindrome.cpp

This program is going to read message from file or user input as 
string input and check if the message is a palindrome 
*****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

#include "myStrCharFunc.h"
#include "../BST/LL_T.h"

void createLL(LL<char> &list, std::string message);
bool palindrome(LL<char> &list1, std::string message);

int main() {
    std::string message;
    std::string palindromeFilename = "palindrome.dat";
    bool isPalindrome;
    std::ifstream palindromeFile;
    palindromeFile.open(palindromeFilename.c_str());
    if(!palindromeFile.is_open()) {
        std::cout << palindromeFilename << " not opened" << std::endl;
        return 1; // exit with code1 error
    }
    LL<char> inputList;
    while(!palindromeFile.eof()) {    
        getline(palindromeFile, message);
        createLL(inputList, message);
        isPalindrome = palindrome(inputList, message);
        std::cout << "\"" << message << "\"";
        if(isPalindrome) std::cout << " is a palindrome" << std::endl;
        else std::cout << " is NOT a palindrome" << std::endl;
    }
    return 0;
}

/*****************************************************************
This function is going to add the characters of the string into
LinkedList in reverse. It will ad using addFront function to add
the string in reverse

pass by reference since we want to make changes to our linkedlist
object
LL &list is our list
std::string message is the message is the sentence or 
word from user input or file data
*****************************************************************/
void createLL(LL<char> &list, std::string message) {
    for(std::string::size_type i = 0; i < message.length(); i++) {
        if(isLetter(message[i])) 
            list.addFront(myToLower(message[i]));  // add into linkedlist and convert uppercase characters into lowercase
    }
}

/*****************************************************************
Bool function will return true if the message is a palidrome
return false not
LL &list is the list characters from the message
std::string message is the message from userinput or file
*****************************************************************/
bool palindrome(LL<char> &list1, std::string message) {
    // Create for loop to iterate through the string
    // We can traverse the string without worrying about the queue underflow because the string and the linkedlist have the same number of characters
    for(std::string::size_type i = 0; i < message.length(); i++) { 
        if(isLetter(message[i])) { // check if the character is a letter
            // if character is letter delete front of the linked list and compare with the 
            if(list1.deleteFront() != myToLower(message[i])) { // if the character is not the same, it is not a palindrome
                while(!list1.isEmpty()) list1.deleteFront(); // traverse list and clear the linked list before leaving this function
                return false;
            }
        }
    }
    return true; // if all characters are the same
}