#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

using namespace std;

int n;
vector<vector<int> > solutions;
vector<int> current_path(10);

// depth: 当前处理第几个配料 (0-9)
// current_sum: 当前已选配料的总和
void dfs(int depth, int current_sum) {
    // 剪枝：如果当前和已经超过n，或者即使剩下全放3都凑不够n，则返回
    if (current_sum > n || current_sum + (10 - depth) * 3 < n) {
        return;
    }

    // 递归出口：10种配料都已选择完毕
    if (depth == 10) {
        if (current_sum == n) {
            solutions.push_back(current_path);
        }
        return;
    }

    // 尝试为当前配料选择1, 2, 或 3克
    for (int i = 1; i <= 3; ++i) {
        current_path[depth] = i;
        dfs(depth + 1, current_sum + i);
    }
}

void solve() {
    cin >> n;
    // 总和的范围是 [10, 30]
    if (n < 10 || n > 30) {
        cout << 0 << endl;
        return;
    }

    dfs(0, 0);

    cout << solutions.size() << endl;
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j];
            if (j != solutions[i].size() - 1) cout << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}