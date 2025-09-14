/// https://leetcode.cn/problems/split-array-largest-sum/description/
/// 题干太难看，其实是一个""画匠问题"
/// 可参考：https://www.nowcoder.com/questionTerminal/767778ca5b38446cba801820df11399d
/// nums[i]表示位置为i的画需要nums[i]个小时才能画完
/// 将nums.size()幅画划分为连续的k份，交给k个画匠
/// 求: 怎样划分任务，所有画完工所需的时间时间最少

#include <climits>
#include <numeric>
#include <vector>
class Solution {
public:
  int splitArray(std::vector<int> &nums, int k) {
    /// 所需的时间ans，最少1，最多等于sum(nums) (k = 1时)
    /// 最少时间ans满足单调性:
    /// [1,ans-1]不能完成画作，[ans,sum(nums)]可以完成画作
    int l = 1, r = std::accumulate(nums.begin(), nums.end(), 0);

    int ans, mid;
    while (l <= r) {
      mid = l + ((r - l) >> 1);

      if (f(nums, mid) <= k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }

  /// @return 要求在limit时间内完工，最少需要几个画匠(k)
  /// 在时间limit内，所有画都要完工，这意味着每一个画匠分配的任务<=limit
  int f(std::vector<int> &nums, int limit) {
    int k = 1;
    int sum = 0;

    for (int num : nums) {
      if (num > limit) {
        return INT_MAX;
      }
      sum += num;
      if (sum > limit) {
        ++k;
        sum = num;
      }
    }

    return k;
  }
};