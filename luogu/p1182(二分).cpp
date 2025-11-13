#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool check(const vector<long long> &a, long long mid, long long m) {
    long long pre = 0, d = 1; //d为段数，初始值应为1，下面每次切分会加一段
    for (long long i = 0; i < a.size(); i++) {
        if (a[i] > mid) return false;
        if (pre + a[i] <= mid) pre += a[i];
        else {
            d++;
            pre = a[i];
        }
    }
    if (d <= m) return true;
    else return false;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9;
    long long ans = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(a, mid, m)) {
            ans = mid; //因为mid是一个可能的值，所以应该放这里，而不是下面
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}