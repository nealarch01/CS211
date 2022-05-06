/***************************************************************                                                                                                                                            
CS211                                                                                                                                                                                                       
Template prepared by Kazumi Slott                                                                                                                                                                           
1-28-2020                                                                                                                                                                                                   
                                                                                                                                                                                                            
This program tests array.h                                                                                                                                                                                  
**************************************************************/
#include <iostream>
#include "array.h"

int main()
{
  //declare const called SZ_I set to 7
  const int SZ_I = 7;
  //declare const called SZ_D set to 3
  const int SZ_D = 3;
  //declare const called SZ_C set to 5
  const int SZ_C = 5;

  //create an integer array that has SZ_I slots
  int array1[SZ_I];
  //create a double array that has SZ_D slots
  double array2[SZ_D];
  //create a character array that has SZ_C slots
  char array3[SZ_C];

  //call fill with the integer array
  std::cout << "------ Filling the integer array ------" << std::endl;
  fill<int>(array1, SZ_I);
  //call fill with the double array
  std::cout << "------ Filling the double array ------" << std::endl;
  fill<double>(array2, SZ_D);
  //call fill with the character array
  std::cout << "------ Filling the character array ------" << std::endl;
  fill<char>(array3, SZ_C);

  //call print (with 2 parameters) with the integer array
  print<int>(array1, SZ_I);
  //call print with the double array
  print<double>(array2, SZ_D);
  //call print with the character array
  print<char>(array3, SZ_C);
  //call getHighest with the character array and show the highest value along with its location
  cout << "The highest is x at " << getHighest<char>(array3, SZ_C) << endl;
  //call getLowest with the duoble and show the lowest value along with its location
  cout << "The lowest is x at " << getLowest<double>(array2, SZ_D) << endl;

  //call getAvg with the integer array and show the returend value
  double avg = getAvg<double, int>(array1, SZ_I);
  cout << "The average is: " << avg << endl;

  for (int i = 0; i < SZ_D; i++)
  {
    cout << array2[i] << " ";
  }
  cout << endl;

  //call unique with integer array and show unique array and the number of unique numbers
  int uniqueArr_I[SZ_I];
  int uniqueNum = unique<int>(array1, uniqueArr_I, SZ_I);
  for (int i = 0; i < uniqueNum; i++)
  {
    cout << uniqueArr_I[i] << " ";
  }
  cout << "\nTotal number of unique integers: " << uniqueNum << endl;
  //call unique with character array and show unique array and the number of unique numbers
  char uniqueArr_C[SZ_C];
  uniqueNum = unique<char>(array3, uniqueArr_C, SZ_C);
  for (int i = 0; i < uniqueNum; i++)
  {
    cout << uniqueArr_C[i] << " ";
  }
  cout << "\nTotal number of unique characters: " << uniqueNum << endl;
  //sort the double array and print it
  bubbleSort<double>(array2, SZ_D);
  for (int i = 0; i < SZ_D; i++)
  {
    cout << array2[i] << " ";
  }
  cout << "\n";
  //sort the character array and print it
  bubbleSort<char>(array3, SZ_C);
  for (int i = 0; i < SZ_C; i++)
  {
    cout << array3[i] << " ";
  }
  cout << "\n";

  return 0;
}
