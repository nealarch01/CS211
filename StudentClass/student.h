#include <string>
using namespace std;
const int MAX = 6;
class Student {
private:
    string firstName;
    string lastName;
    char gender;
    int numberOfClasses;
    int courses[MAX];
public:
    Student(string fN, string lN, char gender);
    string getFirstName() const;
    string getLastName() const;
    int getClassNumber(int) const;
    char getGender() const;

    int addCourse(int crn); // void because we are changing values inside an array
    bool dropCourse(int crn);
    int getCourseNumber() const;
    void viewAllCourses() const;
};