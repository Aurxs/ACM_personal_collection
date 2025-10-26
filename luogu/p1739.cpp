#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>

using namespace std;

void solve() {
    string str;
    getline(cin, str, '@');
    stack<char> s;
    bool is_valid = true;
    for (char c : str) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty()) {
                is_valid = false;
                break;
            }
            s.pop();
        }
    }

    if (!s.empty()) {
        is_valid = false;
    }

    if (is_valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();
    return 0;
}