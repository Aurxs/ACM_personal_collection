#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<long long> S(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        S[i] = S[i + 1] + a[i];
    }
    vector<long long> dp(n + 2, 0);
    dp[n] = 0;
    long long M = S[n] + dp[n];
    for (int i = n - 1; i >= 1; --i) {
        long long a1 = -S[i + 1];
        long long a2 = a[i] - S[i + 1] + M;
        dp[i] = max(a1, a2);
        M = max(M, S[i] + dp[i]);
    }
    cout << dp[1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
