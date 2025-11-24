#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    ranges::sort(a);                                    // 起点时间升序排序
    priority_queue<int, vector<int>, greater<int> > pq; //维护一个最小堆，内容为终点时间
    long long ans = 0;
    // 因为起点时间升序排序，所以每次只需要维护一个大小为 k 的最小堆，堆顶元素即为当前最小的终点时间
    // 最长时间为 堆顶元素 - 当前起点时间
    for (int i = 1; i <= n; i++) {
        pq.push(a[i].second);
        if (pq.size() > k) pq.pop(); //踢出最小的终点时间
        if (pq.size() == k) {
            int ed = pq.top();
            if (ed > a[i].first) ans = max(ans, (long long)ed - a[i].first);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}