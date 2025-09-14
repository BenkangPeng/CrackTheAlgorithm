/// https://leetcode.cn/problems/find-k-th-smallest-pair-distance/description/

#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
  int smallestDistancePair(vector<int> &nums, int k) {

    /// 排序不影响数对的数量,本来数对距离为abs(nums[j] - nums[i]), i < j
    /// 排序后即使两个数交换了相对顺序，数对距离依然不变
    std::sort(nums.begin(), nums.end());
    /// 第k小的距离的范围
    int l = 0, r = nums.back() - nums[0];

    int mid, ans;
    while (l <= r) {
      mid = l + ((r - l) >> 1);

      if (f(nums, mid) >= k) {
        /// 距离为[0,mid]的数对数量 >= k
        /// 第k小的距离一定在[0,mid]内
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }

  /// @return 距离<= limit的数对的个数
  int f(vector<int> &nums, int limit) {

    int ans = 0;
    /// 滑动窗口
    for (int l = 0, r = 0; l < nums.size();) {
      if (r + 1 < nums.size() && nums[r + 1] - nums[l] <= limit) {
        ++r;
      } else {
        ans += r - l;
        ++l;
        r = l;
      }
    }
    return ans;
  }
};