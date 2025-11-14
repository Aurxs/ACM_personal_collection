#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool E(int a, int b, int c) {
    vector s={a,b,c};
    ranges::sort(s, std::greater<int>()); // 从大到小排序
    return s[0] >= 95 && s[1] >= 95 && s[2] >= 90;
}


void solve() {
    int n;
    cin >> n;
    int t = 0,y = 0;
    vector v(n,vector(3,0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        int a = v[i][0],b = v[i][1],c = v[i][2];
        if (a == b && b == c && a == 100) {
            t++;
            continue;
        }
        if (E(a,b,c)) {
            y++;
        }
    }
    cout << t << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}