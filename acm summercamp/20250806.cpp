#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000;
const int MAXN = 1000001;

int ans[MAXN];

void precompute() {
    ans[1] = 1;
    ans[2] = 3;
    for (int i = 2; i < MAXN; ++i) {
        ans[i] = (ans[i - 1] * 2) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << ans[N] << "\n";
    }

    return 0;
}