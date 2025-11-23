#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long t = -1, cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != t) {
            ans += cnt * (n - i);
            t = v[i];
            cnt = 1;
        } else cnt++;
    }
    cout << ans << "\n";
    return 0;
}