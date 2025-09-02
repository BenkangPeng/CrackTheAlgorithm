/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int deleteAndEarn(std::vector<int> &nums) {

    int max_num = *std::max_element(nums.begin(), nums.end());

    /// points[num]表示num这个数的总点数(sum)
    std::vector<int> points(max_num + 1, 0);
    for (int num : nums) {
      points[num] += num;
    }

    /// dp[i]表示在[0:i]中按照规则挑取点数, 可以获得的最大点数
    std::vector<int> dp(max_num + 1, 0);
    dp[1] = points[1];

    for (int i = 2; i <= max_num; ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + points[i]);
    }

    return dp[max_num];
  }
};
// @lc code=end
