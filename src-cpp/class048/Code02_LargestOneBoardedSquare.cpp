/// https://leetcode.cn/problems/largest-1-bordered-square/

#include <vector>
using std::vector;
class Solution {
private:
  std::vector<std::vector<int>> sum;

  /// 获得左上顶点(a,b)右下顶点(c,d)组成的正方形区域的区域和
  int get_region_sum(int a, int b, int c, int d) {
    ++a, ++b, ++c, ++d;
    return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
  }

public:
  int largest1BorderedSquare(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    /// 得到grid二维前缀和
    sum.resize(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i + 1][j + 1] =
            grid[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
      }
    }

    /// 特判全零的测试用例,否则过不了这部分的测试
    /// 如果整个grid数组全为0
    if (sum[m][n] == 0) {
      return 0;
    }

    int max_side_len = 0;
    for (int a = 0; a < m; ++a) {
      for (int b = 0; b < n; ++b) {
        /// the top-left vertex of the square: (a,b)
        /// bottom-right vertex : (c, d)
        /// 遍历所有左上顶点(a,b),边长从side_len开始增长,去尝试
        /// side_len不用从1开始,从max_side_len+1开始就行了
        for (int side_len = max_side_len + 1, c = a + side_len - 1,
                 d = b + side_len - 1;
             c < m && d < n; ++c, ++d, ++side_len) {
          /// (a,b)(c,d)正方形边上的元素和, 是否等于周长
          if (get_region_sum(a, b, c, d) -
                  get_region_sum(a + 1, b + 1, c - 1, d - 1) ==
              ((side_len - 1) << 2)) {
            max_side_len = side_len;
          }
        }
      }
    }
    return max_side_len * max_side_len;
  }
};