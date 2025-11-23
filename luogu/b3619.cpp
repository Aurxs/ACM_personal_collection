#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>

using namespace std;

void solve() {
    string dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s = "";
    int n, x;
    cin >> n >> x;
    while (n != 0) {
        s = dict[n % x] + s;
        n /= x;
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}