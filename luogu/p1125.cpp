#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//埃筛模版
vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) {
        is_prime[0] = false;
    }
    if (n >= 1) {
        is_prime[1] = false;
    }
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}


void solve() {
    string s;
    cin >> s;
    int mi = 100, ma = 0;
    for (int i = 0; i < 26; i++) {
        int cnt = ranges::count(s, 'a' + i);
        if (cnt == 0) {
            continue;
        }
        mi = min(mi, cnt);
        ma = max(ma, cnt);
    }
    int n = ma - mi;
    vector<int> primes = sieve(n);
    if (ranges::count(primes, n) == 1) {
        cout << "Lucky Word" << endl;
        cout << n << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}