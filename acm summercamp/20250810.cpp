#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int> > c(n + 1);
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p != 0) {
            c[p].push_back(i);
        }
    }

    vector<bool> dp(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int temp_dp;
        cin >> temp_dp;
        dp[temp_dp] = true;
    }

    for (int i = 0; i < x; ++i) {
        vector<int> to_dp;
        for (int j = 1; j <= n; ++j) {
            if (dp[j]) {
                for (int child: c[j]) {
                    to_dp.push_back(child);
                }
            }
        }
        for (int x: to_dp) {
            dp[x] = true;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}