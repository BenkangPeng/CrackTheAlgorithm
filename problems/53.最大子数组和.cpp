/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <climits>
#include <vector>
// @lc code=start
class Solution0 {
public:
  int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    // 然后问题就转换成：找差值最大的两点(类似 121.买卖股票的最佳时机)
    std::vector<int> dp(n + 1, 0);
    int ans = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
      dp[i] = prefix[i + 1] - prefix[i];
      if (dp[i + 1] > 0) {
        dp[i] += dp[i + 1];
      }
      ans = std::max(ans, dp[i]);
    }
    return ans;
  }
};

/// 上面方法空间复杂度太高了,不用前缀和，用动态规划
class Solution1 {
public:
  int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    /// dp[i]表示以nums[i]结尾的子数组的最大和
    std::vector<int> dp(n, 0);

    int ans = std::max(0, nums[0]);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = std::max(dp[i - 1], 0) + nums[i];
      ans = std::max(dp[i], ans);
    }

    return ans;
  }
};

/// 进一步省空间
class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();

    int dp = nums[0];
    int ans = dp;
    for (int i = 1; i < n; ++i) {
      dp = std::max(dp, 0) + nums[i];
      ans = std::max(dp, ans);
    }

    return ans;
  }
};
// @lc code=end
