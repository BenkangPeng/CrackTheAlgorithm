/// 离散化
/// https://leetcode.cn/problems/xepqZ5/

// 注意数据范围
// 1 <= forceField.length <= 100
// forceField[i].length == 3
// 0 <= forceField[i][0], forceField[i][1] <= 10^9
// 1 <= forceField[i][2] <= 10^9

#include <algorithm>
#include <vector>
using std::vector;
class Solution {
private:
  void add(std::vector<std::vector<int>> &diff, int a, int b, int c, int d) {
    ++a, ++b, ++c, ++d;
    diff[a][b] += 1;
    diff[c + 1][b] -= 1;
    diff[a][d + 1] -= 1;
    diff[c + 1][d + 1] += 1;
  }

public:
  int fieldOfGreatestBlessing(vector<vector<int>> &forceField) {
    long left, right, top, bottom, x, y, side;

    /// 记录所有力场x轴方向,y轴方向的边界坐标
    /// 为避免出现小数,坐标都乘2
    std::vector<long> x_d, y_d;
    for (auto field : forceField) {
      x = field[0], y = field[1], side = field[2];

      /// 该力场的左边界
      left = (x << 1) - side;
      /// 右边界
      right = (x << 1) + side;
      top = (y << 1) + side;
      bottom = (y << 1) - side;

      x_d.push_back(left);
      x_d.push_back(right);
      y_d.push_back(top);
      y_d.push_back(bottom);
    }

    /// 排序去重
    std::sort(x_d.begin(), x_d.end());
    x_d.erase(std::unique(x_d.begin(), x_d.end()), x_d.end());

    std::sort(y_d.begin(), y_d.end());
    y_d.erase(std::unique(y_d.begin(), y_d.end()), y_d.end());

    int m = x_d.size(), n = y_d.size();

    std::vector<std::vector<int>> diff(m + 2, std::vector<int>(n + 2, 0));
    for (auto field : forceField) {
      long x = field[0], y = field[1], size = field[2];

      /// 找到该力场对应的离散值
      /// 左上角(a,b), 右下角(c,d)
      int a = std::lower_bound(x_d.begin(), x_d.end(), (x << 1) - size) -
              x_d.begin();
      /// @attention 注意这里Y坐标是y*2-size而不是y*2 + size
      /// 因为b要是diff中上边界(小的值),对应的就是2y-size
      int b = std::lower_bound(y_d.begin(), y_d.end(), (y << 1) - size) -
              y_d.begin();

      int c = std::lower_bound(x_d.begin(), x_d.end(), (x << 1) + size) -
              x_d.begin();
      int d = std::lower_bound(y_d.begin(), y_d.end(), (y << 1) + size) -
              y_d.begin();

      add(diff, a, b, c, d);
    }
    /// 还原diff
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        ans = diff[i][j] > ans ? diff[i][j] : ans;
      }
    }

    return ans;
  }
};