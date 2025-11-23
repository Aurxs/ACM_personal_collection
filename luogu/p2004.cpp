#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector v(m + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[j][i];
        }
    }
    vector pre(m + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + v[j][i];
        }
    }
    long long ans = 0, x = 0, y = 0;
    for (int i = c; i <= n; i++) {
        for (int j = c; j <= m; j++) {
            long long temp = pre[i][j] - pre[i - c][j] - pre[i][j - c] + pre[i - c][j - c];
            if (temp > ans) {
                x = i - c;
                y = j - c;
                ans = max(ans, temp);
            }
        }
    }
    cout << x + 1 << " " << y + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}