#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <string>

bool isLetter(char ch);
bool isDigit(char ch);
char myToLower(char ch);
char myToUpper(char ch);

/*****************************************************************
Returns true if character is lowercase / uppercase letter
*****************************************************************/
bool isLetter(char ch) {
	if(ch >= 65 && ch <= 90) return true; // if capital letter
	else if(ch >= 97 && ch <= 122) return true; // if lower case letter
	return false;
}

/*****************************************************************
Returns true if character is a digit character
*****************************************************************/
bool isDigit(char ch) {
	if(ch >= 48 && ch <= 57) return true; // check if equal to or between ascii values
	return false;
}

/*****************************************************************
Returns uppercase character if character is lowercase
char ch character to be checked
*****************************************************************/
char myToLower(char ch) {
	if(ch >= 65 && ch <= 90) return ch + 32; // if uppercase add 32 to convert to lo
	return ch; // if not uppercase letter return the character
}

/*****************************************************************
Returns lowercase character if character is upper case
char ch character to be checked
*****************************************************************/
char myToUpper(char ch) {
	if(ch >= 97 && ch <= 122) return ch - 32; // if lower case then we subtract 32 on the ascii
	return ch; // if not lower case return the character
}

/*******************************************
Take a word string and remove delimiters
and convert uppercase letters into lower case
********************************************/
std::string stringStr(std::string wd) {
    std::string w = ""; // initialize empty
    for(std::string::size_type i = 0; i < wd.length(); i++) {
        if(isLetter(wd[i])) {
            w += myToLower(wd[i]);
        }
    }
    return w;
}

#endif
