#include <iostream>
#include <string>
using namespace std;
enum DIRECTION{NORTH, SOUTH, EAST, WEST};

int main() {
    DIRECTION direction;
    direction = WEST;
    cout << direction << endl;
    return 0;
}