#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    vector H(1e5 + 10, 0);
    int l, h, r;
    while (scanf("%d %d %d", &l, &h, &r) != EOF) {
        for (int i = l; i < r; i++) {
            H[i] = max(H[i], h);
        }
    }
    for (int i = 0, h = 0; i < 1e5 + 10; i++) {
        if (H[i] != h) {
            cout << i << " " << H[i] << " ";
            h = H[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}