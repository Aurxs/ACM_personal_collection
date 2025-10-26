#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][0] = 1;
    }
    for (int x = 2; x <= m; x++) {
        dp[1][x] = 0;
        dp[0][x] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            if (j > i) {
                dp[i][j] = 0;
                continue;
            } else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    }
    cout << dp[n][m] << endl;
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