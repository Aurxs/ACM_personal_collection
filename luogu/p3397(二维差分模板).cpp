#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    int x1, y1, x2, y2;
    cin >> n >> m;
    vector diff(n + 2, vector(n + 2, 0));
    for (int i = 1; i <= m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }
    vector a(n + 2, vector(n + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = diff[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}