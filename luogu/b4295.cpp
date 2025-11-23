#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    vector<int> c;
    for (int i = 1; i <= x + y; i++) {
        c.emplace_back(i);
    }
    int i = 0;
    while (c.size() > x) {
        i = (i + k - 1) % c.size();
        c.erase(c.begin() + i);
    }
    sort(c.begin(), c.end());
    for (int i: c) {
        cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}