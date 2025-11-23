#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 使用 long long 避免坐标运算溢出
using Point = pair<long long, long long>;

// 叉积函数
long long cross_product(const Point &a, const Point &b) {
    return a.first * b.second - a.second * b.first;
}

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<Point> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> stars[i].first >> stars[i].second;
    }

    Point current_dir = {1, 0};

    for (int i = 0; i < m; i++) {
        Point target_dir;
        cin >> target_dir.first >> target_dir.second;

        int ccw_count = 0; // 逆时针 (counter-clockwise)
        int cw_count = 0; // 顺时针 (clockwise)

        // 通过叉积判断从 current_dir 到 target_dir 的最短旋转方向
        long long cp_dirs = cross_product(current_dir, target_dir);

        for (const auto &star: stars) {
            long long cp_start = cross_product(current_dir, star);
            long long cp_end = cross_product(target_dir, star);

            bool in_ccw_sweep = false;
            bool in_cw_sweep = false;

            if (cp_dirs > 0) {
                // 最短路径是逆时针
                if (cp_start >= 0 && cp_end <= 0) {
                    in_ccw_sweep = true;
                }
                // 不在逆时针小扇形内的，就在顺时针大扇形内
                if (!in_ccw_sweep) {
                    in_cw_sweep = true;
                }
            } else if (cp_dirs < 0) {
                // 最短路径是顺时针
                if (cp_start <= 0 && cp_end >= 0) {
                    in_cw_sweep = true;
                }
                // 不在顺时针小扇形内的，就在逆时针大扇形内
                if (!in_cw_sweep) {
                    in_ccw_sweep = true;
                }
            } else {
                // cp_dirs == 0, 方向相反
                if (cp_start >= 0) {
                    in_ccw_sweep = true;
                }
                if (cp_start <= 0) {
                    in_cw_sweep = true;
                }
            }

            if (in_ccw_sweep) ccw_count++;
            if (in_cw_sweep) cw_count++;
        }

        cout << max(cw_count, ccw_count) << "\n";

        current_dir = target_dir;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}