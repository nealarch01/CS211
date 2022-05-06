#include <iostream>
#include <string>
#include <fstream>
#include "array.h"
#include "checkInput.h"
using namespace std;


// function prototypes under
int showMenu();
void getVisitorInfo(int age[], string country[], double timeSpent[], int& numberOfVisitors, int maxVisitors);
bool checkPassword(string);
template<typename O> void sortCountries(string countries[], int size, O& out);
template<typename O> void showStatistic(double timeSpent[], int ages[], int numberOfVisitors, string countries[], O& out);
bool closeMuseum();
void saveVisitorData(ofstream& fout);

/***************************************************************************
Main function will store visitor data in arrays. The museum will take up to
100 but can be changed. Inside the main is an infinite loop to ask for user
response
***************************************************************************/
int main() {
    ofstream fileOut;
    string fileName;

    // Visitor Data
    const int MAX = 2;
    int ages[MAX];
    string countries[MAX];
    double timeSpent[MAX];
    int numberOfVisitors = 0;


    // Staff Data
    string correctPassword = "5678";
    // variable used to get return value from showMenu function
    int showMenuResponse;
    bool isPasswordValid = false;
    while(1) {
        showMenuResponse = showMenu();
        switch(showMenuResponse) {
            case(1):
                getVisitorInfo(ages, countries, timeSpent, numberOfVisitors, MAX);
                break;
            case(2):
                isPasswordValid = checkPassword(correctPassword);
                if(isPasswordValid == true) {
                    showStatistic(timeSpent, ages, numberOfVisitors, countries, cout);
                    if(closeMuseum() == true) {
                        saveVisitorData(fileOut);
                        showStatistic(timeSpent, ages, numberOfVisitors, countries, fileOut);
                        fileOut.close();
                        return 0; // end the program
                    }
                }
                else {
                    cout << "The password is wrong" << endl;
                    continue;
                }
                break; // break the switch statement
        }
    }
    return 0;
}
/***************************************************************************
This function will receive userinput from the menu and will only return 
either 1 or 2. Return 1 will tell main to get visitor data
information. Return 2 will tell main to ask for password
 *************************************************************************/
int showMenu() {
    int response; // create the variable that will return
    int min = 1, max = 2; // the minimum and maximum which will be passed into getInput

    string invalidMessage = "Invalid Choice. Enter 1 or 2: ";
    cout << "==========================================" << endl;
    cout << "1. Visitor" << endl;
    cout << "2. Staff" << endl;
    cout << "Enter your choice: ";
    response = getData<int>(min, max, invalidMessage);
    return response;
}

/***************************************************************************
 This function will take visitor information, country, their age, and time
 spent touring the museum. Ages is the array of visitor ages
 timeSpent is the array of hours spent
 countries is the list of countries where people are from
***************************************************************************/
void getVisitorInfo(int ages[], string countries[], double timeSpent[], int& numberOfVisitors, int maxVisitors) {
    if(numberOfVisitors == maxVisitors) { // return back to the main function if the nunmberOfVisitors hits the maximum
        cout << "We cannot take any more visitor information" << endl;
        return;
    }
    int minimumAge = 0, maximumAge = 200; 
    string invalidAgeMessage = "The age has to be between 0 and 200. Enter again: ";

    double minimumHours = 0.0, maximumHours = 10.0;
    string invalidHoursMessage = "The number of hours has to to be between 0 and 10.0: ";

    
    cout << "Enter your country: ";
    cin >> countries[numberOfVisitors];
    cout << "Enter your age: ";
    ages[numberOfVisitors] = getData<int>(minimumAge, maximumAge, invalidAgeMessage); // call the getData function with the min and max age input
    cout << "Enter the number of hours you explored: ";
    timeSpent[numberOfVisitors] = getData<double>(minimumHours, maximumHours, invalidHoursMessage); //call the getData function with the min and max hours input
    numberOfVisitors++; // increment the number of visitors
}
/***************************************************************************
This function will check if the right password was entered. Return true 
means the password is valid. Return false means it is invalid and will return
back to the menu
string correctPassword is the correct password
***************************************************************************/
bool checkPassword(string correctPassword) {
    string userInputPassword; // string that will take userinput
    cout << "Enter password: ";
    cin >> userInputPassword;
    if(userInputPassword == correctPassword) return true;
    return false;
}
/***************************************************************************
This function will sort the countries alphabetically and then the unique 
function will be called and check if the country has been repeated. No 
country repeats will be shown in statistics
countries[] is the current array of countries which will contain all the 
***************************************************************************/
template<typename O> void printCountries(string countries[], int numberOfVisitors, O& out) {
    string uniqueCountries[numberOfVisitors]; 
    int numberOfUniqueCountries; // used to store and call the unique array
    sort(countries, numberOfVisitors); // sort the countries by ascending order
    numberOfUniqueCountries = unique<string>(countries, uniqueCountries, numberOfVisitors);
    // numberOfUniqueCountries will store the number of unique countries and print out the right number of countries
    printOut(uniqueCountries, numberOfUniqueCountries, out);
}
/*******************************************************************
This function will display the 
timeSpent is the double array storing the visitor's hours
youngest is the youngest age from the ages array
oldest is the oldest age from the ages array
averageAge is the average age from the ages array
*****************************************************************/
template<typename O> void showStatistic(double timeSpent[], int ages[], int numberOfVisitors, string countries[], O& out) {
    if(numberOfVisitors == 0) {
        out <<  "The total number of visitors is 0 "<< endl;
        return; // return back to the previous function
    }
    
    int youngest = getLowest(ages, numberOfVisitors); // get the youngest age
    int oldest = getHighest(ages, numberOfVisitors); // get the oldest age
    double averageAge = getAvg<int>(ages, numberOfVisitors); // calculate the ages average

    int leastTimeSpent = getLowest(timeSpent, numberOfVisitors); // get the least time spent 
    int mostTimeSpent = getHighest(timeSpent, numberOfVisitors); // get the most time spent
    double timeSpentAvg = getAvg<double>(timeSpent, numberOfVisitors); // calculate the ages average
    
    out << endl;
    out << "The total number of visitors is " << numberOfVisitors << endl;
    out << "-------- The names of the countries of visitors --------" << endl;
    printCountries(countries, numberOfVisitors, out); // print a sorted list of countries (ascending) and only show the unique
    out << endl;
    out << "The age of the youngest visitor: " << ages[youngest] << endl;
    out << "The age of the oldest visitor: " << ages[oldest] << endl;
    out << "The average age of the visitors: " << double(averageAge) << endl;
    out << endl;
    out << "The shortest visit hours: " << timeSpent[leastTimeSpent] << endl;
    out << "The longest visit hours: " << timeSpent[mostTimeSpent] << endl;
    out << "The average visit hours: " << timeSpentAvg << endl;
    out << endl;
}
/***************************************************************************
This function will ask staff to continue or not
return true means the museum will close
return false means the museum will continue
***************************************************************************/
bool closeMuseum() {
    char ynResponse; // Yes No Response Char which will be passed into the 
    string invalidOptionMessage = "Invalid option. Enter Y/y or N/n: ";
    cout << "Do you want to close the museum? Y or N: ";
    ynResponse = getYN(invalidOptionMessage);
    switch(ynResponse) {
        case('Y'):
        case('y'):
            return true;
            break;
        default: // if the returned input is N or n
            return false;
            break;
    }
}
/***************************************************************************
This function will save all visitor information collected once staff close
the museum. It will ask for the date to be used as a filename with all 
visitor statistics will be stored in a txt file
fout is the ostream object created in main then passed into this function
which will out data into external file
***************************************************************************/
void saveVisitorData(ofstream& fout) {
    string date;
    string filename;
    cout << "Enter today's date: ";
    cin >> date;
    filename = date + ".txt";
    fout.open(filename.c_str());
}
