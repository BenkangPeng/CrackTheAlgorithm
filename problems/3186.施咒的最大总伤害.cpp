/*
 * @lc app=leetcode.cn id=3186 lang=cpp
 *
 * [3186] 施咒的最大总伤害
 */

#include <algorithm>
#include <map>
#include <vector>

// @lc code=start

/// 超空间限制了, max_power可能有1e9 > O(N), 空间限制一般是O(N)
class Solution0 {
public:
  long long maximumTotalDamage(std::vector<int> &power) {
    int max_power = *std::max_element(power.begin(), power.end());
    if (max_power == 1) {
      return power.size();
    }
    std::vector<int> power_cnt(max_power + 1, 0);

    for (int elem : power) {
      power_cnt[elem]++;
    }

    std::vector<long long> dp(max_power + 1, 0);
    dp[1] = power_cnt[1];
    dp[2] = std::max(dp[1], (long long)(power_cnt[2] << 1));

    for (int i = 3; i <= max_power; ++i) {
      // 释放技能i
      long long p1 = i * power_cnt[i] + dp[i - 3];

      // 不释放技能i
      long long p2 = dp[i - 1];

      dp[i] = std::max(p1, p2);
    }

    return dp[max_power];
  }
};

class Solution {
public:
  long long maximumTotalDamage(std::vector<int> &power) {
    // key表示伤害值，val表示伤害值为key的伤害种类
    // 已排序
    std::map<int, int> power_cnt;
    for (int p : power) {
      power_cnt[p]++;
    }

    int n = power_cnt.size();
    if (n == 1) {
      auto p = power_cnt.begin();
      return (long long)p->first * p->second;
    }

    // 收集所有的伤害值
    std::vector<int> unique_power;
    unique_power.reserve(n);
    for (auto it : power_cnt) {
      unique_power.push_back(it.first);
    }

    // dp[i]表示power_cnt前i个伤害能构成的最大伤害值
    std::vector<long long> dp(n + 1, 0);

    /// 前1个伤害造成的最大值
    auto p = power_cnt.begin();
    dp[1] = (long long)p->first * p->second;

    for (int i = 2; i <= n; ++i) {
      // 选择1：对于伤害值unique_power[i-1]的技能，都不释放
      dp[i] = dp[i - 1];

      // 选择2：释放伤害值为unique_power[i-1]的所有技能
      int cur = unique_power[i - 1];
      long long power = cur * power_cnt[cur];
      // 寻找第一个大于cur - 3的伤害值
      auto tmp =
          std::upper_bound(unique_power.begin(), unique_power.end(), cur - 3);
      if (tmp != unique_power.begin()) {
        --tmp;
        power += dp[tmp - unique_power.begin() + 1];
      }

      dp[i] = std::max(dp[i], power);
    }

    return dp[n];
  }
};

// @lc code=end
