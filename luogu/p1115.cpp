#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    // long long n, ans = 0;
    // cin >> n;
    // vector<long long> v(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     cin >> v[i];
    // }
    // vector<long long> p(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     p[i] = p[i - 1] + v[i];
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j <= n; j++) {
    //         ans = max(ans, p[j] - p[i - 1]);
    //     }
    // }
    // cout << ans << endl;
    // TLE代码
    // dp做法
    long long n, ans = -100000, a, b;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a;
        if (i == 1) b = a;
        else b = max(a, a + b);
        ans = max(ans, b);
    }

    cout << ans << endl;
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