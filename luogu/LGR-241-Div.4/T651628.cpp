#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    x--;
    vector a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int c;
    cin >> c;
    int need = 0;
    if (n == 1) {
        cout << "up" << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        int temp_max = 0, temp_mim = 101;
        for (int j = 0; j < n; j++) {
            if (j == x) continue;
            int t = a[j][i];
            temp_max = max(t, temp_max);
            temp_mim = min(t, temp_mim);
        }
        if (a[x][i] >= temp_max || a[x][i] <= temp_mim) {
            need++;
        }
        if (temp_max - temp_mim <= 1) {
            cout << "up" << endl;
            return;
        }
    }
    if (need > c) {
        cout << "up" << endl;
    } else
        cout << "down" << endl;
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