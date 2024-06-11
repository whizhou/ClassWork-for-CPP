#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool Matched(const std::string & brackets, const int & length) {
    std::stack<char> s;
    for (const auto &bracket : brackets) {
        char c = bracket;
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else {
            if (s.empty())
                return 0;
            if ((c == ')' && s.top() == '(') || (c == ']' && s.top() == '[') || (c == '}' and s.top() == '{'))
                s.pop();
            else
                return 0;
        }
    }
    return s.empty();
}