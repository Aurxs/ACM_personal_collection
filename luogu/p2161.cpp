#include <iostream>
#include <vector>
using namespace std;

vector<long long> v; //维护st

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

int main() {
    int n, ans = 0;
    cin >> n;
    vector<long long> t(2e5 + 10); //维护ed
    v.resize(2e5 + 10);
    for (int i = 1; i <= n; i++) {
        char temp;
        cin >> temp;
        if (temp == 'A') {
            int st, ed, ans1 = 0;
            cin >> st >> ed;
            //从后往前搜，找到第一个符合(st >= ed_old)的日程，即第一个末尾时间不大于新日程开始时间的日程
            while (true) {
                // 利用树状数组，快速查出所有开始时间 st_old <= ed 的日程总数 k
                int k = sum(ed);
                if (k == 0) break;
                // 我们要找的重叠日程，它的开始时间 st_old 必须满足 <= ed。
                // 为了尽快判断，我们先找一个满足 st_old <= ed 的日程中，开始时间最晚（最大）的那一个。
                // 下面这个 while 循环是在用“二分查找”的方法，在树状数组上快速定位这个最晚的开始时间。
                // 你可以把它理解成一个黑盒：它能高效地找到第 k 个被标记的开始时间点在哪里。
                int l = 1, r = ed, idx = 0;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (sum(mid) < k) {
                        idx = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                int pos = idx + 1; // 要删除的位置，1-base
                // 我们已经满足了重叠的第一个条件 st_old <= ed (因为 pos <= ed)。
                // 现在检查第二个条件：st <= ed_old
                // t[pos] 就是这个日程的结束时间 ed_old
                if (t[pos] >= st) {
                    // 两个条件都满足！说明日程 [pos, t[pos]] 和新日程 [st, ed] 重叠了。
                    update(pos, -1);
                    ans1++; //删除数+1
                    ans--;  //总日程数-1
                }
                else {
                    // 如果连这个开始时间最晚的都不满足第二个条件，
                    // 那么其他开始时间更早的，也肯定不会满足。
                    // 所以可以直接确定，没有更多重叠的了。
                    break;
                }
            }
            update(st, 1); //将新日程加入至树状数组
            t[st] = ed;    //记录ed
            ans++;         //总日程数+1
            cout << ans1 << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}