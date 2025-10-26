#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int x, y, z;
    vector<tuple<int, int, int> > v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        v.emplace_back(z, x, y);
    }
    ranges::sort(v);
    double ans = 0;
    for (int i = 1; i < n; i++) {
        const auto &[z1,x1,y1] = v[i - 1];
        const auto &[z2,x2,y2] = v[i];
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
        ans += distance;
    }
    printf("%.3lf\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}