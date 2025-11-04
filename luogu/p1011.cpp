#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    long long a, m;
    int n, x;
    if (!(cin >> a >> n >> m >> x)) return 0;

    if (x == n) {
        cout << 0 << endl;
        return 0;
    }
    if (n <= 2) {
        cout << a << endl;
        return 0;
    }

    // Ba[i], Bk[i]: 第 i 站上车人数中 a 和 k 的系数
    // Sa[i], Sk[i]: 第 i 站开出时车上人数中 a 和 k 的系数˚
    vector<long long> Ba(n), Bk(n), Sa(n), Sk(n);

    // 初始化第 1, 2 站
    Ba[0] = 1;
    Bk[0] = 0; // B[1] = 1*a + 0*k
    Ba[1] = 0;
    Bk[1] = 1; // B[2] = 0*a + 1*k

    Sa[0] = 1;
    Sk[0] = 0; // S[1] = 1*a + 0*k
    Sa[1] = 1;
    Sk[1] = 0; // S[2] = 1*a + 0*k

    // 从第 3 站开始递推到第 n-1 站
    for (int i = 2; i < n - 1; ++i) {
        // B[i+1] = B[i] + B[i-1]
        Ba[i] = Ba[i - 1] + Ba[i - 2];
        Bk[i] = Bk[i - 1] + Bk[i - 2];
        // S[i+1] = S[i] + B[i+1] - B[i]
        Sa[i] = Sa[i - 1] + Ba[i] - Ba[i - 1];
        Sk[i] = Sk[i - 1] + Bk[i] - Bk[i - 1];
    }

    // S[n-1] = m, 即 Sa[n-2]*a + Sk[n-2]*k = m
    // 解出 k
    long long k = (m - Sa[n - 2] * a) / Sk[n - 2];

    if (x <= 2) {
        cout << a << endl;
    }
    else {
        // S[x] = Sa[x-1]*a + Sk[x-1]*k
        cout << Sa[x - 1] * a + Sk[x - 1] * k << endl;
    }

    return 0;
}
