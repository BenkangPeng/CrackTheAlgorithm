/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = 1;

    while (i < n && j < n) {
      while (i < n && nums[i] % 2 == 0) {
        i += 2;
      }

      while (j < n && nums[j] % 2 != 0) {
        j += 2;
      }

      if (i < n && j < n) {
        std::swap(nums[i], nums[j]);
      }
    }

    return nums;
  }
};
// @lc code=end
