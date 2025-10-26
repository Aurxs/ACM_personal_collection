#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector v(m, vector(n + 2, 0)); //m列，n+2行,0-base
    for (int i = 1; i <= n; i++) {
        //i->行
        int a; //a->1-base
        char k;
        cin >> a >> k;
        if (k == 'R') {
            for (int j = a - 1; j <= m - 1; j++) {
                //j->列
                v[j][i] = 1;
            }
        } else {
            for (int j = a - 1; j >= 0; j--) {
                v[j][i] = 1;
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n + 1; i++) {
        bool f = false;
        for (int j = 0; j < m - 1; j++) {
            if (v[j][i] == 0 && v[j][i - 1] == 0) {
                f = true;
                break;
            }
        }
        if (!f) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
}