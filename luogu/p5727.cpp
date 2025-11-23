#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> a;
    int n;
    cin >> n;
    a.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            a.push_back(n);
        } else {
            n = n * 3 + 1;
            a.push_back(n);
        }
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}