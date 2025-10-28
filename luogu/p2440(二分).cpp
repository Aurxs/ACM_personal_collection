#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

long long check(int mid, const vector<int> &a) {
    long long cnt = 0;
    for (int i = 0; i <= a.size(); ++i) {
        cnt += a[i] / mid;
    }
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k) {
        cout << 0 << endl;
        return;
    }
    int l = 0, r = sum / k + 1;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, a) >= k) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}