/// 516
/// https://leetcode.cn/problems/longest-palindromic-subsequence/description/
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

class Solution1 {
public:
  int longestPalindromeSubseq(std::string s) {
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
    return f(s, 0, n - 1, dp);
  }

private:
  /// s[i:j]的最长回文子序列长度
  int f(const std::string &s, int i, int j, std::vector<std::vector<int>> &dp) {

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    /// base case
    if (i == j) {
      dp[i][j] = 1;
      return 1;
    } else if (i + 1 == j) {
      int ans = s[i] == s[j] ? 2 : 1;
      dp[i][j] = ans;
      return ans;
    }

    int ans = 0;
    if (s[i] == s[j]) {
      ans = 2 + f(s, i + 1, j - 1, dp);
    } else {
      ans = std::max(f(s, i, j - 1, dp), f(s, i + 1, j, dp));
    }
    dp[i][j] = ans;
    return ans;
  }
};

/// 严格位置依赖DP
class Solution {
public:
  int longestPalindromeSubseq(std::string s) {
    /// 由上面的递归解法可知, f(i,j)依赖于f(i,j-1),f(i+1,j),f(i+1,j-1)

    int n = s.size();
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

    for (int i = n; i >= 1; --i) {
      for (int j = i; j <= n; ++j) {
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = (i == j) ? 1 : (2 + dp[i + 1][j - 1]);
        } else {
          dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
        }
      }
    }

    return dp[1][n];
  }
};