/**********************************************************
Written By Kazumi Slott
CS211

You can get this program from /cs/slott/cs211/inheritance.cpp

This program demonstrates inheritance.
***********************************************************/

#include <iostream>
using namespace std;
#include "../BST/LL_T.h"

//################################ Employee class
//#######################################
class Employee {  // base class
   protected:
    static int start_id;  // A static data member is created only one instance
                          // for the entire program
    const int ID;  // A constant data member cannot change its value
    string fn;
    string ln;
    double salary;

   public:
    Employee(string f = "unknown",
             string l = "unknown");  // A constant data member needs to be
                                     // initialized in the func header
    virtual void showInfo();
    static int getStartId();  // prototype
};

int Employee::start_id =
    1000;  // initialize a static data member outside the class definition. You
           // need clasEmployee::static_data_member

// You can set default values in the func header of the constructor
Employee::Employee(string f, string l)
    : ID(start_id)  // A constant data member needs to be initialized in the
                    // func header
{
    fn = f;
    ln = l;
    salary = 40000;
    start_id++;  // increment for the next employee
}

void Employee::showInfo() {
    cout << "Employee::showInfo()" << endl;
    cout << ID << "(ID) " << fn << "(fn) " << ln << "(ln) " << salary
         << "(salary)" << endl;
}

int Employee::getStartId()  // This function needs to be implemented after
                            // start_id is initialized.
{
    return start_id;
}

//################################ Manager class
//#######################################
class Manager : public Employee {  // Manager is a inherited class of the
                                   // Employee class (called base class)
   private:
    int groupNum;
    int rank;  // 1, 2, or 3
   public:
    Manager(string f = "unknown", string l = "unknown", int r = 1, int gn = 0)
        : Employee(f, l) {
        rank = r;
        groupNum = gn;
        setSalary();
    }

    // mutator
    void setSalary() {
        cout << "Manager::setSalary" << endl;
        salary = 70000 * (1 + (rank - 1) * 0.1);
    }

    // mutator
    void setGroupNum(int newG)  // change the groupNum
    {
        groupNum = newG;
    }

    // mutator
    void setRank(int newR)  // change the rank
    {
        if (newR >= 1 && newR <= 3) {
            rank = newR;
            setSalary();  // update the salary
        } else
            cout << newR << " is invalid rank." << endl;
    }

    virtual void showInfo() {
        cout << "Manager::showInfo()" << endl;
        Employee::showInfo();  // Calling the function of the base class
        cout << groupNum << "(groupNum) " << rank << "(rank) " << endl << endl;
    }
};

//################################ SE class
//#######################################
class SE : public Employee {  // SE is a inherited class of the Employee class
   private:
    int groupNum;
    int exp_yr;
    LL<string> certificates;  // holds certificates
   public:
    SE(string f = "unknown", string l = "unknown", int yr = 0, int gn = 0)
        : Employee(f, l) {
        exp_yr = yr;
        groupNum = gn;
        setSalary();
    }

    // mutator
    void setSalary() {
        cout << "SE::setSalary" << endl;
        salary = 60000 * (1 + exp_yr * 0.05 + certificates.getCount() * 0.05);
    }

    // mutator
    void setExpYr(int newY) {
        exp_yr = newY;
        setSalary();  // update the salary
    }

    // mutator
    void addCertificate(string c) {
        certificates.addRear(c);
        setSalary();  // update the salary
    }

    virtual void showInfo() {
        cout << "SE::showInfo()" << endl;
        Employee::showInfo();
        // cout << ID << "(ID) " << fn << "(fn) " << ln << "(ln) " << salary <<
        // "(salary) " << endl; //The protected members of the base class can be
        // accessed from the inherited class. An inherited class cannot access
        // private members.
        cout << exp_yr << "(exp_yr) " << groupNum << "(groupNum) ";
        certificates.displayAll();
        cout << "(certificates) " << endl << endl;
    }
};

//################################ Client
//#######################################

int main() {
    Manager m;  // new operator returns the address of the manager object. The
                // default values will be used.
    SE se("Mike", "Smith", 3, 10);
    Employee e("Kathy",
               "Ross");  // You can make an object from the base class too

    cout << "1: (manager)" << endl;
    m.showInfo();
    cout << "--------------------------" << endl;

    m.setRank(2);
    m.setGroupNum(10);
    cout << "2: (manager) after changing rank and group num" << endl;
    m.showInfo();
    cout << "--------------------------" << endl;

    cout << "3: (SE)" << endl;
    se.showInfo();
    cout << "--------------------------" << endl;

    se.addCertificate("C++");
    cout << "4: emp[1](SE) after added 1st certificate" << endl;
    se.showInfo();
    cout << "--------------------------" << endl;
    se.addCertificate("Java");
    cout << "5: emp[1](SE) after added 2nd certificate" << endl;
    se.showInfo();

    cout << "--------------------------" << endl;
    cout << "6: (employee)" << endl;
    e.showInfo();

    cout << "\n--------------------------" << endl;
    cout << "start_id is " << Employee::getStartId() << endl;

    return 0;
}
