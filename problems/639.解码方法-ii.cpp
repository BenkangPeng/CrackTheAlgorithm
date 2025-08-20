/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */
#include <string>
// @lc code=start
class Solution {
public:
  int numDecodings(const std::string &s) {
    int n = s.size();
    constexpr int MOD = int(1e9 + 7);
    long long nextNext = 1, next = 0;

    if (s[n - 1] != '0') {
      if (s[n - 1] == '*') {
        next = 9;
      } else {
        next = 1;
      }
    }

    long long cur = next; /// 为了s = "*"这个特例
    for (int i = n - 2; i >= 0; --i) {
      cur = 0;
      if (s[i] != '0') {
        if (s[i] == '*') {
          /// 单独解码
          cur += 9 * next;

          /// 联合解码
          if (s[i + 1] != '*') {
            if (s[i + 1] <= '6') {
              cur += 2 * nextNext;
            } else {
              cur += nextNext;
            }
          } else {
            /// @attention "**"联合解码时, 可以表达[11,19] + [21,26],
            /// '*'不能表示0
            cur += 15 * nextNext;
          }

        } else {
          /// 单独解码
          cur = next;

          /// 联合解码
          if (s[i + 1] != '*') {
            int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (tmp > 9 && tmp < 27) {
              cur += nextNext;
            }
          } else {
            if (s[i] == '1') {
              cur += 9 * nextNext;
            } else if (s[i] == '2') {
              cur += 6 * nextNext;
            }
          }
        }
      }
      cur %= MOD;
      nextNext = next;
      next = cur;
    }

    return cur;
  }
};
// @lc code=end
