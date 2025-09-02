/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

#include <vector>
// @lc code=start
class Solution {
public:
  const int mod = int(1e9 + 7);
  int countGoodStrings(int low, int high, int zero, int one) {
    std::vector<int> dp(high + 1, -1);

    int ans = 0;
    for (int i = low; i <= high; ++i) {
      ans = (ans + f(i, zero, one, dp)) % mod;
    }

    return ans;
  }

  /// 构造长度为target的字符串有多少种方法
  int f(int target, int zero, int one, std::vector<int> &dp) {
    if (target < 0) {
      return 0;
    }

    if (target == 0) {
      return 1;
    }
    if (dp[target] != -1) {
      return dp[target];
    }

    int ans =
        (f(target - zero, zero, one, dp) + f(target - one, zero, one, dp)) %
        mod;
    dp[target] = ans;
    return ans;
  }
};
// @lc code=end
