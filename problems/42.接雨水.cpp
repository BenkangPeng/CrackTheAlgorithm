/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    std::vector<int> left_max(n, 0), right_max(n, 0);

    int l = 0;
    for (int i = 1; i < n; ++i) {
      l = std::max(l, height[i - 1]);
      left_max[i] = l;
    }

    int r = 0;
    for (int i = n - 2; i >= 0; --i) {
      r = std::max(r, height[i + 1]);
      right_max[i] = r;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
      int edge = std::min(left_max[i], right_max[i]);
      ans += height[i] < edge ? edge - height[i] : 0;
    }

    return ans;
  }
};
// @lc code=end
