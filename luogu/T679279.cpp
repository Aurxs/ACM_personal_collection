#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    char c1, c2;
    int ans = -1;
    int n = s.size();
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) c2 = s[n - 1];
        else c2 = s[i - 1];
        c1 = s[i];
        if (c1 == c2) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
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