//CS211 Kazumi Slott 
//2-9-2021
//This client is to test student class lab 1

#include <iostream> //for cout
using namespace std;
#include "student.h" //for the student class
#include "array.h"

//prototypes
void addCourseToStudent(Student& s, int crn);
void dropCourseFromStudent(Student& s, int crn);


int main()
{
  //create a student with Kathy, Ross, f
  Student stuA( "Kathy" , "Ross" , 'f');
  //create another student with Mike, Smith, m
  Student stuB( "Mike" , "Smith" , 'm');

  //add 111 to Kathy
  addCourseToStudent(stuA, 111);
  //add 111 to Mike
  addCourseToStudent(stuB, 111);
  //add 222 to Mike
  addCourseToStudent(stuB, 222);
  //add 222 to Mike  <ERROR>
  addCourseToStudent(stuB, 222);
  //add 333 to Mike
  addCourseToStudent(stuB, 333);
  //add 444 to Mike
  addCourseToStudent(stuB, 444);
  //add 555 to Mike
  addCourseToStudent(stuB, 555);
  //add 666 to Mike
  addCourseToStudent(stuB, 666);

  //show all the courses each student is taking
  cout << "---- Kathy is taking ----" << endl;
  stuA.viewAllCourses();
  cout << "---- Mike is taking ----" << endl;
  stuB.viewAllCourses();

  //try to add 777 to Mike <ERROR>
  addCourseToStudent(stuB, 777);

  //remove 222 from Kathy <ERROR>
  dropCourseFromStudent(stuA, 222);
  //remove 111 from Kathy
  dropCourseFromStudent(stuA, 111);
  //remove 111 from Kathy  <ERROR>
  dropCourseFromStudent(stuA, 111);
  //remove 333 from Mike
  dropCourseFromStudent(stuB, 333);
  //remove 666 from Mike
  dropCourseFromStudent(stuB, 666);
  //remove 111 from Mike  
  dropCourseFromStudent(stuB, 111);

  //show all the courses each student is taking
  cout << "---- Kathy is taking ----" << endl;
  stuA.viewAllCourses();
  cout << "---- Mike is taking ----" << endl;
  stuB.viewAllCourses();

  return 0;
}

void addCourseToStudent(Student& s, int crn)
{
  int res = s.addCourse(crn);
  if(res == 1) {
    cout << crn << " has been added" << endl;
  }
  else if(crn == 0) {
    cout << crn << " has not been added because crn already exists" << endl;
  }
  else { // result is -1
    cout << crn << " has not been added because the schedule is full" << endl;
  }
}

void dropCourseFromStudent(Student& s, int crn)
{
  bool canDrop = s.dropCourse(crn);
  if(canDrop == false) {
    cout << "The student is not taking " << crn << endl;
  }
  else {
    cout << crn << " has been dropped" << endl;
  }
}
