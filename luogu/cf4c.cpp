#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> name;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (name.find(s) == name.end()) {
            name.insert({s, 0});
            name[s]++;
            cout << "OK" << endl;
        } else {
            cout << s << name[s] << endl;
            name[s]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();
    return 0;
}