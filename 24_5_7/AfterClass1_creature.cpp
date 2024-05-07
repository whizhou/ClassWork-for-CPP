#ifndef CREATURE
#define CREATURE
#include<iostream>
using namespace std;
class Creature{
    public:
        Creature(const char* _sound, int _age);
        Creature(const Creature& other);
        virtual ~Creature();
        Creature& operator=(const Creature& other);

        //print out info: "Creature with age say sound"
        virtual void say()const;

        int getAge()const;
        //friend std::ostream& operator<<(std::ostream& os, const Animal& _animal);
    private:
        char* sound;
        int age;
};
#endif

#include <iostream>
#include <string.h>
using namespace std;

Creature::Creature(const char * _sound, int _age) : age(_age) {
    int len = strlen(_sound);
    sound = new char[len+1];
    strcpy(sound, _sound);
}

Creature::Creature(const Creature& other) : age(other.getAge()) {
    delete[] sound;
    int len = strlen(other.sound);
    sound = new char[len+1];
    strcpy(sound, other.sound);
}

Creature::~Creature() {
    delete[] sound;
}
Creature& Creature::operator=(const Creature& other) {
    age = other.getAge();
    delete[] sound;
    int len = strlen(other.sound);
    sound = new char[len+1];
    strcpy(sound, other.sound);
    return *this;
}

//print out info: "Creature with age say sound"
void Creature::say()const {
    cout << "Creature with age " << age << " say " << sound << endl;
}

int Creature::getAge()const { return age; }
//friend std::ostream& operator<<(std::ostream& os, const Animal& _animal);