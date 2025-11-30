#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned long long MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    unsigned long long cnta = 0, cntc = 0, cntm = 0, cntac = 0, cntcm = 0;
    unsigned long long cnt = 0;
    for (char i : s) {
        if (i == 'c') {
            cntc++;
            cntcm += cntm;
        }
        else if (i == 'm') {
            cntm++;
        }
        else if (i == 'A') {
            cnta++;
        }
        else if (i == 'C') {
            cntc++;
            cntac += cnta;
        }
        else if (i == 'a') {
            cnt += cntcm;
            cntac += cntc;
            cnta++;
        }
        else {
            cnt += cntac;
            cntcm += cntc;
            cntm++;
        }
        cnt = cnt % MOD;
        cout << cnt << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}