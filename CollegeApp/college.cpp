/*********************************************************
CS211
Date: March 10, 2021
Your name: Neal Archival

This program will add/remove/edut students in an array of
student objects. Phase 1 does not have any inputs

to compile: price.cpp student.cpp college.cpp
************************************************************/
#include <iostream>
#include <cstdlib>  //for atoi() <-- you might not use this
#include <fstream>
using namespace std;
#include "array.h"
#include "checkInput.h"
#include "price.h"
#include "student.h"

const int SIZE = 100;      // size of the array
const int START = 100000;  // student id starts at 100000
const int PASSWORD = 123;  // password for admission's office
const int PRIME1 = 31;     // used to calculate a student's password
const int PRIME2 = 5;

int showMenu();
int showAdmMenu();
int showStuMenu();

void addStu(Student students[], int& count, int& curID);
void showStuInfo(const Student& s);
void allStuInfo(const Student s[], const int count);
void removeStu(Student s[], int& count);
void addStuFromFile(Student students[], int& count, int& stuID);
bool operator==(const Student& s, int ID);

void addCourse(Student& student);
void dropCourse(Student& student);
void makePayment(Student& student);

bool checkPassword(const Student &stu, int correctPassword);
int findStu(const Student students[], int count);
int verifyStu(const Student students[], int count);

int main() {
    Student students[SIZE];
    int count = 0;      // the number of students in the array
    int curID = START;  // curID is the student id used for the next student you
                        // are creating
    int mainOption, studentOption,
        adminOption;  // these variables are for the next phases of the program
    int searchRet;
    string firstName, lastName;
    char gender;
    do {
      switch(showMenu()) {
        case(1):
          cout << "Enter admissions office password: ";
          cin >> adminOption;
          if(adminOption == PASSWORD) {
            do {
              adminOption = showAdmMenu();
              switch(adminOption) {
                case(1):
                  addStu(students, count, curID);
                  break;
                case(2):
                  addStuFromFile(students, count, curID);
                  break;
                case(3):
                  removeStu(students, count);
                  break;
                case(4):
                  searchRet = findStu(students, count);
                  if(searchRet >= 0) showStuInfo(students[searchRet]);
                  else cout << "Student id not found" << endl; // findStu return -1 print message
                  break;
                case(5):
                  allStuInfo(students, count);
                  break;
                case(6):
                  break;
              } // end of admin menu switch
            } while(adminOption != 6);
          } else std::cout << "Wrong password" << std::endl;
          break;
        case(2):
          searchRet = findStu(students, count);
          if(searchRet >= 0) {
            if(checkPassword(students[searchRet], students[searchRet].getStuID() % (PRIME1 * PRIME2))) {
              do {
                studentOption = showStuMenu();
                switch(studentOption) {
                  case(1):
                    addCourse(students[searchRet]);
                    break;
                  case(2):
                    dropCourse(students[searchRet]);
                    break;
                  case(3):
                    makePayment(students[searchRet]);
                    break;
                  case(4):
                    showStuInfo(students[searchRet]);
                    break;
                  case(5):
                    break;
                }
              } while(studentOption != 5);
            }
          } else { //  findStu return -1
            cout << "Student id not found" << endl;
          }
          break;
        case(3):
          return 0;
      }
    } while(1);
    return 0;
}
/********************************************************************
This function is going to add one student into the array of students
by asking the user to enter user input
Student students[] is the array (not pass by reference since arrays
are by default)
int& count is the number of members that is going to be incremented
when added
int& curID since we want to change the ID outside this function as well
when we add a new member
*********************************************************************/
void addStu(Student students[], int& count, int& curID) {
    string firstName;
    string lastName;
    char gender;  // create new variables to store the userinput
    cout << "Enter student first name: ";
    cin >> firstName;
    cout << "Enter student last name: ";
    cin >> lastName;
    cout << "Enter student gender: ";
    cin >> gender;
    Student s(firstName, lastName, gender,
              curID++);     // pass the userinput variables into the newly
                            // instantited object and increment the studentID
    students[count++] = s;  // push new object into the array and then increment
                            // the number of students
    cout << endl;
}

/********************************************************************
This function is going to show one student. It will take an object
and display the output
const Student& s const since we are not making any changes to the
object
*********************************************************************/
void showStuInfo(const Student& s) {
    // prompt and get information of the new student to be displayed
    cout << "--------------------" << endl;
    cout << "first name: " << s.getFirstName() << endl;
    cout << "last name: " << s.getLastName() << endl;
    cout << "gender: " << s.getGender() << endl;
    cout << "stu id: " << s.getStuID() << endl;
    cout << "num classes: " << s.getNumClasses() << endl;
    cout << "Courses: ";
    for (int i = 0; i < s.getNumClasses(); i++)
        cout << s.getClassOf(i)
             << ", ";  // Don't use showAllCourses() but show each course at a
                       // time. Which memeber function shows one course?
    cout << "\nAmount owed $" << s.getBalance()
         << endl;  // You have an operator overloading function to show a price
                   // object at once
    cout << endl;
}

/********************************************************************
This function is going to display all Student information using a for
loop to call the function showStuInfo function which will display
information.
const Student s[] passing the entire array so we can traverse the
entire array of Student objects
const int count is the number of members, this will be used to traverse
the number of members in the array of objects
*********************************************************************/
void allStuInfo(
    const Student s[],
    const int count) {  // no need to specify pass by reference because array
                        // parameter is already pass by reference by default
    for (int i = 0; i < count; i++)
        showStuInfo(s[i]);  // for loop while i is less than the number of
                            // students we will call the showStuInfo
}

/********************************************************************
This function is going to remove a student object from the array
by swapping. It will also decrement
Student s[] pass the entire array so we can change the students
int& count is the number of students in the array. We are using
pass by reference so we can decremenet the number of students
when removing an object
*********************************************************************/
void removeStu(Student s[], int& count) {
    int studentID;  // create a variable to ask user input
    cout << "Enter the student ID: ";
    cin >> studentID;
    int index = find(
        s, count,
        studentID);  // check if the studentID is inside the array of students
    if (index == -1) {  // check if the index is not found then the inputted id
                        // does not exist
        cout << "Student with ID " << studentID << " does not exist." << endl;
        return;  // return back to main after displaying the error message
    }
    cout << s[index].getFirstName() << " " << s[index].getLastName()
         << " has been removed" << endl;
    remove(s, count, studentID);  // call the remove function from array.h and
                                  // decrement the count
    count--;
}

/********************************************************************
This function is going to add a student from an external file
Student students[] is the array of objects
int& count is the number of students in the array, pass by reference
since we want to change the number of members in the main
int& studentID is teh student id that is going to be assigned to the
student pass by reference since we want the changes to carry over
to the main function
*********************************************************************/
void addStuFromFile(Student students[], int& count, int& stuID) {
    ifstream fin;  // create ifstream object
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;
    fin.open(filename.c_str());  // open the "college.dat" file which contains
                                 // the student information
    if(!fin.is_open()) {
      cout << filename << " does not exist." << endl;
      return;
    }
    string firstName, lastName;
    char gender;
    while (!fin.eof()) {  // while we have not reached the end of the file fin
                          // userinput
        fin >> firstName;
        fin >> lastName;
        fin >> gender;
        fin.ignore(250, '\n');  // skip to the next line
        Student s(firstName, lastName, gender,
                  stuID++);   // pass the collected information into the
                              // parameterized constructor
        students[count] = s;  // add it into the array and increment the number
                              // of students in the array
        count++;
    }
    fin.close();
}

/********************************************************************
Overloaded operator function that is going to be used for the find
function in array.h and see if the ID is equal to the student object's
associated ID
const Student& s, student object that contains the student's id
int ID is the ID that is going to be compared
*********************************************************************/
bool operator==(const Student& s, int ID) {
    if (s.getStuID() == ID) {  // check if the student ID member is the same to
                               // the user inputted ID
        return true;           // if so, return true
    }
    return false;  // if it's not the same then we return false
}
/************************************
Function is going to add a course to
student

student object not array
************************************/
void addCourse(Student &student) {
    int crn; // course number
    cout << "Add course: ";
    cin >> crn;
    switch(student.addCourse(crn)) { // make switch statement depending if a course already exists or if full
      case(1): // course added successfully (number of classes not full and crn is not in the queue)
        cout << crn << " has been added successfully" << endl;
        student.addFee(50, 14);
        break;
      case(0): // class already exists
        cout << crn << " was not added because you have " << crn << " already" << endl; 
        break;
      case(-1): // no space for class
        cout << crn << " was not added because your schedule is full." << endl;
        break;
    }
}
/************************************
Function is going to drop a course
from a student

student object (not array)
************************************/
void dropCourse(Student &student) {
  int crn; // course number we are going to try and remove
  cout << "Enter course number to be removed: ";
  cin >> crn;
  if(student.dropCourse(crn)) { // if successfully removed drop course is boolean function
    cout << crn << " has been dropped successfully." << endl;
    student.reduceFee(50, 14);
  } else {
    cout << crn << " wasn't dropped from " << student.getFirstName() << " because " << crn << " doesn't exist" << endl;
  }
}
/************************************
Function is going to let user input
how much they want to pay
************************************/
void makePayment(Student &student) {
  int dollar, cent; // dollar and cent input
  cout << "Enter amount you want to pay: ";
  cin >> dollar >> cent; // take input
  student.reduceFee(dollar, cent); // reduce the fee
}

/*
******************** PHASE 3 ****************************

 checkPassword(  )
{
//I am using this function to check a password for both the admission's office
and student
//FYI, I am passing the correct password as a parameter and returning
true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
}

 findStu()
{
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}


 viewStuInfo()
{
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}


 verifyStu()
{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her
student id.
//Make sure the stuent id exists in the array. If not, I am showing an error
message.
//FYI, I am returning the index where the student was found or -1 if not found.
}
*/

bool checkPassword(const Student &stu, int correctPassword) {
  int passwordInput;
  cout << "Enter password: ";
  cin >> passwordInput;
  if(passwordInput == correctPassword) return true;
  cout << "The password is wrong" << endl;
  return false;
}

// int count number of students
int findStu(const Student students[], int count) {
  int idInput;
  cout << "Enter student ID: ";
  cin >> idInput;
  for(int i = 0; i < count; i++) {
    if(students[i].getStuID() == idInput) return i;
  }
  return -1; // if not found return -1
}

int verifyStu(const Student students[], int count) {
  int idInput, index;
  cout << "Enter student ID: ";
  cin >> idInput;
  index = find(students, count, idInput);
  if(index == -1) return -1; // not found
  return index;
}

int showMenu() {
    int choice;
    cout << "========================================================" << endl;
    cout << "1: Admission's Office" << endl;
    cout << "2: Student" << endl;
    cout << "3: End program" << endl;
    cout << "========================================================" << endl;
    cout << "Enter your choice: ";
    choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

    return choice;
}

int showStuMenu() {
    int choice;

    cout << endl;
    cout << "***************************" << endl;
    cout << "1: Add a course" << endl;
    cout << "2: drop a course" << endl;
    cout << "3: Make a payment" << endl;
    cout << "4: View my information" << endl;
    cout << "5: Quit" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice: ";
    choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

    return choice;
}

int showAdmMenu() {
    int choice;

    cout << endl;
    cout << "***************************" << endl;
    cout << "1: Add a new student" << endl;
    cout << "2: Add new students from a file" << endl;
    cout << "3: drop a student" << endl;
    cout << "4: View one student info" << endl;
    cout << "5: View all students' info" << endl;
    cout << "6: Quit" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice: ";
    choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

    return choice;
}
