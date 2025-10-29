#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

vector<long long> v;

int lowbit(int x) {
    return x & -x;
}

void update(int idx, int x) {
    for (int i = idx; i < v.size(); i += lowbit(i)) {
        v[i] += x;
    }
}

long long sum(int idx) {
    long long ans = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        ans += v[i];
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> val = a;
    ranges::sort(val);
    val.erase(ranges::unique(val).begin(), val.end());
    v.assign(val.size() + 1, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = int(ranges::lower_bound(val, a[i]) - val.begin()) + 1;
        long long p = sum(idx);
        ans += i - p;
        update(idx, 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}