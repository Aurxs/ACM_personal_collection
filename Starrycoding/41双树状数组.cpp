#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int lowbit(long long x) {
    return x & -x;
}

void update(vector<long long> &v, int idx, long long val) {
    for (int i = idx; i < v.size(); i += lowbit(i)) {
        v[i] += val;
    }
}

long long sum(const vector<long long> &v, int idx) {
    long long res = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        res += v[i];
    }
    return res;
}

void range_add(vector<long long> &v1, vector<long long> &v2, int l, int r, long long val) {
    update(v1, l, val);
    update(v1, r + 1, -val);
    update(v2, l, val * (l - 1));
    update(v2, r + 1, -val * r);
}

long long prefix_sum(const vector<long long> &v1, const vector<long long> &v2, int idx) {
    return sum(v1, idx) * idx - sum(v2, idx);
}

long long range_sum(const vector<long long> &v1, const vector<long long> &v2, int l, int r) {
    return prefix_sum(v1, v2, r) - prefix_sum(v1, v2, l - 1);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 2, 0);
    vector<long long> t1(n + 2, 0);
    vector<long long> t2(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        range_add(t1, t2, i, i, a[i]);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            long long k;
            cin >> l >> r >> k;
            range_add(t1, t2, l, r, k);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << range_sum(t1, t2, l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}