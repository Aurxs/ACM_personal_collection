#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v;

int check(int a) {
    int cnt = 0, t = -1e9;
    for (int i = 0; i < n; i++) {
        if (v[i] - t >= a) {
            cnt++;
            t = v[i];
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = 1e9 + 10;
    while (l < r - 1) {
        int mid = l + (r - l) / 2;
        if (check(mid) >= m) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}