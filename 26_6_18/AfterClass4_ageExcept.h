#include <iostream>
#include <stdexcept>

class Animal {
protected:
    int age;
public:
    Animal(int age) : age(age) {
        if (age < 0)
            throw std::invalid_argument("Age cannot be negative!");
    }
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    Dog(int age) : Animal(age) {}
    void makeSound() {
        std::cout << "Woof! Woof!\n";
    }
};

class Cat : public Animal {
public:
    Cat(int age) : Animal(age) {}
    void makeSound() {
        std::cout << "Meow! Meow!\n";
    }
};