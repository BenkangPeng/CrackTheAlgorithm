/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */
#include <algorithm>
#include <vector>
// @lc code=start
class Solution {
public:
  int longestSubarray(std::vector<int> &nums) {

    int n = nums.size(), cnt = 0;
    int ans = 0;

    for (int l = 0, r = 0; r < n; ++r) {
      if (nums[r] == 0) {
        ++cnt;
      }

      while (cnt > 1) {
        if (nums[l++] == 0) {
          --cnt;
        }
      }
      ans = std::max(ans, r - l);
    }
    return ans;
  }
};
// @lc code=end

int main() {
  std::vector<int> nums = {1, 1, 0, 1};
  Solution ss;
  ss.longestSubarray(nums);
}