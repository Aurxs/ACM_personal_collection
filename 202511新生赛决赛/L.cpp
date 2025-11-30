#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        cin >> q[i];
        cin >> w[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c = ((p[i] * m) + q[i] - 1) / q[i];
        if (w[i] < c) ans += c - w[i];
    }
    cout << ans;
}