#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int hh, mm;
    cin >> hh >> mm;
    int n = mm % 5;
    if (n == 3)
        cout << "0";
    else {
        if (n == 4)
            cout << "4";
        else if (n == 0)
            cout << "3";
        else if (n == 1)
            cout << "2";
        else if (n == 2)
            cout << "1";
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