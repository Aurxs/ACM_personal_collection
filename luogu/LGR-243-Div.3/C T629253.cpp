#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, k, h, x = 0;
    cin >> n >> m >> k >> h;
    priority_queue<long long, vector<long long>, greater<> > pq;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    for (int i = 0; i < k; i++) {
        x = pq.top();
        pq.pop();
        pq.push(x + h);
    }
    for (int i = 0; i < m; i++) {
        x = pq.top();
        pq.pop();
        pq.push(x + 1);
    }
    cout << pq.top() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}