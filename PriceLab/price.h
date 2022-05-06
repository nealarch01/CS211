#include <iostream>
using namespace std;
class Price {
    friend ostream& operator<<(ostream& out, const Price& p);
private:
    int dollar;
    int cent;
public:
    Price(int dollar, int cent);
    Price();
    Price operator+(Price& secondPrice);
    Price operator-(Price& secondPrice);
};