/**********************************************
Neal Archival
CS 211
1/28/2021
Homework 1 
This program will take two sets of rational
fractions add the two and then simplify to the
smallest fraction
***********************************************/
#include <iostream>
#include <iomanip>
using namespace std;

struct Fraction {
    int numerator, denominator; // numerators and denominators
};

void getRatNum(Fraction& f);
void simplify(Fraction& f); 
Fraction add2RatNum(const Fraction& f1, const Fraction& f2); 
void print(const Fraction& f1, const Fraction& f2, const Fraction& f3); 


int main() {
    Fraction f1, f2, f3; // create the struct objects, f1 is the first rational number / fraction, f2 is second, f3 is going to be the result of f1 + f2
    cout << "Rational Number 1: " << endl; // prompt user for the first rational number
    getRatNum(f1); // get user input
    cout << "Rational Number 2: " << endl;
    getRatNum(f2); 
    f3 = add2RatNum(f1, f2); // f3 will equal to the sum of f1 and f2

    print(f1, f2, f3);

    return 0;
}

/**********************************************************
This function takes a Fraction object pass by reference 
since we want to assign then save user input data from cin.
f - Fraction object
***********************************************************/
void getRatNum(Fraction& f) {
    // prompt and have user enter numerator then denominator
    cout << "\tEnter numerator: "; 
    cin >> f.numerator;
    cout << "\tEnter denominator: ";
    cin >> f.denominator;
    // no return since void and pass by reference
}
/************************************************************************************************
This function simplifies the Fraction object by finding the GCF of the numerator and denominator
The algorithm is explained below before the while loop
It takes struct object parameter, pass by reference since we want to change the 
Fraciton members' data
f - Fraction object
***********************************************************************************************/
void simplify(Fraction& f) {
    int gcf = 0, top, bot; // gcf will be 0 by defaultt the reason behind this is if the loop evaluates top % bot == 0, the loop will not run therefore we are left with 0 which means f.num can be / by f.dem
    // top and bot are guides to the numerator and denominator to keep f.numerator and f.denominator data saved
    top = f.numerator; // top will refer to the numerator
    bot = f.denominator; // bot will refer to the denominator

    /**************************************************************************************************************************************************************************
    This loop works by first checking if the modulo of the numerator and denominator is != 0
    if it evalutes true, the loop will run / continue and swap out the top variable (numerator) to the bot variable (denominator) and the bot (denominator) to the gcf
    this will continue until the modulo is == 0

    For example: test case 35 / 13 should return 35 / 13
    35 % 13 evals as = 9
    gcf = 9
    then 13 % 9 = 4
    gcf = 4
    then 9 % 4 = 1
    gcf = 1
    then 4 % 1 = 0 breaks the loop and leaves us with gcf = 1
    the following conditional statements will divide f.num and f.dem by the gcf (in this case gcf = 1) which keeps the same value
    **********************************************************************************************************************************************************************/
    while(top % bot != 0) { // if modulo is zero, the loop will not run / break this loop will continue checking for gcf, once it reaches zero, the gcf will return with the gcf
        gcf = top % bot; // gcf will be acquired from the modulo of the numerator and denominator
        top = bot; // set top (numerator) = to the bot (the denominator)
        bot = gcf; // set bottom (denominator) == to gcf
    }

    if (gcf == 0) { // if the gcf evaluates to zero (it did not go through the loop, therefore numerator mod denominator = 0)
        // numerator can be divided by denominator, then denominator will cancel and become = 1
        f.numerator /= f.denominator;
        f.denominator = 1; 
    }
    else { // if the gcf was found (gcf went through the loop)
        // both numerator and denominator will be divided by the GCF which will return the simplified fraction
        f.numerator /= gcf; 
        f.denominator /= gcf;
    }
}
/*******************************************************************
 f1 - first rational number 
 f2 - second ratioal number
 This function adds 2 rational numbers.
 It uses a Fraction data type to return a struct object
 The 2 Fraction objects are const because we will not change
 its value, however, we use it to find the result
 *******************************************************************/
Fraction add2RatNum(const Fraction& f1, const Fraction& f2) { // returns Fraction object
    Fraction f_res; // f_res is fraction result (the result of the addition of f1 and f2)
    if (f1.denominator == f2.denominator) { // check if both fraction denominators. If true, both numerators can be added
        f_res.numerator = f1.numerator + f2.numerator;
        f_res.denominator = f1.denominator; // the denominator will equal to f1 denominator since it is the same to f2
    }
    else { // if the denominators are different
        f_res.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator); // numerator will be found by multiplying the opposite fraction's denominator
        f_res.denominator = (f1.denominator * f2.denominator); // the numerator would be found by multiplying both denominators together
    }
    simplify(f_res);
    return f_res; // returns the simplified result
}
/************************************************************************
 f1 - first rational number input
 f2 - second rational number input
 f3 - the simplified sum of f1 and f2
 This function prints out the fraction. There is a conditional statement
 that checks for the denominator == 1 so that only the numerator will be 
 printed out.
 Using const since we are only printing and pass by reference so we don't
 have to create a new memory block for the struct
 *************************************************************************/
void print(const Fraction& f1, const Fraction& f2, const Fraction& f3) {
    cout << right << setw(4) << f1.numerator << right << setw(7) << f2.numerator; // this line will be constant
    if (f3.denominator == 1) { // if the denominator is == 1 then these lines will be printed
        cout << endl << "----" << right << setw(3) << " + " << right << setw(3) << "----" << right << setw(3) << " = " << right << setw(2) << f3.numerator << endl; // numerator is printed in the middle line without a line or denomiantor (2nd / mid line)
        cout << right << setw(4) << f1.denominator << right << setw(7) << f2.denominator << endl; // prints the first and second fraction denominators (third line)
    }
    else { // if not then...
        cout << right << setw(7) << f3.numerator << endl; // f3 numerator will be printed on top line
        cout << "----" << right << setw(3) << " + " << right << setw(3) << "----" << right << setw(3) << " = " << right << setw(3) << "----" << endl; // second line will have a third "----"
        cout << right << setw(4) << f1.denominator << right << setw(7) << f2.denominator << right << setw(7) << f3.denominator << endl; // prints the first and second fraction denominators
    }
}