#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sq = 0;
    for (int i = 0; i <= n; i++) {
        if (i * i >= n) {
            sq = i;
            break;
        }
    }
    int a = n % sq;
    for (int i = a; i > 0; i--) {
        cout << i << " ";
    }
    int t = n / sq;
    for (int i = 1; i <= t; i++) {
        int k = sq * i + a;
        for (int j = 0; j < sq; j++) {
            cout << k << " ";
            k--;
        }
    }
}