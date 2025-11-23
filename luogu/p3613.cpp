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
    int n, q, a, x, y, k;
    cin >> n >> q;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> x >> y >> k;
            mp[{x, y}] = k;
        } else {
            cin >> x >> y;
            cout << mp[{x, y}] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}