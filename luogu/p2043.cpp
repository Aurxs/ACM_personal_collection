#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> prime(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

void solve() {
    int n;
    cin >> n;
    vector<int> primes = prime(n);
    vector<pair<int, int> > factors;
    for (int p: primes) {
        factors.emplace_back(p, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < factors.size(); j++) {
            int count = 0;
            int temp = i;
            if (factors[j].first > i) break;
            while (temp % factors[j].first == 0) {
                temp /= factors[j].first;
                count++;
            }
            factors[j].second += count;
        }
    }
    for (int i = 0; i < factors.size(); i++) {
        if (factors[i].second) {
            cout << factors[i].first << " " << factors[i].second << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();
    return 0;
}