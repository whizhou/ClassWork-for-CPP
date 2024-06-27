#include <stdexcept>
#include <string>

using std::string;

class StringHandler {
    string str;
public:
    void setString(const string &s) {
        str = s;
    }
    char getCharAt(size_t index) {
        if (index >= str.size())
            throw std::out_of_range("Index out of range!");
        return str[index];
    }
};