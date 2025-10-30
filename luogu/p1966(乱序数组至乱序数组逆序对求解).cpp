#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 99999997;

struct Node {
    int val;
    int id;
};

bool cmp(const Node &a, const Node &b) {
    return a.val < b.val;
}

vector<int> BIT;

int lowbit(int n) {
    return n & -n;
}

void add(int idx, int val) {
    for (int i = idx; i < BIT.size(); i += lowbit(i)) {
        BIT[i] += val;
    }
}

int query(int idx) {
    int res = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        res += BIT[i];
    }
    return res;
}

//核心思想是将一个乱序数组排成另一个乱序数组
/*
举例说明
假设输入是：
a = [100, 300, 200]
b = [50, 60, 40]
第 1 步：记录原始值和原始索引
我们创建 Node 结构体来同时保存值和它们在原始数组中的索引 id。
a 序列：{(val:100, id:0), (val:300, id:1), (val:200, id:2)}
b 序列：{(val:50, id:0), (val:60, id:1), (val:40, id:2)}
第 2 步：按数值大小排序
对 a 和 b 的 Node 数组进行排序。
排序后的 a：{(100, 0), (200, 2), (300, 1)} (100是最小的，原索引0；200是第二小，原索引2；...)
排序后的 b：{(40, 2), (50, 0), (60, 1)} (40是最小的，原索引2；50是第二小，原索引0；...)
第 3 步：建立 p 映射关系（核心）
我们遍历排序后的这两个数组，从 i = 0 到 n-1。
当 i = 0 时 (处理两个数组中最小的数):
a 中最小的数是 100，它的原始索引是 a[0].id = 0。
b 中最小的数是 40，它的原始索引是 b[0].id = 2。
匹配规则：a 中最小的数 (100) 应该和 b 中最小的数 (40) 配对。这意味着，100 最终应该被移动到 40 所在的位置，也就是索引 2。
记录映射：100 的原始索引是 0，它的目标位置是 2。所以我们记录 p[0] = 2。
当 i = 1 时 (处理两个数组中第二小的数):
a 中第二小的数是 200，它的原始索引是 a[1].id = 2。
b 中第二小的数是 50，它的原始索引是 b[1].id = 0。
匹配规则：200 应该和 50 配对，移动到 50 所在的位置，也就是索引 0。
记录映射：200 的原始索引是 2，它的目标位置是 0。所以我们记录 p[2] = 0。
当 i = 2 时 (处理两个数组中最大的数):
a 中最大的数是 300，它的原始索引是 a[2].id = 1。
b 中最大的数是 60，它的原始索引是 b[2].id = 1。
匹配规则：300 应该和 60 配对，移动到 60 所在的位置，也就是索引 1。
记录映射：300 的原始索引是 1，它的目标位置是 1。所以我们记录 p[1] = 1。
最终结果
经过这三步，我们得到的 p 数组是 p = [2, 1, 0]。
这个 p 数组告诉我们：
原 a[0] 要去位置 2
原 a[1] 要去位置 1
原 a[2] 要去位置 0
现在问题就变成了：把一个有序的索引序列 0, 1, 2 变成目标序列 2, 1, 0，需要多少次交换？这正是计算序列 p 的逆序对数量。
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].val;
        a[i].id = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].val;
        b[i].id = i;
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[a[i].id] = b[i].id; //原本在 a 序列中索引为 a[i].id 的那个元素，需要移动到最终位置 b[i].id
    }

    // 使用树状数组计算 p 的逆序对
    BIT.assign(n + 1, 0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int r = p[i] + 1; // 目标位置，转为 1-based，不需要搜索，因为没有使用离散化，且p本身有序
        // 已处理的元素总数 i
        // 已处理的元素中 <= p[i] 的个数
        int le = query(r);
        // 逆序对数量 = 已处理的元素中 > p[i] 的个数
        ans = (ans + i - le) % MOD;
        add(r, 1);
    }

    cout << ans << endl;

    return 0;
}