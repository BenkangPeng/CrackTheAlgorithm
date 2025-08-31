/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */
#include <string>
#include <unordered_map>
using std::string;
// @lc code=start
class Solution {
public:
  int maximumLengthSubstring(string s) {

    std::unordered_map<char, int> map;
    int cnt = 0; // 记录出现次数>2的字符的个数(违规字符种数)
    int ans = 0;
    for (int l = 0, r = 0; r < s.size(); ++r) {
      if (map[s[r]]++ == 2) {
        cnt++;
      }

      while (cnt > 0) {
        if (--map[s[l]] == 2) {
          cnt--;
        }
        ++l;
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
// @lc code=end
