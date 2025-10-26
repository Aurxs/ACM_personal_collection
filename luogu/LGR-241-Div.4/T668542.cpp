#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    if (n == 2)
        cout << "Fail to pay.";
    else
        cout << a + b + c;
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