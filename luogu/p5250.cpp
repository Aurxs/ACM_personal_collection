#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

set<long long> s;

void solve() {
    int n, a;
    long long b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a == 1) {
            auto k = s.find(b);
            if (k == s.end()) {
                s.insert(b);
            } else {
                cout << "Already Exist" << "\n";
            }
        } else {
            if (s.empty()) {
                cout << "Empty" << "\n";
                continue;
            }
            auto k = s.find(b);
            if (k != s.end()) {
                cout << b << "\n";
                s.erase(k);
            } else {
                auto it = s.lower_bound(b);
                if (it == s.begin()) {
                    cout << *it << "\n";
                    s.erase(it);
                } else if (it == s.end()) {
                    cout << *(--it) << "\n";
                    s.erase(it);
                } else {
                    auto p = prev(it);
                    if (*it - b < b - *p) {
                        cout << *it << "\n";
                        s.erase(it);
                    } else {
                        cout << *p << "\n";
                        s.erase(p);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}