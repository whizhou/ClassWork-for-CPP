#include <string.h>

class base {
	char *name;
	int age;
public:
	base() : name(new char[0]), age(0) {}
	void setname(char arr[]) {
        delete[] name;
        name = new char[strlen(arr) + 1];
        strcpy(name, arr);
    }
	void setage(int age) { this->age = age; }
	char* getname() {
        return name;
    }
	int getage() { return age; }
};

class leader : virtual public base {
    char *job, *dep;
public:
    leader() : job(new char[0]), dep(new char[0]) {}
    void getter(char *arr) {
        delete[] job;
        job = new char[strlen(arr) + 1];
        strcpy(job, arr);
    }
    void setter(char *arr) {
        delete[] dep;
        dep = new char[strlen(arr) + 1];
        strcpy(dep, arr);
    }
    char *getjob() { return job; }
    char *getdep() { return dep; }
};

class engineer : virtual public base {
    char *pro, *maj;
public:
    engineer() : pro(new char[0]), maj(new char[0]) {}
    void getter(char *arr) {
        delete[] pro;
        pro = new char[strlen(arr) + 1];
        strcpy(pro, arr);
    }
    void setter(char *arr) {
        delete[] maj;
        maj = new char[strlen(arr) + 1];
        strcpy(maj, arr);
    }
    char *getprof() { return pro;}
    char *getmajor() { return maj; }
};

class chairman : public leader, public engineer {
public:
    chairman() {}
    // void setname(char *arr) { base::setname(arr); }
    // void setage(int age) { base::setage(age); }
    void setjob(char *arr) { leader::getter(arr); }
    void setdep(char *dep) { leader::setter(dep); }
    void setmajor(char *arr) { engineer::setter(arr); }
    void setprof(char *arr) { engineer::getter(arr); }
    // char* getname() { }
};