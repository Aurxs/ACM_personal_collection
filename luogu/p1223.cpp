#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i].first = i;
        cin >> v[i].second;
    }
    ranges::sort(v, cmp);
    double ans = 0;
    long long pre = 0;
    for (int i = 1; i <= n; i++) {
        ans += pre;
        pre += v[i].second;
    }
    ans /= n;
    for (int i = 1; i <= n; i++) {
        cout << v[i].first << " ";
    }
    cout << endl;
    printf("%.2lf\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}