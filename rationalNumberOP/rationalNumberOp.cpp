/********************************************
Template created by Kazumi Slott
CS211
Date: Feb 20, 2021
Your name: Neal Archival
Description of your program: This program will
calculate rational numbers as a struct object
The program contains overloaded operators
that will be used for various math operations
********************************************/
#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h

struct rNum // struct we have to overload
{
  int top; //numrator
  int bot; //denominator
};

void simplify(rNum& r); // simplify function from first rationalNumber homework
rNum operator+(const rNum& r1, const rNum& r2); // overloaded opreator to add
ostream& operator<<(ostream& out, const rNum& r); // overloaded operator for printing or out pipe
istream& operator>>(istream& is, rNum& r); // overloaded opreator for taking user input
void operator+=(rNum& r1, const rNum& r2); // overloaded opreator for adding a rationalNumber to itself
bool operator>(const rNum& r1, const rNum& r2); // overloaded opreator to compare if the first rationalNumber is greater than the 
bool operator==(const rNum& r1, const rNum& r2); // overloaded opreator to compare if rationalNumber objects are the same

int main() {
  rNum n1;
  rNum n2;
  rNum ans;

  cout << "\n-------------- 1 -----------------" << endl;
  cout << "Rational Number 1: ";
  cin >> n1;

  cout << "n1 is " << n1 << endl;
 
  cout << "\n-------------- 2 -----------------" << endl;
  cout << "\nRational Number 2: ";
  cin >> n2;
  
  cout << "n2 is " << n2 << endl; 
 
  cout << "\n-------------- 3 -----------------" << endl;
  ans = n1 + n2;
  simplify(ans);
  cout << n1 << " + " << n2 << " = " << ans << endl;

  cout << "\n-------------- 4 -----------------" << endl;
  const int SIZE = 3;
  //Declare an array of rNums that has SIZE slots
  rNum rNumArray[SIZE];
  //fill the array by calling fill() in your array.h
  fill(rNumArray, SIZE);


  cout << "Checking to see if the array is filled" << endl;
  //print the array by calling print() in your array.h
  print(rNumArray, SIZE);

  cout << "\n-------------- 5 -----------------" << endl;
  //sort the array in ascending order by calling sort() in your array.h
  sort(rNumArray, SIZE);

  cout << "Checking to see if the array is sorted in ascending order" << endl;
  //print the array by calling print() in your array.h
  print(rNumArray, SIZE);

  cout << "\n-------------- 6 -----------------" << endl;
  cout << "Checking to see if " << n1 << " is in the array " << endl;
  //Call find() in your array.h to see if n1 exists in the array. Say found or not found. See #6 in the test runs in the hw document.   
  int index = find(rNumArray, SIZE, n1);
  if(index == -1) {
    cout << n1 << " was not found." << endl;
  }
  else {
    cout << n1 << " was found" << endl;
  }
 
  cout << "\n-------------- 7 -----------------" << endl;
  cout << "n1 is " << n1 << " n2 is " << n2 << " before n1 += n2" << endl;
  n1 += n2;
 
  cout << "After n1 += n2, n1 is " << n1 << endl << endl;
  
  return 0;
}

/*************************************************************************
This function will simplify the rational number members (the top and bot)
We will use pass by reference since we are going to return the same object

r is the rational number object, we are using voice and pass by reference
to return the simplified version of the fraction
*************************************************************************/
void simplify(rNum& r) {
  int gcf = 0, numerator, denominator;
  numerator = r.top; // set numerator to top
  denominator = r.bot; // set denominator to bot since we cannot change the object

  while(numerator % denominator != 0) {
    gcf = numerator % denominator; // we can get gcf by getting the remainder of the numbers
    numerator = denominator; // swap the numerator with the denominator
    denominator = gcf; // denominator will be set to the gcf
  } // repeat until the modulo of numerator and denominator is == 0
  if(gcf == 0) { // check if the gcf is equal to zero(the numerator is divisible by the denominator by each other)
    r.top /= r.bot; // divide rational number numerator to the denominator
    r.bot = 1; // since the numerator is divisible by the denominator, bot is equal to 1
  }
  else { // if the gcf is not zero, divide both top and bottom by the gcf
    r.top /= gcf; 
    r.bot /= gcf;
  }
}

/******************************************
Create operator overloading functions down below so the above main runs.
You need to figure out what you need to make.
*******************************************/

/*************************************************************************
This overloads the '+' sign and adds two rational number. It checks for
similar / different denominators and then return the sum
r1 and r2 are both const since we are not changing these values. We are 
returning a rNum object
*************************************************************************/
rNum operator+(const rNum& r1, const rNum& r2) {
  rNum result; // the class object that is going to be returned
  if(r1.bot == r2.bot) {
    result.top = r1.top + r2.top; // add the numerators since the denominators are the same
    result.bot = r2.bot; // it doesn't matter which rNum we use since its the same
  }
  else { // if the denominators are not the same we have to make them the same
    result.top = (r1.top * r2.bot) + (r2.top * r1.bot); // cross multiply
    result.bot = (r1.bot * r2.bot);
  }
  simplify(result); // simplify the result
  return result; // return the result
} 
/*************************************************************************
This function overloads the output operator. It will allow main to print
out rNum top member and rNum bot member in main by doing cout << n1
ostream& out is the ostream "pipe" which can take cout or fout depending
on where we want to print 
const rNum& r is the rNum object with the top and bot members
*************************************************************************/
ostream& operator<<(ostream& out, const rNum& r) {
  out << r.top << "/" << r.bot; // output stream r.top and r.bot with the slash
  return out;
}
/*************************************************************************
This function overloads the input (extractor opreator) that can take user
input. This function will return the istream "pipe" and assign the input
values to the object
istream& is is the istream pipe
rNum& r is the struct object, we are using pass by reference since we want
to make changes to the rational number object
*************************************************************************/
istream& operator>>(istream& is, rNum& r) {
  cout << "\n\tEnter the top number: "; // prompt the user for the numerator
  is >> r.top;
  cout << "\tEnter the bottom number: "; // prompt the user for the denominator
  is >> r.bot;
  return is; // return the input stream pipe
}
/*************************************************************************
The function overloads the += operator. We will make changes to the r1 by
using pass by reference. Void function since we are not returning any values
rNum& r1 is the object that is going to be changed, we use pass by reference
and no const since we are changing r1
rNum& r2 is the object that r1 is going to be added with. Using const since
we are not changing the object
*************************************************************************/
void operator+=(rNum& r1, const rNum& r2) {
  if(r1.bot == r2.bot) {
    r1.top += r2.top; // if the denominators are the same then both numerators can be added
  }
  else { //
    r1.top = (r1.top * r2.bot) + (r2.top * r1.bot);
    r1.bot = (r1.bot * r2.bot);
  }
  simplify(r1);
}
/*************************************************************************
This function will check if r1 is less than r2. If r1 is less than r2 then
the function will return true. If r1 and r2 are equal or if r2 is greater
than r1 the function will return false
const rNum& r1 first object to be compared if less than (not going to change)
const rNum& r2 second object to be compared
will return true or false
*************************************************************************/
bool operator>(const rNum& r1, const rNum& r2) {
  if(r1.bot == r2.bot) { // if both denominators are the same we can compare r1.top and r2.top
    if(r1.top > r2.top) return true;
    return false; // if r2.top is greater than or equal to r1.top then we will return false
  }
  else { // if denominators are not the same we have to make both rational number denominators the same
    int temptop1, temptop2; // create two new variables to hold the temporary numerators
    temptop1 = r1.top * r2.bot; 
    temptop2 = r2.top * r1.bot; // cross multiply tops and bottoms
    if(temptop1 > temptop2) return true; // compare if new rational number is greater, if it is then we return truel
    return false; // if the new rational number top is less than or equal to
  }
}
/*************************************************************************
This operator overloaded function will check if the objects are equal
to each other. If r1 top, bot and r2 top, bot are equal to each other,
then function will return true, otherwise false. This will be used to
overload the find function in array.h
const rNum& r1 is the first first rational number
const rNum& r2 is the second rational number
both are const since we are not making changes
*************************************************************************/
bool operator==(const rNum& r1, const rNum& r2) {
  
  //if(simplify(r1) == simplify(r2)) return true;
  if(r1.top == r2.top && r1.bot == r2.bot) return true; // both rational numbers should share the same numerator and denominator
  return false;
}