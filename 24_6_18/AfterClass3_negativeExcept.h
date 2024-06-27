#include <stdexcept>
#include <math.h>

using namespace std;

double squareRoot(double x) {
    if (x < 0)
        throw invalid_argument("Negative value for square root");
    return sqrt(x);
}