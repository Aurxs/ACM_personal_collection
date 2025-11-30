#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> e(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> e[i];
    }
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    vector dp(n + 1, vector<long long>(2, 0));
    dp[1][0] = e[1];
    dp[1][1] = 0;
    if (n > 1) {
        dp[2][0] = 0;
        dp[2][1] = e[2];
    }
    for (int i = 3; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1] + e[i];
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + e[i];
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
