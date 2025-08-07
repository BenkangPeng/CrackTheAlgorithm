/// https://leetcode.cn/problems/range-sum-query-2d-immutable/
/// 二维前缀和
#include <iostream>
#include <vector>

class NumMatrix {
private:
  std::vector<std::vector<int>> data;

public:
  NumMatrix(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    data.resize(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        data[i][j] = matrix[i - 1][j - 1];
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    row1++, col1++, row2++, col2++;
    return data[row2][col2] - data[row2][col1 - 1] - data[row1 - 1][col2] +
           data[row1 - 1][col1 - 1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// int main() {
//   std::vector<std::vector<int>> vec = {{3, 0, 1, 4, 2},
//                                        {5, 6, 3, 2, 1},
//                                        {1, 2, 0, 1, 5},
//                                        {4, 1, 0, 1, 7},
//                                        {1, 0, 3, 0, 5}};

//   NumMatrix *obj = new NumMatrix(vec);
//   int param_1 = obj->sumRegion(2, 1, 4, 3);
//   std::cout << param_1;
// }