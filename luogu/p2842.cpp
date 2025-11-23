#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(1005), f(100005, 1000000);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= w; j++) {
            f[j] = min(f[j], f[j - a[i]] + 1);
        }
    }
    cout << f[w] << endl;
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