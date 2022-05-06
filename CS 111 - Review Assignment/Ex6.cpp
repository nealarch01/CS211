#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void getStudent(ifstream& fileData);

void getStudent(ifstream& fileData) {
    string name;
    double grade1, grade2, avg;
    cout << left << setw(10) << "Student" << right << setw(5) << "Grade" << endl;
    while(!fileData.eof()) {
        getline(fileData, name, ' '); // assuming the student name might have a dash / hyphen or special character
        fileData >> grade1;
        fileData.ignore();
        fileData >> grade2;
        fileData.ignore();

        avg = (grade1 + grade2) / 2;
        cout << left << setw(10) << name << right << setw(5) << fixed << setprecision(1) << avg << endl;
    }
}

void getStudent(ifstream& fileData);
int main() {
    ifstream fileData;
    fileData.open("scores.dat");
    if (!fileData.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    getStudent(fileData);
}