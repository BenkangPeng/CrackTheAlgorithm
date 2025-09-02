/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 */
#include <string>
#include <vector>
using std::string;
/// 连续单一字符(数字)有多少种解码方式
/// e.g. "666666"有多少种解码方式
/// 又是一个"爬楼梯"问题变形：可以用一个,两个,三个6来拼凑,问拼成"666666"有多少种方法
/// 注意：7和9有4种拼法，其他字符有三种拼法
/// 因此分了两个dp表
// @lc code=start
class Solution {
public:
  int countTexts(string pressedKeys) {
    int n = pressedKeys.size();
    constexpr int mod = int(1e9 + 7);
    std::vector<long long> dp0(100001, -1);
    std::vector<long long> dp1(100001, -1);

    dp0[1] = 1, dp0[2] = 2, dp0[3] = 4; // dp0[4] = 7
    for (int i = 4; i <= n; ++i) {
      dp0[i] = (dp0[i - 1] + dp0[i - 2] + dp0[i - 3]) % mod;
    }

    dp1[1] = 1, dp1[2] = 2, dp1[3] = 4, dp1[4] = 8;
    for (int i = 5; i <= n; ++i) {
      dp1[i] = (dp1[i - 1] + dp1[i - 2] + dp1[i - 3] + dp1[i - 4]) % mod;
    }

    int i = 0, j = 0;
    int ans = 1;
    while (j < n) {
      if (pressedKeys[j] == pressedKeys[i]) {
        ++j;
      } else {
        if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
          ans = (ans * dp1[j - i]) % mod;
        } else {
          ans = (ans * dp0[j - i]) % mod;
        }
        i = j;
      }
    }

    if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
      ans = (long long)(ans * dp1[j - i]) % mod;
    } else {
      ans = (long long)(ans * dp0[j - i]) % mod;
    }

    return ans;
  }
};

// @lc code=end

// "444479999555588866"