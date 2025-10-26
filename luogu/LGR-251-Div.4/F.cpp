#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++) {
        set<long long> s;
        int t;
        cin >> t;
        for (int j = 0; j < n; j++) {
            s.insert(v[j] % t);
        }
        cout << s.size() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}