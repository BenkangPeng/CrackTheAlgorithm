/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 */

// @lc code=start
#include <vector>
class Solution {
public:
  int countHousePlacements(int n) {
    if (n == 1) {
      return 4;
    }
    std::vector<int> dp(n + 1, 0);
    constexpr int mod = int(1e9 + 7);
    dp[1] = 2;
    dp[2] = 3;

    for (int i = 3; i <= n; ++i) {
      dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
    }

    return (long long)dp[n] * dp[n] % mod;
  }
};
// @lc code=end
