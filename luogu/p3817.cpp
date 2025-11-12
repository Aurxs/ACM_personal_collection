#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] - x << endl;
        return;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] + a[i - 1] > x) {
            ans += a[i] + a[i - 1] - x;
            if (a[i] < a[i] + a[i - 1] - x) {
                a[i] = 0;
                a[i - 1] -= x - a[i];
            }
            else a[i] -= a[i] + a[i - 1] - x;
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