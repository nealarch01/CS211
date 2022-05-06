/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Neal
*****************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


/********************************************
This function fills the array with data entered from the keyboard.

"array" is an array of any data type
"SIZE" is the number of items entered into ar
********************************************/
template<typename T>
void fill(T array[], int SIZE) { // going to use void because arrays are pass by reference and we don't need to return any values
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter an item: ";
        cin >> array[i];
    }
}
/*
This function takes two parameters which is the array and the number of members which represents the index
*/


/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template<typename T>
void print(const T array[], int SIZE) { // question about this
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
/*******************************************************************
This function takes two templates one for the array type and the 
other for the extractor object to print cout 
*******************************************************************/
template<typename T, typename O> void printOut(const T array[], int SIZE, O& out) {
    for (int i = 0; i < SIZE; i++) {
        out << array[i] << " ";
    }
    out << "\n";
}

/*******************************************
This function returns the index of the highest value.

array is an array of any data type.
SIZE is the number of items in ar
*******************************************/
template<typename T>
int getHighest(T array[], int SIZE) {
    T largest = array[0];
    int res = 0;
    for (int i = 1; i < SIZE; i++) {
        if(largest < array[i]) {
            largest = array[i];
            res = i;
        }
    }
    return res;
}

/*******************************************
This function returns the index of the lowest value.

array is an array of any data type.
SIZE is the number of items in array
*******************************************/
template<typename T>
int getLowest(T array[], int SIZE) {
    int res = 0;
    T smallest = array[0];
    for (int i = 1; i < SIZE; i++) {
        if(smallest > array[i]) { 
            smallest = array[i];
            res = i;
        }
    }
    return res;
}

/********************************************
This function returns the average.

array is an array of any data type.
SIZE is the number of items in ar
********************************************/
template<typename T>
T getAvg(T array[], int SIZE) {
    T avg = 0;
    for (int i = 0; i < SIZE; i++) {
        avg += array[i];
    }
    return (avg / SIZE);
}

/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1 The function returns 4  

ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template<typename T>
int unique(const T array[], T uniqArray[], int SIZE) {
    uniqArray[0] = array[0];
    int res = 1; // we already know the first element is going to be a unique character
    for (int i = 1; i < SIZE; i++) {
        for (int j = 0; j <= res; j++) {
            if (uniqArray[j] == array[i]) {
                break;
            }
            if(j == res) { // if j has reached the end of the array
                uniqArray[j] = array[i];
                res++;
                break;
            }
        }
    }
    return res; // return the size of uniqArray (number of elements)
}
/*This function is going to sort ascending order

*/
template<typename T>
void sort(T array[], int N) 
{
  int lrgIndx; //the index of the largest value 
  int smallIndex;                                                                                              
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      smallIndex = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[smallIndex]) //The current item is larger                                                                           
            smallIndex = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[smallIndex];
      array[smallIndex] = array[last];
      array[last] = temp;
    }
}

template<typename T>
void bubbleSort(T array[], int SIZE) { // to descending order
    bool isSorted;
    T temp;
    while(isSorted == false) {
        isSorted = true;
        for (int i = 0; i < SIZE - 1; i++) {
            if (array[i] < array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                isSorted = false;
            }
            if (i == SIZE && isSorted == true) {
                break; // break out the for loop and evaluate isSorted bool
            }
            else {
                continue;
            }
        }
    }
}

template<typename T>    
int find(T array[], int size, T key) {
    for (int i = 0 ; i < size; i++)
        if(key == array[i]) return i; // returns the index
    return -1; // return -1 if nothing was found
}
template<typename T>
bool remove(T array[], int size, T key) {
    int res = find(array, size, key);
    if (res == -1) return false;
    for (int i = res; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    return true;
}