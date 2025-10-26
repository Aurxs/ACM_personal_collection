#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(const tuple<string, int, int, int, int> &a, const tuple<string, int, int, int, int> &b) {
    const auto &[name1,y1,m1,d1,key1] = a;
    const auto &[name2,y2,m2,d2,key2] = b;
    if (y1 != y2) return y1 < y2;
    if (m1 != m2) return m1 < m2;
    if (d1 != d2) return d1 < d2;
    return key1 > key2;
}

void solve() {
    int n;
    string s;
    int a, b, c;
    cin >> n;
    vector<tuple<string, int, int, int, int> > v;
    for (int i = 0; i < n; i++) {
        cin >> s >> a >> b >> c;
        v.emplace_back(s, a, b, c, i);
    }
    ranges::sort(v, cmp);
    for (int i = 0; i < n; i++) {
        cout << get<0>(v[i]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}