#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

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
    int n;
    cin >> n;
    vector<int> prime = sieve(n);
    long long temp = 0;
    int ans = 0;
    for (int p : prime) {
        if (temp + p <= n) {
            temp += p;
            cout << p << endl;
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
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