/// 1143 https://leetcode.cn/problems/longest-common-subsequence/description/
#include <algorithm>
#include <string>
#include <vector>
using std::string;

/// 超时
class Solution1 {
public:
  int longestCommonSubsequence(const std::string &text1,
                               const std::string &text2) {
    int m = text1.size(), n = text2.size();
    return f(text1, text2, m - 1, n - 1);
  }

private:
  /// s1[0:i]与s2[0:j]最长的公共子序列长度
  int f(const std::string &s1, const std::string &s2, int i, int j) {
    /// base case
    if (i < 0 || j < 0) {
      return 0;
    }

    /// 比较抽象
    /// f(s1,s2,i,j)就包含以下四种情况:

    /// s1[i]不在最长公共子序列中
    int p1 = f(s1, s2, i - 1, j);
    /// s2[j]不在最长公共子序列中
    int p2 = f(s1, s2, i, j - 1);

    /// s1[i],s2[j]都不在最长公共子序列中
    int p3 = f(s1, s2, i - 1, j - 1);

    /// s1[i],s2[j]都不在最长公共子序列中, 即s1[i]与s2[j]相等时, p4 = p3 + 1
    int p4 = s1[i] == s2[j] ? p3 + 1 : 0;

    return std::max({p1, p2, p3, p4});
  }
};

/// 挂DP表
class Solution2 {
public:
  int longestCommonSubsequence(const std::string &text1,
                               const std::string &text2) {
    int m = text1.size(), n = text2.size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
    return f(text1, text2, m - 1, n - 1, dp);
  }

private:
  /// s1[0:i]与s2[0:j]最长的公共子序列长度
  int f(const std::string &s1, const std::string &s2, int i, int j,
        std::vector<std::vector<int>> &dp) {
    /// base case
    if (i < 0 || j < 0) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    /// 比较抽象
    /// f(s1,s2,i,j)就包含以下四种情况:

    /// s1[i]不在最长公共子序列中
    int p1 = f(s1, s2, i - 1, j, dp);
    /// s2[j]不在最长公共子序列中
    int p2 = f(s1, s2, i, j - 1, dp);

    /// s1[i],s2[j]都不在最长公共子序列中
    int p3 = f(s1, s2, i - 1, j - 1, dp);

    /// s1[i],s2[j]都不在最长公共子序列中, 即s1[i]与s2[j]相等时, p4 = p3 + 1
    int p4 = s1[i] == s2[j] ? p3 + 1 : 0;

    dp[i][j] = std::max({p1, p2, p3, p4});
    return dp[i][j];
  }
};

/// 严格位置依赖的动态规划
class Solution3 {
public:
  int longestCommonSubsequence(const std::string &text1,
                               const std::string &text2) {
    /// dp[i][j] 依赖于 dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
    int m = text1.size(), n = text2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    /// 为避免越界带来的过多的条件判断,
    /// dp[i][j]表示s1[0:i-1]与s2[0:j-1]的最长公共子序列
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        int tmp = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
        dp[i][j] =
            std::max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1], tmp});
      }
    }

    return dp[m][n];
  }
};

/// 省空间, 使用一张一维DP表
class Solution {
public:
  int longestCommonSubsequence(const std::string &text1,
                               const std::string &text2) {
    int m = text1.size(), n = text2.size();
    std::string s1, s2;
    if (m > n) {
      s1 = text1;
      s2 = text2;
    } else {
      s1 = text2;
      s2 = text1;
      int tmp = m;
      m = n;
      n = tmp;
    }

    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
      int leftUp = 0, backup;
      for (int j = 1; j <= n; ++j) {
        /// 保留旧的dp[i][j]
        backup = dp[j];
        if (s1[i - 1] == s2[j - 1]) {
          dp[j] = leftUp + 1;
        } else {
          dp[j] = std::max(dp[j], dp[j - 1]);
        }
        /// 当前backup是下一次迭代dp[i]j+1]的左上元素,用leftUp保存它
        leftUp = backup;
      }
    }

    return dp[n];
  }
};