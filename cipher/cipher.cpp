/***************************************************
This progarm is going to read a sentence from a file
and then cipher the sentence and then decipher the 
vector of characters
***************************************************/
#include <iostream> 
#include <string> // string
#include <fstream> // ifstream read from file

#include "myVector.h" // implemented vector class

std::string readFromFile();
bool isLetterDigit(char ch);
bool isDigit(char ch);
void cipher(MyVector<char> &vec);
void decipher(MyVector<char> &vec, std::string sentence);
char myToLower(char);
void printVector(MyVector<char> &vec);
bool operator==(MyVector<char> &v1,MyVector<char> &v2);
int getData(int minimum, int maximum, std::string message);

int main() {
    MyVector<char> vec; // our vector of characters
    std::string sentence; // the sentence as a string

    sentence = readFromFile();
    std::cout << "---- sentence ----" << std::endl;
    std::cout << sentence << std::endl;
    for(int i = 0; i < sentence.length(); i++) vec.push_back(sentence[i]);
    for(int i = 0; i < vec.size(); i++)  {
        if(!isLetterDigit(vec[i])) {
            vec.erase(i);
            i--; // we need to stay on the same index because we move one forward
                 // we are erasing an index so we need to decrement to stay on the same
        }
    }
    std::cout << "---- after removing non-letter/digit ----" << std::endl;
    printVector(vec);
    for(int i = 0; i < vec.size(); i++) vec[i] = myToLower(vec[i]); // call function to turn character
                                                            // into lower case by calling the function
    std::cout << "---- After converting to lower case ----" << std::endl;
    printVector(vec);
    cipher(vec);
    std::cout << "---- After inserting a space after every 5 characters ----" << std::endl;
    printVector(vec);
    decipher(vec, sentence);
    std::cout << "---- After deciphering ----" << std::endl;
    printVector(vec);
    return 0;
}

std::string readFromFile() {
    std::ifstream cipherFile; // ifstream file
    std::string filename, sentence; // string that will hold the filename and 
                                    // the sentence as a string that will be returned
    std::cout << "Enter filename: ";
    std::cin >> filename;
    cipherFile.open(filename.c_str()); // convert to c string
    while(!cipherFile.is_open()) { // if the filename is not found we will prompt
                                   // the user to enter the filename again
        std::cout << "File not found. Enter again: ";
        std::cin >> filename;
        cipherFile.open(filename.c_str()); // convert because of cstring parameter
    }
    getline(cipherFile, sentence); // getline to read from the file so we can include spaces
    return sentence; 
}

void printVector(MyVector<char> &vec) {
    for(int i = 0; i < vec.size(); i++) std::cout << vec[i]; // iterate and output every character of the vector
    std::cout << std::endl;
}

bool isLetterDigit(char ch) { 
    if(ch >= 48 && ch <= 57) return true; // check digit if ch is in between 48 57 on ascii table
    else if(ch >= 65 && ch <= 90) return true; // check capital letter
    else if(ch >= 97 && ch <= 122) return true; // check if lowercase letter
    return false; // if ascii value is not in between or equal to these values then character 
                  // is neither a digit or letter
}

char myToLower(char ch) {
    if(ch >= 65 && ch <= 90) ch += 32; // if the character is in between these values then
                                        // add by 32 to get the lower case letter
    return ch;
}

bool isDigit(char ch) {
    if(ch >= 48 && ch <= 57) return true; // if in between 48 and 57 or (0 and 9) we return true since 
                                          // they are ascii number of digits
    return false; // if not return false
}
void cipher(MyVector<char> &vec) {
    int shift, ctr = 0; // shift is the user input number which will shift the ascii value of the character if ascii value > 127
                        // counter is used to add a space for every 5 characters
    int tempChar;
    std::cout << "Enter a secret number between 1 and 26 to cipher sentence: ";
    shift = getData(1, 26, "Invalid Input. Enter a number in between 1 -26.\nEnter Again: ");
    // loop to insert spaces every 5 counts and cipher the character
    for(int i = 0; i < vec.size(); i++) {
        if(ctr == 5) {
            vec.insert(i++, ' '); // increment i since we don't want to cipher the space
            ctr = 0; // reset the counter
        } 
        if(isDigit(vec[i])) {
            vec[i] += shift;
            while(!isDigit(vec[i])) vec[i] = (vec[i] % 58) + 48; // algorithm to wrap around the 48 value
        }
        else { // isDigit == false
            tempChar = vec[i] + shift; // 
            while(tempChar < 97 || tempChar > 122) {  // not using isLetterDigit because we are using tempChar which is 
                                                      // an integer and max ascii is 127
                tempChar = (tempChar % 123) + 97; // wrap around the lower case letter ascii values
            }
            vec[i] = tempChar;
        }
        ctr++; // increment the 5 space counter
    }
}


/*************************************
This function is going to decipher the
ciphered message without the key

Steps:
1. Make two new vectors, one to hold
sentence of characters (lower case
with no spaces) and the other to
temporarily hold chars of original 
chars

2. A temporary vector to be used to
backwards shift so we don't change
all the character contents

3. Brute force backshifts 26 times 
 - After one loop iteration
compare if the sentence vector 
and unciphered vector are the same
- if != continue
- if == then copy vector chars and
return back to main

vec is the vector of characters

sentence is the original sentence we
obtained from file data
*************************************/
void decipher(MyVector<char> &vec, std::string sentence) {    
    /*
    sentenceVec will hold the vector of characters
    vecUnciphered will be temporarily holding the unciphered characters that may or may not be the key
    */
    MyVector<char> sentenceVec, vecUnciphered; // sentenceVec will hold the vector of characters from
    // this loop will remove all the spaces from the vector of characters and initialize the size of
    // the unciphered vector by pushing back the content of elements in the regular vector
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == ' ') vec.erase(i); // if we encounter a space we erase it
        vecUnciphered.push_back(vec[i]); // initializing the size of the unciphered vector by pushing back
    }

    /*
    Copy the sentence into a vector and omit non letters/digit characters such as
    spaces, dashes, etc
    */
    for(int i = 0; i < sentence.length(); i++) {
        if(!isLetterDigit(sentence[i])) continue; // if not letter or digit then we skip one iteration
        sentence[i] = myToLower(sentence[i]); // call lower function if character is a capital letter
        sentenceVec.push_back(sentence[i]); // push back the char to sentence vector
    }
    /*
    Do 26 backward shifts until we get the correct key
    We find the correct key by comparing sentenceVec to vecUnciphered, if they are the same
    then we copy all values in vecUnciphered into vec so we can print out in main
    */
    for(int shift = 1; shift < 27; shift++) {
        for(int i = 0; i < vecUnciphered.size(); i++) vecUnciphered[i] = vec[i]; // reset the vecUnciphered to its original state
                                // if we don't reset then it will backwards shift multiple times

        // This loop is going to iterate through the ciphered vector and backward shift the character
        for(int i = 0; i < vecUnciphered.size(); i++) { 
            if(isDigit(vecUnciphered[i])) {
                vecUnciphered[i] -= shift; // initial subtraction
                // while character is not a digit, we wrap around by getting the remainder and subtract 
                // by the greatest digit ascii value
                while(!isDigit(vecUnciphered[i])) vecUnciphered[i] = 58 - (48 % vecUnciphered[i]);
            }
            else { // if not digit (lowercase char)
            // no need for int since we are not going to exceed 127
                vecUnciphered[i] -= shift; // initial subtraction
                while(vecUnciphered[i] < 97) vecUnciphered[i] = 123 - (97 % vecUnciphered[i]); // while character is not lowercase, continue getting remainder and wrapping around
            }
        }
        // now we compare
        if(vecUnciphered == sentenceVec) break; // break loop if vectors match match
    }
    // loop to transfer the contents into our vec (original vector of characters)
    for(int i = 0; i < vecUnciphered.size(); i++) vec[i] = vecUnciphered[i];
}

/*************************************
Overloaded function used to compare 
two MyVector objects will return if
all characters are the same, false
if one is not
*************************************/
bool operator==(MyVector<char> &v1, MyVector<char> &v2) {
    if(v1.size() != v2.size()) return false; // if the sizes are not the same, then the vectors aren't the same
    for(int i = 0; i < v1.size(); i++) if(v1[i] != v2[i]) return false; // if one character is not equal, vectors are != 
    return true; // if we go through the entire loop with no returns, then they are the same
}

int getData(int minimum, int maximum, std::string message) {
    int userInput; // integer to be returned
    std::cout << "Enter a number: ";
    std::cin >> userInput;
    while(std::cin.fail() || userInput < minimum || userInput > maximum) {
        std::cin.clear(); std::cin.ignore(); // clear and ignore the istream buffer to avoid infinite loop
        std::cout << message;
        std::cin >> userInput;
    }
    return userInput;
} 