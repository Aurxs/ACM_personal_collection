#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
long long a, b, n, m, x[23][23], ma[23][23];

void horse(long long x, long long y) {
    ma[x][y] = 1;
    ma[x + 2][y + 1] = 1;
    ma[x + 2][y - 1] = 1;
    ma[x - 2][y + 1] = 1;
    ma[x - 2][y - 1] = 1;
    ma[x + 1][y + 2] = 1;
    ma[x + 1][y - 2] = 1;
    ma[x - 1][y + 2] = 1;
    ma[x - 1][y - 2] = 1;
}

void solve() {
    cin >> n >> m >> a >> b;
    a++;
    b++;
    n++;
    m++;
    horse(a, b);
    x[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (ma[i][j] == 0) {
                x[i][j] = x[i - 1][j] + x[i][j - 1];
            }
        }
    }
    long long ans = x[n][m];
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