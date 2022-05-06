#include <iostream>
#include <string>
using namespace std;

enum DIRECTION{NORTH, EAST, SOUTH, WEST};

class Car {
private:
    string carModel;
    int yearModel, mileage;
    DIRECTION direction;
    int x, y;
    // -x = West; +x = East; -y = South; y = North;
public:
    Car(string carModel, int yearModel, int mileage, DIRECTION direction, int x, int y); // constructor
    
    string getCarModel() const;
    int getYearModel() const;
    
    // movement functions
    void goForward(int distance);
    void goBack(int distance);
    void goRight();
    void goLeft();

    string getDirection() const;
    int getX() const;
    int getY() const;
    int getMileage() const;
};

// Constructor
Car::Car(string carModel, int yearModel, int mileage, DIRECTION direction, int x, int y) { // parameterized constructor
    this->carModel = carModel;
    this->yearModel = yearModel;
    this->mileage = mileage;
    this->direction = direction;
    this->x = x;
    this->y = y;
}

string Car::getCarModel() const {
    return carModel;
}

int Car::getYearModel() const {
    return yearModel;
}

void Car::goForward(int distance) {
    if (direction == NORTH) {
        y += distance;
    }
    else if(direction == EAST) {
        x += distance;
    }
    else if(direction == WEST) {
        x -= distance;
    }
    else if(direction == SOUTH) {
        y -= distance;
    }
    mileage += distance;
}

void Car::goBack(int distance) {
    if (direction == NORTH) {
        y -= distance;
    }
    else if (direction == EAST) {
        x -= distance;
    }
    else if (direction == SOUTH) {
        y += distance;
    }
    else if (direction == WEST) {
        x += distance;
    }
    mileage += distance;
}

void Car::goRight() {
    if (direction == NORTH) {
        direction = EAST;
    }
    else if (direction == EAST) {
        direction = SOUTH;
    }
    else if (direction == SOUTH) {
        direction = WEST;
    }
    else if (direction == WEST) {
        direction = NORTH;
    }
}

void Car::goLeft() {
    if (direction == NORTH) {
        direction = WEST;
    }
    else if (direction == EAST) {
        direction = NORTH;
    }
    else if (direction == SOUTH) {
        direction = EAST;
    }
    else if (direction == WEST) {
        direction = SOUTH;
    }
}

int Car::getX() const {
    return x;
}
int Car::getY() const {
    return y;
}
int Car::getMileage() const {
    return mileage;
}

string Car::getDirection() const {
    switch(direction) {
        case(0):
            return "North";
            break;
        case(1):
            return "East";
            break;
        case(2):
            return "South";
            break;
        case(3):
            return "West";
            break;
    }
}

void printInfo(const Car& c) {
    cout << c.getCarModel() << " (" << c.getYearModel() << ") is located at (" << c.getX() << ", " << c.getY() << ") facing " << c.getDirection() << ". It has " << c.getMileage() << " miles on it." << endl;
}

int main() {
    // Car c1("Camry", 2019);
    Car c1("Camry", 2019, 0, NORTH, 0, 0);
    cout << "Car Model: " << c1.getCarModel() << "\nYear Model: " << c1.getYearModel() << endl;

    c1.goForward(3);
    c1.goRight();
    c1.goForward(5);
    c1.goRight();
    c1.goForward(7);
    c1.goRight();
    c1.goForward(6);
    c1.goLeft();
    c1.goForward(1);
    // res should = (-1, -5) facing south

    // cout << c1.getCarModel() << "(" << c1.getYearModel() << ") is located at (" << c1.getX() << ", " << c1.getY() << ") facing " << c1.getDirection() << endl;
    printInfo(c1);
    return 0;
}