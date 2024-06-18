#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

int getElement(vector<int> arr, int k) {
    if (k >= arr.size())
        throw out_of_range("Index out of range");
    return arr.at(k);
}
