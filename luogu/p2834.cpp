#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    const int mod = 1e9 + 7;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector f(n + 1, vector<int>(w + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1; // 对于前i个数，和为0的方案数总是1（即一个都不选）
        for (int j = 1; j <= w; j++) {
            f[i][j] = f[i - 1][j]; // 先继承不选第i个物品的方案
            if (j >= a[i])
                f[i][j] = (f[i][j] + f[i][j - a[i]]) % mod;
        }
    }

    cout << f[n][w] << endl;
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