#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    for (int m = 0; m < n; m++) {
        int temp_ans = dp1[m] + dp2[m] - 1;
        ans = max(temp_ans, ans);
    }
    cout << n - ans;
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