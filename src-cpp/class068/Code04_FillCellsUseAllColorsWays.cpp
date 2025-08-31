// 有效涂色问题
// 给定n、m两个参数
// 一共有n个格子，每个格子可以涂上一种颜色，颜色在m种里选
// 当涂满n个格子，并且m种颜色都使用了，叫一种有效方法
// 求一共有多少种有效的涂色方法
// 1 <= n, m <= 5000
// 结果比较大请 % 1000000007 之后返回
// 对数器验证

#include <vector>
constexpr int mod = int(1e9 + 7);
class Solution {
public:
  /// dp[i][j]表示i个格子,填满j种颜色,有多少种方法,情况有两种:
  /// 1. 前i-1个格子已经使用了j种颜色, dp[i][j] = dp[i-1][j] * j
  /// 2. 前i-1个格子已经使用了j-1种颜色, dp[i][j] = dp[i-1][j-1] * (m-(j-1))
  /// 其他情况无意义, 例如前i-1个格子使用j-2种颜色,
  /// 那么前i个格子不可能使用j种颜色
  int fillCells(int n, int m) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    dp[1][1] = 1;
    // dp[1][2:m] = 0
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = long(dp[i - 1][j] * j) % mod +
                   long(dp[i - 1][j - 1] * (m - j + 1)) % mod;
      }
    }

    return dp[n][m];
  }
};
int main() {}