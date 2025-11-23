#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m, ans = 0;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a);
    for (int i = 0; i < n; i++) {
        ans += upper_bound(a.begin() + i, a.end(), a[i] + m) - lower_bound(a.begin() + i, a.end(), a[i] + m);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}