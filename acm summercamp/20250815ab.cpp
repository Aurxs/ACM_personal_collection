#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, b;
    cin >> s;
    cin >> b;

    char max_char = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == '1') {
            if (s[i] > max_char) {
                max_char = s[i];
            }
        }
    }

    if (max_char == 0) {
        cout << s << endl;
        return;
    }

    string new_s = "";
    new_s += max_char;

    bool remove = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == max_char && !remove && b[i] == '1') {
            remove = true;
            continue;
        }
        new_s += s[i];
    }

    if (new_s > s) {
        cout << new_s << endl;
    } else {
        cout << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}