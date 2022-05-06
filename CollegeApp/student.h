#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "price.h"
using namespace std;
const int MAX = 6;
class Student {
private:
    string firstName;
    string lastName;
    char gender;
    int studentID;
    int numberOfClasses;
    int courses[MAX];
    Price balance;
public:
// note update the constructors to account for the new class members
    Student(string fN, string lN, char gender, int studentID); // parameterized constructor, takes first name, last name, and gender
    Student(); // default constructor
    string getFirstName() const;
    string getLastName() const;

    int getStuID() const; // make this function
    int getNumClasses() const; // make this function
    int getClassOf(int i) const; // make this function

    char getGender() const;

    int addCourse(int crn); 
    bool dropCourse(int crn);
    int getCourseNumber() const;
    void viewAllCourses() const;

    Price getBalance() const; // get the student's balance and return a price obj
    void addFee(int d, int c);
    void reduceFee(int d, int c);
};
#endif