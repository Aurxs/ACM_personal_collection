#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> b(m, false);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        b[num - 1] = true;
        b[num] = true;
    }
    int ans = 0;
    vector<int> k;
    for (int i = 0; i < m; i++) {
        if (!b[i]) {
            ans++;
            k.emplace_back(i + 1);
        }
    }
    if (ans == 0)
        cout << "Accepted";
    else {
        cout << ans << endl;
        for (int i = 0; i < k.size(); i++) {
            cout << k[i] << " ";
        }
    }
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