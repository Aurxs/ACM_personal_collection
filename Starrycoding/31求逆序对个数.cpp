#include <algorithm>
#include <iostream>
#include <vector>
using namespace std; // 2) 省去 std:: 前缀

static vector<long long> BIT; // 3) 全局树状数组（Fenwick），1-based，下标从 1 开始
//    用 long long 存前缀和，避免累加溢出

// 在秩 i 的位置加上 v：BIT[i] += v，并把它影响到的父节点都更新到
inline void add(int i, long long v) {
    // 4) 单点增加：O(log M)，M 为离散值个数
    for (int n = (int)BIT.size() - 1; // 5) n 为 BIT 的最大合法下标（size()-1，因为 1-based）
         i <= n;                      // 6) 只要还在树状数组范围内
         i += i & -i)                 // 7) i += lowbit(i)：向上跳到包含当前点的更大区间（父节点）
        BIT[i] += v;                  // 8) 把该区间（以 i 为右端点，长度 lowbit(i)）的和加上 v
}

// 返回前缀和 sum(1..i)：BIT[1] + ... + BIT[i]
inline long long sum(int i) {
    // 9) 前缀和查询：O(log M)
    long long s = 0;    // 10) 累加器（64 位，防溢出）
    for (; i > 0;       // 11) 从 i 往上跳父链，直到 0
           i -= i & -i) // 12) i -= lowbit(i)：去掉当前区间长度，跳到更小的祖先区间
        s += BIT[i];    // 13) 累加当前节点保存的区间和
    return s;           // 14) 返回前缀和
}

int main() {
    // 15) 主程序入口
    ios::sync_with_stdio(false); // 16) 关同步以加速 C++ 流
    cin.tie(nullptr);            // 17) 解绑 cin/cout，进一步加速

    int n;                      // 18) 数组长度
    if (!(cin >> n)) return 0;  // 19) 读失败直接退出（鲁棒）
    vector<long long> a(n);     // 20) 原数组（值最大可达 1e9，用 long long 也 OK）
    for (int i = 0; i < n; ++i) // 21) 读取 n 个数
        cin >> a[i];

    // --- 离散化：把大值域映射到紧凑的 1..M，仅保序（大小关系不变） ---
    vector<long long> vals = a;                           // 22) 拷贝一份用于构造“值表”
    sort(vals.begin(), vals.end());                       // 23) 排序：相同值会相邻
    vals.erase(ranges::unique(vals).begin(), vals.end()); // 24) 去重：得到严格递增的“去重值表”
    //     rank(x) = lower_bound(vals, x) - vals.begin() + 1

    BIT.assign((int)vals.size() + 1, 0); // 25) 初始化树状数组，长度 M+1（丢弃 0 号位，1-based）
    long long ans = 0;                   // 26) 逆序对计数（最大 ~ n*(n-1)/2，需 64 位）
    for (int i = 0; i < n; ++i) {
        // 27) 从左到右扫描 a[0..n-1]
        int r = int(ranges::lower_bound(vals, a[i]) - vals.begin()) + 1; // 28) 当前值 a[i] 的秩 r（1-based）
        long long le = sum(r);                                           // 29) le = 左侧（已处理 i 个）中 ≤ a[i] 的个数
        ans += i - le;                                                   // 30) 本位产生的逆序对 = 左侧总数 i - ≤a[i] 个数 le（即 >a[i]）
        add(r, 1);                                                       // 31) 把当前值计入频次，为后续元素服务
    }

    cout << ans << '\n'; // 32) 输出逆序对总数
    return 0;            // 33) 程序结束
}