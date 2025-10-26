#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

// 高精度加法 a + b
vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int carry = 0; // 进位
    for (int i = 0; i < a.size() || i < b.size() || carry; ++i) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % 10);
        carry /= 10;
    }
    return c;
}


void solve() {
    int n;
    cin >> n;
    vector v(n + 1, vector<int>());
    v[0] = {1};
    v[1] = {1};
    for (int i = 2; i <= n; i++) {
        v[i] = add(v[i - 1], v[i - 2]);
    }
    if (n == 0) cout << 0 << endl;
    else {
        for (int i = v[n].size() - 1; i >= 0; i--) {
            cout << v[n][i];
        }
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