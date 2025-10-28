#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * @brief 计算整数的最低有效位。
 *
 * @param n 输入的整数。
 * @return int 返回最低有效位。
 */
int lowbit(int n) {
    return n & -n;
}

/**
 * @brief 在树状数组中更新指定位置的值。
 *
 * @param v 树状数组。
 * @param idx 要更新的位置（1-based）。
 * @param val 增加的值。
 */
void update(vector<long long> &v, int idx, int val) {
    for (int i = idx; i < v.size(); i += lowbit(i)) {
        v[i] += val;
    }
}

/**
 * @brief 计算树状数组中从1到指定位置的前缀和。
 *
 * @param v 树状数组。
 * @param idx 查询的结束位置（1-based）。
 * @return long long 返回前缀和。
 */
long long sum(const vector<long long> &v, int idx) {
    long long res = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        res += v[i];
    }
    return res;
}

/**
 * @brief 解决问题的主函数。
 *
 * 该函数读取输入数据，初始化树状数组，并处理若干查询操作。
 * 查询操作包括更新数组中的值和计算区间和。
 */
void solve() {
    int n, q; // n为数组大小，q为查询数量
    cin >> n >> q;
    vector<int> a(n + 1);          // 输入数组（1-based）
    vector<long long> t(n + 1, 0); // 树状数组（1-based）

    // 读取输入数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 初始化树状数组
    for (int i = 1; i <= n; i++) {
        update(t, i, a[i]);
    }

    // 处理查询操作
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // 更新操作：将数组中某个位置的值增加指定值
            int k, v;
            cin >> k >> v;
            update(t, k, v);
        }
        else {
            // 查询操作：计算区间和
            int l, r;
            cin >> l >> r;
            cout << sum(t, r) - sum(t, l - 1) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 提高输入输出效率
    cin.tie(nullptr);            // 解除cin与cout的绑定

    solve(); // 调用解决函数

    return 0; // 程序正常结束
}