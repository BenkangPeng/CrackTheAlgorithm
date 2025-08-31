/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */
#include <unordered_map>
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    int cnt = 0; /// 记录窗口中有多少种数字
    long long sum = 0, max_sum = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (map[nums[r]]++ == 0) {
        cnt++;
      }
      sum += nums[r];

      while (r - l + 1 > k) {
        if (--map[nums[l]] == 0) {
          --cnt;
        }
        sum -= nums[l++];
      }

      if (r - l + 1 == k && cnt == k) {
        max_sum = std::max(sum, max_sum);
      }
    }

    return max_sum;
  }
};
// @lc code=end
