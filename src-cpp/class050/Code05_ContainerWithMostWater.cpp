#include <vector>
using std::vector;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
      ans = std::max(ans, std::min(height[l], height[r]) * (r - l));
      if (height[l] <= height[r]) {
        // 瓶颈在height[l]
        ++l;
      } else {
        --r;
      }
    }

    return ans;
  }
};