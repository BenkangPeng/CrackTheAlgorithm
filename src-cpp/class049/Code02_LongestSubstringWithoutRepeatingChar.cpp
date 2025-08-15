/// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

#include <string>
#include <vector>
class Solution {
public:
  int lengthOfLongestSubstring(const std::string &s) {

    int n = s.size();
    int ans = 0;
    /// 记录字符上次出现的最迟的位置,初始为-1
    std::vector<int> pos(256, -1);

    for (int l = 0, r = 0; r < n; ++r) {
      /// 该字符以前出现过
      if (pos[s[r]] != -1) {
        /// 在窗口中
        if (pos[s[r]] >= l) {
          /// 调整左边界
          l = pos[s[r]] + 1;
        }
      }
      /// update position
      pos[s[r]] = r;
      ans = r - l + 1 > ans ? r - l + 1 : ans;
    }

    return ans;
  }
};