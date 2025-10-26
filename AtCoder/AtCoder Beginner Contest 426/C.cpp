#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n, q, m = 0;
    cin >> n >> q;
    map<int, long long> mp;
    for (int i = 1; i <= n; ++i) {
        mp[i] = 1;
    }
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        long long cnt = 0;
        auto itend = mp.upper_bound(x);
        vector<int> v;
        for (auto it = mp.begin(); it != itend; ++it) {
            cnt += it->second;
            v.emplace_back(it->first);
        }
        if (cnt > 0) {
            mp[y] += cnt;
            for (int j : v) {
                mp.erase(j);
            }
        }
        cout << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}