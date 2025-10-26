#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (n == 2) {
        if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
            return;
        }
        if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
            cout << 1 << endl;
            return;
        }
        if (m==2) {
            cout << 1 << endl;
            return;
        }
        if (y1==y2) {
            cout << 3 << endl;
            return;
        }
        cout << 2 << endl;
        return;
    }
    if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        return;
    }
    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
        cout << 1 << endl;
        return;
    }
    if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
        if (x1 == x2) {
            if (abs(y2 - y1) % 2 == 0) {
                if (abs(y1 - y2) > (x1 - 1) * 2 && abs(y1 - y2) > (n - x1) * 2) {
                    cout << 3 << endl;
                    return;
                }
            } else {
                if (abs(x2 - x1) > m - y2 && abs(y2 - y1) > y2 - 1 && abs(x2 - x1) > m - y1 && abs(y2 - y1) > y1 - 1) {
                    cout << 3 << endl;
                    return;
                }
            }

        }
        if (y1 == y2) {
            if (abs(x2 - x1) % 2 == 0) {
                if (abs(x1 - x2) > (y1 - 1) * 2 && abs(x1 - x2) > (m - y1) * 2) {
                    cout << 3 << endl;
                    return;
                }
            } else {
                if (abs(x2 - x1) > n - x2 && abs(y2 - y1) > y1 - 1 && abs(x2 - x1) > n - x1 && abs(y2 - y1) > m - y1) {
                    cout << 3 << endl;
                    return;
                }
            }
        }
        cout << 2 << endl;
        return;
    }
    cout << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}