/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */
#include <string>
// @lc code=start
class Solution {
public:
  int maxVowels(const std::string &s, int k) {

    int n = s.size();
    /// 窗口中元音字母个数
    int cnt = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      if (check(s[r])) {
        cnt++;
      }

      if (r - l + 1 ==  k) {
        ans = ans < cnt ? cnt : ans;

        if(check(s[l++])){
            cnt--;
        }
      }

    }
    return ans;
  }

private:
  bool check(char ch) {
    return ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u';
  }
};
// @lc code=end
