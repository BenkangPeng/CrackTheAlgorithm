/// https://leetcode.cn/problems/decode-ways-ii/description/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int numDecodings(const std::string &s) {
    int n = s.size();
    constexpr int MOD = int(1e9 + 7);
    std::vector<long long> dp(n + 1, 0);
    dp[n] = 1;
    if (s[n - 1] != '0') {
      if (s[n - 1] == '*') {
        dp[n - 1] = 9;
      } else {
        dp[n - 1] = 1;
      }
    }

    for (int i = n - 2; i >= 0; --i) {
      if (s[i] != '0') {
        if (s[i] == '*') {
          /// 单独解码
          dp[i] = 9 * dp[i + 1];

          /// 联合解码
          if (s[i + 1] != '*') {
            if (s[i + 1] <= '6') {
              dp[i] += 2 * dp[i + 2];
            } else {
              dp[i] += dp[i + 2];
            }
          } else {
            /// @attention "**"联合解码时, 可以表达[11,19] + [21,26],
            /// '*'不能表示0
            dp[i] += 15 * dp[i + 2];
          }

        } else {
          /// 单独解码
          dp[i] = dp[i + 1];

          /// 联合解码
          if (s[i + 1] != '*') {
            int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (tmp > 9 && tmp < 27) {
              dp[i] += dp[i + 2];
            }
          } else {
            if (s[i] == '1') {
              dp[i] += 9 * dp[i + 2];
            } else if (s[i] == '2') {
              dp[i] += 6 * dp[i + 2];
            }
          }
        }
      }
      dp[i] = dp[i] % MOD;
    }

    return dp[0];
  }
};

/// 优化空间复杂度O(1)
/// 将dp[i+1]改成next表示, 从当前位置i的下一个位置i+1开始解码, 由多少种方法
/// dp[i+2]改成nextNext
/// dp[i]改成cur
class Solution2 {
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

int main() {
  std::string s = "**";
  Solution ss;
  std::cout << ss.numDecodings(s) << std::endl;
}