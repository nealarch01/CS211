/***********************************************************
Neal Archival
CS 211
Feb 28, 2021
Postfix.cpp homework

This program will evaluate expressions entered in postfix
form using the stack data structure
***********************************************************/
#include <iostream>
#include "stack.h"
using namespace std;

bool isOperand(char ch);
int charToInt(char ch);
bool isOperator(char ch);
int doMath(int operand1, char sign, int operand2);
// two additional functions to check if stacks can be added or popped and will return error messages
bool canAddToStack(const Stack& s); 
bool canPopFromStack(const Stack& s);

int main() {
    Stack s; // instantiate stack object
    bool isValid = true; // set isValid to true by default so we can run the loop 
    string expr; // userinput string 
    //prompt and take user input into string
    cout << "Enter expression: ";
    cin >> expr; 

    int counter = 0; // counter to keep track of the string index
    int operand1; // first operand or digit (x)
    int operand2; // second operand or digit (y)
    int result; // the result of the first and second operands (x (add/sub/mult/div) y)
    /*
    This loop is going to scan expr string and check if the input is an operator or operand
    If it is an operand, expr[counter] is going to be converted into an integer and then
    pushed into the stack. If it is an operator, the top two operands are going to be popped
    and then be passed into doMath if the operator is valid. 
    The loop will continue running while the counter is less than expr.length() or the length of the string and
    isValid needs to be set to true (valid string)
    */
    do {
        if(isOperand(expr[counter]) == true) { // check if the character is a number
            if(canAddToStack(s) == true) { // nested conditional statement to check if the number can be pushed into the stack
                s.push(charToInt(expr[counter])); // convert the character into an integer and push into the stack
            }
            else { // there is no space int the stack then we set isValid to false to break the loop
                isValid = false;
            }
        }
        else if(isOperator(expr[counter]) == true) { // check if the character is an operator (+, -, *, /)
            isValid = canPopFromStack(s); // check if the stack can be popped by checking if it is not empty
            // the purpose of this is to determine whether the following instructions should be called and to terminate the loop if there is an error
            if(isValid == true) { // if not empty (true) we will pop the top element (right hand side operand)
                operand2 = s.pop(); 
                isValid = canPopFromStack(s); // call func to check if another number exists below the popped element
                if(isValid == true) { // check if the expression is still valid after popping
                // if isValid is true then we can call doMath function and combine the two numbers obtained from popping the stack
                // if not valid (stack is empty) then an error message will be returned
                    operand1 = s.pop();
                    result = doMath(operand1, expr[counter], operand2); 
                    // no need to check if the stack is empty because we combine the two popped elements and turned it into one
                    s.push(result); // push the result into the stack
                }
            }
        }
        else { // if the user input does not contain either an operand or operator it is an invalid token
            cout << "Error: Invalid item was found (" << expr[counter] << ")" << endl; 
            isValid = false; // set isValid to false to break out the loop
        }
        counter++; // increment the counter
    } while(isValid == true && counter < expr.length()); // while the stack and character is valid (represented with isValid) and the counter is less than the string size
    if(isValid == true) { // check if the string / expression is valid
        result = s.pop(); // pop the top element since we are outside the loop. No need to check if the stack is empty because the else if portion of the do-while loop will terminate the loop because the stack is empty since there are not enough operands
        if(s.isEmpty() == false) { // if the stack is not empty then we have too many operands left in the stack
            cout << "Error: Too many operands" << endl; // prompt error message to the user
        }
        else { // if the stack is empty then we can display the result
            cout << "= " << result << endl;
        }
    }
    return 0; // end of program
}

/***********************************************************
This function is will check if there is space in the stack 
to be pushed. Will return true if there is space and false
if not. This function will also display an expression
error
Stack& s pass the stack object using pass by reference to
not create the object another time. Const since we are
not making any changes to the stack object
***********************************************************/
bool canAddToStack(const Stack& s) {
    if(s.isFull() == true) { // check if the stack is full
        cout << "Error: Expression is too long" << endl; // return this error message to the user if the expression entered is too long
        return false; // return false since we cannot add to the stack
    }
    return true; // return true if the stack can be added
}

/***********************************************************
This function will check if the top element can be popped 
from the stack from the client and display an error message
const Stack& s is the stack object in main
const since we are not changing the object and pass by 
reference so we don't have to create another object
***********************************************************/
bool canPopFromStack(const Stack& s) {
    if(s.isEmpty() == true) {
        cout << "Error: Not enough operands" << endl;
        return false;
    }
    return true;
}
/***********************************************************
This function will check if the character is an operand or
integer. If it is an integer, we will return true
char ch is the expr[index] from main
***********************************************************/
bool isOperand(char ch) {
    if(ch >= '0' && ch <= '9') { // if the character is in between 0 and 9 will return true (this includes 0 and 9) 
        return true;
    }
    return false;
}

int charToInt(char ch) {
    int result = ch - '0';
    return result;
}
/***********************************************************
This function will check if the character is an operator
(plus, minus, multiply, divide) and will return true if ch
is an operator and false if it's not
char ch is the expr[index] from main
***********************************************************/
bool isOperator(char ch) {
    switch(ch) { // switch statement to save time from typing multiple if statements
        case('+'):
        case('-'):
        case('*'):
        case('/'):
            return true;
            break;
        default: // if the character is not an operand or operator then it is invalid
        return false; 
        break;
    }
}
/***********************************************************
This function will add the operands and the operators
int operand1 is the second pop operand (x)
char opt is the operator (+, -, *, /)
int operand2 is the first pop operand (y)
***********************************************************/
int doMath(const int operand1, char sign, const int operand2) {
    int result; // create integer variable that will hold the result of the two operations
    switch(sign) {
        case('+'):
            result = operand1 + operand2;
            break;
        case('-'):
            result = operand1 - operand2;
            break;
        case('*'):
            result = operand1 * operand2;
            break;
        case('/'):
            result = operand1 / operand2;
            break;
    }
    // no need for default since the loop will terminate if an invalid operator is found and this function would not be called
    return result;
}