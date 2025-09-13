/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <vector>
// @lc code=start
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int n = prices.size();
    // dp[i]表示买入prices[i]股票时, 能获得的最大利润
    std::vector<int> dp(n, 0);
    int ans = 0;

    for (int i = n - 2; i >= 0; --i) {
      dp[i] = std::max(prices[i + 1] + dp[i + 1] - prices[i], 0);
      ans = std::max(dp[i], ans);
    }

    return ans;
  }
};
// @lc code=end
