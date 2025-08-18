/// 没想到fibonacci有这么多花样

/// https://leetcode.cn/problems/fibonacci-number/description/
// "每个动态规划问题中,都会有一个反复调用的迭代过程"

/// 递归写法,复杂度为O(2^N)
#include <vector>
class Solution1 {
public:
  int fib(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    return fib(n - 1) + fib(n - 2);
  }
};
/// 但是我们发现上述的递归写法有许多冗余计算
/// 例如, 计算f(6)时,需要递归展开f(5)和f(4),
/// 计算f(5)时必须先计算出f(4),但是f(4)的结果没有保存,之后仍然要重复计算一次f(4)


/// 记录递归中算过的数值, 避免重复计算
/// O(N)
/// 从顶到底的动态规划, 记忆化搜索
class Solution2 {
public:
  int fib(int n) {
    std::vector<int> dp(n + 1, -1);
    return f(n, dp);
  }

private:
  int f(int n, std::vector<int> &dp) {
    if (n == 0 || n == 1) {
      return n == 1 ? 1 : 0;
    }
    if (dp[n] != -1) {
      return dp[n];
    }

    /// 记录下算出来过的fib(n)
    dp[n] = f(n - 1, dp) + f(n - 2, dp);
    return dp[n];
  }
};

/// 从底到顶的动态规划
class Solution3 {
public:
  int fib(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    return f(n, dp);
  }

private:
  int f(int n, std::vector<int> &dp) {
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};

/// 再省省空间
class Solution4 {
public:
  int fib(int n) {
    if (n == 0 || n == 1) {
      return n == 1 ? 1 : 0;
    }

    int last = 1, lastLast = 0;
    int cur = 0;
    for (int i = 2; i <= n; ++i) {
      cur = last + lastLast;
      lastLast = last;
      last = cur;
    }
    return cur;
  }
};