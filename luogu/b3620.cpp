#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << stoi(s, nullptr, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}