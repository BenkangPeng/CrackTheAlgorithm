/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
// @lc code=start
class Solution {
public:
  int rob(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> dp(101, -1);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; ++i) {
      dp[i] = std::max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    }

    return dp[n];
  }
};
// @lc code=end
