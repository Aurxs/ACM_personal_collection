#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    int k, x;
    cin >> k >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) k--;
        if (k == 0) {
            cout << i + 1;
            return;
        }
    }
    if (k > 0) {
        cout << "Error";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}