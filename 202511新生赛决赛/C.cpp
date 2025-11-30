#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, q, k;
    cin >> n >> q;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k != 1) {
            v.push_back(k);
        }
    }
    for (int k = 0; k < q; k++) {
        long long a;
        cin >> a;
        if (v.empty()) {
            cout << "NO" << "\n";
            continue;
        }
        int i = 0, j = 0;
        long long c = v[0];
        bool found = false;
        int size = v.size();
        while (j < size) {
            if (c == a) {
                found = true;
                break;
            }
            else if (c < a) {
                j++;
                if (j < size) {
                    c *= v[j];
                }
            }
            else {
                if (i == j) {
                    j++;
                    i++;
                    if (j < size) {
                        c = v[j];
                    }
                }
                else {
                    c /= v[i];
                    i++;
                }
            }
        }
        if (found) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
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
