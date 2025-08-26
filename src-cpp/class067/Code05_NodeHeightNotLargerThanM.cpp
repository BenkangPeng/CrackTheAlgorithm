/// https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea
/// 二叉树的动态规划一般都是左节点递归下去, 右节点递归下去
#include <iostream>
#include <vector>
const int MOD = int(1e9 + 7);
int compute(int n, int m, std::vector<std::vector<long>> &dp) {
  /// base case
  if (n == 0) {
    return 1; // 空树
  }

  // n > 0
  if (m == 0) {
    return 0;
  }

  if (dp[n][m] != -1) {
    return dp[n][m];
  }

  long ans = 0;
  for (int i = 0; i < n; ++i) {
    /// root结点的左树有i个结点, 右树有n-1-i个结点

    // 左树的种类
    long left = compute(i, m - 1, dp) % MOD;
    // 右树的种类
    long right = compute(n - 1 - i, m - 1, dp) % MOD;

    ans = (ans + (left * right) % MOD) % MOD;
  }

  dp[n][m] = ans;
  return ans;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<long>> dp(n + 1, std::vector<long>(m + 1, -1));

  std::cout << compute(n, m, dp);
}