#include <iostream>
#include <string>
#include <fstream>


class Stt {
public:
    std::string firstName, lastName;
    char gender;
};

void openFile(std::ifstream& fin, Stt& s);

int main() {
    Stt s;
    std::ifstream fin;
    fin.open("college.dat");
    while(!fin.eof()) {
        openFile(fin, s);
    }
    return 0;
}

void openFile(std::ifstream& fin, Stt& s) {
    fin >> s.firstName;
    fin >> s.lastName;
    fin >> s.gender;
    fin.ignore(250, '\n');

    std::cout << s.firstName << std::endl << s.lastName << std::endl;
    std::cout << s.gender << std::endl;
}