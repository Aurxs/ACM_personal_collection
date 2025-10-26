#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    vector<int> n(3);
    for (int i = 0; i < 3; i++) {
        cin >> n[i];
    }
    sort(n.begin(), n.end());
    for (int i = 0; i < 3; i++) {
        cout << n[i] << " ";
    }
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