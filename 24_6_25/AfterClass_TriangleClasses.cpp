#include "TriangleClasses.h"
#include "Exception.h"
#include <cmath>

using namespace std;

constexpr double zero = 1e-12;

InputException::InputException() {
    // setError("the input number is negative error!");
}

ZeroException::ZeroException() {
    // serError("the divisor is zero!");
}

NoTriangleException::NoTriangleException() {
    // serError("Three numbers cannot form a triangle!");
}

Triangle::Triangle(double t1, double t2, double t3) : a(t1), b(t2), c(t3) {
    Exception e;
    if (a < 0 || b < 0 || c < 0) {
        e = InputException();
        e.setError("the input number is negative error!");
        throw e;
    }
    if (a < zero || b < zero || c < zero) {
        e = ZeroException();
        e.setError("the divisor is zero!");
        throw e;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        e = NoTriangleException();
        e.setError("Three numbers cannot form a triangle!");
        throw e;
    }
}

double Triangle::area() {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}