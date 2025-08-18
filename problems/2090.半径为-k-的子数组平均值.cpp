/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

#include <vector>
// @lc code=start
class Solution {
public:
  std::vector<int> getAverages(std::vector<int> &nums, int k) {

    int n = nums.size();
    long long sum = 0;
    std::vector<int> ans(n, -1);
    for (int l = 0, r = 0; r < n; ++r) {
      sum += nums[r];

      if (r - l == 2 * k) {
        ans[r - k] = sum / (2 * k + 1);

        sum -= nums[l++];
      }
    }
    return ans;
  }
};
// @lc code=end
