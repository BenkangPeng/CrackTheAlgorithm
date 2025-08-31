/// 97. https://leetcode.cn/problems/interleaving-string/description/

// clang-format off
// dp[i][j]表示s1[0:i-1]与s2[0:j-1]是否能交错构成s3[0:i+j-1], 那么answer = dp[m][n]
// 1. if s3[i+j-1] = s1[i-1], dp[i][j] = dp[i-1][j](用s1[i-1]构成s3[i+j-1], 用s1[0:i-2],s2[0:j-1]构成s3[0:i+j])
// 2. if s3[i+j-1] = s2[j-1], dp[i][j] = dp[i][j-1] 
// 3. else dp[i][j] = false
// clang-format on
#include <iostream>
#include <string>
#include <vector>

class Solution0 {
public:
  bool isInterleave(const std::string &s1, const std::string &s2,
                    const std::string &s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) {
      return false;
    }
    if (m == 0 || n == 0) {
      return s1 == s3 || s2 == s3;
    }

    /// @note vector<bool>不安全
    std::vector<std::vector<char>> dp(m + 1, std::vector<char>(n + 1, false));

    for (int i = 1; i <= m; ++i) {
      // 只用s1[0:i-1]能否构成s3[0:i-1]
      dp[i][0] = s1.substr(0, i) == s3.substr(0, i);
    }

    for (int i = 1; i <= n; ++i) {
      dp[0][i] = s2.substr(0, i) == s3.substr(0, i);
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {

        /// @attention 这里的判断调试了很久
        /// 考虑到s1[i-1],s2[j-1],s3[i+j-1]可能都相等,
        /// 构建s3[0:i+j-1]有两种方式:
        /// 1. 用s1[i-1]构成s3[i+j-1], 用s1[0:i-2],s2[0:j-1]构成s3[0:i+j]
        /// 2. 用s2[j-1]构成s3[i+j-1], 用s1[0:i-1],s2[0:j-2]构成s3[0:i+j]
        // 只要其中一种为true, dp[i][j] = true
        if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
          dp[i][j] = bool(dp[i - 1][j]) || bool(dp[i][j - 1]);
          continue;
        }

        if (s1[i - 1] == s3[i + j - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else if (s2[j - 1] == s3[i + j - 1]) {
          dp[i][j] = dp[i][j - 1];
        }
        // else dp[i][j] = false;
      }
    }

    return dp[m][n];
  }
};

/// 看了左神的代码, 优化
class Solution {
public:
  bool isInterleave(const std::string &s1, const std::string &s2,
                    const std::string &s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) {
      return false;
    }
    if (m == 0 || n == 0) {
      return s1 == s3 || s2 == s3;
    }

    /// @note vector<bool>不安全
    std::vector<std::vector<char>> dp(m + 1, std::vector<char>(n + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= m; ++i) {
      // 只用s1[0:i-1]能否构成s3[0:i-1]
      dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
    }

    for (int i = 1; i <= n; ++i) {
      dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {

        /// @attention 这里的判断调试了很久
        /// 考虑到s1[i-1],s2[j-1],s3[i+j-1]可能都相等,
        /// 构建s3[0:i+j-1]有两种方式:
        /// 1. 用s1[i-1]构成s3[i+j-1], 用s1[0:i-2],s2[0:j-1]构成s3[0:i+j]
        /// 2. 用s2[j-1]构成s3[i+j-1], 用s1[0:i-1],s2[0:j-2]构成s3[0:i+j]
        // 只要其中一种为true, dp[i][j] = true
        dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) ||
                   (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
      }
    }

    return dp[m][n];
  }
};

// int main() {
//   std::string s1 = "ab", s2 = "bc", s3 = "babc";
//   Solution ss;
//   std::cout << ss.isInterleave(s1, s2, s3);
// }