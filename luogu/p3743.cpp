#include <iostream>
#include <vector>

using namespace std;

int check(double mid, double p, const vector<double> &a, const vector<double> &b) {
    double q = p * mid;
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] * mid <= b[i]) {
            continue;
        }
        sum += (a[i] * mid - b[i]);
    }
    return sum <= q;
}

int main() {
    int n;
    double p;
    double l = 0, r = 1e10, sum = 0;
    cin >> n >> p;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p) {
        cout << -1.000000 << endl;
        return 0;
    }
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid, p, a, b)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}