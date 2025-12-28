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
    int ans = 0;
    if (s[0] == 'u') {
        ans++;
        s[0] = 's';
    }
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'u' && s[i - 1] == 'u') {
            ans++;
            s[i] = 's';
        }
    }
    if (s[s.size() - 1] == 'u') {
        ans++;
        s[s.size()] = 's';
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
