#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int happy = 0, cnt = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            happy += 100;
        }

        if (a[i] == 1) {
            if (cnt % 2 == 1)
                happy += 50;
            else
                happy -= 30;
            cnt++;
        }
        cout << happy << endl;
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