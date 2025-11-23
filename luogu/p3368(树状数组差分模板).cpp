#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int lowbit(int n) {
    return n & -n;
}

void update(vector<long long> &v, int idx, int val) {
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

void solve() {
    int n, q; // n为数组大小，q为查询数量
    cin >> n >> q;
    vector<int> a(n + 1); // 输入数组（1-based）
    vector<long long> t(n + 1, 0); // 树状数组（1-based）

    // 读取输入数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 初始化树状数组
    for (int i = 1; i <= n; i++) {
        update(t, i, a[i] - a[i - 1]);
    }

    // 处理查询操作
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // 更新操作：将数组中某个位置的值增加指定值
            int x, y, k;
            cin >> x >> y >> k;
            update(t, x, k);
            update(t, y + 1, -k);
        } else {
            // 查询操作：计算区间和
            int x;
            cin >> x;
            cout << sum(t, x) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 提高输入输出效率
    cin.tie(nullptr); // 解除cin与cout的绑定

    solve(); // 调用解决函数

    return 0; // 程序正常结束
}