#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<vector<int>> adj;
vector<int> a;
vector<bool> visited;
int temp_max;

void dfs(int u) {
    visited[u] = true;
    temp_max = max(temp_max, a[u]);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        visited.assign(n + 1, false);
        temp_max = 0;
        dfs(i);
        ans.push_back(temp_max);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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