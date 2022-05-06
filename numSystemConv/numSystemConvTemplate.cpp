#include <iostream>
#include <string>
using namespace std;

int getInput(int minimum, int maximum, string inputPrompt);


int main() {
    int dec;
    int base;
    getInput(1, 999999, "Enter a number in base 10: ");
    cout << "Enter a number in base 10: ";
    cin >> dec;
    while(dec > 1 || dec < 999999) {
        cout << "Enter a number between 1 and 999999. Enter again: ";
        cin >> dec;
    }
    cout << "Enter a base to convert the base 10 number to: ";
    cin >> base;
    switch(base) {
        case(2): 
            // binary func
            break;
        case(8):
            // octal func
            break;
        case(16):
            // hexadecimal func
            break;
        default:
            cout << "Invalid Base Enter Bases 2,8,16 Enter again: " << endl;
            cin.clear();
            cin.ignore(); // used to avoid infinite loop if invalid input is entered

    }
}