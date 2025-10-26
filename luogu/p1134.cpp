#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
        while (ans % 10 == 0)
            ans /= 10;
        ans %= 10000000000;
    }
    cout << ans % 10;
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