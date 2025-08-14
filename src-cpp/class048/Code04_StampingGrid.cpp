/// https://leetcode.cn/problems/stamping-the-grid/

#include <iostream>
#include <utility>
#include <vector>

using std::vector;
class Solution {
private:
  /// 获得前缀和数组
  std::vector<std::vector<int>>
  getPrefixSum(const std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> prefix(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        prefix[i + 1][j + 1] =
            prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + grid[i][j];
      }
    }
    return std::move(prefix);
  }

  /// 差分数组
  std::vector<std::vector<int>>
  getDiff(const std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> _diff(m + 2, std::vector<int>(n + 2, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          regionOp(_diff, i, j, i, j, 1);
        }
      }
    }

    return std::move(_diff);
  }

  /// region operation
  void regionOp(std::vector<std::vector<int>> &diff, int a, int b, int c, int d,
                int k) {
    ++a, ++b, ++c, ++d;
    diff[a][b] += k;
    diff[c + 1][b] -= k;
    diff[a][d + 1] -= k;
    diff[c + 1][d + 1] += k;
  }

  /// 通过前缀和数组得到区域和
  int sumRegion(const std::vector<std::vector<int>> &prefixSum,
                const std::vector<std::vector<int>> &grid, int a, int b, int c,
                int d) {
    ++a, ++b, ++c, ++d;
    return prefixSum[c][d] - prefixSum[c][b - 1] - prefixSum[a - 1][d] +
           prefixSum[a - 1][b - 1];
  }

public:
  bool possibleToStamp(vector<vector<int>> &grid, int stampHeight,
                       int stampWidth) {
    int m = grid.size(), n = grid[0].size();
    auto prefixSum = getPrefixSum(grid);
    auto diff = getDiff(grid);
    for (int i = 0, c = i + stampHeight - 1; i < m && c < m; ++i, ++c) {
      for (int j = 0, d = j + stampWidth - 1; j < n && d < n; ++j, ++d) {
        /// 如果区域(i,j)  (i+stampHeight-1,
        /// j+stampWidth-1)全是0,那么可以贴一张邮票
        if (sumRegion(prefixSum, grid, i, j, c, d) == 0) {
          regionOp(diff, i, j, c, d, 1);
        }
      }
    }

    /// 检查贴过邮票后,格子中是否还有零
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        /// 还原grid
        diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        if (diff[i][j] == 0) {
          return false;
        }
      }
    }

    return true;
  }
};

// int main() {
//   Solution ss;
//   std::vector<std::vector<int>> vec = {
//       {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

//   std::cout << ss.possibleToStamp(vec, 2, 2) << std::endl;
// }
