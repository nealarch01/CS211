#include "price.h"
using namespace std;
Price::Price() {
    dollar = 0;
    cent = 0;
}
Price::Price(int dollar, int cent) {
    this->dollar = dollar;
    this->cent = cent;
}
Price Price::operator+(Price& secondPrice) {
    int newDollar;
    int newCent;
    newDollar = this->dollar + secondPrice.dollar;
    newCent = this->cent + secondPrice.cent;

    if(newCent >= 100) {
        newCent -= 100;
        newDollar += 1;
    }

    Price total(newDollar, newCent);
    return total; // returns the object
}
Price Price::operator-(Price& secondPrice) {
    int newDollar;
    int newCent;
    newDollar = this->dollar - secondPrice.dollar;
    newCent = this->cent - secondPrice.cent;
    if(newCent < 0) {
        newDollar -= 1;
        newCent = 100 + newCent;
    }
    Price diff(newDollar, newCent);
    return diff;
}
ostream& operator<<(ostream& out, const Price& p) {
    out << p.dollar;
    if (p.cent < 10) {
        out << ".0";
    }
    else {
        out << ".";
    }
    out << p.cent;  
    return out;
}