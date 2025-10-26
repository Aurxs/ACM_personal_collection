#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

bool cmp(const pair<double, double> &p1, const pair<double, double> &p2) {
    return p1.second / p1.first > p2.second / p2.first;
}

void solve() {
    int n, t;
    double ans = 0.00;
    cin >> n >> t;
    vector<pair<double, double> > v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    ranges::sort(v, cmp);
    for (const auto &[weight, value] : v) {
        if (t == 0) break;
        if (weight <= t) {
            ans += value;
            t -= weight;
        } else {
            ans += value / weight * t;
            t = 0;
        }
    }
    printf("%.2f\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}