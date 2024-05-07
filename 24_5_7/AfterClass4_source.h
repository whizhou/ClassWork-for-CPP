#include <iostream>
using namespace std;

class Number {
    int x;
public:
    Number(int x) : x(x) {}
    Number &add(int rhs) {
        x += rhs;
        return *this;
    }
    Number &sub(int rhs) {
        x -= rhs;
        return *this;
    }
    void print() {
        cout << x << endl;
    }
};