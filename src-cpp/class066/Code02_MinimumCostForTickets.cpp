/// https://leetcode.cn/problems/minimum-cost-for-tickets/description/

#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
  int mincostTickets(std::vector<int> &days, std::vector<int> &costs) {
    int n = days.size();
    std::vector<int> dp(n, -1);
    return f(dp, days, costs, 0);
  }

private:
  std::vector<int> durations = {1, 7, 30};

  /// 从days[i]开始旅行,需要的最少花费
  int f(std::vector<int> &dp, const std::vector<int> &days,
        const std::vector<int> &costs, int i) {

    /// 递归结束
    if (i == days.size()) {
      return 0;
    }
    if (dp[i] != -1) {
      return dp[i];
    }

    int ans = INT_MAX;
    /// 尝试所有的购票方案
    for (int k = 0, j = i; k < 3; ++k) {
      while (j < days.size() && days[i] + durations[k] > days[j]) {
        j++;
      }

      ans = std::min(ans, costs[k] + f(dp, days, costs, j));
    }
    /// 缓存答案
    dp[i] = ans;
    return ans;
  }
};
