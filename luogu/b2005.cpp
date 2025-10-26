#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    cout << "  " << s << "  " << endl;
    cout << " " << s << s << s << " " << endl;
    cout << s << s << s << s << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}