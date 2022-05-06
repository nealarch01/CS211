// student.h Implementation File
#include <string>
#include "student.h"
#include "array.h"

using namespace std;

Student::Student(string fN, string lN, char gender, int id) {
    firstName = fN;
    lastName = lN;
    this->gender = gender;
    studentID = id;
    numberOfClasses = 0;
}

Student::Student() {
    firstName = "unknown";
    lastName = "unknown";
    gender = 'x';
    numberOfClasses = 0;
    studentID = -1;
}
/***********************************************************
Add course to a student object

1 = successfully added
0 = course already exists for student
-1 = course list full
************************************************************/
int Student::addCourse(int crn) {
    int res = find(courses, MAX, crn); // the result returned from find
    // res will return either 1 or -1
    if(numberOfClasses == MAX) return -1; // return because the array is full
    if(res == -1) { // class has not been found
        courses[numberOfClasses] = crn;
        numberOfClasses++;
        return 1; // successfully added new class
    }
    return 0; // class already exists
}
bool Student::dropCourse(int crn) {
    bool success = remove(courses, numberOfClasses, crn);
    if(success == true) {
        numberOfClasses--;
        return true;
    } else {
        return false;
    }
}
string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;
}
char Student::getGender() const {
    return gender;
}
void Student::viewAllCourses() const {
    print(courses, numberOfClasses);
}
Price Student::getBalance() const {
    return balance;
}
void Student::addFee(int d, int c) {
    Price p(d, c);
    balance = balance + p;
}
void Student::reduceFee(int d, int c) {
    Price p(d, c);
    balance = balance - p;
}
int Student::getStuID() const {
    return studentID;
}
int Student::getNumClasses() const {
    return numberOfClasses;
}
int Student::getClassOf(int i) const {
    return courses[i];
}
