/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <vector>
// @lc code=start
class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    int slow = 0, fast = 0;

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (nums[slow] != nums[fast]);

    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
// @lc code=end
