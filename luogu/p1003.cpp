#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int T;
    cin >> T;
    vector<tuple<int, int, int, int>> carpets;

    for (int i = 0; i < T; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        carpets.emplace_back(a, b, x, y);
    }

    int n, m;
    cin >> n >> m;

    int ans = -1;
    for (int i = T - 1; i >= 0; i--) {
        auto [a, b, x, y] = carpets[i];
        if (n >= a && n <= a + x && m >= b && m <= b + y) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();
    return 0;
}