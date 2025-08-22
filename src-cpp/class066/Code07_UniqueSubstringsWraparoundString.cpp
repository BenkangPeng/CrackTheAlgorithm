/// 467.
/// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/
/// 这道题如果还用严格位置依赖的DP来做的话,
/// 发现转移状态方程不好写(找不到dp[i]与dp[j]之间的关系)
/// 用dp表存储以各字符结尾的子串个数, 例如dp[0]表示以'a'结尾的满足条件的子串个数

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
class Solution {
public:
  int findSubstringInWraproundString(const std::string &s) {
    /// 用dp表存储以各字符结尾的子串个数,
    /// 例如dp[0]表示以'a'结尾的满足条件的子串个数
    std::vector<int> dp(26, 0);

    int n = s.size();
    std::vector<int> sv(n, 0);
    int i = 0;
    for (char ch : s) {
      sv[i++] = ch - 'a';
    }

    /// 以s的第一个字符结尾的子串长度为1
    dp[sv[0]] = 1;

    /// 累计的有效子串长度
    int max_len = 1;
    for (int i = 1; i < n; ++i) {
      if (sv[i] - 1 == sv[i - 1] || (sv[i] == 0 && sv[i - 1] == 25)) {
        ++max_len;
        dp[sv[i]] = std::max(dp[sv[i]], max_len);
      } else {
        max_len = 1;
        dp[sv[i]] = std::max(1, dp[sv[i]]);
      }
    }

    return std::accumulate(dp.begin(), dp.end(), 0);
  }
};