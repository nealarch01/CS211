/**************************
Neal Archival
April 7, 2021
add2LargeInt.cpp Homework

This application is going to
take two integers that would
cause an overflow on an 
integer data type and add
them using linked queue
***************************/

#include <iostream> // std::cout std::cin
#include <string> // string input

#include "lqueue.h"

void printAll(LQueue numbers);
char printAllReverse(LQueue &numbers);
void createReverseLL(LQueue &numbers, const std::string &operand1);
void addLLs(LQueue &operand1, LQueue &operand2, LQueue &total);
int convInt(char ch);
char convCh(int num);

int main() {
    std::string operandInputs1, operandInputs2; // the two numbers as strings
    std::cout << "Enter first number: "; 
    std::cin >> operandInputs1; // first number as sstring
    std::cout << "Enter second number: ";
    std::cin >> operandInputs2; // second number as string
    LQueue operandList1, operandList2, total; // instantiate three Linked Queue objects
    // operandList 1 is for operandInputs1
    // operandList2 is for operandInputs2 
    // total is the sum of both operands

    createReverseLL(operandList1, operandInputs1);
    createReverseLL(operandList2, operandInputs2);
    addLLs(operandList1, operandList2, total);
    std::cout << operandInputs1 << " + " << operandInputs2 << " = ";
    total.printAllReverse();
    return 0;
}
/**************************
this function is going
to take 3 list queue objects
and get the sum of the last 
one

operand1 is the left or first
operand entered

operand2 is the right or last
operand entered

total is the sum of both 
operands
***************************/
void addLLs(LQueue &operand1, LQueue &operand2, LQueue &total) {
    int op1, op2, sum, leftover = 0;
    /* use a do loop because we want to traverse the loop at least
    and since leftover is initialized to zero

    The way this algorithm works is we set op1 and op2 (one single digit) equal to 0
    If its coresponding operand is empty, then we will not deleteFront and the digit
    will stay as 0

    Once we attempt to deleteFront we will then sum up the operands including the leftover
    (leftover will == 0 for the first iteration)

    If the sum is greater than 10 then we have excess of 1 which we 

    Loop through while operands are not empty and we have leftovers
    */
    do {
        op1 = 0;
        op2 = 0;
        if(!operand1.isEmpty()) op1 = convInt(operand1.deleteFront()); // if not empty then we can assign op1 by deleting front
        if(!operand2.isEmpty()) op2 = convInt(operand2.deleteFront()); // if not empty then we can assign op2 by deleting front
        sum = op1 + op2 + leftover;
        if(sum < 10) { // if the sum is less than 10 there is no leftover
            total.addRear(convCh(sum)); // convert our sum into a character by calling the convCh function
            leftover = 0; // leftover = 0 because the sum is less than 9
        }
        else {
            total.addRear(convCh(sum - 10));
            leftover = 1; // set to one addition of single digits will only reach 18
        } 
    } while(!operand1.isEmpty() || !operand2.isEmpty() || leftover > 0); // while our
    // operands are not empty or we have a leftover continue running the loop
}
/**************************
This function is going
to convert a character
into an integer by subtract
-ing by '0'

ch is the character to be 
changed
***************************/
int convInt(char ch) {
    return ch - '0';
}
/**************************
This function is going to 
take an int and return it
as a char

int num is the number
***************************/
char convCh(int num) {
    return num + 48;
}

/**************************
This function is going
to read the string in
reverse and push it into 
the Linked Queue
***************************/
void createReverseLL(LQueue &numbers, const std::string &operand) {
    for(int i = operand.length() - 1; i >= 0; i--) numbers.addRear(operand[i]); // add characters starting from the right most to the linked queue
}
