#include <cmath>
class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}
    double getArea() { return a * b; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double getArea() { return acos(-1) * r * r; }
};