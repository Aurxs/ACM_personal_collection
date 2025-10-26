#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> diff(n);
    diff[0] = a[0];
    for (long long i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }
    long long z = 0, f = 0;
    for (long long i = 1; i < n; i++) {
        if (diff[i] > 0) z += diff[i];
        else f += -diff[i];
    }
    long long ans1 = max(f, z);
    long long ans2 = abs(f - z) + 1;
    cout << ans1 << "\n" << ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}