#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Platform {
    long long x, y;
};

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<Platform> platforms(n);
    for (int i = 0; i < n; ++i) {
        cin >> platforms[i].x >> platforms[i].y;
    }

    if (n == 1) {
        cout << "Yes" << endl;
        return;
    }

    long long max_reachable = platforms[0].x + platforms[0].y;

    bool can_reach_last = false;

    for (int i = 1; i < n; ++i) {
        if (platforms[i].x + platforms[i].y <= max_reachable + k) {
            max_reachable = max(max_reachable, platforms[i].x + platforms[i].y);
            if (i == n - 1) {
                can_reach_last = true;
                break;
            }
        }
    }

    if (can_reach_last) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <numeric>

// struct Platform {
//     long long x, y;
// };

// void solve() {
//     int n;
//     long long k;
//     std::cin >> n >> k;
//     std::vector<Platform> platforms(n);
//     for (int i = 0; i < n; ++i) {
//         std::cin >> platforms[i].x >> platforms[i].y;
//     }

//     if (n == 1) {
//         std::cout << "Yes" << std::endl;
//         return;
//     }

//     // reachable[i] 表示第 i 个平台是否可以从起点到达
//     std::vector<bool> reachable(n, false);
//     reachable[0] = true; // 起始平台总是可达的

//     // 遍历所有平台
//     for (int i = 0; i < n; ++i) {
//         // 如果当前平台 i 是可达的
//         if (reachable[i]) {
//             // 尝试从平台 i 跳到它右边的所有平台 j
//             for (int j = i + 1; j < n; ++j) {
//                 // 如果平台 j 已经确定可达，就没必要再计算了
//                 if (reachable[j]) {
//                     continue;
//                 }

//                 // 检查从 i 到 j 的跳跃条件
//                 // x_j - x_i <= y_i + k - y_j
//                 if (platforms[j].x - platforms[i].x <= platforms[i].y + k - platforms[j].y) {
//                     // 如果可以跳到，则将平台 j 标记为可达
//                     reachable[j] = true;
//                 }
//             }
//         }
//     }

//     // 检查最后一个平台是否可达
//     if (reachable[n - 1]) {
//         std::cout << "Yes" << std::endl;
//     } else {
//         std::cout << "No" << std::endl;
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     int t;
//     std::cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }