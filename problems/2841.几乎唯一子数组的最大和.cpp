/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */
#include <iostream>
#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  long long maxSum(std::vector<int> &nums, int m, int k) {

    int n = nums.size(), collect = 0;
    std::unordered_map<int, int> cnt;
    long long sum = 0, ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      if (cnt[nums[r]]++ == 0) {
        collect++;
      }
      sum += nums[r];

      if (r - l + 1 == k) {
        if (collect >= m) {
          ans = sum > ans ? sum : ans;
        }
        if (--cnt[nums[l]] == 0) {
          collect--;
        }
        sum -= nums[l++];
      }
    }
    return ans;
  }
};
// @lc code=end

int main() {
  std::vector<int> nums = {2, 6, 7, 3, 1, 7};
  int m = 3, k = 4;
  Solution ss;
  std::cout << ss.maxSum(nums, m, k) << std::endl;
}