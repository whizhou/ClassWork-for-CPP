#include <iostream>

using namespace std;

class Base {
public:
    virtual void display1() {
        cout << "Base::display1()" << endl;
    }

    void display2() {
        cout << "Base::display2()" << endl;
    }
};

class Derived : public Base {
public:
    void display1() {
        cout << "Derived::display1()" << endl;
    }

    void display2() {
        cout << "Derived::Display2()" << endl;
    }
};