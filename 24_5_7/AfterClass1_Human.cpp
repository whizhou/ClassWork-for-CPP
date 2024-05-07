#ifndef HUMAN
#define HUMAN
#include<iostream>
#include<string>
#include"creature.h"
using namespace std;

class Human: public Creature{
    public:
        Human(const char* _languages, const char* _sound, int _age);
        Human(const char* _languages, const Creature& _creature);
        Human(const Human& other);
        ~Human();
        Human& operator=(const Human& other);

        //print out info: "Human with age speak languages"
        void say()const;

        //add new_language to the end of languages, split by ','
        void studyLanguage(const char* new_language);
        //friend std::ostream& operator<<(std::ostream& os, const People& _people);
    private:
        char* languages;
};
#endif

#include <iostream>
#include <string.h>
using namespace std;

Human::Human(const char* _languages, const char* _sound, int _age) : Creature(_sound, _age) {
    int len = strlen(_languages);
    languages = new char[len + 1];
    strcpy(languages, _languages);
}
Human::Human(const char* _languages, const Creature& _creature) : Creature(_creature) {
    delete[] languages;
    int len = strlen(_languages);
    languages = new char[len + 1];
    strcpy(languages, _languages);
}
Human::Human(const Human& other) : Creature(other) {
    delete[] languages;
    int len = strlen(other.languages);
    languages = new char[len + 1];
    strcpy(languages, other.languages);
}
Human::~Human() {
    delete[] languages;
}
Human& Human::operator=(const Human& other) {
    Creature::operator=(other);
    delete[] languages;
    int len = strlen(other.languages);
    languages = new char[len + 1];
    strcpy(languages, other.languages);
    return *this;
}

//print out info: "Human with age speak languages"
void Human::say()const {
    cout << "Human with age " << getAge() << " speak " << languages << endl;
}

//add new_language to the end of languages, split by ','
void Human::studyLanguage(const char* new_language) {
    int len1 = strlen(languages), len2 = strlen(new_language);
    char* tmp = new char[len1 + len2 + 1];
    strcpy(tmp, languages);
    strcat(tmp, ",");
    strcat(tmp, new_language);
    delete[] languages;
    languages = tmp;
}
//friend std::ostream& operator<<(std::ostream& os, const People& _people);