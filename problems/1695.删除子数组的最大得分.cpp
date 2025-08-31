/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */
#include <unordered_map>
#include <vector>
// @lc code=start
class Solution {
public:
  int maximumUniqueSubarray(const std::vector<int> &nums) {

    std::unordered_map<int, int> map;
    int cnt = 0, ans = 0;
    int sum = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {

      if (map[nums[r]]++ == 0) {
        cnt++;
      }
      sum += nums[r];

      while (cnt > r - l + 1) {
        if (--map[nums[l]] == 0) {
          --cnt;
        }
        sum -= nums[l++];
      }

      ans = std::max(ans, sum);
    }
    return ans;
  }
};
// @lc code=end
