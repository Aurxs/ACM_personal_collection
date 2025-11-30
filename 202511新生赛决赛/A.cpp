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
    int d = 0, ma = 0, mi = 100;
    for (int i = 0; i < n; i++) {
        if (v[i] > ma) ma = v[i];
        if (v[i] < mi) mi = v[i];
    }
    d = ma - mi;
    cout << 1 << " " << n << " " << d;
}