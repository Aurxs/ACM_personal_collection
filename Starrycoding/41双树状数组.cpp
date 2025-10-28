#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
#include <string>

using namespace std;

// 低位运算：获取最后一个 1
int lowbit(int n) {
    return n & -n;
}

// 单点更新：在树状数组 t 上 idx 位置增加 val
void update(vector<long long> &t, int idx, long long val) {
    for (int i = idx; i < (int)t.size(); i += lowbit(i)) {
        t[i] += val;
    }
}

// 前缀和：查询树状数组 t 的 [1, idx] 和
long long sum(const vector<long long> &t, int idx) {
    long long res = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        res += t[i];
    }
    return res;
}

// 区间加：对区间 [l, r] 每个位置都 +k
void range_add(vector<long long> &t1, vector<long long> &t2, int l, int r, long long k) {
    // t1 维护差分，t2 维护带权差分
    update(t1, l, k);
    update(t1, r + 1, -k);
    update(t2, l, k * (l - 1));
    update(t2, r + 1, -k * r);
}

// 前缀和（原数组前缀）：利用两棵树状数组合成
long long prefix_sum(const vector<long long> &t1, const vector<long long> &t2, int x) {
    return sum(t1, x) * x - sum(t2, x);
}

// 区间和查询：[l, r] 的和
long long range_sum(const vector<long long> &t1, const vector<long long> &t2, int l, int r) {
    return prefix_sum(t1, t2, r) - prefix_sum(t1, t2, l - 1);
}

void solve() {
    int n, q; // n 为数组大小，q 为操作次数
    cin >> n >> q;

    // +2 以便安全更新到 r+1
    vector<long long> a(n + 2, 0);
    vector<long long> t1(n + 2, 0), t2(n + 2, 0); // 两棵树状数组

    // 读取初始数组，并用区间加初始化（等价于逐点赋值）
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) range_add(t1, t2, i, i, a[i]);

    // 操作：
    // op==1 l r k ：区间 [l,r] 全部 +k
    // op==2 l r   ：查询区间 [l,r] 的和
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            long long k;
            cin >> l >> r >> k;
            range_add(t1, t2, l, r, k);
        }
        else if (op == 2) {
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