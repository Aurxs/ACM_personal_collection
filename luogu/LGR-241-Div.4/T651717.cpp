#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int ans = 0, a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i <= a / 2; i++) {
        if (i > 10) continue;
        for (int j = 0; j <= b; j++) {
            for (int k = c / 2; k <= c; k++) {
                if (i + j + k == 0) continue;
                if (!(i <= j && k <= j)) continue;
                if (k > 0 && i * j > k * k) continue;
                ans++;
            }
        }
    }
    cout << ans;
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