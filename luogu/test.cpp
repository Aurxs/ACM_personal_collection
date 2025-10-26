#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        return;
    }
    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
        cout << 1 << endl;
        return;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}