#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> v1(n, 0); //tian
    vector<long long> v2(m, 0); //qi
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    // sort(v1.begin(), v1.end());
    // long long ans = 0;
    // for (int i = 0; i < m; i++) {
    //     if(v1.empty()) break;
    //     auto it = upper_bound(v1.begin(), v1.end(), v2[i]);
    //     if (it != v1.end()) {
    //         ans += v2[i];
    //         v1.erase(it);
    //     }
    // }
    long long ans = 0;
    for (int i = 0, j = 0; i < m; i++) {
        if (v1[j] > v2[i]) {
            ans += v2[i];
            j++;
        }
        if (j == n) break;
    }
    cout << ans;
}