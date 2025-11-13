#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

long long check(const vector<int> &a, int h) {
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > h) ans += a[i] - h;
    }
    return ans;
}

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long l = 0, r = 4e5;
    int ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(a, mid) < m) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}