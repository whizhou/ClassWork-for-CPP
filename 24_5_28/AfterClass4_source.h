#include <algorithm>
#include <string>
#include <iostream>

template <typename T>
class Counter {
    struct Str {
        T str;
        int num = 0;
    };
    Str words[10000];
    int wordNum = 0;

public:
    void count(T s) {
        int cur = 0;
        while (cur < wordNum && s != words[cur].str)
            ++cur;
        if (cur == wordNum)
            words[wordNum++] = (Str) {s, 1};
        else
            ++words[cur].num;
    }
    static bool cmp(const Str& a, const Str& b) { return a.num > b.num || (a.num == b.num && a.str < b.str); }
    void sortCounter() {
        std::sort(words, words + wordNum, cmp);
    }
    void discard_less_than(int times) {
        int validWords = 0;
        for (int i = 0; i < wordNum; ++ i)
            if (words[i].num >= times)
                words[validWords++] = words[i];
        wordNum = validWords;
    }
    friend std::ostream& operator<<(std::ostream& os, Counter& counter) {
         counter.sortCounter();
        for (int i = 0; i < counter.wordNum; ++i)
            os << counter.words[i].str << ' ' << counter.words[i].num << std::endl;
        return os;
    }
};