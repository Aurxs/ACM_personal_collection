#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int check(int mid, int n, const vector<int> &a) {
    int pre = 0, cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] - pre < mid) {
            cnt++;
        } else pre = a[i];
    }
    return cnt;
}

void solve() {
    int s, n, m;
    cin >> s >> n >> m;
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, r = s;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, n, a) <= m) l = mid + 1, ans = mid;
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