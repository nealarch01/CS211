/*********************************************************
Template provided by Kazumi Slott

Name: Neal Archival
This client tests the queue class memeber functions.
********************************************************/
#include <iostream>
using namespace std;
#include "queue.h"

void showMenu();
void addNewElem(Queue& q);
void removeElem(Queue& q);


int main() {
  Queue q;
  int input;
  el_t el; // char as of right now
  do{
    showMenu();
    cout << "Selection: ";
    cin >> input;
  switch(input) {
    case(1):
      addNewElem(q);
      break;
    case(2):
      removeElem(q);
      break;
    case(3):
      cout << q.getFront() << endl;
      q.isEmpty();
      break;
    case(4):
      q.goToBack();
      break;
    case(5):
      cout << q.getSize() << endl;
      break;
    case(6):
      q.displayAll();
      break;
    case(7):
      break;
    default:
      cout << "Invalid Input" << endl;
      cin.clear();
      cin.ignore();
      break;
  }
  } while(input != 7);
  return 0;
}


void showMenu() {
  cout << "1: add a new element" << endl; //(testing add(), isFull())
  cout << "2: remove an element" << endl; // (testing remove(), isEmpty())
  cout << "3: check the front element" << endl; //(testing getFront(), isEmpty())
  cout << "4: go back to the rear" << endl; //(testing goToBack())
  cout << "5: get the number of elements in the queue" << endl; //(testing getSize()) 
  cout << "6: display all the elements in the queue" << endl; //(testing displayAll()) 
  cout << "7: quit program" << endl;
}

void addNewElem(Queue& q) {
  if(q.isFull() == true) {
    cout << "Cannot add a new character because the queue is full" << endl;
    return;
  }
  char ch;
  cout << "Enter new element: ";
  cin >> ch;
  q.add(ch);
}

void removeElem(Queue& q) {
  if(q.isEmpty() == true) {
    cout << "Cannot remove elements beacuse the queue is empty" << endl;
    return;
  }
  char removedElement = q.remove();
  cout << removedElement << " has been removed from the queue" << endl;
}