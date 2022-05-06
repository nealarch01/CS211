#include <iostream>
#include <fstream>
#include "Person.h"
#include "../BST/LL_T.h"

using namespace std;

int main() {
    ifstream fin;
    fin.open("campus.dat");
    if(!fin.is_open()) return 2; // exit with code 2
    LL<Person*> l1;
    int personType = 0;
    string fn, ln, ssn, email, major;
    int years, deptID;
    double gpa;
    char studentYR;
    while(fin >> personType) {
        fin >> fn;
        fin >> ln;
        fin >> ssn;
        fin >> email;
        switch(personType) {
            case(1):
                l1.addRear(new Person(fn, ln, ssn, ssn));
                break;
            case(2):
                fin >> deptID;
                fin >> years;
                l1.addRear(new Faculty(fn, ln, ssn, email, deptID, years));
                break;
            case(3):
                fin >> major;
                fin >> gpa;
                fin >> studentYR;
                l1.addRear(new Student(fn, ln, ssn, email, major, gpa, studentYR));
                break;
        }
        fin.ignore();
    }
    cout << "Inside list: " << l1.getCount() << endl;
    Person *temp;
    while(!l1.isEmpty()) {
        temp = l1.deleteFront();
        temp->printInfo();
        cout << "------------------------------" << endl;
    }
    return 0;
}