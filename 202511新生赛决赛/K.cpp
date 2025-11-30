#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> diff(n);
    diff[0] = 0;
    for (int i = 1; i < n; i++) {
        diff[i] = v[i] - v[i - 1];
    }
    sort(diff.begin(), diff.end());
    int d = v[n - 1] - v[0];
    for (int i = n - 1; i >= 0; i--) {
        cout << d << " ";
        d -= diff[i];
    }
}