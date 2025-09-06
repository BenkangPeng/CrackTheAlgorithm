#include <algorithm>
#include <vector>
using std::vector;

/// O(N), O(N)
class Solution0 {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    /// left_max[i]表示height[0:i-1]的最大值
    /// height[i]能接住的雨水格数, = min(left_max[i], right_max[i]) - height[i]
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

/// 双指针, O(N), O(1)
class Solution {
public:
  int trap(std::vector<int> &height) {
    int n = height.size();
    int lmax = height[0], rmax = height[n - 1];
    int l = 1, r = n - 2;

    int ans = 0;
    while (l <= r) {
      if (lmax < rmax) {
        ans += std::max(lmax - height[l], 0);
        lmax = std::max(lmax, height[l++]);
      } else {
        ans += std::max(rmax - height[r], 0);
        rmax = std::max(rmax, height[r--]);
      }
    }
    return ans;
  }
};
