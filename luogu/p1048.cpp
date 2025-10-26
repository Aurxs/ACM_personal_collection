#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    int time, n;
    cin >> time >> n;
    vector<pair<int, int>> m(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    vector dp(n + 1, vector<int>(time + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= time; j++) {
            if (j < m[i].first)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - m[i].first] + m[i].second);
        }
    }
    cout << dp[n][time] << endl;
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