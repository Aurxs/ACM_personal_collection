#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            if (a[i] != a[i + 1]) {
                flag = false;
                break;
            }
        } else {
            if (a[i] == a[i + 1]) {
                flag = false;
                break;
            }
        }
    }
    if (flag) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}