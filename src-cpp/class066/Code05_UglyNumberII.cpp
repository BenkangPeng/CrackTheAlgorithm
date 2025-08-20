/// https://leetcode.cn/problems/ugly-number-ii/description/

/// 思路: 一个丑数可以由之前的丑数*2/3/5得到
#include <algorithm>
#include <vector>
class Solution {
public:
  int nthUglyNumber(int n) {
    std::vector<int> dp(n + 1, 0);

    /// 第一个丑数是1
    dp[1] = 1;

    /// i2是一个指针, 指向丑数dp[i2], 得到丑数dp[i2] * 2
    for (int i = 2, i2 = 1, i3 = 1, i5 = 1; i <= n; ++i) {
      int a = dp[i2] * 2;
      int b = dp[i3] * 3;
      int c = dp[i5] * 5;

      dp[i] = std::min({a, b, c});

      if (a == dp[i]) {
        ++i2;
        continue;
      }
      if (b == dp[i]) {
        ++i3;
        continue;
      }
      if (c == dp[i]) {
        ++i5;
      }
    }

    return dp[n];
  }
};