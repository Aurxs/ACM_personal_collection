#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> f(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        for (int i = l - 1; i < r; i++) {
            f[i]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (f[i] % 2 == 1) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();
    return 0;
}