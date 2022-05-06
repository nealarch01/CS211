/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include <cstdlib>
// #include "array.h"
using namespace std;

void test(int code);
void fill(int array[], int SIZE);
void print(int array[], int SIZE);


void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);

int main()
{
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2);

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3);

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4);

  return 0;
}

void print(int array[], int SIZE) {
  for (int i = 0; i < SIZE; i++) {
    cout << array[i] << " ";
  }
}

//This function fills the array with random numbers between 1 and 100
void fill(int array[], int SIZE) 
{
  srand(time(0));
  int num;
  for (int i = 0; i < SIZE; i++) { // traverse the array and generate a random number using rand
   array[i] = rand() % 100 + 1;
  }
}

//code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

void test(int code)
{
  //make a constant SIZE set to 10
  const int SIZEA = 10;
  //declare an integer array using SIZE  
  int someArray[SIZEA];
  //fill the array by calling fill()
  fill(someArray, SIZEA);
  //print the array by calling print() in array.h
  print(someArray, SIZEA);
  //create a switch statement here to call a different sort function depending on the code.
  switch(code) {
    case(1):
      selectionSort1(someArray, SIZEA);
      break;
    case(2):
      selectionSort2(someArray, SIZEA);
      break;
    case(3):
      selectionSort3(someArray, SIZEA);
      break;
    case(4):
      selectionSort4(someArray, SIZEA);
      break;
  }
  cout << "\n------ Sorted Array ------\n";
  print(someArray, SIZEA);
}


//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N)
{
  int lrgIndx; //the index of the largest value
  int temp;    //temporary variable that holds the largest value

  //last is the first traversal from right to left
  for (int last = N - 1; last >= 1; last--)
  {
    lrgIndx = 0; //assume the first item is the largest
    //find the largest in unsorted part ([0..last])
    for (int i = 1; i <= last; i++)
    {
      if (array[i] > array[lrgIndx]) //The current item is larger
        lrgIndx = i;
    }
    //swap the largest with the last item in the unsorted part
    temp = array[lrgIndx];
    array[lrgIndx] = array[last];
    array[last] = temp;
  }
}


//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smallIndex; // the largest index
  int temp; // temporary variable to hold data when swapping
  //?????????                                                                                                                                                
  for(int last = N-1; last >= 1; last--)
    {
      smallIndex = 0; // set the largest index to 0 by default

      // second loop traversal to check for size
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smallIndex]) // compare if the first iteration element is greater than the second                                                                                                                          
            smallIndex = i;
        }

      // do swaps
      temp = array[smallIndex];
      array[smallIndex] = array[last];
      array[last] = temp;
    }
}


//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int index; // get the smallest index
  int temp; // variable used to temporarily hold element data when switching                                                                                                                                                                     
  // create a loop to traverse the entire array from left to right
  for(int i = 0; i < N; i++)
    {
      index = N - 1; // set the index = n - 1 or the greatest index
      // create a second to traverse right to left
      for(int j = N - 1; j >= i; j--)
        {
          if(array[j] < array[index]) // comparison to check if less than (check which number is larger)
            index = j;
        }
      // do swap
      temp = array[i];
      array[i] = array[index];
      array[index] = temp; 
    }
}

//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int index; // get the largest index
  int temp; // variable used to temporarily hold element data when swapping                                                                                                                                                                     
  // create a loop to traverse from left to right
  for(int i = 0; i < N; i++)
    {
      index = N - 1; // set the index = n - 1 or the highest index
      // create a second traverse right to left
      for(int j = N - 1; j >= i; j--)
        {
          if(array[j] > array[index]) // check if element is greater than(find the least) 
            index = j;
        }
      // do swap
      temp = array[i];
      array[i] = array[index];
      array[index] = temp; 
    }
}