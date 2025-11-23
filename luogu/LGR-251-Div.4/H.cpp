#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    vector v(x, vector<char>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < y; i++) {
        int pre = x - 1;
        for (int j = x - 1; j >= 0; j--) {
            if (isupper(v[j][i])) {
                if (pre != j) {
                    v[pre][i] = v[j][i];
                    v[j][i] = '.';
                }
                pre--;
            } else if (v[j][i] == '-') {
                pre = j - 1;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}