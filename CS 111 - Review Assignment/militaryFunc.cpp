#include <iostream>
#include <string>
using namespace std;

void showProgInfo();
void getInfo(string&, char&, int&);
bool isEligible(char, int);
void printMessage(bool, string, char);

int main() {
    // Test Cases // *** These variables are just here to check the test cases instead of having to manually type each test case ***
    string nameTestCase[] = {"Mike", "Dave", "Kathy", "Mike", "Dave"};
    char genderTestCase[] = {'m', 'm', 'f', 'm', 'm'};
    int ageTestCase[] = {15, 18, 25, 17, 20};
    // Order: too young, eligible, gender ineligible, too young, eligible
    for (unsigned int i = 0; i < sizeof(nameTestCase) / sizeof(nameTestCase[0]); i++) {
        cout << "Test Case " << i + 1 << " Information: " << nameTestCase[i] << " " << genderTestCase[i] << " " << ageTestCase[i] << endl;
        printMessage(isEligible(genderTestCase[i], ageTestCase[i]), nameTestCase[i], genderTestCase[i]);
    }
    cout << "End of Test Cases \n\n\n";
    // End Of Test Cases //

    // **** User Input Starts Here **** //
    string name;
    int age;
    char gender;
    showProgInfo();
    getInfo(name, gender, age);
    printMessage(isEligible(gender, age), name, gender);
}

void showProgInfo() {
    cout << "**************************************\nAre You Eligible To Join The Military?\n**************************************" << endl;
}

void getInfo(string& name, char& gender, int& age) {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your age: ";
    cin >> age;
}

bool isEligible(char gender, int age) {
    if (gender == 'F' || gender == 'f') {
        return false;
    }
    else {
        if (age >= 18) {
            return true;
        }
        else {
            return false;
        }
    }
}

void printMessage(bool isEligible, string name, char gender) {
    if (isEligible == true) {
        cout << "Dear " << name << ", please consider joining the military." << endl;
    }
    else {
        if(gender == 'F' || gender == 'f') {
            cout << "Sorry " << name << ", but women are not eligible. Thank you for applying." << endl;
        }
        else {
            cout << "Sorry " << name << ", but you are too young. Thank you for applying." << endl;
        }
    }
}