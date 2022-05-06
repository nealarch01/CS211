#include <iostream>
#include <string>

#include "../BST/LL_T.h"

class Person {

   protected:
    static int num;  // static since total number of people created stays the same
    static int currentID;  // static for each person has a unique id
    const int ID;
    std::string firstname;
    std::string lastname;
    std::string ssn;
    std::string email;

   public:
    Person(std::string fn = "unknown", std::string lastname = "unknown",
           std::string ssn = "000-00-0000", std::string email = "unknown");
    static int getCurrentID();
    virtual void printInfo();
    static int returnNum();
};

// since these are variables put at the top
int Person::currentID = 1000;  // initialize the static variable for current ID
int Person::num = 0;  // initialize the static variable for the total number of students

// ******** Person Function Implementation ***************

Person::Person(std::string fn, std::string ln, std::string s, std::string e)
    : ID(currentID) {
    firstname = fn;
    lastname = ln;
    ssn = s;
    email = e;
    num++;        // increment the number of students
    currentID++;  // increment the student id
}

void Person::printInfo() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "First name: " << firstname << std::endl;
    std::cout << "Last name: " << lastname << std::endl;
    std::cout << "Social security number: " << ssn << std::endl;
    std::cout << "Email: " << email << std::endl;
}

int Person::returnNum() { return num; }

int Person::getCurrentID() { return currentID++; } // increment the current ID next person can have their own


// ******* End of Person Function Methods ********
// ******* Start of Student Function Methods

class Faculty : public Person {
   private:
    const int departmentID;
    int years;  // years at school
   public:
    Faculty(std::string fn = "unknown", std::string ln = "unknown",
            std::string s = "000-00-0000", std::string e = "unknown",
            int deID = -1, int yrs = -1);
    void printInfo();
};

// Constructor Method
Faculty::Faculty(std::string fn, std::string ln, std::string s, std::string e,
                 int deID, int yrs)
    : departmentID(deID), Person(fn, ln, s, e) {
    years = yrs;
}

void Faculty::printInfo() {
    Person::printInfo();
    std::cout << "Department ID: " << departmentID << std::endl;
    std::cout << "Number of years: " << years << std::endl;
}

// ********** End of Faculty methods **************

class Student : public Person {
   private:
    std::string major;
    double gpa;
    char grade;  // (freshman, junior, sophomore senior) (f, j, s, n)
   public:
    // parameterized constructor below
    Student(std::string fn = "unknown", std::string ln = "unknown",
            std::string s = "000-00-0000", std::string e = "unknown",
            std::string m = "unknown", double gp = -1.00, char gr = '?');
    void printInfo();
};

// ******* Student methods *************
Student::Student(std::string fn, std::string ln, std::string s, std::string e,
                 std::string m, double gp, char gr)
    : Person(fn, ln, s, e) {
    major = m;
    gpa = gp;
    grade = gr;
}

void Student::printInfo() {
    Person::printInfo();
    std::cout << "Major: " << major << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
    std::cout << "Grade: " << grade << std::endl;
}
