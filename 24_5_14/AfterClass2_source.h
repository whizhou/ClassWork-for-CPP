#include <cmath>

const double PI = acos(-1);

class Land {
public:
    virtual double calcEstate() { return 0; }
};

class Circle : public Land {
    double price, r;
public:
    Circle(double r, double p) : price(p), r(r) {}
    double calcEstate() { return price * PI * r * r; }
};

class Square : public Land {
    double price, a;
public:
    Square(double a, double p) : price(p), a(a) {}
    double calcEstate() { return price * a * a; }
};

class Accountant {
    double totalEstate = 0;
public:
    void DevelopEstate(Land *land) {
        totalEstate += land->calcEstate();
    }
    double CheckMoney() { return totalEstate; }
};