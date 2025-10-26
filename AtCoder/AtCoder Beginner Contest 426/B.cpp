#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    char a = s[0];
    int cnt = count(s.begin(), s.end(), a);
    if (cnt == 1) cout << a;
    else {
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != a) cout << s[i];
        }
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}