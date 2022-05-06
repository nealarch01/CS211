//Test client to test LL class
//4-22-2016
//CS211  Kazumi Slott

#include <iostream>
using namespace std;
#include "LL.h"

int main()
{
  LL l;

  cout << "TEST deleteNode **************************************************************" << endl;

  l.addRear(3);
  l.addRear(9);
  l.addRear(2);
  l.addRear(1);
  l.addRear(9);
  l.addRear(11);
  l.displayAll();  //[3] -> [9] -> [2] -> [1] -> [9] -> [11]
  cout << endl;

  l.deleteNode(9);
  l.displayAll();  //[3] -> [2] -> [1] -> [9] -> [11]
  cout << endl;

  l.deleteNode(9);
  l.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl;

  l.deleteNode(5); 
  l.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl;

  l.deleteNode(3); 
  l.displayAll(); //[2] -> [1] -> [11]
  cout << endl;

  l.deleteNode(11); 
  l.displayAll(); //[2] -> [1]
  cout << endl;

  l.deleteNode(1); 
  l.displayAll(); //[2]
  cout << endl;

  l.deleteNode(2); 
  l.displayAll(); //[empty]
  cout << endl;

  l.deleteNode(5); // Nothing happens
  cout << endl;

  /*
  cout << "TEST addInOrder**************************************************************" << endl;

  l.addInOrderAscend(5);
  l.displayAll(); //[5]
  cout << endl;

  l.addInOrderAscend(1);
  l.displayAll(); //[1] -> [5]
  cout << endl;

  l.addInOrderAscend(3);
  l.displayAll(); //[1] -> [3] -> [5]
  cout << endl;

  l.addInOrderAscend(0);
  l.displayAll(); //[0]->[1]->[3]->[5]
  cout << endl;

  l.addInOrderAscend(7);
  l.displayAll(); //[0]->[1]->[3]->[5]->[7]
  cout << endl;

  l.addInOrderAscend(7);
  l.displayAll(); //[0]->[1]->[3]->[5]->[7]->[7]
  cout << endl;

  l.addInOrderAscend(5);
  l.displayAll(); //[0]->[1]->[3]->[5]->[5]->[7]->[7]
  cout << endl;

  l.addInOrderAscend(0);
  l.displayAll(); //[0]->[0]->[1]->[3]->[5]->[5]->[7]->[7]
  cout << endl;

*/
  cout << "TEST Search **************************************************************" << endl;

  LL l2;
  l2.addRear(3);
  l2.addRear(9);
  l2.addRear(2);
  l2.addRear(1);
  l2.addRear(9);
  l2.addRear(11);

  cout << l2.search(3) << endl;  //1
  cout << l2.search(11) << endl; //1
  cout << l2.search(2) << endl;  //1
  cout << l2.search(9) << endl;  //1
  cout << l2.search(100) << endl; //0

  cout << "##### EXTRA CREDIT -  TEST deleteNodes (all occurences) **************************************************************" << endl;

  l2.displayAll(); //[3] -> [9] -> [2] -> [1] -> [9] -> [11]
  cout << endl;

  l2.deleteNodes(9);
  l2.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl;

  l2.addRear(3);
  l2.displayAll(); //[3] -> [2] -> [1] -> [11] -> [3]
  cout << endl;

  l2.deleteNodes(3);
  l2.displayAll(); //[2] -> [1] -> [11]
  cout << endl;
  // segmentation error here *************
  l2.addRear(5);
  l2.displayAll(); //[2] -> [1] -> [11] -> [5]
  cout << endl;

  l2.deleteNodes(2); 
  l2.displayAll(); //[1] -> [11] -> [5]
  cout << endl;

  l2.deleteNodes(11); 
  l2.displayAll(); //[1] -> [5]
  cout << endl;

  l2.deleteNodes(5); 
  l2.displayAll(); //[1]
  cout << endl;

  l2.deleteNodes(1); 
  l2.displayAll(); //[empty]
  cout << endl;

  l2.deleteNodes(100); //nothing happens

/*
  cout << "##### EXTRA CREDIT - TEST addInOrderDescend **************************************************************" << endl;

  l2.addInOrderDescend(5);
  l2.displayAll(); //[5]
  cout << endl;

  l2.addInOrderDescend(1);
  l2.displayAll(); //[5] -> [1]
  cout << endl;

  l2.addInOrderDescend(3);
  l2.displayAll(); //[5] -> [3] -> [1]  
  cout << endl;

  l2.addInOrderDescend(0);
  l2.displayAll(); //[5] -> [3] -> [1] -> [0]
  cout << endl;

  l2.addInOrderDescend(7);
  l2.displayAll(); //[7] -> [5] -> [3] -> [1] -> [0]
  cout << endl;

  l2.addInOrderDescend(7);
  l2.displayAll(); //[7] -> [7] -> [5] -> [3] -> [1] -> [0]
  cout << endl;

  l2.addInOrderDescend(5);
  l2.displayAll(); //[7] -> [7] -> [5] -> [5] -> [3] -> [1] -> [0]
  cout << endl;

  l2.addInOrderDescend(0);
  l2.displayAll(); //[7] -> [7] -> [5] -> [5] -> [3] -> [1] -> [0] -> [0] 
  cout << endl;
  */

  return 0;
}
