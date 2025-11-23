#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string f(string a, long long b) {
    string t = a[a.length() - 1] + a.substr(0, a.length() - 1);
    a = a + t;
    if (a.length() < b) a = f(a, b);
    return a;
}

void solve() {
    long long n;
    string s;
    cin >> s >> n;
    string ans = f(s, n);
    cout << ans[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}