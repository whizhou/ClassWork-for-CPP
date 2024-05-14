class Shape {
public:
    virtual double GetArea() { return 0; }
    virtual double GetPerim() { return 0; }
};

class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}
    double GetArea() { return a * b; }
    double GetPerim() { return (a + b) * 2; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double c) : r(c) {}
    double GetArea() { return PI * r * r; }
    double GetPerim() { return 2 * PI * r; }
};