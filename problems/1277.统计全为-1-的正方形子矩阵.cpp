/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */
#include <vector>
// @lc code=start
class Solution {
public:
  int countSquares(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int>> prefix(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        prefix[i + 1][j + 1] =
            prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + matrix[i][j];
      }
    }

    int ans = 0;
    /// 遍历每一个可能的左上顶点(a,b)
    for (int a = 0; a < m; ++a) {
      for (int b = 0; b < n; ++b) {
        /// 遍历每一个可能的右下顶点
        for (int c = a, d = b; c < m && d < n; ++c, ++d) {
          int num_one = (c - a + 1) * (c - a + 1);
          if (prefix[c + 1][d + 1] - prefix[c + 1][b] - prefix[a][d + 1] +
                  prefix[a][b] ==
              num_one) {
            ++ans;
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end
