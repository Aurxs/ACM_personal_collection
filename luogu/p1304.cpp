#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> primes(int n) {
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }
    return prime;
}

vector<bool> is_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

void solve() {
    int n;
    cin >> n;
    vector<int> prime = primes(n + 1);
    vector<bool> is_prime = is_primes(n + 1);
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; prime[j] <= i / 2; j++) {
            int s = prime[j], e = i - prime[j];
            if (is_prime[e]) {
                cout << i << "=" << s << "+" << e << endl;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
