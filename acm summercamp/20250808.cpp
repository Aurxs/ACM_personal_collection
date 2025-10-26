#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        if (val > 0) {
            pq.push(val);
        }
    }

    long long ans = 0;
    vector<long long> temp_k;

    while (pq.size() >= k) {
        for (int i = 0; i < k; i++) {
            temp_k.push_back(pq.top());
            pq.pop();
        }
        long long x = temp_k.back();
        long long y = 0;
        if (!pq.empty()) {
            y = pq.top();
        }
        long long rounds = 1;
        if (x > y) {
            rounds = x - y;
        }
        ans += rounds;
        for (long long val : temp_k) {
            if (val - rounds > 0) {
                pq.push(val - rounds);
            }
        }
        temp_k.clear();
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}