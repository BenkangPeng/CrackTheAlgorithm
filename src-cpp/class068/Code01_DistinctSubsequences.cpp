/// https://leetcode.cn/problems/distinct-subsequences/description/
// 思路：定义dp[i][j]为, s[0:i-1](长度为i)的子序列中, 等于t[0:j-1]的个数
// 转移方程可以这样求: dp[i][j]分为两种情况：
// 1. if s[i-1] != t[j-1],  dp[i][j] = dp[i-1][j]
// 2. if s[i-1] = t[j-1], dp[i][j] = dp[i-1][j-1] +
// dp[i-1][j](有可能s[0:i-2]也能凑出与t[0:j-1]的子序列)
#include <string>
#include <vector>
using std::string;

/// 这题好坑,中间结果连long long都放不下
using ull = unsigned long long;
class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    std::vector<std::vector<ull>> dp(n + 1, std::vector<ull>(m + 1, 0));

    // base case
    // dp[0:m][0] = 1, dp[0][1:n] = 0
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
      for (in t j = 1; j <= m; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][m];
  }
};