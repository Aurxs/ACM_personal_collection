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
    priority_queue<long long, vector<long long>, greater<> > q;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        q.push(t);
    }
    int ans = 0;
    while (q.size() > 1) {
        int temp = q.top();
        ans += q.top();
        q.pop();
        ans += q.top();
        temp += q.top();
        q.pop();
        q.push(temp);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}