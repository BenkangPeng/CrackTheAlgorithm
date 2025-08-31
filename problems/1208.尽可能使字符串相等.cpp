/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */
#include <string>
using std::string;
// @lc code=start
class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {

    int cost = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < s.size(); ++r) {
      cost += (s[r] > t[r]) ? s[r] - t[r] : t[r] - s[r];

      while (cost > maxCost) {
        cost -= (s[l] > t[l]) ? s[l] - t[l] : t[l] - s[l];
        ++l;
      }

      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
// @lc code=end
