#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    const long zero = ranges::count(s, '0');
    const long one = ranges::count(s, '1');
    const long two = ranges::count(s, '2');
    //需要特判？是否重叠，不然影响-，需要补回-
    if (zero+one+two >= n) {
        cout << string(n,'-') << "\n";
        return;
    }
    vector<string> v(n, " ");
    for (int i = 0; i < zero; i++) {
        v[i] = "-";
    }
    for (int i = 0; i < one; i++) {
        v[n - i - 1] = "-";
    }
    for (long i = zero + two; i < n - one - two; i++) {
        v[i] = "+";
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == " ") {
            v[i] = "?";
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}