#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b || a == c || b == c) cout << "Report";
    else if (d == a || d == b || d == c) {
        if (d == a) cout << "A";
        else if (d == b) cout << "B";
        else cout << "C";
    } else {
        vector v = {a, b, c};
        ranges::sort(v);
        if (v[1] == a) cout << "A";
        else if (v[1] == b) cout << "B";
        else cout << "C";
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}