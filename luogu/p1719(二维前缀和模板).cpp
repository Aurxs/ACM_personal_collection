#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector a(N + 1, vector<long long>(N + 1, 0));
    vector s(N + 1, vector<long long>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    long long ans = -1000000;
    for (int x1 = 1; x1 <= N; x1++)
        for (int y1 = 1; y1 <= N; y1++)
            for (int x2 = x1; x2 <= N; x2++)
                for (int y2 = y1; y2 <= N; y2++)
                    ans = max(ans, s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();
    return 0;
}