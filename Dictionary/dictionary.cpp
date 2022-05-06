#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

#include "LL.h"
#include "utility.h"

void buildLL(LL &list);
std::string stringStr(std::string wd);
void removeBadWords(LL &list);
void saveToFile(LL &list);

int main() {
    LL list;
    buildLL(list);
    removeBadWords(list);
    saveToFile(list);
}

/*******************************************
Build the linked list and add words

LL &list pass by reference to add words to
list
********************************************/
void buildLL(LL &list) {
    std::ifstream fin;
    fin.open("essay.txt");
    std::string word;
    while(!fin.eof()) { // while we not at the end of the file
        fin >> word;
        if(list.search(stringStr(word)) == 0) list.addInOrderAscend(stringStr(word)); // if word is not found in list add (avoid repeats)
    }
    fin.close();
}

/*******************************************
Remove the bad words in the linked list

LL &list the list pass by reference to make
changes to list (remove words)
********************************************/
void removeBadWords(LL &list) {
    std::ifstream fin; // in file
    std::string word; // word
    fin.open("badWords.txt");
    while(!fin.eof()) { // while we are not at the end of the file
        fin >> word; // extract file word into string
        list.deleteNode(stringStr(word)); // delete word (if exists) 
    }
    fin.close();
}

/*******************************************
Save words in linked list into individual 
text files

LL &list since we want to remove elements 
from the list (remove words and individual)
********************************************/
void saveToFile(LL &list) {
    std::string filename = "./dictionary/A.txt", word; // filename with directory and file name the word from list
    char ch = 'a'; // filename character (can be 'a', 'b', 'c') used to change filename[13] character
    std::ofstream fout; // out filestream
    fout.open(filename.c_str()); // open a by default
    while(!list.isEmpty()) { // while list contains words
        word = list.deleteFront(); // delete the front of the list
        if(ch != word[0]) { // check if word belongs to file
            fout.close(); // close current file
            ch = word[0]; // set the character to first letter of word
            filename[13] = myToUpper(ch);
            fout.open(filename.c_str());
        }
        fout << word << std::endl; // print word and new line
    }
    fout.close();
}