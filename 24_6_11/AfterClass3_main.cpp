#include <queue>
#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        queue<int> q1;
        priority_queue<int> q2;
        for (int i = 0; i < n; ++ i) {
            int x; cin >> x;
            q1.push(x), q2.push(x);
        }
        int ans = 0;
        while (true) {
            if (k--) {
                if (q1.front() == q2.top())
                    q1.pop(), q2.pop(), ++ ans;
                else
                    q1.push(q1.front()), q1.pop();
            } else {
                if (q1.front() == q2.top()) {
                    cout << ans + 1 << endl;
                    break;
                } else {
                    q1.push(q1.front()), q1.pop();
                    k = q1.size() - 1;
                }
            }
        }
    }
}