#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    const int mod = 1e9 + 7;
    vector<int> a(n + 1), f(w + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - a[j] < 0) continue;
            f[i] += f[i - a[j]];
            f[i] %= mod;
        }
    }
    cout << f[w] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();

    return 0;
}