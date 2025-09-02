/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include <vector>
// @lc code=start
class Solution {
public:
  int combinationSum4(const std::vector<int> &nums, int target) {
    std::vector<int> dp(target + 1, -1);
    return f(nums, target, dp);
  }

private:
  int f(const std::vector<int> &nums, int target, std::vector<int> &dp) {

    if (target < 0) {
      return 0;
    }
    if (target == 0) {
      return 1;
    }
    if (dp[target] != -1) {
      return dp[target];
    }

    int ans = 0;
    for (int num : nums) {
      ans += f(nums, target - num, dp);
    }

    dp[target] = ans;
    return ans;
  }
};
// @lc code=end
