#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <bit>

using namespace std;

void solve() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    int t = x ^ y;
    int n = std::bit_floor((unsigned int) t);
    if (n <= l) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}