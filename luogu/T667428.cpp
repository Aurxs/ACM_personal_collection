#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    long long y, m, d;
    string w;
    cin >> y >> m >> d >> w;
    long long y1, m1, d1;
    cin >> y1 >> m1 >> d1;
    if (d1 < d) {
        d1 += 30;
    }
    long long md = d1 - d;
    long long dsum = md %= 5;
    vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int start = 0;
    for (int i = 0; i < 5; i++) {
        if (week[i] == w) {
            start = i;
            break;
        }
    }
    cout << week[(start + dsum) % 5] << endl;
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
