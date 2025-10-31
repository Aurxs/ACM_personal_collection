#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    int l, n;
    cin >> n >> l;
    vector<pair<int, int> > m(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    vector dp(l + 1, 0);
    for (int i = 1; i <= n; i++) {
        int w = m[i].first;
        int v = m[i].second;
        for (int j = l; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[l] << endl;
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