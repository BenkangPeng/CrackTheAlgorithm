/// https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc
/// 二维差分我理解有困难, 见note.md
#include <iostream>
#include <vector>

void add(std::vector<std::vector<long>> &matrix, int x1, int y1, int x2, int y2,
         int k) {
  matrix[x1][y1] += k;
  matrix[x2 + 1][y1] -= k;
  matrix[x1][y2 + 1] -= k;
  matrix[x2 + 1][y2 + 1] += k;
}
int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  /// 二维差分数组
  std::vector<std::vector<long>> diff(n + 2, std::vector<long>(m + 2, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int val;
      std::cin >> val;
      /// 原数组的值, 转换到差分数组
      add(diff, i + 1, j + 1, i + 1, j + 1, val);
    }
  }

  int x1, y1, x2, y2, k;
  while (q--) {
    std::cin >> x1 >> y1 >> x2 >> y2 >> k;
    add(diff, x1, y1, x2, y2, k);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      diff[i][j] +=
          diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
      std::cout << diff[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
