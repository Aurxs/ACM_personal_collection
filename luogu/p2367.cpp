#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, x, y, z, ans = 1000;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> diff(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) diff[i] = a[i] - a[i - 1];
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + diff[i];
    }
    for (int i = 1; i <= n; i++) {
        ans = min(ans, v[i]);
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