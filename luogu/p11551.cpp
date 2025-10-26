#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, a;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
        if (pq.size() == 1) continue;
        int temp = pq.top();
        pq.pop();
        cout << pq.top() << " ";
        pq.push(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}