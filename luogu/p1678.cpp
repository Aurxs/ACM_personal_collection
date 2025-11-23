#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> sch(m);
    vector<int> stu(n);
    for (int i = 0; i < m; i++) cin >> sch[i];
    for (int i = 0; i < n; i++) cin >> stu[i];
    sort(sch.begin(), sch.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto e = lower_bound(sch.begin(), sch.end(), stu[i]);
        if (e != sch.end()) {
            int k = e - sch.begin();
            if (e != sch.begin()) ans += min(abs(sch[k - 1] - stu[i]), abs(sch[k] - stu[i]));
            else ans += abs(sch[k] - stu[i]);
        } else ans += abs(sch[m - 1] - stu[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}