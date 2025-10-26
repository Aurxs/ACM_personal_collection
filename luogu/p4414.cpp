#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> arr(3);
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    string s;
    cin >> s;
    if (s == "ABC")
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    else if (s == "ACB")
        cout << arr[0] << " " << arr[2] << " " << arr[1] << endl;
    else if (s == "BAC")
        cout << arr[1] << " " << arr[0] << " " << arr[2] << endl;
    else if (s == "BCA")
        cout << arr[1] << " " << arr[2] << " " << arr[0] << endl;
    else if (s == "CAB")
        cout << arr[2] << " " << arr[0] << " " << arr[1] << endl;
    else
        cout << arr[2] << " " << arr[1] << " " << arr[0] << endl;
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