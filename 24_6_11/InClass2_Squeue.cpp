#ifndef __SQUEUE__
#define __SQUEUE__

#include <iostream>
#include <stack>
using namespace std;

class Squeue {
    private:
        stack<int> s1; // The stack used for data storage.
        stack<int> s2; // The stack used for supporting operation "Pop" and "Front".
        
    public:
        int Size() const; // Get the size of Squeue.
        bool Empty() const; // Judge whether Squeue is empty.
        void Push(const int &ele); // Push operation of Squeue.
        void Pop(); // Pop operation of Squeue.
        int Front(); // Get the first element of Squeue, return 0 if empty.
        int Back() const; // Get the last element of Squeue, return 0 if empty.
        
        friend void DisplaySqueue(Squeue &sq); // Notice: You NEED NOT to implement this function.
};

#endif

#include "SQueue.h"

int Squeue::Size() const { return s1.size(); }

bool Squeue::Empty() const { return s1.empty(); }

void Squeue::Push(const int &ele) { s1.push(ele); }

void Squeue::Pop() {
    while (! s1.empty())
        s2.push(s1.top()), s1.pop();
    if (! s2.empty())
        s2.pop();
    while (! s2.empty())
        s1.push(s2.top()), s2.pop();
}

int Squeue::Front() {
    while (! s1.empty())
        s2.push(s1.top()), s1.pop();
    int front_ans = s2.empty() ? 0 : s2.top();
    while (! s2.empty())
        s1.push(s2.top()), s2.pop();
    return front_ans;
}

int Squeue::Back() const {
    return s1.empty() ? 0 : s1.top();
}
