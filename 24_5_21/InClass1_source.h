#include <string>
using namespace std;

class Object {
    string name;
public:
    Object() : name("Object") {}
    Object(string name) : name(name) {}
    string get() {
        return name;
    }
};

class Animal:public Object {
public:
    Animal() : Object("Animal") {}
    Animal(string name) : Object(name) {}
};

class Dog:public Animal {
public:
    Dog() : Animal("Dog") {}
};

class Cat:public Animal {
public:
    Cat() : Animal("Cat") {}
};

/*

* 一个Object对象
* 返回这个对象实例实际的类型名
* 例如： Object *obj = new Bus();
* 则instanceof(*obj) == "Bus"

*/

string instanceof(Object obj) {
    return obj.get();
}