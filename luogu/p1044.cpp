#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector dp(25, vector<int>(25, 0));
    for (int i = 0; i <= 20; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j) dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
            else dp[i][j] = dp[i - 1][j + 1];
        }
    }
    cout << dp[n][0] << endl;
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