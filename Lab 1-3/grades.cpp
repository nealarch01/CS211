#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void calcLowHighAvg(int grades[], const int& SIZE, int& highest, int& lowest, double& avg);

int main() {
    string fname, lname;
    const int GRADESIZE = 3;
    int grades[GRADESIZE];
    int highest, lowest, id;
    double avg;

    ifstream readFile;
    ofstream writeFile;
    readFile.open("stuscores.dat");
    writeFile.open("scores.out");
    if (!readFile.is_open()) {
        cout << "There was an error opening the file " << endl;
        return 2;
    }
        cout << right << setw(2) << "ID" << right << setw(14) << "Lowest" << right << setw(14) << "Highest" << right << setw(14) << "Average" << endl;
        writeFile << right << setw(2) << "ID" << right << setw(14) << "Lowest" << right << setw(14) << "Highest" << right << setw(14) << "Average" << endl;

    while(!readFile.eof()) {
        lowest = 127;
        highest = 0;
        avg = 0;
        readFile >> id;
        readFile >> fname;
        readFile >> lname;
        for(int i = 0; i < GRADESIZE; i++) {
            readFile >> grades[i];
        }
        calcLowHighAvg(grades, GRADESIZE, highest, lowest, avg);
        cout << right << id << right << setw(13) << lowest << right << setw(14) << highest << right << setw(14) << fixed << setprecision(2) << avg << endl;
        writeFile << right << id << right << setw(13) << lowest << right << setw(14) << highest << right << setw(14) << fixed << setprecision(2) << avg << endl;
    }
    readFile.close();
    writeFile.close();
    return 0;
}
void calcLowHighAvg(int grades[], const int& SIZE, int& highest, int& lowest, double& avg) {
    for (int i = 0; i < SIZE; i++) {
        if(highest < grades[i]) highest = grades[i];
        if(lowest > grades[i]) lowest = grades[i];
        avg += (double)grades[i];
    }
    avg /= (double)SIZE;
}