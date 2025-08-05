/// https://leetcode.cn/problems/corporate-flight-bookings/

#include <vector>
using std::vector;
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    std::vector<int> ans(n, 0);
    /// ans为差分数组,在最终结果的[l,r]加num
    /// 只需操作差分数组ans[l] += num, ans[r+1] -= num;
    for (auto booking : bookings) {
      /// 航班索引[1,n]对应ans索引[0,n)
      ans[booking[0] - 1] += booking[2];
      if (booking[1] < n) { /// 避免越界
        ans[booking[1]] -= booking[2];
      }
    }
    /// 差分数组求和,得到最终数组
    for (int i = 1; i < n; ++i) {
      ans[i] += ans[i - 1];
    }
    return ans;
  }
};