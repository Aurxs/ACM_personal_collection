#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * @brief 解决特定问题的函数。
 *
 * 该函数读取输入数据，处理一系列查询，输出每个查询的结果。
 * 输入包括一组点的坐标和若干查询区间，输出每个区间内的值的总和。
 */
void solve() {
    int n, q; // n为点的数量，q为查询的数量
    cin >> n >> q;

    // 存储点的坐标对 (x, y)
    vector<pair<long long, long long> > v;
    v.reserve(n); // 预分配空间以提高性能
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y; // 读取点的坐标
        v.emplace_back(x, y);
    }

    // 按x坐标排序
    sort(v.begin(), v.end());

    // idx存储唯一的x坐标，val存储对应的y值的累加和
    vector<long long> idx;
    vector<long long> val;
    idx.reserve(n);
    val.reserve(n);
    for (long long i = 0; i < v.size(); i++) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            idx.push_back(v[i].first); // 添加新的x坐标
            val.push_back(v[i].second); // 添加对应的y值
        } else {
            val.back() += v[i].second; // 累加相同x坐标的y值
        }
    }

    // 计算前缀和数组
    vector<long long> prefix(val.size() + 1, 0);
    for (long long i = 0; i < val.size(); i++) {
        prefix[i + 1] = prefix[i] + val[i]; // 前缀和计算
    }

    // 处理每个查询
    while (q--) {
        long long l, r;
        cin >> l >> r; // 读取查询区�� [l, r]

        // 找到区间的左右边界在idx中的位置
        l = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
        r = upper_bound(idx.begin(), idx.end(), r) - idx.begin();

        // 计算区间内的值的总和
        long long ans = prefix[r] - prefix[l];
        cout << ans << "\n"; // 输出结果
    }
}

int main() {
    ios_base::sync_with_stdio(false); // 提高输入输出效率
    cin.tie(nullptr); // 解除cin与cout的绑定

    solve(); // 调用解决函数

    return 0; // 程序正常结束
}