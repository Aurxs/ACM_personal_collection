#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > adj;

void solve() {
    int n;
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1;i <= n;i++) {
    //     cout << i << ":\n";
    //     for (int j = 0;j < adj[i].size();j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<long long> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        // cout << i << ":";
        for (int j = 0; j < adj[i].size(); j++) {
            int k = adj[i][j];
            long long s = adj[k].size() - 1;
            // cout << s << "\n";
            ans[i] += s;
        }
    }
    long long midx = 0, m = -1;
    for (int i = 1; i <= n; i++) {
        if (ans[i] >= m) {
            midx = i;
            m = ans[i];
        }
    }
    cout << midx << " " << ans[midx] << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}