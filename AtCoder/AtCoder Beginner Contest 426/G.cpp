#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    int T;
    cin >> T;
    while (T--) {
        int l, r, c;
        cin >> l >> r >> c;
        vector<pair<long long, long long> > s(r - l + 1);
        for (int i = 0; i < r - l + 1; ++i) {
            s[i] = a[l - 1 + i];
        }
        vector<long long> dp(c + 1, 0);
        for (const auto &[w, v]: s) {
            for (int j = c; j >= w; --j) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
        cout << dp[c] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}