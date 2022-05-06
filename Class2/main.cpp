#include <iostream>
#include <string>
#include "./Person.h"
using namespace std;
int main() {
    Faculty f1("Kathy", "Ross", "222-33-4444", "kathy@csusm.edu", 100, 2);
    Student s1("Tony", "Lopez", "333-44-5555", "tom@csusm.edu", "CS", 3.33, 'J');
    f1.printInfo();
    cout << "-------------------------------" << endl;
    s1.printInfo();
    cout << "-------------------------------" << endl;
    cout << "Printing unknown person" << endl;
    cout << "-------------------------------" << endl;
    Person unknown;
    unknown.printInfo();
    cout << "-------------------------------" << endl;
    cout << "Static data" << endl;
    cout << "-------------------------------" << endl;
    cout << "Number of students: " << Person::returnNum() << endl;
    cout << "Current ID: " << Person::getCurrentID() << endl;
    return 0;
}