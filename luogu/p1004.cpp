#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector cube(n + 2, vector<int>(n + 2, 0));
    while (true) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) break;
        cube[x][y] = z;
    }

    long long ans = 0;
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