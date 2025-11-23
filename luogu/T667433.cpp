#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long sum = 0;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    long long mod = sum % n;
    long long avg = sum / n;
    long long ans = 0;
    long long modr = mod;

    for (int i = 0; i < n && modr > 0; i++) {
        if (a[i] > avg) {
            long long r = a[i] - avg;
            long long numr = min((long long) modr, r);
            a[i] -= numr;
            modr -= numr;
        }
    }
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - avg);
    }
    long long ans1 = (ans / 2) + mod;
    cout << ans1 << "\n";
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