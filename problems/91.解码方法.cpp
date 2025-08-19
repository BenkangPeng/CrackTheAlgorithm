/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <string>
#include<vector>
// @lc code=start
class Solution {
public:
  int numDecodings(const std::string &s) {
    int n = s.size();
    std::vector<int> dp(n, -1);
    return f(s, 0, dp);
  }

private:
  int f(const std::string &s, int idx, std::vector<int> &dp) {
    if (dp[idx] != -1) {
      return dp[idx];
    }

    if (idx == s.size() - 1) {
      if (s[idx] != '0') {
        return 1;
      }
      return 0;
    }

    
    int ans = 0;
    int x = s[idx] - '0', y = s[idx + 1] - '0';
    int z = x * 10 + y;

    if (x != 0) {
      /// 将s[idx]单独解码成一个字母
      ans += f(s, idx + 1, dp);
    }

    /// 将s[idx:idx+1]当成整体解码成一个字母
    if (z >= 10 && z <= 26) {
      /// 一个特判
      if (idx + 2 == s.size()) {
        ans++;
      } else {
        ans += f(s, idx + 2, dp);
      }
    }
    dp[idx] = ans;
    return ans;
  }
};
// @lc code=end
