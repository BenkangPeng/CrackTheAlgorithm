/// https://leetcode.cn/problems/decode-ways/
#include <string>
#include <vector>
#include<iostream>

/// 递归调用, 记忆化搜索
class Solution1 {
public:
  int numDecodings(const std::string &s) {
    int n = s.size();
    std::vector<int> dp(n, -1);
    return f(s, 0, dp);
  }

private:
  /// 从idx开始, 共多少种解码方式
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

/// 由递归改成自底向顶
class Solution2 {
public:
  int numDecodings(const std::string &s) {
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = s[n - 1] != '0' ? 1 : 0;

    for (int i = n - 2; i >= 0; --i) {
      int x = s[i] - '0', y = s[i + 1] - '0';
      int z = x * 10 + y;

      /// 将s[i]单独解码
      if (x != 0) {
        dp[i] += dp[i + 1];
      }

      /// 将s[i:i+1]解码
      if (z >= 10 && z <= 26) {
        dp[i] += dp[i + 2];
      }
    }

    return dp[0];
  }
};

/// 继续优化, 省空间
class Solution3 {
public:
  int numDecodings(const std::string &s) {

    int n = s.size();
    int nextNext = 1; // idx=n时解码种数
    int next = 0;
    if (s[n - 1] != '0') {
      next = 1;
    }
    /// 特判
    if(n == 1){
      return next;
    }

    int cur = 0;
    for (int i = n - 2; i >= 0; --i) {
      cur = 0;
      if (s[i] != '0') {
        cur += next;
      }

      int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
      if (tmp > 9 && tmp < 27) {
        cur += nextNext;
      }

      nextNext = next;
      next = cur;
    }

    return cur;
  }
};

int main(){
  std::string s = "226";
  Solution3 ss;
  std::cout << ss.numDecodings(s) << std::endl;
}