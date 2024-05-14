#include <iostream>

using namespace std;

class A {
public:
    virtual void display() {
        cout << "A::display()" << endl;
    }
    virtual ~A() {
        cout << "A::~A()" << endl;
    }
};

class B :  virtual public A {
public:
    void display() {
        cout << "B::display()" << endl;
    }
    ~B() {
        cout << "B::~B()" << endl;
    }
};

class C : virtual public A {
public:
    void display() {
        cout << "C::display()" << endl;
    }
    ~C() {
        cout << "C::~C()" << endl;
    }
};

class D : public C {
public:
    void display() {
        cout << "D::display()" << endl;
    }
    ~D() {
        cout << "D::~D()" << endl;
    }
};

class E : public B, virtual public D {
public:
    void display() {
        cout << "E::display()" << endl;
    }
    ~E() {
        cout << "E::~E()" << endl;
    }
};