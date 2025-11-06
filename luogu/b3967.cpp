#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    string a;
    int n;
    cin >> a;
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            bool flag = true;
            n = (j - i + 1) / 2;
            vector v(26, 0);
            for (int k = i; k <= j; k++) {
                v[a[k] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                if (v[k] > n) flag = false;
            }
            if (flag) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}