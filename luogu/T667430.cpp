#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    string a;
    cin >> a;

    long long x = 0, y = 0;
    long long ans = 0;

    for (char c : a) {
        if (c == 'U')
            y++;
        else if (c == 'D')
            y--;
        else if (c == 'R')
            x++;
        else if (c == 'L')
            x--;
        ans = max(ans, abs(x) + abs(y));
    }

    long long dx = x;
    long long dy = y;

    if (dx != 0 || dy != 0) {
        long long temp_x = (k - 1) * dx;
        long long temp_y = (k - 1) * dy;

        for (char c : a) {
            if (c == 'U')
                temp_y++;
            else if (c == 'D')
                temp_y--;
            else if (c == 'R')
                temp_x++;
            else if (c == 'L')
                temp_x--;
            ans = max(ans, abs(temp_x) + abs(temp_y));
        }
    } else {
        cout << ans << endl;
        return;
    }

    cout << ans << endl;
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