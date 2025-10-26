#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    string n;
    cin >> n;
    int len = n.length();
    if (len == 1) cout << "Yes";
    else {
        for (int i = len - 1; i > 0; i--) {
            if (n[i]!='0') {
                cout << "No";
                return;
            }
        }
        cout << "Yes";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}