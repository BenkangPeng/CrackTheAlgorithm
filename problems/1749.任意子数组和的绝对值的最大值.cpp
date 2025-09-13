/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int maxAbsoluteSum(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    /// 求最大子数组和，最小子数组和

    int past_max = prefix[n] - prefix[n - 1];
    int past_min = past_max;
    int cur_max = 0, cur_min;
    int ans_max = past_max, ans_min = past_min;
    for (int i = n - 2; i >= 0; --i) {
      int tmp = prefix[i + 1] - prefix[i];
      cur_max = std::max(tmp, tmp + past_max);
      cur_min = std::min(tmp, tmp + past_min);
      past_max = cur_max;
      past_min = cur_min;
      ans_max = std::max(ans_max, cur_max);
      ans_min = std::min(ans_min, cur_min);
    }

    return _abs(ans_max) > _abs(ans_min) ? _abs(ans_max) : _abs(ans_min);
  }

  int _abs(int x) { return x < 0 ? -x : x; }
};
// @lc code=end
