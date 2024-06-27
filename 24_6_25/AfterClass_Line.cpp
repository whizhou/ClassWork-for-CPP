#include "Line.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

constexpr double zero = 1e-12;

line::line() : a(0), b(0), c(0) {}

line::line(const line &ob) : a(ob.a), b(ob.b), c(ob.c) {}

void line::set() {
    cin >> a >> b >> c;
}

void setpoint(line &ob1, line &ob2) {
    try {
        if (abs(ob1.a * ob2.b - ob1.b * ob2.a) < zero && abs(ob1.c - ob2.c) < zero)
            throw runtime_error("error: Two lines coincide");
        double x = (- ob1.c * ob2.b + ob2.c * ob1.b) / (ob1.a * ob2.b - ob1.b * ob2.a);
        double y = (- ob1.a * ob2.c + ob2.a * ob1.c) / (ob1.a * ob2.b - ob1.b * ob2.a);
        cout << "Intersection coordinates:(" << x << ',' << y << ')';
    }
    catch (runtime_error &e) {
        cout << e.what();
    }
}
