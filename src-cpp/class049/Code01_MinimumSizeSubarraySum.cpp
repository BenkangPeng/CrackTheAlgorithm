/// https://leetcode.cn/problems/minimum-size-subarray-sum/

#include <climits>
#include <vector>
class Solution {
public:
  int minSubArrayLen(int target, std::vector<int> &nums) {

    int n = nums.size();
    int sum = 0;
    int ans = INT_MAX;
    for (int l = 0, r = 0; r < n; ++r) {
      /// 窗口向右滑动
      sum += nums[r];

      /// 尝试缩小左边界
      while (sum - nums[l] >= target) {
        sum -= nums[l];
        ++l;
      }

      if (sum >= target) {
        ans = (r - l + 1) < ans ? (r - l + 1) : ans;
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};