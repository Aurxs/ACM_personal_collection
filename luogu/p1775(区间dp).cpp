#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MAX

// 假设石子数量存储在 stones 数组中，下标从 1 开始
// N 是石子堆的数量
void solve_stone_merging(int N, const std::vector<int> &stones) {
    // dp[i][j] 表示合并第 i 堆到第 j 堆的最小代价
    std::vector<std::vector<int> > dp(N + 1, std::vector<int>(N + 1, 0));

    // prefix_sum[i] 存储前 i 堆石子的总数，用于快速计算区间和
    std::vector<int> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + stones[i];
    }

    // len 是区间的长度
    for (int len = 2; len <= N; ++len) {
        // i 是区间的起始点
        for (int i = 1; i <= N - len + 1; ++i) {
            // j 是区间的终点
            int j = i + len - 1;

            // 初始化 dp[i][j] 为一个很大的值
            dp[i][j] = INT_MAX;

            // 计算区间 [i, j] 的石子总和
            int sum = prefix_sum[j] - prefix_sum[i - 1];

            // k 是分割点，枚举所有可能的最后一次合并的位置
            for (int k = i; k < j; ++k) {
                // 状态转移方程
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
            }
        }
    }

    // 最终结果是合并整个区间 [1, N] 的最小代价
    std::cout << dp[1][N] << std::endl;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> stones(N + 1);
    for (int i = 1; i <= N; i++) std::cin >> stones[i];
    solve_stone_merging(N, stones);
    return 0;
}