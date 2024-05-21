#include "transport.hpp"

class Car : public Transport {
    double speed;
public:
    Car(double speed) : speed(speed) {}
    double travelTime(double distance) const {
        return distance / speed;
    }
    ~Car() {}
};

class Train : public Transport {
    double speed;
public:
    Train(double speed) : speed(speed) {}
    double travelTime(double distance) const {
        return distance / speed;
    }
    ~Train() {}
};