#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.first + a.second < b.first + b.second;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long> > a;
    for (int i = 0; i < n; i++) {
        long long w, s;
        cin >> w >> s;
        a.emplace_back(w, s);
    }
    ranges::sort(a, cmp);
    long long sum = 0, ans = -100000000;
    for (const auto &[w,s] : a) {
        ans = max(ans, sum - s);
        sum += w;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}