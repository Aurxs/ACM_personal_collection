#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>

using namespace std;

string multiply(string num1, string num2) { // 高精度乘法板子
    if (num1 == "0" || num2 == "0") return "0";

    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }

    int i = 0;
    while (i < res.size() && res[i] == 0) i++;

    string result;
    for (; i < res.size(); i++) {
        result.push_back(res[i] + '0');
    }

    return result;
}

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, pair<int, int>> side;  // (x, z) -> {max_y, weight}
    map<pair<int, int>, pair<int, int>> up;    // (x, y) -> {max_z, weight}
    map<pair<int, int>, pair<int, int>> front; // (y, z) -> {max_x, weight}
    for (int i = 0; i < n; i++) {
        int x, y, z;
        int w;
        cin >> x >> y >> z >> w;

        if (!side.count({x, z}) || side[{x, z}].first > y) { // 左视图应该看最小的y，符号反转
            side[{x, z}] = {y, w};
        }

        if (!up.count({x, y}) || up[{x, y}].first < z) {
            up[{x, y}] = {z, w};
        }

        if (!front.count({y, z}) || front[{y, z}].first < x) {
            front[{y, z}] = {x, w};
        }
    }
    unsigned long long sum_front = 0, sum_up = 0, sum_side = 0;

    for (const auto &[key, value] : front) {
        long long w = stoll(multiply(to_string(value.second), to_string(value.second)));
        sum_front += w;
    }

    for (const auto &[key, value] : up) {
        long long w = stoll(multiply(to_string(value.second), to_string(value.second)));
        sum_up += w;
    }

    for (const auto &[key, value] : side) {
        long long w = stoll(multiply(to_string(value.second), to_string(value.second)));
        sum_side += w;
    }

    cout << sum_front << " " << sum_up << " " << sum_side << "\n";
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