#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector a(n + 2, vector(m + 2, 0));
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cnt = 0;
            if (a[i][j] == -1) continue;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    if (a[i + dx][j + dy] == -1) {
                        cnt++;
                    }
                }
            }
            a[i][j] = cnt;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == -1) {
                cout << 'B' << " ";
            }
            else {
                cout << a[i][j] << " ";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}