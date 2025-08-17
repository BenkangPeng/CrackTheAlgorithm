/// https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
/// 这道题硬做不太好解,但固定字符种类后就好解了
/// 分类讨论
/// 1. 当子串中字符种类为1时, >=k的最长子串
/// 2. 当子串中字符种类为2时, >=k的最长子串
/// ......
/// i. 当子串中字符种类为i时, >=k的最长子串(1<= i <=26)
/// 对以上26中情况求最大值

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int longestSubstring(const std::string &s, int k) {

    int ans = 0;
    /// @param num 子串中字符种类
    for (int num = 1; num <= 26; ++num) {
      int max_len = f(s, num, k);
      ans = ans < max_len ? max_len : ans;
    }

    return ans;
  }

private:
  /*!
   @brief 找到s中, 字符种类为num, 且所有字符个数>=k的最长子串
   @return 满足条件的子串的最大长度
  */
  int f(const std::string &s, int num, int k) {
    /// 记录每种字符出现的次数
    std::vector<int> cnt(26, 0);
    /// @param collect 当前窗口收集到的字符种类数
    /// @param satisfy 满足"个数>=k"的字符的种类数(有几种字符的个数>=k)
    int collect = 0, satisfy = 0;
    int ans = 0;

    for (int l = 0, r = 0; r < s.size(); ++r) {
      int idx = s[r] - 'a';
      cnt[idx]++;

      if (cnt[idx] == 1) {
        collect++;
      }

      if (cnt[idx] == k) {
        satisfy++;
      }

      if (collect == num && satisfy == num) {
        ans = ans < r - l + 1 ? r - l + 1 : ans;
      }

      /// 窗口中字符种类数>num(超标了)
      /// 向左滑动窗口
      while (collect > num) {

        int idx_l = s[l] - 'a';
        cnt[idx_l]--;

        if (cnt[idx_l] == 0) {
          collect--;
        }

        if (cnt[idx_l] == k - 1) {
          satisfy--;
        }
        l++;
      }
    }

    return ans;
  }
};

// int main() {
//   std::string s = "aaabbb";
//   Solution ss;
//   std::cout << ss.longestSubstring(s, 3) << std::endl;
// }