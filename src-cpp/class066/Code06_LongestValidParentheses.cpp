/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 */
#include <iostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int longestValidParentheses(const std::string &s) {
    int n = s.size();
    /// dp[i] 表示以s[i]开头的最长有效括号的长度
    std::vector<int> dp(n + 1, 0);

    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] == ')') {
        dp[i] = 0;
      } else { // s[i] = '('
        if (s[i + 1] == ')') {
          /// s[i]与s[i+1]组成一对有效括号, 再加上dp[i+2]
          dp[i] = 2 + dp[i + 2];
        } else { // s[i+1] = '('
          int p = i + dp[i + 1] + 1;
          if (p < n && s[p] == ')') {
            /// s[i]与s[p]组成一对有效括号, 其中包含了长度为dp[i+1]的有效括号
            /// 仍需检查dp[p+1]向右能否构成有效括号
            dp[i] = 2 + dp[i + 1] + (p + 1 < n ? dp[p + 1] : 0);
          }
        }
      }

      ans = std::max(ans, dp[i]);
    }

    return ans;
  }
};
// @lc code=end

int main() {
  std::string s = "((()))())";
  Solution ss;
  std::cout << ss.longestValidParentheses(s) << std::endl;
}