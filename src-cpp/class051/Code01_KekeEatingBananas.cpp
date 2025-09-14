/// https://leetcode.cn/problems/koko-eating-bananas/description/

/// 二分问题
/// 最小速度k在一个范围[l,r]中，且[l,k-1]不能在h时间内吃完香蕉,[k,r]可以吃完
/// 问题具有单调性,可以使用二分答案法

/// 模板：左右范围为闭区间, while(l <= r), mid+1,mid-1

#include <algorithm>
#include <vector>
class Solution {
public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int l = 1;
    int r = *std::max_element(piles.begin(), piles.end());
    int mid, ans;

    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (f(piles, mid) <= h) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }

  /// 以k速度，多少小时可以吃完香蕉
  long long f(std::vector<int> &piles, int k) {
    long long ans = 0;
    for (auto pile : piles) {
      ans += (pile + k - 1) / k;
    }

    return ans;
  }
};