// clang-format off
/// 72. https://leetcode.cn/problems/edit-distance/description/
// 思路：dp[i][j] 表示s1[0:i-1]变成s2[0:j-1]所需要的最少步数
// 1. s1[i-1]参与s2[0:j-1]的组成:
    // a. s1[i-1] = s2[j-1], dp[i][j] = dp[i-1][j-1](贪心)
    // b. s1[i-1] != s2[j-1]:
        // b1. s1[i-1]变成s2[j-1], dp[i][j] = 1 + dp[i-1][j-1]
        // b2. s1[i-1]不变成s2[j-1], dp[i][j] = 1 + dp[i][j-1](1是一步插入操作,在s1后插入s2[j-1])

// 2. s1[i-1]不参与s2[0:j-1]的构成, dp[i][j] = 1 + dp[i-1][j] (1是一步删除操作,删除s1[i-1])

// 由此可见dp[i][j]依赖于dp[i-1][j-1], dp[i][j-1], dp[i-1][j]

// 此题可以进一步扩展, 若删除/插入/替换的代价各自不同, 分别为a/b/c,
// 求s1变到s2的最小代价
// clang-format on
#include <string>
#include <vector>
class Solution {
public:
  int minDistance(const std::string &word1, const std::string &word2) {
    /// 三种操作代价均为1, 即步数
    return f(word1, word2, 1, 1, 1);
  }
  int f(const std::string &s1, const std::string &s2, int a, int b, int c) {
    int m = s1.size(), n = s2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // dp[0][1:n]为
    for (int i = 1; i <= n; ++i) {
      // 长度为0的s1串, 变成长度为i的s2串, 代价为i步插入操作
      dp[0][i] = i * b;
    }

    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i * a;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // s1[i-1]参与s2[0:j-1]的构成
        int p1, p2;
        if (s1[i - 1] == s2[j - 1]) {
          p1 = dp[i - 1][j - 1];
        } else {
          // 1. s1[i-1]要变为s2[j-1], c + dp[i-1][j-1]
          // 2. s1[i-1]不变为s2[j-1], b + dp[i][j-1] (s1后插入一个s2[j-1])
          p1 = std::min(c + dp[i - 1][j - 1], b + dp[i][j - 1]);
        }

        // s1[i-1]不参与s2[0:j-1]的构成, 删除s1[i-1]
        p2 = a + dp[i - 1][j];

        dp[i][j] = std::min(p1, p2);
      }
    }

    return dp[m][n];
  }
};