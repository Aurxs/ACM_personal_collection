#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, string> &p1, const pair<int, string> &p2) {
    if (p1.second.length() != p2.second.length()) {
        return p1.second.length() < p2.second.length();
    }
    return p1.second < p2.second;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, string> > a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i - 1].second;
        a[i - 1].first = i;
    }
    ranges::sort(a,cmp);
    cout << a[n-1].first << endl << a[n-1].second << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}