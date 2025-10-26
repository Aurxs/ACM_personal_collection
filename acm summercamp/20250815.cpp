#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int length;
    cin >> length;
    vector<int> arr(length);
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    bool ans = true;
    int res = arr[1] - arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] - arr[i - 1] != res) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}