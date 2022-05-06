/***************************************************************************
CS211
Template prepared by Kazumi Slott 
Your name: Neal Archival

Program description: this program is going to take a decimal input from
1 to 999,999 from the user and convert it into binary (base 2), octet(base 8)
and hexadecimal (base 16) using two functions. The first function is going to
convert the decimal to base using recursion and the second will convert using
stack class data type
***************************************************************************/
#include <iostream>
using namespace std;
#include "stack.h"
#include "checkInput.h"


int getBase();
char convertToChar(int n);
void convertRec(int n, int b);
void convertStack(int n, int b);


int main() {
  int dec;
  int base;

  cout << "Enter a number in base 10: ";
  //get a decimal number by calling getData in checkInput.h. Accept a numer 
  //between 1 and 999999.
  dec = getData(1, 999999, "Enter a number between 1 and 999999. Enter again: ");

  //get a base (2, 8 or 16) by calling getBase
  base = getBase();

  cout << "----------- Using recursion ---------------" << endl;
  //call convertRec to show the number in the base number system of the user’s choice
  convertRec(dec, base);

  cout << endl;

  cout << "----------- Using a stack ---------------" << endl;
  convertStack(dec, base);


  cout << endl;
  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted, either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase() {
  int input; // create integer 
  cout << "Enter a base to convert the base 10 to number to: ";
  cin >> input;
  while(input != 2 && input != 8 && input != 16) {
    cin.clear();
    cin.ignore(); // used to avoid infinite loop (clears the input stream then ignores)
    cout << "Invalid Base. Enter 2,8,16 base: ";
    cin >> input;
  }
  return input;
}

/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'

n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n) {
  char ch; // get the character 
  if(n < 10) { // if the decimal is less than 10 then we return the same number but as a character data type
    return ch = 48 + n; // 48 is the ascii value of 0 we will add the decimal to the character ascii code to get the desired number
  }
  // this will only run if the decimal is greater than 9
  return ch = 55 + n; // 55 is the ascii value of 7 but if we add the decimal we will return an character with an ascii value
  // for ex. if n == 10 then ch = 65, 65 is 10 on the ascii table
}

/***************************************************************************
This is a <<recursive>> function to convert a decimal number to a different number system and print it.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b) {
  if(n == 0) {
    return; // return before we hit switch statement
  }
  switch(b) { // n will change depending on the base type, using a switch statement
    case(2):
      convertRec(n / 2, b); // call the function dividing decimal by half
      cout << n % 2; // print the number to the console, this will return as either 0 or 1 since this is binary
      break;    
    case(8):
      convertRec(n / 8, b); // same approach but divide by 8 since we are converting to octet
      cout << n % 8; // print out the octate value by finding the remainder
      break;
    case(16):
      convertRec(n / 16, b); // same approach but divide by 16 since we are converting to hexadecimal
      cout << convertToChar(n % 16); // we call this function since hexadecimal prints out 
      break;
  }
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number system and prints it.
This is not a recursive function.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b) {
  Stack s; // instantiate our stack object
  while(n > 0) { // while the decimal is greater than zero we enter the switch statement and push back the value
    switch(b) {
      case(2): // if the base is 2 then we push the first modulo into the stack
        s.push(n % 2);
        n /= 2; // divide the decimal by and continue until the decimal is zero
        break;
      case(8): // same approach but instead of two we push the remainder of n / 8 and divide derement by dividing by 8
        s.push(n % 8);
        n /= 8;
        break;
      case(16): // same approac
        s.push(n % 16);
        n /= 16;
        break;
    }
  }
  if(b == 16) { // if the base is == 16 then we have to convert the decimal into a character
    while(!s.isEmpty()) { // while the stack is not empty then we will pop the top
      cout << convertToChar(s.pop()); // convert the decimal into a character and then display the top element
    }
  }
  else { // if it is not 16 then we don't have to convert
    while(!s.isEmpty()) { // while the stack is not empty we will pop the top element and display it
      cout << s.pop();
    }
  }

}