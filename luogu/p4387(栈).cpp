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
    stack<int> st;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        st.push(a[i]);
        while (!st.empty() && st.top() == b[idx]) {
            st.pop();
            idx++;
        }
    }
    if (st.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}