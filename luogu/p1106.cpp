#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>
#include <deque>

using namespace std;

void solve() {
    string n;
    int s, i;
    cin >> n >> s;
    while (s) {
        for (i = 0; n[i] <= n[i + 1];) {
            i++;
        }
        n.erase(i, 1);
        s--;
    }
    while (n[0] == '0' && n.size() > 1) {
        n.erase(0, 1);
    }
    cout << n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}