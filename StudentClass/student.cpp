// Implementation File
#include <string>
#include "student.h"
#include "array.h"

using namespace std;

Student::Student(string fN, string lN, char gender) {
    firstName = fN;
    lastName = lN;
    this->gender = gender;
    numberOfClasses = 0;
}

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
    }
    else {
        return false;
    }
}
string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;
}
int Student::getClassNumber(int i) const {
    return courses[i];
}
char Student::getGender() const {
    return gender;
}
void Student::viewAllCourses() const {
    print(courses, numberOfClasses);
}