/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>
class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 1 && n == 1) {
      return 1;
    }

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));
    return f(1, 1, m, n, dp);
  }

  int f(int i, int j, int m, int n, std::vector<std::vector<int>> &dp) {
    /// base case
    if ((i == m - 1 && j == n) || (i == m && j == n - 1)) {
      return 1;
    }

    if (i > m || j > n) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int ans = f(i + 1, j, m, n, dp) + f(i, j + 1, m, n, dp);
    dp[i][j] = ans;
    return ans;
  }
};
// @lc code=end
