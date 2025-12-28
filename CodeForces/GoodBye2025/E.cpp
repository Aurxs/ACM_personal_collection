#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

long long up_div(long long a, long long b) {
    if (a == 0) return 0;
    return (a + b - 1) / b;
}

long long query(long long l, long long r) {
    if (l > r) return 0;
    cout << "? " << l << " " << r << endl;
    long long res;
    cin >> res;
    return res;
}

void solve() {
    long long n;
    cin >> n;
    long long L = 1, R = n;
    long long current_sum = query(1, n);
    while (L < R) {
        long long mid = L + (R - L) / 2;
        long long len_l = mid - L + 1;
        long long len_r = R - mid;
        long long sum_l = query(L, mid);
        long long sum_r = current_sum - sum_l;
        bool flag = (__int128) sum_l * len_r >= (__int128) sum_r * len_l;
        if (flag) {
            R = mid;
            current_sum = sum_l;
        } else {
            L = mid + 1;
            current_sum = sum_r;
        }
    }
    cout << "! " << current_sum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
