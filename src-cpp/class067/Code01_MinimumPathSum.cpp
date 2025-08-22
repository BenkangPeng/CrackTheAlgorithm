/// https://leetcode.cn/problems/minimum-path-sum/description/

#include <algorithm>
#include <climits>
#include <vector>

/// 记忆化搜索
class Solution1 {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));

    return f(m - 1, n - 1, dp, grid);
  }

private:
  /// 从(0,0)到(i,j)的最小路径和
  int f(int i, int j, std::vector<std::vector<int>> &dp,
        std::vector<std::vector<int>> &grid) {
    /// base case
    if (i == 0 && j == 0) {
      return grid[0][0];
    }
    if (i < 0 || j < 0) {
      return INT_MAX;
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int left = f(i, j - 1, dp, grid);
    int up = f(i - 1, j, dp, grid);

    int min_sum = grid[i][j] + std::min(left, up);
    dp[i][j] = min_sum;
    return min_sum;
  }
};

/// 严格位置依赖的DP
class Solution2 {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    /// dp[i][j] 表示(0,0)到(i,j)的最小路径和
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[m - 1][n - 1];
  }
};

/// 再省一点空间, 一张一维的DP表就行了
class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    std::vector<int> dp(n, 0);

    dp[0] = grid[0][0];
    for(int i = 1; i < n; ++i){
        dp[i] = dp[i-1] + grid[0][i];
    }

    int left;
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        left = j > 0 ? dp[j - 1] : INT_MAX;
        dp[j] = grid[i][j] + std::min(left, dp[j]);
      }
    }

    return dp[n - 1];
  }
};