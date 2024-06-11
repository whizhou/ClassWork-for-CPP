#include <deque>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    int n; cin >> n;
    int k;
    string str;
    deque<pair<int, string>> q;
    for (int i = 0; i < n; ++ i) {
        cin >> k >> str;
        for (auto i = q.begin(); i != q.end(); ++ i)
            if (i->first == k) {
                q.erase(i);
                q.push_front(pair<int, string>(k, str));
                str = "indeque";
                break;
            }
        if (str != "indeque")
            q.push_back(pair<int, string>(k, str));
    }
    for (const auto &i: q)
        cout << i.first << ": " << i.second << endl;
}