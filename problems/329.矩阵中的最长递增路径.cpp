/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <algorithm>
#include <climits>
#include <vector>

using std::vector;
// @lc code=start
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int ans = 0;
    int m = matrix.size(), n = matrix[0].size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = std::max(ans, f(matrix, i, j, dp));
      }
    }

    return ans;
  }

private:
  int f(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int ans = 0, cur = matrix[i][j];
    int m = matrix.size(), n = matrix[0].size();

    if (j > 0 && matrix[i][j - 1] > cur) {
      ans = std::max(ans, f(matrix, i, j - 1, dp));
    }

    if (j < n - 1 && matrix[i][j + 1] > cur) {
      ans = std::max(ans, f(matrix, i, j + 1, dp));
    }

    if (i > 0 && matrix[i - 1][j] > cur) {
      ans = std::max(ans, f(matrix, i - 1, j, dp));
    }

    if (i < m - 1 && matrix[i + 1][j] > cur) {
      ans = std::max(ans, f(matrix, i + 1, j, dp));
    }

    dp[i][j] = ans + 1;
    return ans + 1;
  }
};
// @lc code=end
