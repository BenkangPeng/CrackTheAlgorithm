/*
 * @lc app=leetcode.cn id=2141 lang=cpp
 *
 * [2141] 同时运行 N 台电脑的最长时间
 */

#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    long long l = 1, r = static_cast<long long>(1e14);
    long long mid, ans;

    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (f(batteries, n, mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }

  /// 电池能否支持n台电脑运行time时间
  bool f(vector<int> &batteries, int n, int time) {}
};
// @lc code=end
