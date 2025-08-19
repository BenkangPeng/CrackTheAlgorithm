/// https://leetcode.cn/problems/minimum-cost-for-tickets/description/

#include <climits>
#include <iostream>
#include <vector>

/// 从顶到底的动态规划
class Solution1 {
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

      /// 寻找下一个需要再次买票的日子days[j]
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

/// 从底到顶
class Solution2 {
public:
  int mincostTickets(std::vector<int> &days, std::vector<int> &costs) {
    int n = days.size();
    std::vector<int> dp(n + 1, INT_MAX);
    /// days[n]旅游花费0
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i) {
      for (int k = 0, j = i; k < 3; ++k) {
        while (j < n && days[i] + durations[k] > days[j]) {
          ++j;
        }
        dp[i] = std::min(dp[i], costs[k] + dp[j]);
      }
    }

    return dp[0];
  }

private:
  std::vector<int> durations = {1, 7, 30};
};