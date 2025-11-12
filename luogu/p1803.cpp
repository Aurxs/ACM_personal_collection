#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= idx) {
            ans++;
            idx = a[i].second;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}