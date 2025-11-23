#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << "\n";
        } else {
            vector<long long> pre(n);
            pre[0] = 1;
            int temp1 = 1, temp2 = 0;
            for (int j = 1; j < n; j++) {
                if (j % 2 == 1) {
                    temp2 = n - temp1 + 1;
                    pre[j] = pre[j - 1] + temp2 - temp1;
                } else {
                    temp1 = j / 2 + 1;
                    pre[j] = n + 1 - temp2 + temp1 + pre[j - 1];
                }
            }
            cout << 1 << " ";
            for (int j = 1; j < n; j++) {
                cout << pre[j] - pre[j - 1] << " ";
            }
            cout << "\n";
        }
    }
}