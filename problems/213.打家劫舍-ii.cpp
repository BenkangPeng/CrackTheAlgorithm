/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
// @lc code=start
class Solution {
public:
  int rob(std::vector<int> &nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    int num0 = nums[0];
    // 不偷nums[0]
    nums[0] = 0;
    int ans0 = f(nums);

    // 偷
    nums[1] = 0;
    nums[n - 1] = 0;
    int ans1 = num0 + f(nums);

    return std::max(ans0, ans1);
  }

  /// 198打家劫舍I的rob函数
  int f(std::vector<int> &nums) {
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
